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
    unsigned long sizeul = 8*sizeof(unsigned long);
    if (n > sizeul && data[min(sizeul, n)-1])
    {
        bitset<n> m1(-1);
        m1.flip();
        data |= m1;
    }
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

// Conversion to bool
template <size_t n>
LooongInt<n>::operator bool(void) const
{
    return data.any();
}

// Logical negation
template <size_t n>
bool LooongInt<n>::operator!(void) const
{
    return !static_cast<bool>(*this);
}

// Logical conjunction
template <size_t n>
bool LooongInt<n>::operator&&(const LooongInt<n> &other) const
{
    return static_cast<bool>(*this) && static_cast<bool>(other);
}

// Logical disjunction
template <size_t n>
bool LooongInt<n>::operator||(const LooongInt<n> &other) const
{
    return static_cast<bool>(*this) || static_cast<bool>(other);
}

// Compare (equals to)
template <size_t n>
bool LooongInt<n>::operator==(const LooongInt<n> &other) const
{
    return data == other.data;
}

// Compare (not equals to)
template <size_t n>
bool LooongInt<n>::operator!=(const LooongInt<n> &other) const
{
    return !( (*this) == other );
}

// Compare (less than)
template <size_t n>
bool LooongInt<n>::operator<(const LooongInt<n> &other) const
{
    if (data[n-1] != other.data[n-1])
        return data[n-1];
        
    for (unsigned int i = n-2; i != 0xffffffff; --i)
    {
        if (data[i] != other.data[i])
            return other.data[i];
    }
    
    return false;
}

// Compare (more than)
template <size_t n>
bool LooongInt<n>::operator>(const LooongInt<n> &other) const
{
    return !( (*this) <= other );
}

// Compare (less than or equals to)
template <size_t n>
bool LooongInt<n>::operator<=(const LooongInt<n> &other) const
{
    return (*this) == other || (*this) < other;
}

// Compare (more than or equals to)
template <size_t n>
bool LooongInt<n>::operator>=(const LooongInt<n> &other) const
{
    return !( (*this) < other );
}

// Compound sum and assignment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator+=(const LooongInt<n> &other)
{
    bitset<n> carry;
    bitset<n> op(other.data);
    while (op.any())
    {
        carry = (data & op) << 1;
        data ^= op;
        op = carry;
    }
    return *this;
}

// Compoud subtraction and assignment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator-=(const LooongInt<n> &other)
{
    return (*this) += -other;
}

// Compoud multiplication and assignment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator*=(const LooongInt<n> &other)
{
    LooongInt<n> m(*this);
    data.reset();
    for (size_t i = 0; i < n; ++i)
    {
        if (other.data[i])
            (*this) += m;
            
        m <<= 1;
    }

    return *this;
}

// Compoud division and assignment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator/=(const LooongInt<n> &other)
{
    return *this;
}

// Compoud modulo and assignment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator%=(const LooongInt<n> &other)
{
    return *this;
}

// Addition
template <size_t n>
LooongInt<n> LooongInt<n>::operator+(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res += other;
}

// Subtraction
template <size_t n>
LooongInt<n> LooongInt<n>::operator-(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res -= other;
}

// Multiplication
template <size_t n>
LooongInt<n> LooongInt<n>::operator*(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res *= other;
}

// Diviion
template <size_t n>
LooongInt<n> LooongInt<n>::operator/(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res /= other;
}

// Modulo (remainder of division)
template <size_t n>
LooongInt<n> LooongInt<n>::operator%(const LooongInt<n> &other) const
{
    LooongInt<n> res(*this);
    return res %= other;
}

// unary minus
template <size_t n>
LooongInt<n> LooongInt<n>::operator-(void) const
{
    LooongInt<n> res(*this);
    res.Flip();
    return ++res;
}

// prefix increment
template <size_t n>
LooongInt<n> &LooongInt<n>::operator++(void)
{
    return (*this) += LooongInt<n>(1);
}

// prefix decrement
template <size_t n>
LooongInt<n> &LooongInt<n>::operator--(void)
{
    return (*this) += LooongInt<n>(-1);
}

// postfix increment
template <size_t n>
LooongInt<n> LooongInt<n>::operator++(int a) const
{
    return ++LooongInt<n>(*this);
}

// postfix decrement
template <size_t n>
LooongInt<n> LooongInt<n>::operator--(int a) const
{
    return --LooongInt<n>(*this);
}

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

// Absolute value
template <size_t n>
LooongInt<n> LooongInt<n>::Abs(void) const
{
    return data[n-1] ? -(*this) : (*this);
}

// Sign
template <size_t>
char LooongInt<n>::Sign(void) const
{
    LooongInt<n> zero();
    return LooongInt<n>(( (*this > zero) ) - ( (*this) < zero ));
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

