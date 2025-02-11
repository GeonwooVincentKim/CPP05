/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:04:50 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/11 19:08:34 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// コンストラクタ
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// デストラクタ
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// ASCII アートをファイルに書き込む
void ShrubberyCreationForm::performAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
        return;

    file << "       _-_       \n"
            "    /~~   ~~\\    \n"
            " /~~         ~~\\ \n"
            "{               }\n"
            " \\  _-     -_  / \n"
            "   ~  \\ //  ~   \n"
            "_- - | | _- _    \n"
            "  _ -|_|-_ -    \n";
    file.close();
}
