#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

template <typename T>
class Array {
public:
    class IndexTooHigh : public std::exception {
        public:
        const char *what() const throw(){
            return ("ERROR: index > array size");
        };
};

public:

    Array(){
        this->_array = new T[0]();
        this->_size = 0;
    };

    Array(unsigned int n){
        this->_array = new T[n]();
        this->_size = n;
    };

    Array(const Array<T> &ref){
        *this = ref;
    };

    ~Array(){
            delete[] this->_array;
    }
    Array<T> &operator=(const Array<T> &ref){
        this->_size = ref._size;
        this->_array = new T[this->_size];
        return(*this);
    };

    int size(){
        return (this->_size);
    };

    T &operator[](int index){
        if (index + 1 > size())
            throw Array<T>::IndexTooHigh();
        return (this->_array[index]);
    };

private:
    T *_array;
    int _size;
     
};

template<typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &arr) {
	out << "[ ";
	for(int i = 0; i < arr.size(); ++i)
		out << arr[i] << " ";
	out << "]" << std::endl;
	return out;
}

#endif