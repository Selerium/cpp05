/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:48:27 by jadithya          #+#    #+#             */
/*   Updated: 2024/02/22 20:49:22 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	const std::string	name;
	bool				sign;
	const int			gradeToSign;
	const int			gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm &f);
		AForm &operator = (AForm &f);
		virtual ~AForm() = 0;

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat &b);

		void setSign(bool sign);
		virtual void doAction() const = 0;
		void execute(Bureaucrat const &executor) const;

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

		class FormAlreadySignedException : public std::exception {
			std::string what_msg;

			public:
				FormAlreadySignedException() throw();
				~FormAlreadySignedException() throw();
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			std::string what_msg;

			public:
				FormNotSignedException() throw();
				~FormNotSignedException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream &operator << (std::ostream &obj, AForm &f);

#endif