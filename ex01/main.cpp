/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:54:33 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/22 20:57:20 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main() {
	std::cout << "Working tests (and overloaded operator):" << std::endl;
	Form a("Form A", 10, 8);
	Form b("Form B", 120, 80);
	std::cout << a << std::endl << b << std::endl;

	std::cout << std::endl << "Invalid grades:" << std::endl;
	Form c("Form C", 0, 8);
	Form d("Form C", 151, 8);
	Form e("Form C", 1, -8);
	Form f("Form C", 1, 800);

	std::cout << std::endl << "Signing forms:" << std::endl;
	Bureaucrat ba("John", 1);
	Bureaucrat bb("Bob", 10);
	a.beSigned(ba);
	b.beSigned(bb);

	std::cout << std::endl << "Invalid signs:" << std::endl;
	Bureaucrat bc("Charles", 150);
	bc.signForm(c);

	std::cout << std::endl << "Repeated signs:" << std::endl;
	ba.signForm(a);
	bb.signForm(a);
}