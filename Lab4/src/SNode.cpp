#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

SNode::SNode(string Word, int p){
	word = Word;
	priority = p;
	next = NULL;
}
SNode::~SNode(){
	//Whatever I do with this function it won't work for me
	//Any chance you could try it out Logan?
	word = "";
	priority = 0;
	next = NULL;
}
void SNode::printNode(){
	std::cout << this->word << ":" << this->priority << ", ";
}
