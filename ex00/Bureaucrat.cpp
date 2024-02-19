/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:59:55 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/19 09:35:07 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("sample"), grade(150) {
	// std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	// std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	try {
		if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &c) : name(c.getName()), grade(c.getGrade()) {
	// std::cout << "Bureaucrat copy constructor called" << std::endl;
	try {
		if (c.getGrade() < 1)
			throw GradeTooHighException();
		if (c.getGrade() > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &c) {
	// std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &c) {
		this->grade = c.getGrade();
	}
	try {
		if (c.getGrade() < 1)
			throw GradeTooHighException();
		if (c.getGrade() > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
	return (this->name);
}

int	Bureaucrat::getGrade() const {
	return (this->grade);
}

void	Bureaucrat::increaseGrade() {
	try {
		if (this->grade - 1 <= 0)
			throw GradeTooHighException();
		this->grade--;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decreaseGrade() {
	try {
		if (this->grade + 1 >= 151)
			throw GradeTooLowException();
		this->grade++;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator << (std::ostream &obj, const Bureaucrat &c) {
	obj << c.getName() << ", bureaucrat grade " << c.getGrade() << "." << std::endl;
	return (obj);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() : what_msg("Grade is too high") {
	// std::cout << "GTHE constructor called" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
	// std::cout << "GTHE destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return (what_msg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() : what_msg("Grade is too low") {
	// std::cout << "GTLE constructor called" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	// std::cout << "GTLE destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return (what_msg.c_str());
}
