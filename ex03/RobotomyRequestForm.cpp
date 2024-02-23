/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:14:03 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/23 01:50:09 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Sample", 72, 45) {
	std::cout << "Robotomy Form created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {
	std::cout << "Robotomy Form (" << name << ") created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &s) : AForm(s) { 
	std::cout << "Robotomy Form copy constructed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm &s) {
	if (this != &s) {
		this->setSign(s.getSigned());
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Form (" << this->getName() << ") destructed" << std::endl;
}

void RobotomyRequestForm::doAction() const {
	std::cout << "*drilling noises*" << std::endl
		<< "*drilling noises*" << std::endl
		<< "*drilling noises*" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->getName() << " has been robotomized succesfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}