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

// --- Constructors & Destructor ---

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int value) {
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value){
	if (value >= 0)
		this->_value = (int)(value * (1 << _fractionalBits) + 0.5f);
	else
		this->_value = (int)(value * (1 << _fractionalBits) - 0.5f);
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {
}

// --- Assignment Operator ---

Fixed& Fixed::operator=(const Fixed& other) {
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
	return _value;
}

/**
 * Sets the raw fixed-point value
 * @param value: Raw fixed-point value
 */
void Fixed::setRawBits(int value) {
	_value = value;
}

// --- Converters ---

/**
 * Converts the Fixed to float
 * @return: Floating-point value
 */
float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionalBits);
}

/**
 * Converts the Fixed to int
 * @return: Integer value
 */
int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

// --- Operators Overloads ---

// Comparison Operators
bool Fixed::operator>(const Fixed& other) const {
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->_value != other._value);
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
	if (other._value == 0) {
		std::cerr << "Division by zero error" << std::endl;
		exit(EXIT_FAILURE);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement Operators

// Pre-increment (++a)
Fixed& Fixed::operator++() {
	this->_value++;
	return *this;
}

// Post-increment (a++)
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_value++;
	return temp;
}

// Pre-decrement (--a)
Fixed& Fixed::operator--() {
	this->_value--;
	return *this;
}

// Post-decrement (a--)
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value--;
	return temp;
}

// --- Static Public Functions ---

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a._value < b._value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a._value > b._value) ? a : b;
}

// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
