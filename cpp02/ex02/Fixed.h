/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:50:17 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/05 22:37:38 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
	int _fixedPointValue;
	static const int _fractionalBits;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	bool operator==(const Fixed& rFixed) const;
	bool operator!=(const Fixed& rFixed) const;
	bool operator<=(const Fixed& rFixed) const;
	bool operator>=(const Fixed& rFixed) const;
	bool operator>(const Fixed& rFixed) const;
	bool operator<(const Fixed& rFixed) const;
	Fixed operator+(const Fixed& rFixed) const;
	Fixed operator-(const Fixed& rFixed) const;
	Fixed operator*(const Fixed& rFixed) const;
	Fixed operator/(const Fixed& rFixed) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed& min(Fixed& p1, Fixed&p2);
	static Fixed& min(const Fixed& p1, const Fixed&p2);
	static Fixed& max(Fixed& p1, Fixed&p2);
	static Fixed& max(const Fixed& p1, const Fixed&p2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif