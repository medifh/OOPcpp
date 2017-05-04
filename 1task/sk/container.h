#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <string>

#include <iostream>

#include <fstream>

#include <math.h>

#include <functional>

//#include <windows.h>

template <typename T >

class Container 
{
private:
	struct Element
	{
		T value;
		Element* next;
		Element* previous;
		int tag;
	};
	Element* head;
	Element* tail;
	int quanity;
public:
	Container()
	{
		head = NULL;
		tail = NULL;
		quanity=0;
	};
	~Container()
	{
		Element* current = head;
		Element* current2 = head;
		while (current != NULL)
		{
			current2 = (current->previous);
			delete current;
			current = current2;
		}
	};
	Container(const Mul& orig)
	{
		this->head = orig.head;
		this->tail = orig.tail;
	}
	 void Deltail()
	 {
		 if (tail != NULL)
		 {
			 Element* current = tail->next;
			 delete tail;
			 tail = current;
			 quanity--;
		 }
	 }
	 void Delhead()
	 {
		 if (head != NULL)
		 {
			 Element* current = head->previous;
			 delete head;
			 head = current;
			 quanity--;
		 }
	 }
	 T Gethead()
	 {
		 if (head != NULL)
		 {
			 return head->value
		 } 
		 else 
		 throw badhead("head is empty");  
	 }
	 T Gettail()
	 {
		 if (tail != NULL)
		 {
			 return tail->value
		 } 
		 else 
		 throw badtail("tail is empty");  
	 }
	 void Puthead(T newval)
	 {
		 Element* newhead=new element;
		 newhead->next=NULL;
		 newhead->previous=head;
		 newhead->value=newval;
		 head=newhead;
		 quanity++;
	 }
	 void Puttail(T newval)
	 {
		 Element* newtail=new element;
		 newtail->next=tail;
		 newtail->previous=NULL;
		 newtail->value=newval;
		 tail=newtail;
		 quanity++;
	 }
	 bool isEmpty()
	 {
		 return (head==NULL); 
	 }
	 void Clearing()
	 {
		Element* current = head;
		Element* current2 = head;
		while (current != NULL)
		{
			current2 = (current->previous);
			delete current;
			current = current2;
		}
		head = NULL;
		tail = NULL;
		quanity=0;
	 }
}
