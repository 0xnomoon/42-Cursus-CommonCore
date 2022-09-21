#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <list>
#include <iostream>
#include <deque>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
public:
		// typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename Container::iterator iterator; //The Containers library is a generic collection of class templates and algorithms that allow programmers to easily implement common data structures like queues, lists and stacks
    iterator begin(){
        return(this->c.begin());
    };
    iterator end(){
        return (this->c.end());
    };
};

#endif