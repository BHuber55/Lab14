#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
	ListArrayIterator<CD>* iter = list->iterator();

	while (iter->hasNext())
	{
		CD* cd = iter->next();
		delete cd;
	}
	delete iter;
}

int main()
{
	ListArray<CD>* cds = CD::readCDs("cds.txt");
	int num_items = cds->size();
	cout << num_items << endl;

	TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

	//DO THIS
	//thoroughly test your table

	ListArrayIterator<CD>* iter = cds->iterator();

	while (iter->hasNext())
	{
		CD* cd = iter->next();
		String* title = cd->getKey();
		title->displayString();
		cout << endl;
		slt->tableInsert(cd);
	}
	delete iter;

	cout << endl  << "Hit enter to continue." << endl;
	cin.get();

	//to dipslay
	TableSortedList<CD>* slt2 = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);
	ListDoublyLinkedIterator<CD>* iter2 = slt->iterator();
	
	while (iter2->hasNext())
	{
		CD* cd = iter2->next();
		String* title2 = cd->getKey();
		title2->displayString();
		cout << endl;
		slt2->tableInsert(cd);
	}
	delete iter2;

	String* random = new String("Dead Calm Chaos");

	bool rem = slt2->tableRemove(random);
	if (rem)
	{
		cout << "Removed item" << endl << endl;
	}
	
	iter2 = slt2->iterator();
	while (iter2->hasNext())
	{
		CD* cd = iter2->next();
		String* random2 = cd->getKey();
		random2->displayString();
		cout << endl;
	}

	delete random;
	deleteCDs(cds);
	delete cds;
	delete slt;
	delete slt2;

	return 0;
}