/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:34:05 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/10 01:50:05 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "Brain.h"
#include <iostream>

class Dog : public Animal
{
private:
  Brain *brain;
public:
  Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog();
  void makeSound() const;
};
#endif
