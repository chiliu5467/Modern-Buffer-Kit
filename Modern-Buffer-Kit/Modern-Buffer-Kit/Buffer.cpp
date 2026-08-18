#include "Buffer.h"

Buffer::Buffer(std::size_t size) 
	: data_(size)
{
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

int& Buffer::At(std::size_t index)
{
	return data_.at(index);
}

const int& Buffer::At(std::size_t index) const
{
	return data_.at(index);
}