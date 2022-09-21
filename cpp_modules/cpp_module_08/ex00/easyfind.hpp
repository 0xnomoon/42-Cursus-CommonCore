#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <forward_list>

template <typename T>
int easyfind(T &list, int diff){
    typename T::iterator y;
    int i = 0;
    for (y = list.begin(); y != list.end(); y++){
        if (*y == diff)
            return (i);
        i++;
    }
    throw std::invalid_argument("No Occurence Found");
}

#endif