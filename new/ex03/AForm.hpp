#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;

class AForm
{
private:
    const std::string	_name;
    bool				_isSigned;
    const int			_gradeToSign;
    const int			_gradeToExecute;

protected:
    virtual void executeAction() const = 0;

public:
    AForm();
    AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm &other);
    virtual ~AForm();
    AForm &operator=(const AForm &other);

    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
#pragma once

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    AForm();
    AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm &other);
    virtual ~AForm();
    AForm &operator=(const AForm &other);
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;
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
std::ostream& operator<<(std::ostream& out, const AForm& f);
#endif