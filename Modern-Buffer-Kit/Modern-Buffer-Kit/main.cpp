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

int main() 
{
	TestBuffer();
}
