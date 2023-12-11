#include "Serializer.hpp"

int main( void )
{
    Data        data;
    uintptr_t   ptr;
    Data *      raw;

    data.name = "test data";
    data.number = 42;
    std::cout << "Data addres: " << &data << " name: " << \
    data.name << " number: " << data.number << std::endl;

    std::cout << "\n\n";

    ptr = Serializer::serialize(&data);
    std::cout << "ptr addres: " << ptr << std::endl;

    std::cout << "\n\n";

    raw = Serializer::deserialize(ptr);
    std::cout << "raw addres: " << raw << " name: " << \
    raw->name << " number: " << raw->number << std::endl;

    return 0;
}