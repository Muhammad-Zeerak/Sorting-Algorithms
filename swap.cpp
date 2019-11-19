#pragma once

// will be used in different sorting algorithms so in separate class

template <class X>
inline void swap(X *p, X *q) {

	X temp = *p;
	*p = *q;
	*q = temp;
}
