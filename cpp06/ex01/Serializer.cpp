#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t ui_ptr;

	ui_ptr = reinterpret_cast<uintptr_t>(ptr);
	return (ui_ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	Data *data;

	data = reinterpret_cast<Data*>(raw);
	return (data);
}

int	main(void) {
	Data *data = new Data;
	char *data_str;
	char int_str[8];

	data->iValue = 98;
	std::cout << "Cual es la direccion de Data*: " << data << std::endl;
	uintptr_t ui_ptr = Serializer::serialize(data);
	printf("Cual es la direccion de ui_ptr: %p\n", (void *)ui_ptr);
	printf("Cual es la direccion de deserialize: %p\n", Serializer::deserialize(ui_ptr));

	data_str = reinterpret_cast<char*>(data);
	memcpy(int_str, data_str, 8);
	int *int_to_print = reinterpret_cast<int*>(int_str);
	std::cout << "Int para printar: " << *int_to_print << std::endl;

	delete data;
}