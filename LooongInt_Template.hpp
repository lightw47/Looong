#include <algorithm>

using namespace std;

/*******************************************************************************
    class template implementation
*/

// Default constructor
template <size_t n>
LooongInt<n>::LooongInt(void) :
    data()
{
}

// Construct from known built-in types
template <size_t n>
LooongInt<n>::LooongInt(unsigned long l) :
    data(l)
{
}

// Build from bitset
template <size_t n>
LooongInt<n>::LooongInt(const bitset<n> &b) :
    data(b)
{
}

// Copy constructor
template <size_t n>
LooongInt<n>::LooongInt(const LooongInt &other) :
    data(other.data)
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
    swap(data, other.data);
}

/*******************************************************************************
    function template implementations
*/

// stream output
template <size_t n>
ostream &operator<<(ostream &stream, const LooongInt<n> &li)
{
    stream << li.data;
    return stream;
}

