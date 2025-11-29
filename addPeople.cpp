#include "addPeople.h"

/*
	string HoTen;
	string Parent = "Unknow";
	int tuoi = -1;
	string sex;
	int general = -1;
*/

Person createPerson()
{
	Person A;
	cin.ignore(10000, '\n');
	cout << "Nhap ho ten: ";
	getline(cin, A.HoTen);
	cout << "Nhap Parent: ";
	getline(cin, A.Parent);
	cout << "Nhap gioi tinh: "; 
	getline(cin, A.sex); //male hoac female
	cout << "Nhap the he: "; cin >> A.general;
	cin.ignore(10000, '\n');

	return Person(A);
}

Node* createNode(Person A)
{
	Node* node = new Node;
	node->data = A;
	node->nextPerson = NULL;
	return node;
}

void createGiaPha(GiaPha& gia_pha)
{
	gia_pha.firstChild = NULL;
	gia_pha.lastChild = NULL;
}

void add_first_person(GiaPha& Giapha, Node* node)
{
	if (Giapha.firstChild == NULL)
	{
		Giapha.firstChild = node;
		Giapha.lastChild = node;
	}
	else
	{
		node->nextPerson = Giapha.firstChild;
		Giapha.firstChild = node;
	}
}

void add_last_person(GiaPha& Giapha, Node* node)
{
	if (Giapha.firstChild == NULL)
	{
		Giapha.firstChild = node;
		Giapha.lastChild = node;
	}
	else
	{
		Giapha.lastChild->nextPerson = node;
		Giapha.lastChild = node;
	}
}

void add_after_q(GiaPha& Giapha, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->nextPerson = q->nextPerson;
		q->nextPerson = p;
		if (Giapha.lastChild == q)
			Giapha.lastChild = p;
	}
	else
		add_first_person(Giapha, p);
}

