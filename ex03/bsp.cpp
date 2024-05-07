/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:25:54 by okraus            #+#    #+#             */
/*   Updated: 2024/05/07 18:32:20 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string>


static Fixed get_sign(Point p1, Point p2, Point p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

// bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3)
// {
//     float d1, d2, d3;
//     bool has_neg, has_pos;

//     d1 = sign(pt, v1, v2);
//     d2 = sign(pt, v2, v3);
//     d3 = sign(pt, v3, v1);

//     has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
//     has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	d1;
	Fixed	d2;
	Fixed	d3;
	bool	all_pos;
	bool	all_neg;

	// std::cout << "point A " << a << std::endl;
	// std::cout << "point B " << b << std::endl;
	// std::cout << "point C " << c << std::endl;
	// std::cout << "point point " << point << std::endl;
	d1 = get_sign(point, a, b);
	d2 = get_sign(point, b, c);
	d3 = get_sign(point, c, a); //order is important
	// std::cout << "Point A " << a << std::endl;
	// std::cout << "d1: " << d1 << std::endl;
	// std::cout << "d2: " << d2 << std::endl;
	// std::cout << "d3: " << d3 << std::endl;
	all_pos = (d1.getRawBits() > 0.0) && (d2.getRawBits() > 0) && (d3.getRawBits() > 0);
	all_neg = (d1.getRawBits() > 0) && (d2.getRawBits() > 0) && (d3.getRawBits() > 0);
	return (all_pos || all_neg);
}
