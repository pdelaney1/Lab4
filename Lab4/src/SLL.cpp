#include "SLL.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

SLL::SLL(){
	first = NULL;
	last = p2->next;
	p2 = first->next;
	size = 0;
}

SLL::~SLL(){
	SNode *tmp = first;
	while(tmp->next != NULL){
		SNode * tmp2 = tmp->next;
		tmp->~SNode();
		tmp = tmp2;
		delete[] tmp2;
		size -= 1;
	}
	delete [] tmp;
	size -= 1;
}

void SLL::printSLL(){
	SNode *tmp = first;
	cout << "Priority 1: " << endl;
	while(tmp->priority == 1){
		cout << tmp->word << ":" << tmp->priority << ", " <<endl;
		tmp = tmp->next;
	}
	cout << endl;
	cout << endl;
	cout << "Priority 2: " << endl;
	while(tmp->priority == 2){
		cout << tmp->word << ":" << tmp->priority << ", " <<endl;
		tmp = tmp->next;
	}
	cout << endl;
	cout << endl;
	cout << "Priority 3: " << endl;
	while(tmp->priority == 3){
		cout << tmp->word << ":" << tmp->priority << ", " <<endl;
		tmp = tmp->next;
	}
}
void SLL::priorityInsert(string s, int p){
	SNode *tmp = new SNode(s, p);
	if(p == 1){
		addAtFront(tmp);
	}
	else if(p == 2){
		tmp->next = p2->next;
		p2->next = tmp;
		p2 = tmp;
		size += 1;
	}
	else{
		push(tmp);
	}
}
void SLL::push(SNode *n){
	last->next = n;
	n->next = NULL;
	last = n;
	size += 1;
}
void SLL::addAtFront(SNode *n){
	n->next = first;
	n = first;
	size += 1;
}
