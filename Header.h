#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <array>

namespace TiffParse 
{
	//using namespace std;
	class Header
	{
	public:
		Header(FILE* filePtr);
		Header();
		int GetInitialOffset() { return (int)_initialIfdOffset; }
		friend void operator<<(std::ostream& os, const Header& h);


	private:
		unsigned int _initialIfdOffset;
		unsigned short Endianness;
	};
}

