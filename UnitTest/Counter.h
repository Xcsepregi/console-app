#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>

template<typename T>
size_t pocitadlo(istream &s)
{
	return distance(istream_iterator<T>(s), istream_iterator<T>());
}

struct Line :public string {};
istream & operator >> (istream &stream, Line &line)
{
	getline(stream, line);
	return stream;
};
