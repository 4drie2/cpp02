/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:33:07 by abidaux           #+#    #+#             */
/*   Updated: 2025/10/25 19:06:47 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

// Number of bits used for the fractional part (16 bits)
extern const int FRACTION_BITS;

// Scale factor for conversion (2^16 = 65536)
extern const int SCALE_FACTOR;

// Type definition for fixed-point number (int32_t)
typedef int32_t fixed_t;

/**
 * Converts a floating-point number to fixed-point
 * @param value: Value to convert (double)
 * @return: Fixed-point value (fixed_t)
 */
fixed_t float_to_fixed(double value);

/**
 * Converts a fixed-point number to floating-point
 * @param value: Value to convert (fixed_t)
 * @return: Floating-point value (double)
 */
double fixed_to_float(fixed_t value);

/**
 * Structure representing a fixed-point number
 * Allows precise arithmetic operations
 */
struct FixedPoint{
	// Raw value stored as fixed-point
	fixed_t raw_value;

	/**
	 * Default constructor: Creates a FixedPoint initialized to 0
	 */
	FixedPoint();

	/**
	 * Constructor: Creates a FixedPoint from a double
	 * @param value: Value to convert
	 */
	FixedPoint(double value);

	/**
	 * Converts the FixedPoint to double
	 * @return: Floating-point value
	 */
	double to_float() const;

	/**
	 * Addition of two FixedPoint numbers
	 * @param other: Value to add
	 * @return: Result of the addition
	 */
	FixedPoint operator+(const FixedPoint& other) const;

	/**
	 * Subtraction of two FixedPoint numbers
	 * @param other: Value to subtract
	 * @return: Result of the subtraction
	 */
	FixedPoint operator-(const FixedPoint& other) const;

	/**
	 * Multiplication of two FixedPoint numbers
	 * @param other: Value to multiply
	 * @return: Result of the multiplication
	 */
	FixedPoint operator*(const FixedPoint& other) const;

	/**
	 * Division of two FixedPoint numbers
	 * @param other: Divisor
	 * @return: Result of the division
	 */
	FixedPoint operator/(const FixedPoint& other) const;
};
