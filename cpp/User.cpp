#pragma once

#include <fstream>
#include <iostream>

using namespace std;

class User
{
public:
    User(std::string name, std::string login, std::string pass):_name(name), _login(login), _pass(pass){};
    friend std::fstream& operator >> (std::fstream& is, User& obj);
    friend std::ostream& operator << (std::ostream& os, User& obj);

private:
    std::string _name;
    std::string _login;
    std::string _pass;
};


std::fstream& operator >> (std::fstream& is, User& obj)
{
    is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}
std::ostream& operator << (std::ostream& os, User& obj)
{
    os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	return os;
}