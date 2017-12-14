#pragma once

#include "cppincl.h"

class CustomException : public exception
{
public:
	virtual const char* what() const throw();
};

class GoesWrong
{
public:
	void methodThatGoesWrong();
};

void runDerivedException();