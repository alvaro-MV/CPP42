#pragma once

template <typename T>
Array<T>::Array() {
	this->array = NULL;
	this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::Array(const Array<T>& array) {
	size_t copySize = array.size();
	this->array = new T[copySize];
	this->len = copySize;
	memcpy(this->array, array.array, copySize * sizeof(T));
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& array) {
	if (this != &array) {
		size_t copySize = array.size();
		delete[] this->array;
		this->array = new T[copySize];
		this->len = copySize;
		memcpy(this->array, array.array, copySize * sizeof(T));
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete[] this->array;
	std::cout << "Template Array Destructor called\n";
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->len)
		throw Array<T>::IndexOutOfBounds();
	else
		return (this->array[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (this->len);
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what(void) const throw() {
	return ("exception: index from array is greater than array size");
}