/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral_rmunoz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:01:25 by alvmoral          #+#    #+#             */
/*   Updated: 2025/07/25 19:02:03 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    this->type = type;
}

AMateria::~AMateria(){
    std::cout << "El material se ha acabado, cambia de dealer" << std::endl;
}

AMateria::AMateria(AMateria &a){
    this->type = a.type;
}

AMateria &AMateria::operator=(AMateria &other){
    return(*this);
}
