/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:31:45 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/10 16:31:45 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        // Bureaucrat インスタンス Bob (グレード 50) の作成
        Bureaucrat bob("Bob", 50);
        // Form インスタンス（署名グレード 40、実行グレード 20）
        Form contract("Top Secret Contract", 40, 20);

        // フォーム情報の表示
        std::cout << contract << std::endl;
        bob.signForm(contract); // グレードが低いため署名できない

        // Bureaucrat インスタンス Alice (グレード 30) の作成
        Bureaucrat alice("Alice", 30);
        alice.signForm(contract); // 署名可能

        // フォーム情報の再表示
        std::cout << contract << std::endl;
    }
    catch (const std::exception &e)
    {
        // 例外メッセージの出力
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Bureaucrat インスタンス Alice (等級 150) の作成
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;

        // 等級を 151 に降格 → 例外発生
        alice.decrementGrade();
    }
    catch (const std::exception &e)
    {
        // 例外メッセージの出力
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
