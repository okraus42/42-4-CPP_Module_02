/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/07 18:31:13 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	const Point a(0.0, 5.0);
	const Point b(-5.0, 0.0);
	const Point c(5.0, 0.0);
	const Point point1(0.0, 0.0);
	const Point point2(0.0, 5.0);
	const Point point3(0.0, 1.0);
	const Point point4(-12.25, 42.25);
	std::cout << "point A " << a << std::endl;
	std::cout << "point B " << b << std::endl;
	std::cout << "point C " << c << std::endl;
	std::cout << std::endl;
	// bsp(a, b, c, point4);
	std::cout << "point point1 " << point1
		<< " " << bsp(a, b, c, point1) << std::endl;
	std::cout << "point point2 " << point2
		<< " " << bsp(a, b, c, point2) << std::endl;
	std::cout << "point point3 " << point3
		<< " " << bsp(a, b, c, point3) << std::endl;
	std::cout << "point point4 " << point4
		<< " " << bsp(a, b, c, point4) << std::endl;
	return (0);
}