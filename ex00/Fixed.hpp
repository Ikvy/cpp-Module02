/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:01:03 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/21 12:32:02 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP



class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &f);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		void operator=(Fixed &f);

	private:
		const static int bits_nbr = 8;
		int	rawBits;
};

#endif
