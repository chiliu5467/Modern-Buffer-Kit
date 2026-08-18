#pragma once
#include <vector>
#include <cstddef>

class Buffer
{
    public:
        explicit Buffer(std::size_t size);

        std::size_t Size() const;
        bool Empty() const;

        int& operator[](std::size_t index);
        const int& operator[](std::size_t index) const;

        int& At(std::size_t index);
        const int& At(std::size_t index) const;

    private:
        std::vector<int> data_;
};
