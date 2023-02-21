/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:13:23 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/21 12:59:52 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp" 

void	my_test()
{
	Fixed a;
	Fixed b(a);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	a.setRawBits(13);
	b = a;
	std::cout << b.getRawBits() << std::endl;
}

void	subject_test()
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

int main( void ) {

	subject_test();
	std::cout << "\n\n\n";
	my_test();
	return 0;
}
