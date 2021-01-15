#include "IFD.h"


namespace TiffParse
{
	/// <summary>
	/// IFD constructor
	/// </summary>
	/// <param name="filePtr">File ptr to tiff file.</param>
	/// <param name="offset">Offset from beginning of file to Beginning of IFD </param>
	IFD::IFD(FILE* filePtr, int offset) {
		_numDirEntries = 0;
		fseek(filePtr, (long)offset, 0);
		fread(&_numDirEntries, sizeof(_numDirEntries), 1, filePtr);

		//Extract tags from file.
		TagList = vector<Tag>();
		for (int i = offset + 2; i < offset + 2 + _numDirEntries * 12; i += 12) {
			TagList.push_back(Tag(filePtr, i));
		}

		_nextIfdOffset = 0;
		fseek(filePtr, (long)offset + 2 + 12 * _numDirEntries, 0);
		fread(&_nextIfdOffset, sizeof(_nextIfdOffset), 1, filePtr);
	}

	void operator<<(std::ostream& os, const IFD& i) {
		os << "Number of dir entries: " << i._numDirEntries << "\nNext offset: " << i._nextIfdOffset<<"\n";
		os << "\nTag Entries:\n\n";
		for (Tag tag : i.TagList)
		{
			os << tag;
			os << "\n";
		}

	}
}