#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Constructor" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain &other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
	std::cout << "Brain Copy Constructor." << std::endl;
}

Brain & Brain::operator=(const Brain &other) {
	if (this != &other)
	{
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
		std::cout << "Brain Copy Assignment" << std::endl;
	}
	return *this;
}

void    Brain::setIdeas() {
    std::string line = "reflective historical promise yam wild psychotic toad clumsy brake obsequious night church bury distance party parsimonious weary receptive pretend exercise field direful sore clammy shake jog support sharp towering aromatic ethereal utter hallowed roomy calm creator spiffy wonder taboo abstracted regular fertile safe warlike nippy word sofa tease approval wriggle cuddly nonchalant sisters breakable punishment adjustment possess check transport dress irritating deer detailed black amazing aloof excuse channel grey soda domineering noisy hurried lace attraction wipe thread wheel boil terrify coherent dead repair quince health kill water insect eight general certain scratch creepy four nauseating table symptomatic sleet smelly babies";
    int i = 0;
    std::stringstream ssin(line);
    while (ssin.good() && i < 100) {
        ssin >> ideas[i];
        i++;
    }
}

std::string Brain::getIdeas(int i) const {
    return (ideas[i]);
}

std::ostream& operator<<(std::ostream& out, const Brain &brain) {
    out << "[ ";
	for(int i = 0; i < 100; ++i) {
		out << brain.getIdeas(i) << " ,";
	}
	out << " ]" << std::endl;
	return out;
}