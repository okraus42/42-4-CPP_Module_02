/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 11:14:57 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fix)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed	&Fixed::operator = (const Fixed &fix)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = fix.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int fixint)
{
	//std::cout << "Copy int constructor called" << std::endl;
	if (fixint > 0xFFFFFF || fixint < -(0x1000000))
	{
		std::cerr << "Error: Value <" << fixint
			<< "> does not fit in Fixed range, initialised as 0 instead"
			<< std::endl;
		this->fixedPointValue = 0;
	}
	else
		this->fixedPointValue = fixint << this->fractionalBits;
}

Fixed::Fixed(const float fixfloat)
{
	int	temp;

	//std::cout << "Copy float constructor called" << std::endl;
	if (fixfloat * (1 << this->fractionalBits) >= 2147483648.f || fixfloat * (1 << this->fractionalBits) < -2147483648.f)
	{
		std::cerr << "Error: Value <" << fixfloat
			<< "> does not fit in Fixed range, initialised as 0 instead"
			<< std::endl;
		this->fixedPointValue = 0;
	}
	else
	{
		if (fixfloat > 0)
			temp = fixfloat * (1 << this->fractionalBits) + 0.5;
		else if (fixfloat < 0)
			temp = fixfloat * (1 << this->fractionalBits) - 0.5;
		else
			temp = 0;
		this->fixedPointValue = temp;
	}
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointValue) / static_cast<float>(1 << this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	if (this->fixedPointValue < 0 && this->fixedPointValue != ((this->fixedPointValue >> this->fractionalBits) << this->fractionalBits))
		return ((this->fixedPointValue >> this->fractionalBits) + 1);
	return (this->fixedPointValue >> this->fractionalBits);
}

std::string	Fixed::toString(void) const
{
	std::string	whole;
	std::string	fraction;
	int			front;
	int			back;
	int			mask;
	int			tens;
	int			fives;

	//get front
	if (this->fixedPointValue < 0 && this->fixedPointValue != ((this->fixedPointValue >> this->fractionalBits) << this->fractionalBits))
		front = (this->fixedPointValue >> this->fractionalBits) + 1;
	else
		front = this->fixedPointValue >> this->fractionalBits;
	if (front < 0)
		front *= -1;
	if (!front)
		whole = "0";
	while (front)
	{
		whole = (static_cast<char>('0' + ((front) % 10))) + whole;
		front /= 10;
	}
	if (this->fixedPointValue < 0)
		whole = "-" + whole;
	//get back
	fives = 1;
	mask = 0;
	tens = 1;
	for (int i = 0; i < this->fractionalBits; ++i)
	{
		fives *= 5;
		tens *= 10;
		mask = mask << 1 | 1;
	}
	back = fives * (this->fixedPointValue & mask);
	tens /= 10;
	if (!back || this->fixedPointValue >= 0)
	{
		for (int j = 0; j < this->fractionalBits; ++j)
		{
			fraction = fraction + (static_cast<char>('0' + ((back / tens) % 10)));
			tens /= 10;
		}
	}
	else
	{
		back = (1 << this->fractionalBits) * fives - back;
		for (int j = 0; j < this->fractionalBits; ++j)
		{
			fraction = fraction + (static_cast<char>('0' + ((back / tens) % 10)));
			tens /= 10;
		}
	}
	return (whole + "." + fraction + "FP");
}

//	ostream
std::ostream	&operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return (o);
}

//Operators
		// bool	operator > (Fixed fix)const;
		// bool	operator < (Fixed fix)const;
		// bool	operator >= (Fixed fix)const;
		// bool	operator <= (Fixed fix)const;
		// bool	operator == (Fixed fix)const;
		// bool	operator != (Fixed fix)const;
bool	Fixed::operator > (const Fixed &fix)const
{
	return (this->getRawBits() > fix.getRawBits());
}

bool	Fixed::operator < (const Fixed &fix)const
{
	return (this->getRawBits() < fix.getRawBits());
}

bool	Fixed::operator >= (const Fixed &fix)const
{
	return (this->getRawBits() >= fix.getRawBits());
}

bool	Fixed::operator <= (const Fixed &fix)const
{
	return (this->getRawBits() <= fix.getRawBits());
}

bool	Fixed::operator == (const Fixed &fix)const
{
	return (this->getRawBits() == fix.getRawBits());
}

bool	Fixed::operator != (const Fixed &fix)const
{
	return (this->getRawBits() != fix.getRawBits());
}

Fixed	Fixed::operator + (const Fixed &fix)const
{
	Fixed	result;

	//std::cout << "Operator + called" << std::endl;
	result.setRawBits(this->fixedPointValue + fix.getRawBits());
	return (result);
}

Fixed	Fixed::operator + (const int &fint)const
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator + with int called" << std::endl;
	result.setRawBits(this->fixedPointValue + fixint.getRawBits());
	return (result);
}

Fixed	Fixed::operator + (const float &ffloat)const
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator + with float called" << std::endl;
	result.setRawBits(this->fixedPointValue + fixfloat.getRawBits());
	return (result);
}

Fixed	operator + (int fint, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator + with int called" << std::endl;
	result.setRawBits(fix.getRawBits() + fixint.getRawBits());
	return (result);
}

Fixed	operator + (float ffloat, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator + with float called" << std::endl;
	result.setRawBits(fix.getRawBits() + fixfloat.getRawBits());
	return (result);
}

Fixed	Fixed::operator - (const Fixed &fix)const
{
	Fixed	result;

	//std::cout << "Operator - called" << std::endl;
	result.setRawBits(this->fixedPointValue - fix.getRawBits());
	return (result);
}

Fixed	Fixed::operator - (const int &fint)const
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator - with int called" << std::endl;
	result.setRawBits(this->fixedPointValue - fixint.getRawBits());
	return (result);
}

Fixed	Fixed::operator - (const float &ffloat)const
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator - with float called" << std::endl;
	result.setRawBits(this->fixedPointValue - fixfloat.getRawBits());
	return (result);
}

Fixed	operator - (int fint, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator - with int called" << std::endl;
	result.setRawBits(fix.getRawBits() - fixint.getRawBits());
	return (result);
}

Fixed	operator - (float ffloat, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator - with float called" << std::endl;
	result.setRawBits(fix.getRawBits() - fixfloat.getRawBits());
	return (result);
}

Fixed	Fixed::operator * (const Fixed &fix)const
{
	Fixed	result;

	//std::cout << "Operator * called" << std::endl;
	result.setRawBits((static_cast<long long>(this->fixedPointValue) * fix.getRawBits()) >> this->fractionalBits);
	return (result);
}

Fixed	Fixed::operator * (const int &fint)const
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator * with int called" << std::endl;
	result.setRawBits((static_cast<long long>(this->fixedPointValue) * fixint.getRawBits()) >> this->fractionalBits);
	return (result);
}

Fixed	Fixed::operator * (const float &ffloat)const
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator * with float called" << std::endl;
	result.setRawBits((static_cast<long long>(this->fixedPointValue) * fixfloat.getRawBits()) >> this->fractionalBits);
	return (result);
}

Fixed	operator * (int fint, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator * with int called" << std::endl;
	result.setRawBits((static_cast<long long>(fix.getRawBits()) * fixint.getRawBits()) >> fix.fBits);
	return (result);
}

Fixed	operator * (float ffloat, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator * with float called" << std::endl;
	result.setRawBits((static_cast<long long>(fix.getRawBits()) * fixfloat.getRawBits()) >> fix.fBits);
	return (result);
}

Fixed	Fixed::operator / (const Fixed &fix)const
{
	Fixed	result;

	//std::cout << "Operator / called" << std::endl;
	result.setRawBits(((static_cast<long long>(this->fixedPointValue)) << this->fractionalBits) / fix.getRawBits());
	return (result);
}

Fixed	Fixed::operator / (const int &fint)const
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator / with int called" << std::endl;
	result.setRawBits(((static_cast<long long>(this->fixedPointValue)) << this->fractionalBits) / fixint.getRawBits());
	return (result);
}

Fixed	Fixed::operator / (const float &ffloat)const
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator / with float called" << std::endl;
	result.setRawBits(((static_cast<long long>(this->fixedPointValue)) << this->fractionalBits) / fixfloat.getRawBits());
	return (result);
}

Fixed	operator / (int fint, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixint(fint);

	//std::cout << "Operator / with int called" << std::endl;
	result.setRawBits(((static_cast<long long>(fix.getRawBits())) << fix.fBits) / fixint.getRawBits());
	return (result);
}

Fixed	operator / (float ffloat, const Fixed &fix)
{
	Fixed	result;
	Fixed	fixfloat(ffloat);

	//std::cout << "Operator * with float called" << std::endl;
	result.setRawBits(((static_cast<long long>(fix.getRawBits())) << fix.fBits) / fixfloat.getRawBits());
	return (result);
}

Fixed	Fixed::operator ++ (void)
{
	++(this->fixedPointValue);
	return (*this);
}

Fixed	Fixed::operator -- (void)
{
	--(this->fixedPointValue);
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed result;

	result = *this;
	++(this->fixedPointValue);
	return (result);
}

Fixed	Fixed::operator -- (int)
{
	Fixed result;

	result = *this;
	--(this->fixedPointValue);
	return (result);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
