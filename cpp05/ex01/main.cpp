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
    try
    {
        Bureaucrat b1("Alice", 50);
        Form f1("Form A", 30, 20);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        b1.incrementGrade();
        std::cout << "After incrementing grade: " << b1 << std::endl;
        f1.beSigned(b1);
        std::cout << "After signing: " << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
