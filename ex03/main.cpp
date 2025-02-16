/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:00:50 by geonwkim           #+#    #+#             */
/*   Updated: 2025/02/11 18:00:50 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testBureaucratCreation()
{
    std::cout << "\n\033[33mTesting Bureaucrat Creation with Invalid Grades\033[0m\n";
    try
    {
        Bureaucrat high("High", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try
    {
        Bureaucrat low("Low", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void testBureaucratGradeAdjustment()
{
    std::cout << "\n\033[33mTesting Bureaucrat Grade Adjustment\033[0m\n";
    Bureaucrat bob("Bob", 2);
    std::cout << bob;
    try
    {
        bob.incrementGrade();
        std::cout << bob;
        bob.incrementGrade(); // Should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    Bureaucrat tim("Tim", 149);
    std::cout << tim;
    try
    {
        tim.decrementGrade();
        std::cout << tim;
        tim.decrementGrade(); // Should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void testForms()
{
    std::cout << "\n\033[33mTesting Forms Execution\033[0m\n";

    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Alice");

    Bureaucrat gardener("Gardener", 130);
    Bureaucrat technician("Technician", 45);
    Bureaucrat president("President", 5);

    gardener.signForm(shrubbery);
    gardener.executeForm(shrubbery);

    technician.signForm(robotomy);
    technician.executeForm(robotomy);

    president.signForm(pardon);
    president.executeForm(pardon);
}

void testIntern()
{
    std::cout << "\n\033[33mTesting Intern Form Creation\033[0m\n";
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm *form = intern.makeForm("robotomy request", "Marvin");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    form = intern.makeForm("unknown form", "Nobody"); // Should print an error
    if (form)
        delete form;
}

int main()
{
    testBureaucratCreation();
    testBureaucratGradeAdjustment();
    testForms();
    testIntern();

    return 0;
}
