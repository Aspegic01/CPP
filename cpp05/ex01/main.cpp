/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:11:12 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/03/07 20:19:36 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "----- Valid case -----" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 10);
        Form taxForm("Tax Form", 20, 10);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        taxForm.beSigned(bob);
        std::cout << "After sign: " << taxForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- Bureaucrat exception case -----" << std::endl;
    {
        try
        {
            Bureaucrat top("Top", 1);
            std::cout << top << std::endl;
            top.incrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n----- Form exception case -----" << std::endl;
    {
        try
        {
            Bureaucrat intern("Intern", 150);
            Form secret("Secret", 50, 50);
            std::cout << intern << std::endl;
            std::cout << secret << std::endl;
            secret.beSigned(intern);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    return 0;
}
