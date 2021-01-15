#pragma once
class ReadEndian
{
public:
	static enum Endianness { LITTLE, BIG };
	static long ToBigEndianness(long n, bool isLittle);
	static void ToBigEndianness(char outArr[], bool isLittle);
private:
	ReadEndian();
};

