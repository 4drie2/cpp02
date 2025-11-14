/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:33:07 by abidaux           #+#    #+#             */
/*   Updated: 2025/10/27 18:32:13 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPoint.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>

const int FRACTION_BITS = 16;
const int SCALE_FACTOR = 1 << FRACTION_BITS;

fixed_t float_to_fixed(double value) {
	if (value >= 0)
		return (fixed_t)(value * SCALE_FACTOR + 0.5);
	else
		return (fixed_t)(value * SCALE_FACTOR - 0.5);
}

double fixed_to_float(fixed_t value) {
	return (double)value / SCALE_FACTOR;
}

FixedPoint::FixedPoint() : raw_value(0) {
}

FixedPoint::FixedPoint(double value){
	raw_value = float_to_fixed(value);
}

double FixedPoint::to_float() const {
	return fixed_to_float(raw_value);
}

FixedPoint FixedPoint::operator+(const FixedPoint& other) const {
	FixedPoint result;
	result.raw_value = this->raw_value + other.raw_value;
	return result;
}

FixedPoint FixedPoint::operator-(const FixedPoint& other) const {
	FixedPoint result;
	result.raw_value = this->raw_value - other.raw_value;
	return result;
}

FixedPoint FixedPoint::operator*(const FixedPoint& other) const {
	FixedPoint result;
	result.raw_value = (fixed_t)( ((int64_t)this->raw_value * (int64_t)other.raw_value) >> FRACTION_BITS );
	return result;
}

FixedPoint FixedPoint::operator/(const FixedPoint& other) const {
	// * Protection against division by zero
	if (other.raw_value == 0) {
		std::cerr << "Error: Division by zero detected!" << std::endl;
		std::abort();
	}
	FixedPoint result;
	result.raw_value = (fixed_t)( ((int64_t)this->raw_value << FRACTION_BITS) / other.raw_value );
	return result;
}
