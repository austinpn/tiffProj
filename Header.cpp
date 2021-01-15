#include "Header.h"

namespace TiffParse
{
	Header::Header()
	{
		Endianness = 0;
		_initialIfdOffset = 0;

	}

	Header::Header(FILE* filePtr)
	{
		char data[8];
		char* dataPtr = data;

		fread(data, sizeof(data), 1, filePtr);
		Endianness = *(unsigned short*)dataPtr;

		dataPtr += 4;
		_initialIfdOffset = *(unsigned int*)(dataPtr);
	}

	void operator<<(std::ostream& os, const Header& h)
	{
		os << "Endianness: " << h.Endianness << "\nInitial Offset: " << h._initialIfdOffset<<"\n";
	}
}