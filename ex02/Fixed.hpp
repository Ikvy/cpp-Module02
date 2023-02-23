/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:01:03 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/23 13:24:42 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> 

class Fixed
{
	public:
		Fixed();
		Fixed(const float n);
		Fixed(const int n);
		Fixed(Fixed const &f);
		~Fixed();

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits() const;
		void setRawBits(int const raw);
		void operator=(Fixed const &f);
		
		static Fixed min(Fixed &nbr, Fixed &nbr2);
		static Fixed min(const Fixed &nbr, const Fixed &nbr2);
		static Fixed max(Fixed& nbr, Fixed& nbr2);
		static Fixed max(const Fixed& nbr, const Fixed& nbr2);

		int operator>(const Fixed& nbr);
		int operator<(const Fixed& nbr);
		int operator<=(const Fixed& nbr);
		int operator>=(const Fixed& nbr);
		int operator==(const Fixed& nbr);
		int operator!=(const Fixed& nbr);

		Fixed operator+(const Fixed& nbr);
		Fixed operator-(const Fixed& nbr);
		Fixed operator*(const Fixed& nbr);
		Fixed operator/(const Fixed& nbr);

		Fixed operator++(int a);
		Fixed& operator++();
		Fixed operator--(int a);
		Fixed& operator--();

	private:
		const static int bits_nbr = 8;
		int	rawBits;
};

std::ostream& operator<<(std::ostream& ostream, Fixed const &f);

#endif
