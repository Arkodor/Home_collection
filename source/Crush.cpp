#include "Crush.h"
#include "Weapon.h"

Crush::Crush(string name, string kind, string weight, string overall_length, string length_of_the_blade, string length_of_the_handle, string form)
{
    this->form = form;
	this->name                 = name;
    this->kind                 = kind;
    this->weight               = weight;
    this->overall_length       = overall_length;
    this->length_of_the_blade  = length_of_the_blade;
    this->length_of_the_handle = length_of_the_handle;
}

string Crush::Print()
{
	string str;
	str = "Name: " + this->name + "\n" + "Kind: " + this->kind + "\n" + "Weight: " + this->weight + "\n" + "Length: " + this->overall_length + "\n" + "Blade lenght: " + this->length_of_the_blade + "\n" + "Handel lenght: " + this->length_of_the_handle + "\n" +  "Kind crush: " + this->form + "\n";
	return str;
}
string Crush::In_file()
{
	
	string str;
	str = "Crush\n" + this->name + "\n" + this->kind + "\n" + this->weight + "\n" + this->overall_length + "\n" + this->length_of_the_blade + "\n" + this->length_of_the_handle + "\n" + this->form + "\n";
	return str;
}