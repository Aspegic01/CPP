#pragma once

#include <iostream>
#include <cstdlib>

class Base {
public:
    virtual ~Base();
};

void identify(Base* p);
void identify(Base& p);
Base *generate();