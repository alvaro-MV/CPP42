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
    _equiped = false;
    std::cout << "AMateria constructor called." << std::endl;
    this->type = type;
}

AMateria::~AMateria(){
    std::cout << "El material se ha acabado, cambia de dealer" << std::endl;
}

AMateria::AMateria(const AMateria &a){
    _equiped = false;
    this->type = a.type;
}

AMateria &AMateria::operator=(const AMateria &other){
    this->type = other.type;
    return(*this);
}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter&){
    std::cout << "* uses " << this->type << " *" << std::endl;
}

bool AMateria::equip(char rw) {
    if (rw == 'w')
        _equiped = true;
    return _equiped;
}
bool AMateria::not_equip(char rw) {
    if (rw == 'w')
        _equiped = false;
    return _equiped;
}