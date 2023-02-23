/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:04:33 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/23 09:50:29 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream> 
#include <cmath> 

#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

void	Fixed::operator=(Fixed const &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = f.getRawBits();
}

Fixed::Fixed(Fixed const &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl; 
	this->rawBits = n << this->bits_nbr;
}

Fixed::Fixed(const float f)
{
	int	raw_bits;

	std::cout << "Float constructor called" << std::endl; 
	raw_bits = roundf(f * (1 << this->bits_nbr));
	this->rawBits = raw_bits;
}

float Fixed::toFloat() const
{
	float result = (float)this->rawBits / (1 << this->bits_nbr);
	return (result);
}

int	Fixed::toInt() const
{
	return (this->rawBits / (1 << this->bits_nbr));
}

int	Fixed::getRawBits() const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}


std::ostream& operator<<(std::ostream& ostream, Fixed const& f)
{
	ostream << f.toFloat();
	return (ostream);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
