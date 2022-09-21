#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
#include <string>

template<typename T>
void swap(T &i, T &y) {
	T temp = i;
	i = y;
	y = temp;
}

template<typename T>
T min(T i, T y) {
	if (i < y)
		return i;
	return y;
}

template<typename T>
T max(T i, T y) {
	if (i > y)
		return i;
	return y;
}

#endif