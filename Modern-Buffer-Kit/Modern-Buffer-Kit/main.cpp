#include "Buffer.h"
#include <iostream>

void TestBuffer()
{
    Buffer buffer(5);

    buffer[0] = 10;
    buffer[1] = 20;

    std::cout << buffer[0] << '\n';
    std::cout << buffer.Size() << '\n';
}

void TestAt()
{
    try
    {
        Buffer buffer(5);

        buffer.At(2) = 42;
        std::cout << buffer.At(2) << '\n';

        std::cout << buffer.At(100) << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Out of range: " << e.what() << '\n';
    }
}

int main() 
{
    TestBuffer();
    TestAt();
}
