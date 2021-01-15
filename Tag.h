#pragma once
#include <iostream>
namespace TiffParse
{
	class Tag
	{
	public:
		Tag(FILE* filePtr, int offset);
		//Tag();
		unsigned short GetTagId() { return _tagId; }
		unsigned short GetDataType() { return _dataType; }
		unsigned int GetDataCount() { return _dataCount; }
		unsigned int GetDataOffset() { return _dataOffset; }
		friend void operator<<(std::ostream& os, const Tag& t);
	private:
		unsigned short _tagId;
		unsigned short _dataType;
		unsigned int _dataCount;
		unsigned int _dataOffset;
	};
}

