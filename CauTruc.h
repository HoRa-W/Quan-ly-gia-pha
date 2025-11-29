#pragma once
#include <string>
using std::string;


struct Person{
	string HoTen;
	string Parent = "Unknow";
	string sex;
	int general = -1;
};

struct Node {
	Person data;
	Node* nextPerson;
};

struct GiaPha {
	Node* firstChild;
	Node* lastChild;
};
