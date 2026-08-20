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

    // 驗證 destination 收到正確資料
    std::cout << moved[0] << '\n';
    std::cout << moved[1] << '\n';
    std::cout << moved[2] << '\n';

    // 不假設 original move 後的 size
    // 而是驗證它仍然可以重新被賦值、繼續使用
    original = Buffer(2);

    original[0] = 100;
    original[1] = 200;

    std::cout << original[0] << '\n';
    std::cout << original[1] << '\n';
}

void TestMoveAssignment()
{
    Buffer source(3);

    source[0] = 10;
    source[1] = 20;
    source[2] = 30;

    Buffer destination(5);

    destination = std::move(source);

    // 驗證 destination 收到資料
    std::cout << destination[0] << '\n';
    std::cout << destination[1] << '\n';
    std::cout << destination[2] << '\n';

    // 不檢查 source.Size() 是否為 0
    // 驗證 moved-from source 仍然可以重新使用
    source = Buffer(1);
    source[0] = 99;

    std::cout << source[0] << '\n';
}

int main() 
{
    TestBuffer();
    TestAt();
    TestCopySemantics();
    TestMoveSemantics();
    TestMoveAssignment();
}
