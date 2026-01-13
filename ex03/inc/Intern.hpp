#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"
#include <string>

typedef struct t_map
{
	std::string	key;
	AForm		*value;
};

const unsigned short int MAX_FORMS = 3;

class Intern {
private:
	t_map forms[MAX_FORMS];
public:
	Intern();
	Intern(const Intern &copy);
	Intern operator=(const Intern &copy);
	~Intern();

	AForm *makeForm(std::string formName, std::string targetName);
};

#endif // __INTERN_HPP__