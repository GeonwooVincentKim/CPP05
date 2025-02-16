/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:05:25 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/16 16:30:46 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void) other; }
Intern &Intern::operator=(const Intern &other) { (void) other; return *this; }
Intern::~Intern() {}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	int i = 0;
	std::string available_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (i < 3 && formName != available_forms[i])
		i++;
	
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << formName << std::endl;
		return (new ShrubberyCreationForm(target));
	case 1:
		std::cout << "Intern creates " << formName << std::endl;
		return (new RobotomyRequestForm(formName));
	case 2:
		std::cout << "Intern creates " << formName << std::endl;
		return (new PresidentialPardonForm (target));
	default:
		std::cout << "Form is not existing" << std::endl;
		return NULL;
	}
}