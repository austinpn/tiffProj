#include "ReadEndian.h"

long ReadEndian::ToBigEndianness(long n, bool isLittle) {
	if (isLittle) {
		return n;
	}

	long swapped = 0;
	long mask = 0xff;
	for (int i = 0; i < sizeof(long); i++) {
		swapped |= (n & mask << (24 - 4 * i));
	}
	return swapped;
}
