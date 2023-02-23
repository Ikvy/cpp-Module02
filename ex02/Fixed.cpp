/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:04:33 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/23 13:24:56 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream> 
#include <cmath> 

#include "Fixed.hpp"


Fixed::Fixed()
{
//	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}


Fixed::Fixed(Fixed const &f)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int n)
{
//	std::cout << "Int constructor called" << std::endl; 
	this->rawBits = n << this->bits_nbr;
}

Fixed::Fixed(const float f)
{
	int	raw_bits;

//	std::cout << "Float constructor called" << std::endl; 
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



Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

///////////min/max

Fixed Fixed::min(Fixed& nbr, Fixed& nbr2)
{
	return (nbr.toInt() < nbr2.toInt()) ? (nbr) : (nbr2);
}

Fixed Fixed::min(const Fixed& nbr, const Fixed& nbr2)
{
	return (nbr.toInt() < nbr2.toInt()) ? (nbr) : (nbr2);
}

Fixed Fixed::max(Fixed& nbr, Fixed& nbr2)
{
	return (nbr.toInt() > nbr2.toInt()) ? (nbr) : (nbr2);
}

Fixed Fixed::max(const Fixed& nbr, const Fixed& nbr2)
{
	return (nbr.toInt() > nbr2.toInt()) ? (nbr) : (nbr2);
}

///operators

std::ostream& operator<<(std::ostream& ostream, Fixed const& f)
{
	ostream << f.toFloat();
	return (ostream) ;
}

void	Fixed::operator=(Fixed const &f)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = f.getRawBits();
}

////new ones

int Fixed::operator>(const Fixed& nbr)
{
	return (this->rawBits > nbr.getRawBits()) ? 1 : 0;
}

int Fixed::operator>=(const Fixed& nbr)
{
	return (this->rawBits >= nbr.getRawBits()) ? 1 : 0;
}

int Fixed::operator<(const Fixed& nbr)
{
	return (this->rawBits < nbr.getRawBits()) ? 1 : 0;
}

int Fixed::operator<=(const Fixed& nbr)
{
	return (this->rawBits <= nbr.getRawBits()) ? 1 : 0;
}

int Fixed::operator==(const Fixed& nbr)
{
	return (this->rawBits == nbr.getRawBits()) ? 1 : 0;
}

int Fixed::operator!=(const Fixed& nbr)
{
	return (this->rawBits != nbr.getRawBits()) ? 1 : 0;
}
///////arithmetic


Fixed Fixed::operator+(const Fixed& nbr)
{
	Fixed res;

	res.setRawBits((this->toFloat() + nbr.toFloat()) * (1 << this->bits_nbr));
	return (res);
}

Fixed Fixed::operator-(const Fixed& nbr)
{
	Fixed res;

	res.setRawBits((this->toFloat() - nbr.toFloat()) * (1 << this->bits_nbr));
	return (res);
}

Fixed Fixed::operator*(const Fixed& nbr)
{
	Fixed res;
	
	res.setRawBits((this->toFloat() * nbr.toFloat()) * (1 << this->bits_nbr));
	return (res);
}

Fixed Fixed::operator/(const Fixed& nbr)
{
	Fixed res;
	
	res.setRawBits((this->toFloat() / nbr.toFloat()) * (1 << this->bits_nbr));
	return (res);
}

/////////

Fixed Fixed::operator++(int)
{
	Fixed old(*this);

	this->rawBits++;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);

	this->rawBits--;
	return (old);
}

Fixed& Fixed::operator++()
{
	this->rawBits++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->rawBits--;
	return (*this);
}
