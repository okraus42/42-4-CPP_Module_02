/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/07 09:35:39 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		//	Canonical
		Fixed(void);
		Fixed(const Fixed& fix);
		Fixed &operator=(const Fixed& f);
		~Fixed(void);

		//	extra construcotrs
		Fixed(const int fixint);
		Fixed(const float fixfloat);

		//	extra overloads (not yet)

		//	getter
		int			getRawBits(void) const;
		
		//	setter
		void		setRawBits(int const raw);

		//	other methods
		float		toFloat(void) const;
		int			toInt(void) const;
		std::string	toString(void) const;
};

//	ostream overload
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
#endif