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

// Bitwise &=
template <size_t n>
LooongInt<n> &LooongInt<n>::operator&=(const LooongInt<n> &other)
{
    data &= other.data;
    return *this;
}

// Bitwise |=
template <size_t n>
LooongInt<n> &LooongInt<n>::operator|=(const LooongInt<n> &other)
{
    data |= other.data;
    return *this;
}

// Bitwise ^=
template <size_t n>
LooongInt<n> &LooongInt<n>::operator^=(const LooongInt<n> &other)
{
    data ^= other.data;
    return *this;
}

// Bitwise &
template <size_t n>
LooongInt<n> LooongInt<n>::operator&(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res &= other;
}

// Bitwise |
template <size_t n>
LooongInt<n> LooongInt<n>::operator|(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res |= other;
}

// Bitwise ^
template <size_t n>
LooongInt<n> LooongInt<n>::operator^(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res ^= other;
}

// Bitwise ~
template <size_t n>
LooongInt<n> LooongInt<n>::operator~(void) const
{
    LooongInt<n> res(*this);
    return res.Flip();
}

// Compound bitshift to left and assignment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator<<=(size_t val)
{
    data <<= val;
    return *this;
}

// Compound bitshift to right and assignment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator>>=(size_t val)
{
    data >>= val;
    return *this;
}

// bitshift to left
template <size_t n>
LooongInt<n> LooongInt<n>::operator<<(size_t val) const
{
    LooongInt res(*this);
    return res <<= val;
}

// bitshift to right
template <size_t n>
LooongInt<n> LooongInt<n>::operator>>(size_t val) const
{
    LooongInt res(*this);
    return res >>= val;
}

// space for other operators

// Swap function
template <size_t n>
void LooongInt<n>::Swap(LooongInt<n> &other)
{
    swap(data, other.data);
}

// Flip all bits in data
template <size_t n>
LooongInt<n> &LooongInt<n>::Flip(void)
{
    data.flip();
    return *this;
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

