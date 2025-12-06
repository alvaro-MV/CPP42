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

int main(void) {
    Data* data = new Data;

    data->iValue = 98;
    data->fValue = 42.42f;
    data->dValue = 123.456;

    std::cout << "Original pointer:        " << data << std::endl;

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized uintptr_t:    " << reinterpret_cast<void*>(raw) << std::endl;

    Data* restored = Serializer::deserialize(raw);
    std::cout << "Restored pointer:        " << restored << std::endl;

    std::cout << "\nContenido restaurado:\n";
    std::cout << "iValue = " << restored->iValue << std::endl;
    std::cout << "fValue = " << restored->fValue << std::endl;
    std::cout << "dValue = " << restored->dValue << std::endl;

    delete data;
}
