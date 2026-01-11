/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:32:33 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/08 20:33:03 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include <iostream>
class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();
    void makeSound() const;
};
#endif
