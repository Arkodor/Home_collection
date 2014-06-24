#ifndef WEAPON_H
#define WEAPON_H


#include <iostream>
#include <string>

using namespace std;

class Weapon
{
protected:
	string name;//им€
	string kind;//тип
    string weight; //масса
    string overall_length; //обша€ длина
    string length_of_the_blade; // длина клинка
    string length_of_the_handle; // длина руко€ти
public:

    void SetName(string new_name){this->name = new_name;}
    void SetKind(string new_kind){this->kind = new_kind;}
    void SetWeight(string new_weight){this->weight=new_weight;}
    void SetOverall_Length(string new_overall_length){this->overall_length=new_overall_length;}
    void SetLength_Blade(string new_length_of_the_blade){this->length_of_the_blade=new_length_of_the_blade;}
    void SetLength_Handle(string new_length_of_the_handle){this->length_of_the_handle=new_length_of_the_handle;}

    string GetName(){return name;}
    string GetKind(){return kind;}
    string GetWeight(){return weight;}
    string GetOverall_Length(){return overall_length;}
    string GetLength_Blade(){return length_of_the_blade;}
    string GetLength_Handle(){return length_of_the_handle;}

	virtual string Print() = 0;
	virtual string In_file() = 0;
};
#endif
