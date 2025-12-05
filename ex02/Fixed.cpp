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
}

Fixed::Fixed(const int value) {
	_fixedPointValue = value << _numberOfFractionalBits;
}

Fixed::Fixed(const float value){
	if (value >= 0)
		this->_fixedPointValue = (int)(value * (1 << _numberOfFractionalBits) + 0.5f);
	else
		this->_fixedPointValue = (int)(value * (1 << _numberOfFractionalBits) - 0.5f);
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {
}

// --- Assignment Operator ---

Fixed& Fixed::operator=(const Fixed& other) {
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
	return _fixedPointValue;
}

/**
 * Sets the raw fixed-point value
 * @param value: Raw fixed-point value
 */
void Fixed::setRawBits(int value) {
	_fixedPointValue = value;
}

// --- Converters ---

/**
 * Converts the Fixed to float
 * @return: Floating-point value
 */
float Fixed::toFloat() const {
	return (float)_fixedPointValue / (1 << _numberOfFractionalBits);
}

/**
 * Converts the Fixed to int
 * @return: Integer value
 */
int Fixed::toInt() const {
	return _fixedPointValue >> _numberOfFractionalBits;
}

// --- Operators Overloads ---

// Comparison Operators
bool Fixed::operator>(const Fixed& other) const {
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const {
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
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a._fixedPointValue < b._fixedPointValue) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a._fixedPointValue > b._fixedPointValue) ? a : b;
}

// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
