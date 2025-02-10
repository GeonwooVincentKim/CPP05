/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:32:33 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/10 18:32:33 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // 前方宣言 (Bureaucrat の参照が必要)

class Form
{
private:
    const std::string _name; // フォームの名前（変更不可）
    bool _isSigned;          // 署名状態（初期値は false）
    const int _signGrade;    // 署名に必要な最小グレード
    const int _executeGrade; // 実行に必要な最小グレード

public:
    // 例外クラス
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // コンストラクタ & デストラクタ
    Form();
    Form(const std::string &name, int signGrade, int executeGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    // Getter メソッド
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    // フォームの署名機能
    void beSigned(const Bureaucrat &bureaucrat);
};

// << 演算子のオーバーロード（非メンバ関数）
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
