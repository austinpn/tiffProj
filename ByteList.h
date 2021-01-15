#pragma once
#include "ReadEndian.h"

class ByteList
{
public:
	ByteList(ReadEndian::Endianness endianness);
	char operator[] (int i);
	long ConcatBytes(int i, int n);

private:
	char elements[];
	ByteList();
};

