#include "printFucn.h"

/*
	string HoTen;
	string Parent = "Unknow";
	int tuoi = -1;
	string sex;
	int general = -1;
*/

void xuatPerson(Person A)
{
	cout << "The he: " << A.general << "\n";
	cout << "HoTen: " << A.HoTen << "\n";
	cout << "Parent: " << A.Parent << "\n";
	cout << "Gioi tinh: " << A.sex << "\n";
}

void xuatGiaPha(GiaPha Giapha)
{	
	if (Giapha.firstChild != NULL)
	{
		Node* node = Giapha.firstChild;
		while (node != NULL)
		{
			xuatPerson(node->data);
			node = node->nextPerson; // Chuyen sang node tiep theo
		}
	}
}

Node* Search_Hoten(GiaPha& Giapha, Person A)
{
	Node* node = Giapha.firstChild;
	int i = 0;
	while (node != NULL && node->data.HoTen != A.HoTen)
		node = node->nextPerson;
	if (node != NULL)
		return node;

	return NULL;
}

