#ifndef LOOONG_LOOONG_INT_HPP
#define LOOONG_LOOONG_INT_HPP

#include <iostream>
#include <bitset>

/*******************************************************************************
    class template declatation
*/

template <size_t n>
class LooongInt
{
public:

    // Default constructor
    LooongInt<n>(void);
    
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

