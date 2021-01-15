#pragma once
#include <iostream>
#include <Header.h>
#include <IFD.h>
#include <Tag.h>

namespace TiffParse
{
	class TiffFile
	{

	public:
		TiffFile(string fileName);
		Header FileHeader;
		//int GetIfdCount() { return size(IFDList); }
		unsigned int GetIfdCount();
		string GetFileName() { return _fileName; }
		friend void operator<<(ostream& os, const TiffFile& t);
	private:
		//unsigned int Endianness;
		//unsigned int InitialOffset;
		//int _ifdCount;
		string _fileName;

		vector<IFD> IFDList;
	};
}