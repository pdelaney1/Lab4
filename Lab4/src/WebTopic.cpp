#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cctype>
using namespace std;
WebTopic::WebTopic(string filename) {
	file = filename;
	wordlist = new SLL();
	currpriority = 3;
}
void WebTopic::getPriority(string line) {
// determine the current priority, based on the tag that starts the line
//See the header file for more details
	if(line.compare(0,5,"title") || line.compare(0,2,"h1") || line.compare(0,2,"h2")){
		currpriority = 1;
	}
	else if(line.compare(0,2,"h3") || line.compare(0,2,"h4") || line.compare(0,2,"h5") || line.compare(0,2,"h6")){
		currpriority = 2;
	}
	else{
		currpriority = 3;
	}
}
void WebTopic::printPage() {
//Prints out the list of web page words and their priority. You can
//look at my output below to see what mine looks like
	for(int i=1;i<4;i++){
		SNode *tmp = wordlist->first;
		cout << "Priority " << i << ":" <<endl;
		while(tmp->next != NULL){
			if(tmp->priority == i){
				tmp->printNode();
			}
			tmp = tmp->next;
		}
		cout << endl;
		cout << endl;
		delete[] tmp;
	}
}
void WebTopic::ReadFile() {
	ifstream infile(file.c_str(), ios::in); // open file
	string line = "";
	char c;
	while (infile.get(c)) {
		if (c == '<') {
			if (!line.empty()) {
				parseString(line);
				line = "";
			}
		} else if (c == '>') {
			getPriority(line);
			line = "";
		} else {
			line += c;
		}
	}
	cout << endl;
	infile.close();
}
string WebTopic::stripSpace(string s) {
	unsigned int i = 0;
	while (i < s.length()) {
		if (!isalpha(s[i])) {
			s.erase(i);
		}
		i++;
	}
	return s;
}
void WebTopic::parseString(string line) {
	//takes the line and breaks it down into words (separated by space), calls
	//stripSpace to get rid of anything not alphanumeric, and then inserts each
	//word into the list along with its priority
	getPriority(line);
	stripSpace(line);
	string temp;
	for(int i = 0; i<=line.length(); i++){
		if(line[i] != ' '){
			temp = temp + line[i];
		}
		else{
			wordlist->priorityInsert(temp, currpriority);
			temp = "";
		}
	}
	// This should now be a line beginning with the header (ie title, h1, h2, ...)
	// Now needs to find a way to extract the specific words out of the line (string)
	// and make a new SNode as follows
}
