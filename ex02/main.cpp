/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:54:08 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/24 06:57:35 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 

#include "Fixed.hpp"

void	subject_test()
{
	Fixed a;
	Fixed b;
	Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "--b ; "<< --b << std::endl;
	std::cout << "a : "<< a << std::endl;
	std::cout << "b : "<< b << std::endl;
	std::cout << "a++ : "<< a++ << std::endl;
	std::cout << "b-- : "<< b-- << std::endl;
	std::cout << "a : " <<a << std::endl;
	std::cout << "b : " << b << std::endl;
	
	std::cout << "c = 5.05 * 2 : " << c << std::endl;
	
	std::cout <<"max a,c : " << Fixed::max( a, c ) << std::endl;
	std::cout <<"min a,c : " << Fixed::min( a, c ) << std::endl;
}

void	my_test()
{
	Fixed a(1);
	Fixed b(2);
	Fixed c(3);
	Fixed d(4);

	std::cout << "1 > 2 : " << (a > b) << std::endl;
	std::cout << "1 < 2 : " << (a < b) << std::endl;
	std::cout << "1 <= 1 : " << (a <= a) << std::endl;
	std::cout << "1 >= 3 : " << (a >= c) << std::endl;
	std::cout << "3 + 2 : " << (c + b) << std::endl;
	std::cout << "2 - 3 : " << (b - c) << std::endl; 
	std::cout << "3 * 2 : " << (c * b) << std::endl; 
	std::cout << "3 / 2 : " << (c / b) << std::endl;

}


int main( void ) {

	subject_test();
	std::cout << "\n\n\n\n";
	my_test();
	return 0;
}
