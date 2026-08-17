#include "Buffer.h"

Buffer::Buffer(std::size_t size) 
{
	data_ = std::vector<int>(size);
}

std::size_t Buffer::Size() const
{
	return data_.size();
}

bool Buffer::Empty() const
{
	return data_.empty();
}

int& Buffer::operator[](std::size_t index)
{
	return data_[index];
}

const int& Buffer::operator[](std::size_t index) const
{
	return data_[index];
}