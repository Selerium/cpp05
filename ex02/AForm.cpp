/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:23:11 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/22 20:56:13 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Sample"), sign(false), gradeToSign(150), gradeToExecute(150) {
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	try {
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw AForm::GradeTooLowException();
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw AForm::GradeTooHighException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}

AForm::AForm(AForm &f) : name(f.getName()), sign(f.getSigned()), gradeToSign(f.getGradeToSign()), gradeToExecute(f.getGradeToExecute()) {
}

AForm &AForm::operator = (AForm &f) {
	if (this != &f)
		this->sign = f.sign;
	return (*this);
}

AForm::~AForm() {
}

std::string AForm::getName() const {
	return (this->name);
}

bool AForm::getSigned() const {
	return (this->sign);
}

int AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void AForm::beSigned(Bureaucrat &b) {
	if (this->sign)
		throw AForm::FormAlreadySignedException();
	if (b.getGrade() <= this->gradeToSign)
		this->sign = true;
	else
		throw AForm::GradeTooLowException();
}

AForm::GradeTooHighException::GradeTooHighException() throw() : what_msg("Grade is too high") {
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
}

const char* AForm::GradeTooHighException::what() const throw() {
	return (what_msg.c_str());
}

AForm::GradeTooLowException::GradeTooLowException() throw() : what_msg("Grade is too low") {
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
}

const char* AForm::GradeTooLowException::what() const throw() {
	return (what_msg.c_str());
}

AForm::FormAlreadySignedException::FormAlreadySignedException() throw() : what_msg("Form already signed") {
}

AForm::FormAlreadySignedException::~FormAlreadySignedException() throw() {
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return (what_msg.c_str());
}

AForm::FormNotSignedException::FormNotSignedException() throw() : what_msg("Form not signed") {
}

AForm::FormNotSignedException::~FormNotSignedException() throw() {
}

const char* AForm::FormNotSignedException::what() const throw() {
	return (what_msg.c_str());
}

std::ostream &operator << (std::ostream &obj, AForm &f) {
	obj << f.getName() << ", signed: " << f.getSigned() << ", sign grade: "
		<< f.getGradeToSign() << ", execute grade: " << f.getGradeToExecute();
	return (obj);
}

void AForm::setSign(bool sign) {
	this->sign = sign;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (this->sign) {
		if (executor.getGrade() <= this->gradeToExecute)
			this->doAction();
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}
