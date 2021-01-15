#include "Scratch.h"
int main()
{
	FILE* filePtr;
	char charArr[8];
	char* bytePointer = charArr;
	fopen_s(&filePtr, "tiffEx.tif", "rb");

	int* offset = (int*)(bytePointer + 4);

	if (filePtr) {
		fclose(filePtr);
	}


	return 1;
}