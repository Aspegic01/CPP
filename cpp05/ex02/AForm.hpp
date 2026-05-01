/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:15:18 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/03/28 16:52:41 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &other);
        ~AForm();
        AForm &operator=(const AForm &other);
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &out, const AForm &form);
#endif
