#include "removePeople.h"

int remove_first(GiaPha& Giapha)
{
	if (Giapha.firstChild != NULL)
	{
		Node* node = Giapha.firstChild;

		Giapha.firstChild = node->nextPerson;
		delete node;
		if (Giapha.firstChild == NULL)
			Giapha.lastChild = NULL;
		return 1;
	}
	return 0;
}

int remove_After_Q(GiaPha& Giapha, Node* q)
{
	if (q != NULL) {
		Node* p = q->nextPerson;
		if (p != NULL)
		{
			if (Giapha.lastChild == p)
				Giapha.lastChild = q;
			q->nextPerson = p->nextPerson;
			delete q;
			return 1;
		}
		return 0;
	}
	return 0;
}

bool remove_person(GiaPha& Giapha, Node* person)
{
	Node* p = new Node;
	if (Giapha.firstChild == person)
	{
		remove_first(Giapha);
		return 1;
	}
	for (Node* k = Giapha.firstChild; k != NULL; k = k->nextPerson)
	{
		if (k->data.HoTen == person->data.HoTen)
		{
			p->nextPerson = k->nextPerson;
			delete k;
			return 1;
		}
		//gan node p bang node k de node p luon la node dung truoc node k
		p = k;
	}
	return 0;
}

void destroy_giapha(GiaPha& Giapha)
{
	Node* node = Giapha.firstChild;
	while (node != NULL)
	{
		remove_first(Giapha);
		node = Giapha.firstChild;
	}
	Giapha.lastChild = NULL;
}
