#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Test 1: Basic round-trip
    Data data = {5, 100, 1000, true, false};
    uintptr_t raw = Serializer::serialize(&data);
    Data *result = Serializer::deserialize(raw);

    std::cout << "Original: " << &data << std::endl;
    std::cout << "Result:   " << result << std::endl;
    std::cout << "Equal: " << (result == &data ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    // Test 2: Data integrity
    std::cout << "Level: " << result->level << " (expected 5)" << std::endl;
    std::cout << "Health: " << result->health << " (expected 100)" << std::endl;
    std::cout << "Points: " << result->points << " (expected 1000)" << std::endl;
    std::cout << std::endl;

    // Test 3: Modification through deserialized pointer
    result->level = 99;
    std::cout << "Modified result->level to 99" << std::endl;
    std::cout << "Original data.level: " << data.level << " (should be 99)" << std::endl;

    return 0;
}
