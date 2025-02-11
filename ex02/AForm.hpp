/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:06:43 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/11 19:25:50 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // 循環参照を防ぐための前方宣言

class AForm
{
private:
    const std::string _name;  // フォームの名前（変更不可）
    bool _is_signed;           // 署名状態
    const int _sign_grade;     // 署名に必要な最小グレード
    const int _execute_grade;  // 実行に必要な最小グレード

protected:
	virtual void performAction() const = 0;	// 純粋仮想関数（派生クラスで実装必須）

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

    class IsNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // コンストラクタ & デストラクタ
    AForm();
    AForm(const std::string &name, int signGrade, int executeGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // Getter
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
	void setIsSigned(bool isSigned);
	

    // 署名機能
    void beSigned(const Bureaucrat &bureaucrat);

    // 純粋仮想関数（派生クラスで実装必須）
    void execute(const Bureaucrat &executor) const;
};

// << 演算子のオーバーロード（非メンバ関数）
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
