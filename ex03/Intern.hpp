/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:10:17 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/23 14:30:28 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <cctype>

class Intern {
	public:
		Intern();
		Intern(Intern &i);
		Intern &operator = (const Intern &i);
		~Intern();

		AForm *makeForm(std::string formName, std::string formTarget);
		AForm *ShruberryFactory(std::string target);
		AForm *RobotomyFactory(std::string target);
		AForm *PardonFactory(std::string target);

		typedef AForm *(Intern::*form) (std::string);
};

#endif