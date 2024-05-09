/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 11:20:21 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string>

Point::Point() : x(0), y(0)
{
	// std::cout << "Default constructor called \t\t" << this << std::endl;
}

Point::Point(const Point &p) : x(p.getX()), y(p.getY())
{
// 	std::cout << "Copy constructor called\t" << this << std::endl;
// 	*this = p;
}

Point	&Point::operator = (const Point &p)
{
	// std::cout << "Copy assignment operator called\t\t" << this << std::endl;
	// this->x = p.getX();
	// this->y = p.getY();
	std::cerr << "Cannot assign to constatnt values\t\t" << this << std::endl;
	(void)p;
	return (*this);
}

Point::~Point()
{
	// std::cout << "Destructor called\t\t\t" << this << std::endl;
}

Point::Point(const float f1, const float f2) : x(f1), y(f2)
{
	// std::cout << "Copy float constructor called\t\t" << this << std::endl;
	// Point x(f1);
	// Point y(f2);

	// this->x = x;
	// this->y = y;
}

const Fixed	&Point::getX(void) const
{
	return (this->x);
}

const Fixed	&Point::getY(void) const
{
	return (this->y);
}

std::ostream &operator<<(std::ostream &o, Point const &p)
{
	o << "[" << p.getX() << ", " << p.getY() << "]";
	return (o);
}