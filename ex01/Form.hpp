/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:48:27 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/22 20:49:22 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	const std::string	name;
	bool				sign;
	const int			gradeToSign;
	const int			gradeToExecute;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form &f);
		Form &operator = (Form &f);
		~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat &b);

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

std::ostream &operator << (std::ostream &obj, Form &f);

#endif