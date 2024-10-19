/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:32:54 by victoirevau       #+#    #+#             */
/*   Updated: 2024/10/18 12:51:27 by victoirevau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> int easyfind(T &container, int value)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
			return *it;
	}
	throw ValueNotFound();
}