#include "Buffer.h"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <type_traits>

static_assert(std::is_move_constructible_v<Buffer>, "Buffer should be move constructible");
static_assert(std::is_move_assignable_v<Buffer>, "Buffer should be move assignable");

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

void TestCopySemantics()
{
    Buffer original(3);

    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    Buffer copy = original;

    copy[0] = 999;

    std::cout << "original: " << original[0] << '\n';
    std::cout << "copy: " << copy[0] << '\n';
}

void TestMoveSemantics()
{
    Buffer original(3);

    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    Buffer moved = std::move(original);

    std::cout << moved[0] << '\n';
    std::cout << moved[1] << '\n';
    std::cout << moved[2] << '\n';

    std::cout << original.Size() << '\n';
    std::cout << moved.Size() << '\n';
}

int main() 
{
    TestBuffer();
    TestAt();
    TestCopySemantics();
    TestMoveSemantics();
}
