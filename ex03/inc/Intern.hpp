#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"
#include <string>

class Intern {
public:
	Intern();
	Intern(const Intern &copy);
	Intern operator=(const Intern &copy);
	~Intern();

	AForm *makeForm(std::string formName, std::string targetName);
};

#endif // __INTERN_HPP__