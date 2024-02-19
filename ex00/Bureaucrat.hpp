/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:00:07 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/19 08:55:43 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class Bureaucrat {
	const std::string	name;
	int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &c);
		Bureaucrat &operator = (const Bureaucrat &c);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		increaseGrade();
		void		decreaseGrade();

	class GradeTooHighException : public std::exception {
		std::string what_msg;

		public:
			GradeTooHighException() throw();
			~GradeTooHighException() throw();
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		std::string what_msg;

		public:
			GradeTooLowException() throw();
			~GradeTooLowException() throw();
			virtual const char* what() const throw();
	};
};

std::ostream &operator << (std::ostream &obj, const Bureaucrat &c);

#endif