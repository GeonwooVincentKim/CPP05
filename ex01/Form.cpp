/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:36:25 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/10 18:36:25 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// 例外メッセージの返却
const char *Form::GradeTooHighException::what() const throw()
{
    return "Error: Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Error: Form grade is too low!";
}

// デフォルトコンストラクタ（デフォルト値の設定）
Form::Form() : _name("default"), _isSigned(false), _signGrade(1), _executeGrade(1) {}

// ユーザー定義コンストラクタ
Form::Form(const std::string name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

// コピーコンストラクタ
Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

// 代入演算子のオーバーロード
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned; // 署名状態のみコピー
    }
    return *this;
}

// デストラクタ
Form::~Form() {}

// Getter メソッドの実装
std::string Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecuteGrade() const { return _executeGrade; }

// Bureaucrat が Form に署名を試みる
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

// << 演算子のオーバーロード（非メンバ関数）
std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Required Sign Grade: " << form.getSignGrade()
       << ", Required Execute Grade: " << form.getExecuteGrade();
    return os;
}
