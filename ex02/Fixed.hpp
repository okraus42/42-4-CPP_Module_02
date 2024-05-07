/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/07 13:58:41 by okraus           ###   ########.fr       */
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

		// Comparison Operators
		// bool	operator>(Fixed fix)const;
		// bool	operator<(Fixed fix)const;
		// bool	operator>=(Fixed fix)const;
		// bool	operator<=(Fixed fix)const;
		// bool	operator==(Fixed fix)const;
		// bool	operator!=(Fixed fix)const;

		// Arithmetic .Operators
		Fixed operator+(const Fixed& fix2)const;
		// Fixed	&operator-(Fixed fix2)const;
		// Fixed	&operator*(Fixed fix2)const;
		// Fixed	&operator/(Fixed fix2)const;

		// // pre-increment Operators
		// Fixed	operator++();
		// Fixed	operator--();
		// // post-increment Operators
		// Fixed	operator++(int);
		// Fixed	operator--(int);

		//	getter
		int			getRawBits(void) const;
		
		//	setter
		void		setRawBits(int const raw);

		//	other methods
		float				toFloat(void) const;
		int					toInt(void) const;
		std::string			toString(void) const;
		// static Fixed		&min(Fixed &first, Fixed &second);
		// static const Fixed	&min(Fixed const &first, Fixed const &second);
		// static Fixed		&max(Fixed &first, Fixed &second);
		// static const Fixed	&max(const Fixed &first, const Fixed &second);
};

//	ostream overload
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
#endif