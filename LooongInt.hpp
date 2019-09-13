#ifndef LOOONG_LOOONG_INT_HPP
#define LOOONG_LOOONG_INT_HPP

#include <iostream>
#include <bitset>
#include <string>

/*******************************************************************************
    class template declatation
*/

template <size_t n>
class LooongInt
{
public:

    // Default constructor
    LooongInt(void);
    
    // Construct from known built-in types
    LooongInt(unsigned long l);
   
    // Build from bitset
    LooongInt(const std::bitset<n> &b);
    
    // Copy constructor
    LooongInt(const LooongInt &other);
    
    // Destructor
    ~LooongInt(void);
    
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
    LooongInt &operator<<=(size_t val);
    LooongInt &operator>>=(size_t val);
    LooongInt operator<<(size_t val) const;
    LooongInt operator>>(size_t val) const;
    
    // Conversion to bool
    explicit operator bool(void) const;
    
    // Logical operators
    bool operator!(void) const;
    bool operator&&(const LooongInt &other) const;
    bool operator||(const LooongInt &other) const;

    // Comparison operators
    bool operator==(const LooongInt &other) const;
    bool operator!=(const LooongInt &other) const;
    bool operator<(const LooongInt &other) const;
    bool operator>(const LooongInt &other) const;
    bool operator<=(const LooongInt &other) const;
    bool operator>=(const LooongInt &other) const;

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
    LooongInt operator++(int a) const;
    LooongInt operator--(int a) const;
    
    // Swap function
    void Swap(LooongInt &other);
    
    // Flip all bits in data
    LooongInt &Flip(void);
    
    // Mathematical functions
    LooongInt Abs(void) const;
    LooongInt Sign(void) const;
    LooongInt &TwosComp(void);
    size_t FLS(void) const;
    
    
//private:
    static void Division(LooongInt &quotient, LooongInt &dividend, LooongInt divisor);
    static std::string Decimal(const LooongInt &li);
    
public:
    // data bits
    std::bitset<n> data;
};

/*******************************************************************************
    function template declatations
*/

// stream output
template <size_t n>
std::ostream &operator<<(std::ostream &stream, const LooongInt<n> &li);

#include "LooongInt_Template.hpp"

#endif //LOOONG_LOOONG_INT_HPP

