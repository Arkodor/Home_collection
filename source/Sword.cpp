#include "Sword.h"

Sword::Sword(string name, string kind, string weight, string overall_length, string length_of_the_blade, string length_of_the_handle, string blade_shape)
{
    this->blade_shape = blade_shape;
	this->name                 = name;
    this->kind                 = kind;
    this->weight               = weight;
    this->overall_length       = overall_length;
    this->length_of_the_blade  = length_of_the_blade;
    this->length_of_the_handle = length_of_the_handle;
  
}

string Sword::Print()
{
	string str;
	str = "Name: " + this->name + "\n" + "Kind: " + this->kind + "\n" + "Weight: " + this->weight + "\n" + "Length: " + this->overall_length + "\n" + "Blade lenght: " + this->length_of_the_blade + "\n" + "Handel lenght:  " + this->length_of_the_handle + "\n" +  "Blade Shape:  " + this->blade_shape + "\n";
	return str;
}
string Sword::In_file()
{
	string str;
	str = "Sword\n" + this->name + "\n" + this->kind + "\n" + this->weight + "\n" + this->overall_length + "\n" + this->length_of_the_blade + "\n" + this->length_of_the_handle + "\n" + this->blade_shape + "\n";
	return str;
}
