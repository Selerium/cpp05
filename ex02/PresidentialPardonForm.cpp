/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:33:32 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/22 21:12:43 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Sample", 25, 5) {
	std::cout << "Presidential Form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {
	std::cout << "Presidential Form (" << name << ") created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &s) : AForm(s) { 
	std::cout << "Presidential Form copy constructed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm &s) {
	if (this != &s) {
		this->setSign(s.getSigned());
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Form (" << this->getName() << ") destructed" << std::endl;
}

void PresidentialPardonForm::doAction() const {
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
