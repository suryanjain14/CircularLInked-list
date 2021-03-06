// CircularLInked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<conio.h>

using namespace std;

struct node
{
	int data;
	node *next;
};

class cllist
{
	node *start=NULL;
public:
	cllist()
	{
		node *start = NULL;
	}
	void append(int num);
	void display();
	void del(int loc);
	void addinbetween(int loc, int num);
};

void cllist::append(int num)
{
	node *temp = new node;
    temp->data = num;
	if (start == NULL)
	{
		start = temp;
		temp->next = start;
	}
	else 
	{
		node *t;
		t = start;
		while (t->next != start)
		{
			t = t->next;
		}
		t->next = temp;
		temp->next = start;
	}
}

void cllist::display()
{
	if (start == NULL)
	{
		cout << "THe list is empty" << endl;
	}
	else
	{
		int i = 0;
		node *t = start;
		while (t->next!= start)
		{

			cout << "\n The data is: " << t->data << endl;
			t = t->next;
		}

		cout << "\n The data is: " << t->data << endl;

	}
}

void cllist::addinbetween(int loc,int num)
{

	if (start == NULL)
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		node *t = start;
		for (int i = 0; i < loc; i++)
		{
			t = t->next;
		}
		t->data = num;
	}
}


void cllist::del(int loc)
{
	if (start == NULL)
	{
		cout << "The list is empty" << endl;
	}
	else//this method will work properly only whin location given is less than the size of linked list
	{
		node *t = start;
		node  *prev=NULL;
		for (int i = 0; i < loc; i++)
		{
			prev = t;
			t = t->next;
		}
		prev->next = t->next;
		delete t;

	}
}

int main()
{
		cllist obj;
		int j=0;
		while (j != 5)
		{
			cout << "\n1 add\n2 del \n3 add at loc \n4 display \n5 exit" << endl;
			cin >> j;
			switch (j)
			{
			case 1:
				int num;
				cout << "Enter the value" << endl;
				cin >> num;
				obj.append(num);
				break;
			case 2:
				int loc;
				cout << "Enter the loc" << endl;
				cin >> loc;
				obj.del(loc);
				break;
			case 3:

				cout << "Enter the value" << endl;
				cin  >> num;
				cout << "Enter the loc" << endl;
				cin >> loc;
				obj.addinbetween(loc, num);
				break;
			case 4:
				obj.display();
				break;

			case 5:
			break; 
			default:
				cout << "Invalid entry" << endl;
				break;
			}

		}
		return 0;
}

