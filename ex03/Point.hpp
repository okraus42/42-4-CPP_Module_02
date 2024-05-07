/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/07 18:25:39 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		//	Canonical
		Point(void);
		Point(const Point& p);
		Point	&operator = (const Point& p);
		~Point(void);

		//	extra construcotrs
		Point(const float f1, const float f2);

		//	getter
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

		//	setter

		//	other methods

	// Other member functions
};

//	other functions
bool	bsp(const Point a, const Point b, const Point c, const Point point);

//	ostream functions
std::ostream	&operator << (std::ostream &o, Point const &p);
#endif