/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:33:32 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/23 01:51:16 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Sample", 145, 137) {
	std::cout << "Shrubbery Form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {
	std::cout << "Shrubbery Form (" << name << ") created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &s) : AForm(s) { 
	std::cout << "Shrubbery Form copy constructed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm &s) {
	if (this != &s) {
		this->setSign(s.getSigned());
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shruberry Form (" << this->getName() << ") destructed" << std::endl;
}

void ShrubberyCreationForm::doAction() const {
	std::ofstream file;

	file.open((this->getName() + "_shrubbery").c_str());
	file << "                                                  ." << std::endl
		<< "                                       .         ;  " << std::endl
		<< "          .              .              ;%     ;;   " << std::endl
		<< "            ,           ,                :;%  %;   " << std::endl
		<< "             :         ;                   :;%;'     .,   " << std::endl
		<< "    ,.        %;     %;            ;        %;'    ,;" << std::endl
		<< "      ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
		<< "       %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl
		<< "        ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
		<< "         `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
		<< "          `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
		<< "             `:%;.  :;bd%;          %;@%;'" << std::endl
		<< "               `@%:.  :;%.         ;@@%;'   " << std::endl
		<< "                 `@%.  `;@%.      ;@@%;         " << std::endl
		<< "                   `@%%. `@%%    ;@@%;        " << std::endl
		<< "                     ;@%. :@%%  %@@%;       " << std::endl
		<< "                       %@bd%%%bd%%:;     " << std::endl
		<< "                         #@%%%%%:;;" << std::endl
		<< "                         %@@%%%::;" << std::endl
		<< "                         %@@@%(o);  . '         " << std::endl
		<< "                         %@@@o%;:(.,'         " << std::endl
		<< "                     `.. %@@@o%::;         " << std::endl
		<< "                        `)@@@o%::;         " << std::endl
		<< "                         %@@(o)::;        " << std::endl
		<< "                        .%@@@@%::;         " << std::endl
		<< "                        ;%@@@@%::;.          " << std::endl
		<< "                       ;%@@@@%%:;;;. " << std::endl
		<< "                   ...;%@@@@@%%:;;;;,.." << std::endl
		<< std::endl;
	file.close();
}