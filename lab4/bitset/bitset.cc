#include "bitset.h"
#include "bitreference.h"
#include "bitsetiterator.h"

Bitset::Bitset() : bits(0) {}

size_t Bitset::size() const {
	return BPW;
}

bool Bitset::operator[](size_t pos) const {
	return (bits & (1L << pos)) != 0;
}

BitReference Bitset::operator[](size_t pos) {
	return BitReference(&bits, pos);
}


//BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}
//förenklat
//BitsetIterator(Bitstorage, size)
//Storage för bitset är &bits
//size

Bitset::iterator Bitset::begin() {
	//return Bitset::iterator(&bits, 0); 

	return BitsetIterator(&bits, 0);
}

Bitset::iterator Bitset::end() {
	return BitsetIterator(&bits, BPW); //BPW should be end?
										 //may be size too
}
