/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:36:16 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/08 20:37:35 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
	std::cout << "correct animal sounds" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\nwrong animal sounds" << std::endl;
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	std::cout << wc->getType() << " " << std::endl;
	wa->makeSound();
	wc->makeSound();
		
	delete wa;
	delete wc;

	return 0;
}
