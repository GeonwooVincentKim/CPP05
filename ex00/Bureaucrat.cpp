/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:25:27 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/10 17:25:27 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// 例外メッセージの返却
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error: Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error: Grade is too low!";
}

// デフォルトコンストラクタ（デフォルト名 "default"、デフォルト等級 150）
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

// ユーザー定義コンストラクタ
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

// コピーコンストラクタ
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

// 代入演算子オーバーロード
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        _grade = other._grade; // _nameはconstなので変更不可
    }
    return *this;
}

// デストラクタ
Bureaucrat::~Bureaucrat() {}

// Getter 実装
std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

// 等級の昇格（1になったら例外をスロー）
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

// 等級の降格（150になったら例外をスロー）
void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

// << 演算子オーバーロード（非メンバ関数）
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
