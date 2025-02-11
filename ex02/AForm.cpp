/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:02:47 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/11 19:26:41 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// 例外クラスのメッセージ
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Error: Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Error: Grade is too low!";
}

const char *AForm::IsNotSignedException::what() const throw()
{
    return "Error: Form is not signed!";
}

// コンストラクタ
AForm::AForm() : _name("default"), _is_signed(false), _sign_grade(1), _execute_grade(1) {}

AForm::AForm(const std::string &name, int sign_grade, int execute_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

// コピーコンストラクタ
AForm::AForm(const AForm &other)
    : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {}

// 代入演算子のオーバーロード
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _is_signed = other._is_signed;
    }
    return *this;
}

// デストラクタ
AForm::~AForm() {}

// Getter メソッド
std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _is_signed; }
int AForm::getSignGrade() const { return _sign_grade; }
int AForm::getExecuteGrade() const { return _execute_grade; }
void AForm::setIsSigned(bool isSigned) { _is_signed = isSigned; }

// 署名機能
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _sign_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

// フォーム実行
void AForm::execute(const Bureaucrat &executor) const
{
    if (!_is_signed)
        throw IsNotSignedException();
    if (executor.getGrade() > _execute_grade)
        throw GradeTooLowException();

    performAction(); // 具体的な処理は派生クラスで実装
}

// 出力演算子オーバーロード
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Required Sign Grade: " << form.getSignGrade()
       << ", Required Execute Grade: " << form.getExecuteGrade();
    return os;
}
