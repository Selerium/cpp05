/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:54:33 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/19 09:35:31 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main() {
	std::cout << "Working tests (and overloaded operator):" << std::endl;
	Bureaucrat a("John", 1);
	Bureaucrat b("Bob", 150);
	std::cout << a << b;

	std::cout << std::endl << "Tests for creating invalid grade bureaucrats:" << std::endl;
	Bureaucrat c("Alice", 24104124);
	Bureaucrat d("Charles", -24124);

	std::cout << std::endl << "Tests for incrementing/decrementing to wrong grade:" << std::endl;
	std::cout << a << "Increasing " << a.getName() << "'s grade:" << std::endl;
	a.increaseGrade();
	std::cout << b << "Decreasing " << b.getName() << "'s grade:" << std::endl;
	b.decreaseGrade();

	std::cout << std::endl << "Tests for decrementing grade:" << std::endl;
	std::cout << a;
	a.decreaseGrade();
	a.decreaseGrade();
	std::cout << a;

	std::cout << std::endl << "Tests for incrementing grade:" << std::endl;
	std::cout << b;
	b.increaseGrade();
	b.increaseGrade();
	std::cout << b;
}