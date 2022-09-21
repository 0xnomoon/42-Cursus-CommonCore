#include "Span.hpp"

Span::Span(unsigned int n){
    this->_vect.reserve(n); //increase capacity of the vector
}

Span::Span(const Span &other){
    *this = other;
}

Span &Span::operator=(const Span &other){
    this->_vect.reserve(other._vect.size());
    for (size_t i = 0; i < other._vect.size(); i++){
        _vect[i] = other._vect[i];
    }
    return (*this);
}

Span::~Span(){};

void Span::fullingVctRdNb(){
    srand(time(NULL));
    for (size_t i = 0; i < this->_vect.capacity(); i++)
        this->_vect.push_back(rand () % INT_MAX);
}

void Span::addNumber(unsigned int n){
    if (std::find(this->_vect.begin(), this->_vect.end(), n) != this->_vect.end())
        throw std::runtime_error("Error: You can't add this number in the vector it's already in it");
    this->_vect.push_back(n);
}

unsigned int Span::shortestSpan(){
    if (this->_vect.empty() || this->_vect.size() == 1)
        throw std::runtime_error("Error: vector size isn't correct");
    std::vector<unsigned int> temp;
    unsigned int tmp = *max_element(this->_vect.begin(), this->_vect.end()); //max_element: Returns an iterator pointing to the element with the largest value in the range [first,last)
    for(size_t i = 0; i < this->_vect.size(); i++){
        temp.push_back(this->_vect[i]);
    }
    std::sort (temp.begin(), temp.end());
    for(size_t i = 0; i < this->_vect.size(); i++){
        if (i + 1 < this->_vect.size() && temp[i + 1] - temp[i] < tmp)
            tmp = temp[i + 1] - temp[i];
    }
    return(tmp);
}

unsigned int Span::longestSpan(){
    if (this->_vect.empty() || this->_vect.size() == 1)
        throw std::runtime_error("Error: vector wrong size");
    unsigned int min = *min_element(this->_vect.begin(), this->_vect.end()); //min_element: Finds the smallest element in the range [first, last).
    unsigned int max = *max_element(this->_vect.begin(), this->_vect.end()); //max_element: Returns an iterator pointing to the element with the largest value in the range [first,last)
    return(max - min);
}
