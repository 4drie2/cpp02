/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <adrien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:33:07 by abidaux           #+#    #+#             */
/*   Updated: 2025/11/14 10:02:00 by adrien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPoint.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>

const int FRACTION_BITS = 16;
const int SCALE_FACTOR = 1 << FRACTION_BITS;

Fixed::~Fixed() {
	std::cout << "Fixed destructor called" << std::endl;
}

fixed_t float_to_fixed(double value) {
	if (value >= 0)
		return (fixed_t)(value * SCALE_FACTOR + 0.5);
	else
		return (fixed_t)(value * SCALE_FACTOR - 0.5);
}

double fixed_to_float(fixed_t value) {
	return (double)value / SCALE_FACTOR;
}

Fixed::Fixed() : raw_value(0) {
}

Fixed::Fixed(double value){
	raw_value = float_to_fixed(value);
}

double Fixed::to_float() const {
	return fixed_to_float(raw_value);
}

double Fixed::getRawBits() const {
	return this->raw_value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.raw_value = this->raw_value + other.raw_value;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.raw_value = this->raw_value - other.raw_value;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.raw_value = (fixed_t)( ((int64_t)this->raw_value * (int64_t)other.raw_value) >> FRACTION_BITS );
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	// * Protection against division by zero
	if (other.raw_value == 0) {
		std::cerr << "Error: Division by zero detected!" << std::endl;
		std::abort();
	}
	Fixed result;
	result.raw_value = (fixed_t)( ((int64_t)this->raw_value << FRACTION_BITS) / other.raw_value );
	return result;
}
