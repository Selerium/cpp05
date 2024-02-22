/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:23:11 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/22 20:56:13 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Sample"), sign(false), gradeToSign(150), gradeToExecute(150) {
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	try {
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw Form::GradeTooLowException();
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw Form::GradeTooHighException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}

Form::Form(Form &f) : name(f.getName()), sign(f.getSigned()), gradeToSign(f.getGradeToSign()), gradeToExecute(f.getGradeToExecute()) {
}

Form &Form::operator = (Form &f) {
	if (this != &f)
		this->sign = f.sign;
	return (*this);
}

Form::~Form() {
}

std::string Form::getName() const {
	return (this->name);
}

bool Form::getSigned() const {
	return (this->sign);
}

int Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void Form::beSigned(Bureaucrat &b) {
	if (this->sign) {
		std::cout << "Document already signed" << std::endl;
		return ;
	}
	if (b.getGrade() <= this->gradeToSign)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}

Form::GradeTooHighException::GradeTooHighException() throw() : what_msg("Grade is too high") {
	// std::cout << "GTHE constructor called" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException() throw() : what_msg("Grade is too low") {
	// std::cout << "GTLE constructor called" << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
	// std::cout << "GTHE destructor called" << std::endl;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
	// std::cout << "GTLE destructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
	return (what_msg.c_str());
}

const char* Form::GradeTooLowException::what() const throw() {
	return (what_msg.c_str());
}

std::ostream &operator << (std::ostream &obj, Form &f) {
	obj << f.getName() << ", signed: " << f.getSigned() << ", sign grade: "
		<< f.getGradeToSign() << ", execute grade: " << f.getGradeToExecute();
	return (obj);
}