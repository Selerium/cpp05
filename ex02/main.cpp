/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:54:33 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/23 01:42:09 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main() {
	std::cout << "Working tests:" << std::endl;
	ShrubberyCreationForm a("chicken 1");
	RobotomyRequestForm b("chicken 2");
	PresidentialPardonForm c("chicken 3");
	Bureaucrat d("Bob", 1);
	Bureaucrat e("Alice", 150);

	std::cout << std::endl << "Signing forms: " << std::endl;
	d.signForm(a);
	e.signForm(b);
	d.signForm(b);
	e.signForm(b);

	std::cout << std::endl << "Executing forms: " << std::endl;
	d.executeForm(a);
	e.executeForm(b);
	d.executeForm(b);
	e.executeForm(c);
	d.signForm(c);
	d.executeForm(c);
}