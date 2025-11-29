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

int remove_person(GiaPha& Giapha, Node* person)
{
	if (person != NULL)
	{

	}
	return 0;
}

void destroy_giapha(GiaPha& Giapha)
{
	Person x;
	Node* node = Giapha.firstChild;
	while (node != NULL)
	{
		remove_first(Giapha, x);
		node = Giapha.firstChild;
	}
	Giapha.lastChild = NULL;
}
