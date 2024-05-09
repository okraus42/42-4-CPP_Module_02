/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 11:02:55 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called \t\t" << this << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called \t\t" << this << std::endl;
	*this = fix;
}

Fixed&	Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy assignment operator called \t" << this << std::endl;
	// if (this != &fix)
	// 	this->fixedPointValue = fix.getRawBits();
	this->fixedPointValue = fix.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called \t\t\t" << this << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called \t" << this << std::endl;
	return this->fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called \t" << this << std::endl;
	this->fixedPointValue = raw;
}
