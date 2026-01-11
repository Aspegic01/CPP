/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:32:33 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/10 01:49:57 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include "Brain.h"
#include <iostream>
class Cat : public Animal
{
private:
  Brain *brain;
public:
  Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  ~Cat();
  void makeSound() const;
};
#endif
