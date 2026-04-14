/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:49:07 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/03/07 20:10:59 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat {
private: 
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat& operator=(const Bureaucrat &other);
	~Bureaucrat();

	int getGrade() const;
	const std::string getName() const;

	void	incrementGrade();
	void	decrementGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
		const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
