/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:02:47 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/11 20:00:05 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> // ファイル出力用

/*
ASCII アートの木をファイルに書き込む

署名グレード：145
実行グレード：137
*/
class ShrubberyCreationForm : public AForm
{
private:
    std::string _target; // 実行対象

protected:
    void performAction() const; // 具体的な処理をオーバーライド

public:
	ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

	// exceptions
	class OpenFileExeption: public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif
