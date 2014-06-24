#ifndef CRUSH_H
#define CRUSH_H

#include "Weapon.h"
class Crush: public Weapon
{
    string form;//форма
public:
    Crush(string name, string kind, string weight, string overall_length, string length_of_the_blade, string length_of_the_handle, string form);

    void SetForm(string new_form){this->form = new_form;}

    string GetForm(){return form;}
	virtual string Print();
	virtual string In_file();
};
#endif
