/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:18:08 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/11 19:43:08 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

// コンストラクタ
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

// コピーコンストラクタ
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

// コピーコンストラクタ
// PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
// 	: AForm(other), _target(other._target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other)
{
	*this = other;
}

// 代入演算子のオーバーロード
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		_target = other._target;
		setIsSigned(other.getIsSigned());
	}
	return *this;
}

// デストラクタ
PresidentialPardonForm::~PresidentialPardonForm() {}

// 大統領恩赦
void PresidentialPardonForm::performAction() const
{
	std::cout << getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
