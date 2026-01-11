/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:48:49 by mlabrirh          #+#    #+#             */
/*   Updated: 2026/01/10 01:49:11 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>
class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(std::string ideas[]);
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();
};
#endif
