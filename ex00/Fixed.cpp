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

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>

// --- Constructors & Destructor ---

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _numberOfFractionalBits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	if (value >= 0)
		this->_fixedPointValue = (int)(value * (1 << _numberOfFractionalBits) + 0.5f);
	else
		this->_fixedPointValue = (int)(value * (1 << _numberOfFractionalBits) - 0.5f);
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// --- Assignment Operator ---

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}

// --- Getters & Setters ---

/**
 * Retrieves the raw fixed-point value
 * @return: Raw fixed-point value
 */
int Fixed::getRawBits() const {
	std::cout << "getRawBits called" << std::endl;
	return _fixedPointValue;
}

/**
 * Sets the raw fixed-point value
 * @param value: Raw fixed-point value
 */
void Fixed::setRawBits(int value) {
	std::cout << "setRawBits called" << std::endl;
	_fixedPointValue = value;
}

// --- Converters ---

/**
 * Converts the Fixed to float
 * @return: Floating-point value
 */
float Fixed::toFloat() const {
	std::cout << "toFloat called" << std::endl;
	return (float)_fixedPointValue / (1 << _numberOfFractionalBits);
}

/**
 * Converts the Fixed to int
 * @return: Integer value
 */
int Fixed::toInt() const {
	std::cout << "toInt called" << std::endl;
	return _fixedPointValue >> _numberOfFractionalBits;
}

// --- Operators Overloads ---

// Comparison Operators
bool Fixed::operator>(const Fixed& other) const {
	std::cout << "operator> called" << std::endl;
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const {
	std::cout << "operator< called" << std::endl;
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const {
	std::cout << "operator>= called" << std::endl;
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const {
	std::cout << "operator<= called" << std::endl;
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const {
	std::cout << "operator== called" << std::endl;
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const {
	std::cout << "operator!= called" << std::endl;
	return (this->_fixedPointValue != other._fixedPointValue);
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other._fixedPointValue == 0) {
		std::cerr << "Division by zero error" << std::endl;
		exit(EXIT_FAILURE);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement Operators

// Pre-increment (++a)
Fixed& Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

// Post-increment (a++)
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

// Pre-decrement (--a)
Fixed& Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

// Post-decrement (a--)
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

// --- Static Public Functions ---

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	std::cout << "min (non-const) called" << std::endl;
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	std::cout << "min (const) called" << std::endl;
	return (a._fixedPointValue < b._fixedPointValue) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	std::cout << "max (non-const) called" << std::endl;
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	std::cout << "max (const) called" << std::endl;
	return (a._fixedPointValue > b._fixedPointValue) ? a : b;
}

// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
