#include "Serializer.hpp"
#include <iostream>


int main() {
    Data data = {42, "Hello, World!"};
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: id = " << deserializedData->id
              << ", name = " << deserializedData->name << std::endl;

    return 0;
}