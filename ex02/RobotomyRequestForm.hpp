/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:14:04 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/11 19:45:40 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // rand() 用
#include <ctime>   // time() 用

/*
50% の確率でロボトミー手術を成功させる

署名グレード：72
実行グレード：45
*/
class RobotomyRequestForm : public AForm
{
private:
	std::string _target; // 実行対象
	virtual void performAction() const; // 具体的な処理をオーバーライド


public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	// exceptions
	class RobotizationFailed: public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif
