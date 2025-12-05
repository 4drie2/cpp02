/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPointDebug.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:33:07 by abidaux           #+#    #+#             */
/*   Updated: 2025/12/02 23:59:04 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPoint.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>

const int FRACTION_BITS = 16;
const int SCALE_FACTOR = 1 << FRACTION_BITS;

// --- Helper Functions ---

/**
 * Converts a floating-point number to fixed-point
 * @param value: Value to convert (float)
 * @return: Fixed-point value (fixed_t)
 */
fixed_t float_to_fixed(float value) {
	std::cout << "float_to_fixed called" << std::endl;
	if (value >= 0)
		return (fixed_t)(value * SCALE_FACTOR + 0.5f);
	else
		return (fixed_t)(value * SCALE_FACTOR - 0.5f);
}

// --- Constructors & Destructor ---

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << FRACTION_BITS;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	if (value >= 0)
		_value = (fixed_t)(value * SCALE_FACTOR + 0.5f);
	else
		_value = float_to_fixed(value);
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// --- Assignment Operator ---

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return *this;
}

// --- Getters & Setters ---

/**
 * Retrieves the raw fixed-point value
 * @return: Raw fixed-point value
 */
int Fixed::getRawBits() const {
	std::cout << "getRawBits called" << std::endl;
	return _value;
}

/**
 * Sets the raw fixed-point value
 * @param value: Raw fixed-point value
 */
void Fixed::setRawBits(int value) {
	std::cout << "setRawBits called" << std::endl;
	_value = value;
}

// --- Converters ---

/**
 * Converts the Fixed to float
 * @return: Floating-point value
 */
float Fixed::toFloat() const {
	std::cout << "toFloat called" << std::endl;
	return (float)_value / SCALE_FACTOR;
}

/**
 * Converts the Fixed to int
 * @return: Integer value
 */
int Fixed::toInt() const {
	std::cout << "toInt called" << std::endl;
	return _value >> FRACTION_BITS;
}

// --- Operators Overloads ---

// Comparison Operators
bool Fixed::operator>(const Fixed& other) const {
	std::cout << "operator> called" << std::endl;
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	std::cout << "operator< called" << std::endl;
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	std::cout << "operator>= called" << std::endl;
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	std::cout << "operator<= called" << std::endl;
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	std::cout << "operator== called" << std::endl;
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	std::cout << "operator!= called" << std::endl;
	return this->_value != other._value;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& other) const {
	std::cout << "operator+ called" << std::endl;
	Fixed result;
	result._value = this->_value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	std::cout << "operator- called" << std::endl;
	Fixed result;
	result._value = this->_value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	std::cout << "operator* called" << std::endl;
	Fixed result;
	result._value = (fixed_t)( ((int64_t)this->_value * (int64_t)other._value) >> FRACTION_BITS );
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	std::cout << "operator/ called" << std::endl;
	if (other._value == 0) {
		std::cerr << "Error: Division by zero detected!" << std::endl;
		std::abort();
	}
	Fixed result;
	result._value = (fixed_t)( ((int64_t)this->_value << FRACTION_BITS) / other._value );
	return result;
}

// Increment / Decrement Operators
Fixed& Fixed::operator++() {
	std::cout << "operator++ (prefix) called" << std::endl;
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	std::cout << "operator++ (postfix) called" << std::endl;
	Fixed tmp(*this);
	++this->_value;
	return tmp;
}

Fixed& Fixed::operator--() {
	std::cout << "operator-- (prefix) called" << std::endl;
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	std::cout << "operator-- (postfix) called" << std::endl;
	Fixed tmp(*this);
	--this->_value;
	return tmp;
}

// --- Static Public Functions ---

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	std::cout << "min (non-const) called" << std::endl;
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	std::cout << "min (const) called" << std::endl;
	return (a._value < b._value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	std::cout << "max (non-const) called" << std::endl;
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	std::cout << "max (const) called" << std::endl;
	return (a._value > b._value) ? a : b;
}

// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	float value_to_display = fixed.toFloat();
	os << value_to_display;
	return os;
}


// GEMINI SALE MERDE
