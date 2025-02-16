/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:15:07 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/11 20:07:45 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

// コンストラクタ
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default target") {}

// コンストラクタ
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		_target = other._target;
		setIsSigned(other.getIsSigned());
	}
	return *this;
}

// デストラクタ
RobotomyRequestForm::~RobotomyRequestForm() {}

// 50% の確率でロボトミー成功
void RobotomyRequestForm::performAction() const
{
    std::cout << "* Drilling noises... *" << std::endl;
    srand(time(NULL)); // 乱数のシード設定

    if (rand() % 2)
        std::cout << _target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return "Error: Robotomy failed!";
}
