/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:33:07 by abidaux           #+#    #+#             */
/*   Updated: 2025/12/05 01:49:08 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>

extern const int FRACTION_BITS;
extern const int SCALE_FACTOR;
typedef int32_t fixed_t;

/**
 * Converts a floating-point number to fixed-point
 * @param value: Value to convert (float)
 * @return: Fixed-point value (fixed_t)
 */
fixed_t float_to_fixed(float value);

/**
 * Converts a fixed-point number to floating-point
 * @param value: Value to convert (fixed_t)
 * @return: Floating-point value (float)
 */
float fixed_to_float(fixed_t value);

/**
 * Structure representing a fixed-point number
 * Allows precise arithmetic operations
 */
struct Fixed
{
public:
	// --- Constructors & Destructor ---
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	~Fixed();

	// --- Assignment Operator ---
	Fixed &operator=(const Fixed &other);

	// --- Getters & Setters ---
	/**
	 * Retrieves the raw fixed-point value
	 * @return: Raw fixed-point value
	 */
	int getRawBits() const;
	/**
	 * Sets the raw fixed-point value
	 * @param value: Raw fixed-point value
	 */
	void setRawBits(int value);

	// --- Converters ---
	/**
	 * Converts the Fixed to float
	 * @return: Floating-point value
	 */
	float toFloat() const;
	/**
	 * Converts the Fixed to int
	 * @return: Integer value
	 */
	int toInt() const;

	// --- Operators Overloads ---

	// Comparison Operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Arithmetic Operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Increment / Decrement Operators
	Fixed &operator++();       // Prefix increment
	Fixed operator++(int);     // Postfix increment
	Fixed &operator--();       // Prefix decrement
	Fixed operator--(int);     // Postfix decrement

	// --- Static Public Functions ---
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int _value;
	static const int _fractionalBits = 8;
};

// Stream insertion overload
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
