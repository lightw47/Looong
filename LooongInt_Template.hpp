#include <algorithm>

using namespace std;

// Default constructor
template <size_t n>
LooongInt<n>::LooongInt<n>(void) :
    _data()
{
}

// Construct from known built-in types
template <size_t n>
LooongInt<n>::LooongInt<n>(unsigned long l) :
    _data(l)
{
}

// Build from bitset
template <size_t n>
LooongInt<n>::LooongInt<n>(const bitset<n> &b) :
    _data(b)
{
}

// Copy constructor
template <size_t n>
LooongInt<n>::LooongInt<n>(const LooongInt &other) :
    _data(other._data)
{
}

// Destructor
template <size_t n>
LooongInt<n>::~LooongInt(void)
{
}

// Copy assignment operator
template <size_t n>
LooongInt<n> &LooongInt<n>::operator=(LooongInt<n> other)
{
    Swap(other);
    return *this;
}

// space for other operators

// Swap function
template <size_t n>
void LooongInt<n>::Swap(LooongInt<n> &other)
{
    swap(_data, other._data);
}
