/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:39:14 by vvaudain          #+#    #+#             */
/*   Updated: 2024/11/05 16:01:35 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void printSeparator(void)
{
    std::cout << "----------------------------------------" << std::endl;
}

int main(void)
{
    {    
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
        printSeparator();
    }
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(mstack);  
        return 0;
    }
    
    return 0;
}

// int main(void){
    
//     std::cout << BOLDBLUE << "Testing with a stack of ints" << RESET << std::endl;
//     MutantStack<int> mstackint;
//     for(int i = 0; i < 10; i++)
//         mstackint.push(i);
//     for (MutantStack<int>::iterator it = mstackint.begin(); it != mstackint.end(); it++)
//         std::cout << *it << std::endl;

//     std::cout << BOLDBLUE << "Testing with a stack of strings" << RESET << std::endl;
//     MutantStack<std::string> mstackstr;
//     for(int i = 0; i < 10; i++)
//     {
//         std::stringstream ss;
//         ss << "coucou \""<< i << "\"";
//         mstackstr.push(ss.str());
//     }
//     for (MutantStack<std::string>::iterator it = mstackstr.begin(); it != mstackstr.end(); it++)
//         std::cout << *it << std::endl;
//     return 0;
// }