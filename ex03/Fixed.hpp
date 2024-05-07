/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/07 16:28:45 by okraus           ###   ########.fr       */
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
		static const int	fBits = fractionalBits;
		Fixed(void);
		Fixed(const Fixed& fix);
		Fixed	&operator = (const Fixed& f);
		~Fixed(void);

		//	extra construcotrs
		Fixed(const int fixint);
		Fixed(const float fixfloat);

		//	extra overloads (not yet)

		// Comparison Operators
		bool	operator > (const Fixed &fix)const;
		bool	operator < (const Fixed &fix)const;
		bool	operator >= (const Fixed &fix)const;
		bool	operator <= (const Fixed &fix)const;
		bool	operator == (const Fixed &fix)const;
		bool	operator != (const Fixed &fix)const;

		// Arithmetic .Operators
		Fixed	operator + (const Fixed& fix)const;
		Fixed	operator + (const int& fint)const;
		Fixed	operator + (const float& ffloat)const;
		Fixed	operator - (const Fixed& fix)const;
		Fixed	operator - (const int& fint)const;
		Fixed	operator - (const float& ffloat)const;
		Fixed	operator * (const Fixed& fix)const;
		Fixed	operator * (const int& fint)const;
		Fixed	operator * (const float& ffloat)const;
		Fixed	operator / (const Fixed& fix)const;
		Fixed	operator / (const int& fint)const;
		Fixed	operator / (const float& ffloat)const;

		// pre-increment Operators
		Fixed	operator ++ ();
		Fixed	operator -- ();
		// post-increment Operators
		Fixed	operator ++ (int);
		Fixed	operator -- (int);

		//	getter
		int			getRawBits(void) const;
		
		//	setter
		void		setRawBits(int const raw);

		//	other methods
		float				toFloat(void) const;
		int					toInt(void) const;
		std::string			toString(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
	// Other member functions
};

//	ostream overload
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

// other overloads
Fixed	operator + (int fint, const Fixed& fix);
Fixed	operator + (float ffloat, const Fixed& fix);
Fixed	operator - (int fint, const Fixed& fix);
Fixed	operator - (float ffloat, const Fixed& fix);
Fixed	operator * (int fint, const Fixed& fix);
Fixed	operator * (float ffloat, const Fixed& fix);
Fixed	operator / (int fint, const Fixed& fix);
Fixed	operator / (float ffloat, const Fixed& fix);
#endif