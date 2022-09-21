#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form ff("", 3, 2);
	Bureaucrat ss(1, "hhhh");
	try {
		ss.upRank();
		std::cout << ff << std::endl;
	} catch (std::exception &e) {
		std::cout <<"Exception caught: "<< e.what() <<std::endl;
	}
	Bureaucrat b2(1, "hhhh");
	ff.beSigned(b2);
	b2.signForm(ff);
	Form aze("", 2, 2);
	Bureaucrat wer(40, "Joe");
	wer.signForm(aze);

}