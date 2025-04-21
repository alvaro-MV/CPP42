#pragma once

template <typename T>
Array<T>::Array() {
	this->array = new T[];
	this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::Array(Array<T>& array) {
	size_t copySize = array.size();
	this->array = new T[copySize];
	this->len = copySize;
	memcpy(this->array, array.array, copySize * sizeof(T));
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& array) {
	size_t copySize = array.size();
	this->array = new T[copySize];
	this->len = copySize;
	memcpy(this->array, array.array, copySize * sizeof(T));
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
		throw Array<T>::IndexOutOfBounds(index);
	else
		return (this->array[index]);
}

template <typename T>
size_t Array<T>::size() {
	return (this->len);
}


template <typename T>
const char* Array<T>::IndexOutOfBounds::what(void) const throw() {
	std::string problem = "Array<T>::IndexOutOfBounds exception: index "
	+ std::to_string(this->index)
	+ " from array of "
	+ "typeid<"
	+ typeid(T).name()
	+ ">"
	+ " is greater than size of the array.";

	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);	
}