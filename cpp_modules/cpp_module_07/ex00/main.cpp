#include "whatever.hpp"

class Awesome
{
	public:
		Awesome(void) : _n(0) {return;}
		Awesome(int n) : _n(n) {return ;}
        Awesome & operator= (Awesome & a) {_n = a._n; return *this;}
		bool operator==(Awesome const & rhs) const {return (this->_n == rhs._n);}
		bool operator!=(Awesome const & rhs) const{return (this->_n != rhs._n);}
		bool operator>(Awesome const & rhs) const {return (this->_n > rhs._n);}
		bool operator<(Awesome const & rhs) const {return (this->_n < rhs._n);}
		bool operator>=(Awesome const & rhs) const {return (this->_n >= rhs._n);}
		bool operator<=(Awesome const & rhs) const {return (this->_n <= rhs._n);}
		int get_n(void) const {return this->_n;}
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main( void ) {
	int a = 2; //main du sujet 
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "str1";
	std::string d = "str2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "-----------------" << std::endl;
	Awesome i(2), y(4); //test du sujet de correction
	::swap(i, y);
	std::cout << i << " " << y << std::endl;
	std::cout << ::max(i, y) << std::endl;
	std::cout << ::min(i, y) << std::endl;
	return 0;
}
