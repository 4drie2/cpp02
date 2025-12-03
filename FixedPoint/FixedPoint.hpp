/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:33:07 by abidaux           #+#    #+#             */
/*   Updated: 2025/12/03 03:09:13 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

extern const int FRACTION_BITS;
extern const int SCALE_FACTOR;
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
struct Fixed{
	// Raw value stored as fixed-point
	fixed_t raw_value;

	/**
	 * Default constructor: Creates a Fixed initialized to 0
	 */
	Fixed();

	/**
	 * Constructor: Creates a Fixed from a double
	 * @param value: Value to convert
	 */
	Fixed(double value);

	double getRawBits() const ;

	/**
	 * Converts the Fixed to double
	 * @return: Floating-point value
	 */
	double to_float() const;

	/**
	 * Addition of two Fixed numbers
	 * @param other: Value to add
	 * @return: Result of the addition
	 */
	Fixed operator+(const Fixed& other) const;

	/**
	 * Subtraction of two Fixed numbers
	 * @param other: Value to subtract
	 * @return: Result of the subtraction
	 */
	Fixed operator-(const Fixed& other) const;

	/**
	 * Multiplication of two Fixed numbers
	 * @param other: Value to multiply
	 * @return: Result of the multiplication
	 */
	Fixed operator*(const Fixed& other) const;

	/**
	 * Division of two Fixed numbers
	 * @param other: Divisor
	 * @return: Result of the division
	 */
	Fixed operator/(const Fixed& other) const;
};
