/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:57:44 by abidaux           #+#    #+#             */
/*   Updated: 2025/12/05 04:54:33 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	std::cout << "subject main ----------" << std::endl;
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}

	std::cout << std::endl << "simple test ----------" << std::endl;
	{
		Fixed a = 5.2f;
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		std::cout << "a as float: " << a.toFloat() << std::endl;
		std::cout << "b as float: " << b.toFloat() << std::endl;
		std::cout << "c as float: " << c.toFloat() << std::endl;
	}
	return 0;
}
