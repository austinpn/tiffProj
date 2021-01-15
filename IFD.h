#pragma once
#include <iostream>
#include <vector>
#include <Tag.h>


using namespace std;
namespace TiffParse
{
	class IFD
	{
	public:
		IFD(FILE* filePtr, int offset);
		vector<Tag>& GetTagList() { return TagList; }
		unsigned int GetNextIFDOffset() { return _nextIfdOffset; }
		unsigned short GetNumDirEntries() { return _nextIfdOffset; }
		friend void operator<<(std::ostream& os, const IFD& i);
	private:
		vector<Tag> TagList;
		unsigned short _numDirEntries;
		unsigned int _nextIfdOffset;

	};
}

