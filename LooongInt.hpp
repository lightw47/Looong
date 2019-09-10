#ifndef LOOONG_LOOONG_INT_HPP
#define LOOONG_LOOONG_INT_HPP

#include <bitset>

template <size_t n>
class LooongInt
{
public:

    // Default constructor
    LooongInt(void)
    
    // Construct from known built-in types
    LooongInt(bool b);
    LooongInt(char c);
    LooongInt(unsigned char c);
    LooongInt(int i);
    LooongInt(unsigned int i);
    LooongInt(long l);
    LooongInt(unsigned long l);
   
    // Build from bitset
    LooongInt(const std::bitset<n> &other);
    
    // Destructor
    ~LooongInt(void);
    
    // Copy constructor
    LooongInt(const LooongInt &other);
    
    // Copy assignment operator
    LooongInt &operator=(LooongInt other);
    
    // Bit-wise operators
    LooongInt &operator&=(const LooongInt &other);
    LooongInt &operator|=(const LooongInt &other);
    LooongInt &operator^=(const LooongInt &other);
    LooongInt operator&(const LooongInt &other) const;
    LooongInt operator|(const LooongInt &other) const;
    LooongInt operator^(const LooongInt &other) const;
    LooongInt operator~(void) const;
    
    // Bit shift operators
    LooongInt &operator<<=(int val);
    LooongInt &operator>>=(int val);
    LooongInt operator>>(int val) const;
    LooongInt operator<<(int val) const;
    
    // Binary arithmetic operators
    LooongInt &operator+=(const LooongInt &other);
    LooongInt &operator-=(const LooongInt &other);
    LooongInt &operator*=(const LooongInt &other);
    LooongInt &operator/=(const LooongInt &other);
    LooongInt &operator%=(const LooongInt &other);
    LooongInt operator+(const LooongInt &other) const;
    LooongInt operator-(const LooongInt &other) const;
    LooongInt operator*(const LooongInt &other) const;
    LooongInt operator/(const LooongInt &other) const;
    LooongInt operator%(const LooongInt &other) const;
    
    // Unary arithmetic operators
    LooongInt operator-(void) const;
    LooongInt &operator++(void);
    LooongInt &operator--(void);
    LooongInt operator++(int) const;
    LooongInt operator--(int) const;
    
    // Comparison operators
    bool operator==(const LooongInt &other) const;
    bool operator!=(const LooongInt &other) const;
    bool operator<(const LooongInt &other) const;
    bool operator>(const LooongInt &other) const;
    bool operator<=(const LooongInt &other) const;
    bool operator>=(const LooongInt &other) const;

    // Logical operator
    bool operator!(void) const;
    bool operator&&(const LooongInt &other) const;
    bool operator||(const LooongInt &other) const;
    
    // Swap function
    void Swap(LooongInt &other);
    
private:
    std::bitset<n> _data;
};

#endif //LOOONG_LOOONG_INT_HPP
