/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:15:04 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/23 14:55:45 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(Intern &i) {
	(void) i;
	std::cout << "Intern created" << std::endl;
}

Intern &Intern::operator = (const Intern &i) {
	(void) i;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

AForm *Intern::ShruberryFactory(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::RobotomyFactory(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::PardonFactory(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	std::string funcNames[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	form functions[3] = { &Intern::ShruberryFactory, &Intern::RobotomyFactory, &Intern::PardonFactory };

	for (int i = 0; i < 3; i++) {
		if (formName.compare(funcNames[i]) == 0) {
			std::cout << "Intern created " << formName << std::endl;
			return ((this->*functions[i])(formTarget));
		}
	}
	std::cout << "Error: Form type doesn't exist" << std::endl;
	return 0;
}