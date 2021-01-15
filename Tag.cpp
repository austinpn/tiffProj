#include "Tag.h"
namespace TiffParse
{
	Tag::Tag(FILE* filePtr, int offset) {
		char tagBytes[12];
		fseek(filePtr, offset, 0);
		fread(tagBytes, sizeof(tagBytes), 1, filePtr);


		char* tagBytesPtr = tagBytes;
		_tagId = *(unsigned short*)tagBytesPtr;

		tagBytesPtr += sizeof(_tagId);
		_dataType = *(unsigned short*)tagBytesPtr;

		tagBytesPtr += sizeof(_dataType);
		_dataCount = *(unsigned int*)tagBytesPtr;

		tagBytesPtr += sizeof(_dataCount);
		_dataOffset = *(unsigned int*)tagBytesPtr;
	}

	void operator<<(std::ostream& os, const Tag& t) {
		os << "Tag ID: " << t._tagId << "\nData Type: " <<
			t._dataType << "\nData Count: " << t._dataCount << "\nData Offset: " << t._dataOffset<<"\n";
	}
}