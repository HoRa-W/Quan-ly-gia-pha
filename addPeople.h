#pragma once
#include <string>
#include <iostream>
#include "CauTruc.h"
using std::string;
using std::getline;
using std::cin; using std::cout;

Person createPerson();
Node* createNode(Person A);
void createGiaPha(GiaPha& gia_pha);
void add_first_person(GiaPha& Giapha, Node* node);
void add_last_person(GiaPha& Giapha, Node* node);
void add_after_q(GiaPha& Giapha, Node* p, Node* q);
