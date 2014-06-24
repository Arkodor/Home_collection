#ifndef SPEAR_H
#define SPEAR_H

#include "Weapon.h"
class Spear: public Weapon
{
	string blade_shape;//форма лезвия

public:
    Spear(string nema, string kind, string weight, string overall_length, string length_of_the_blade, string length_of_the_handle, string blade_shape);

    void SetBlade_shape(string new_blade_shape){this->blade_shape = new_blade_shape;}
	
    string GetBlade_shape(){return blade_shape;}
	virtual string Print();
	virtual string In_file();
};
#endif
