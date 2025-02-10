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

int main()
{
    try
    {
        // Bureaucrat インスタンス Bob (等級 2) の作成
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        // 等級を 1 に昇格
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        // 等級 1 を超えると例外発生
        bob.incrementGrade();
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
