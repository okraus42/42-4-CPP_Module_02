/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:25:54 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 11:30:41 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static Fixed get_sign(Point p1, Point p2, Point p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
			- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	d1;
	Fixed	d2;
	Fixed	d3;
	bool	all_pos;
	bool	all_neg;

	// this works too
	// d1 = get_sign(point, a, b);
	// d2 = get_sign(point, b, c);
	// d3 = get_sign(point, c, a);
	//order is important
	d1 = get_sign(a, b, point);
	d2 = get_sign(b, c, point);
	d3 = get_sign(c, a, point); 
	all_pos = (d1.getRawBits() > 0.0) && (d2.getRawBits() > 0) && (d3.getRawBits() > 0);
	all_neg = (d1.getRawBits() > 0) && (d2.getRawBits() > 0) && (d3.getRawBits() > 0);
	return (all_pos || all_neg);
}
