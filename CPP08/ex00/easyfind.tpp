/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:32:54 by victoirevau       #+#    #+#             */
/*   Updated: 2024/11/05 16:57:23 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> int easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw ValueNotFound();
	else
		return (*it);
}