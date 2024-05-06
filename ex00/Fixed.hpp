/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/06 17:47:28 by okraus           ###   ########.fr       */
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
		Fixed(void);
		Fixed(const Fixed& fix);
		Fixed &operator=(const Fixed& f);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif