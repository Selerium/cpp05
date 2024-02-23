/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:54:33 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/23 14:49:31 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

int	main() {
	std::cout << "Create actors:" << std::endl;
	Intern someRandomIntern, a;
	Bureaucrat b("Alice", 1);
	AForm *rrf, *test1, *test2;

	std::cout << std::endl << "Make forms: " << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	test1 = a.makeForm("shrubbery creation", "Chicken");
	test2 = a.makeForm("presidential pardon", "Nuggets");

	std::cout << std::endl << "Sign forms: " << std::endl;
	b.signForm(*rrf);
	b.signForm(*test1);
	b.signForm(*test2);

	std::cout << std::endl << "Execute forms: " << std::endl;
	b.executeForm(*rrf);
	b.executeForm(*test1);
	b.executeForm(*test2);

	std::cout << std::endl;
	delete rrf;
	delete test1;
	delete test2;
}