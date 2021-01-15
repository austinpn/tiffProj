#include "TiffFile.h"

namespace TiffParse
{
	TiffFile::TiffFile(string fileName) {
		FILE* tiffFile;
		fopen_s(&tiffFile, fileName.c_str(), "r");
		FileHeader = Header(tiffFile);

		unsigned int nextIfdOffset = FileHeader.GetInitialOffset();
		while (nextIfdOffset > 0) {
			IFD ifd = IFD(tiffFile, nextIfdOffset);
			nextIfdOffset = ifd.GetNextIFDOffset();
			IFDList.push_back(ifd);
		}
	}

	unsigned int TiffFile::GetIfdCount() {
		return IFDList.size();
	}

	void operator<<(ostream& os, const TiffFile& t) {
		os << t._fileName << "\n";
		os << t.FileHeader;
		os << "\nIFD Entries:" << size(t.IFDList)<<"\n";
		for (IFD ifd : t.IFDList) {
			os << ifd;
		}
	}
}