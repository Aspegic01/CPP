/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:50:41 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/05 22:35:05 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    // std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
    // std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
} 

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat() const{
	return (float)this->_fixedPointValue / 256;
}

int Fixed::toInt(void) const {
	return roundf(this->_fixedPointValue / 256);
}

bool Fixed::operator==(const Fixed& rFixed) const {
    return this->_fixedPointValue == rFixed._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& rFixed) const {
    return this->_fixedPointValue != rFixed._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& rFixed) const {
    return this->_fixedPointValue <= rFixed._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& rFixed) const {
    return this->_fixedPointValue >= rFixed._fixedPointValue;
}

bool Fixed::operator>(const Fixed& rFixed) const {
    return this->_fixedPointValue > rFixed._fixedPointValue;
}

bool Fixed::operator<(const Fixed& rFixed) const {
    return this->_fixedPointValue < rFixed._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& rFixed) const {
    return Fixed(this->toFloat() + rFixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& rFixed) const {
    return Fixed(this->toFloat() - rFixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& rFixed) const {
    return Fixed(this->toFloat() * rFixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& rFixed) const {
    return Fixed(this->toFloat() / rFixed.toFloat());
}

Fixed& Fixed::operator++() {
    this->_fixedPointValue++;
    return *this;
}

Fixed& Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& p1, Fixed&p2){
	if (p1 > p2)
		return p2;
	else
		return p1;
}
Fixed& Fixed::max(Fixed& p1, Fixed&p2){
	if (p1 > p2)
		return p1;
	else
		return p2;
}
Fixed& Fixed::min(const Fixed& p1, const Fixed&p2){
	if (p1 > p2)
		return (Fixed&)p2;
	else
		return (Fixed&)p1;
}
Fixed& Fixed::max(const Fixed& p1, const Fixed&p2){
	if (p1 > p2)
		return (Fixed&)p1;
	else
		return (Fixed&)p2;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}