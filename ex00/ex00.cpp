/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:57:44 by abidaux           #+#    #+#             */
/*   Updated: 2025/12/02 17:43:05 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../FixedPoint/FixedPoint.hpp"
int main( void ) {
	Fixed a = 5.2;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "a as float: " << a.to_float() << std::endl;
	std::cout << "b as float: " << b.to_float() << std::endl;
	std::cout << "c as float: " << c.to_float() << std::endl;
	return 0;
}
