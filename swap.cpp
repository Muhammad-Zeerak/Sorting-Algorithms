#pragma once

template <class X>
inline void swap(X *p, X *q) {

	X temp = *p;
	*p = *q;
	*q = temp;
}