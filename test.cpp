/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:55:38 by abidaux           #+#    #+#             */
/*   Updated: 2025/10/25 19:06:50 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "FixedPoint.hpp"

void print_test(const char* name, bool passed) {
	std::cout << "[" << (passed ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m") << "] " << name << std::endl;
}

bool approx_equal(double a, double b, double epsilon = 0.001) {
	return std::abs(a - b) < epsilon;
}

int main() {
	std::cout << "=== FixedPoint Tests ===" << std::endl << std::endl;

	// Test 1: Default constructor
	std::cout << "Test 1: Default Constructor" << std::endl;
	FixedPoint fp1;
	print_test("Default constructor (value should be 0)", approx_equal(fp1.to_float(), 0.0));
	std::cout << "  Value: " << fp1.to_float() << std::endl << std::endl;

	// Test 2: Constructor with positive value
	std::cout << "Test 2: Constructor with Positive Value" << std::endl;
	FixedPoint fp2(42.5);
	print_test("Constructor with 42.5", approx_equal(fp2.to_float(), 42.5));
	std::cout << "  Value: " << fp2.to_float() << std::endl << std::endl;

	// Test 3: Constructor with negative value
	std::cout << "Test 3: Constructor with Negative Value" << std::endl;
	FixedPoint fp3(-15.75);
	print_test("Constructor with -15.75", approx_equal(fp3.to_float(), -15.75));
	std::cout << "  Value: " << fp3.to_float() << std::endl << std::endl;

	// Test 4: Addition
	std::cout << "Test 4: Addition" << std::endl;
	FixedPoint a(10.5);
	FixedPoint b(5.25);
	FixedPoint sum = a + b;
	print_test("10.5 + 5.25 = 15.75", approx_equal(sum.to_float(), 15.75));
	std::cout << "  Result: " << sum.to_float() << std::endl << std::endl;

	// Test 5: Subtraction
	std::cout << "Test 5: Subtraction" << std::endl;
	FixedPoint c(20.0);
	FixedPoint d(7.5);
	FixedPoint diff = c - d;
	print_test("20.0 - 7.5 = 12.5", approx_equal(diff.to_float(), 12.5));
	std::cout << "  Result: " << diff.to_float() << std::endl << std::endl;

	// Test 6: Multiplication
	std::cout << "Test 6: Multiplication" << std::endl;
	FixedPoint e(4.0);
	FixedPoint f(2.5);
	FixedPoint prod = e * f;
	print_test("4.0 * 2.5 = 10.0", approx_equal(prod.to_float(), 10.0));
	std::cout << "  Result: " << prod.to_float() << std::endl << std::endl;

	// Test 7: Division
	std::cout << "Test 7: Division" << std::endl;
	FixedPoint g(15.0);
	FixedPoint h(3.0);
	FixedPoint quot = g / h;
	print_test("15.0 / 3.0 = 5.0", approx_equal(quot.to_float(), 5.0));
	std::cout << "  Result: " << quot.to_float() << std::endl << std::endl;

	// Test 8: Negative operations
	std::cout << "Test 8: Negative Numbers Operations" << std::endl;
	FixedPoint neg1(-10.0);
	FixedPoint neg2(5.0);
	FixedPoint neg_sum = neg1 + neg2;
	print_test("-10.0 + 5.0 = -5.0", approx_equal(neg_sum.to_float(), -5.0));
	std::cout << "  Result: " << neg_sum.to_float() << std::endl << std::endl;

	// Test 9: Small values
	std::cout << "Test 9: Small Values (precision test)" << std::endl;
	FixedPoint small1(0.125);
	FixedPoint small2(0.375);
	FixedPoint small_sum = small1 + small2;
	print_test("0.125 + 0.375 = 0.5", approx_equal(small_sum.to_float(), 0.5, 0.0001));
	std::cout << "  Result: " << small_sum.to_float() << std::endl << std::endl;

	// Test 10: Complex calculation
	std::cout << "Test 10: Complex Calculation" << std::endl;
	FixedPoint x(5.0);
	FixedPoint y(3.0);
	FixedPoint z(2.0);
	FixedPoint result = (x * y) + (z * FixedPoint(4.0));
	// (5 * 3) + (2 * 4) = 15 + 8 = 23
	print_test("(5.0 * 3.0) + (2.0 * 4.0) = 23.0", approx_equal(result.to_float(), 23.0));
	std::cout << "  Result: " << result.to_float() << std::endl << std::endl;

	// Test 11: Chained operations
	std::cout << "Test 11: Chained Operations" << std::endl;
	FixedPoint chain = FixedPoint(10.0) + FixedPoint(5.0) - FixedPoint(3.0);
	print_test("10.0 + 5.0 - 3.0 = 12.0", approx_equal(chain.to_float(), 12.0));
	std::cout << "  Result: " << chain.to_float() << std::endl << std::endl;

	// Test 12: Zero handling
	std::cout << "Test 12: Zero Handling" << std::endl;
	FixedPoint zero(0.0);
	FixedPoint num(10.0);
	FixedPoint zero_add = num + zero;
	FixedPoint zero_mult = num * zero;
	print_test("10.0 + 0.0 = 10.0", approx_equal(zero_add.to_float(), 10.0));
	print_test("10.0 * 0.0 = 0.0", approx_equal(zero_mult.to_float(), 0.0));
	std::cout << std::endl;

	std::cout << "=== All Basic Tests Completed ===" << std::endl << std::endl;

	// Test 13: Division by zero (should crash with error message)
	std::cout << "Test 13: Division by Zero (should display error and crash)" << std::endl;
	std::cout << "Uncomment the following lines to test:" << std::endl;
	std::cout << "  FixedPoint divByZero = FixedPoint(10.0) / FixedPoint(0.0);" << std::endl;
	// FixedPoint divByZero = FixedPoint(10.0) / FixedPoint(0.0);

	return 0;
}
