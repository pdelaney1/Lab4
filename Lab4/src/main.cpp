#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
int main() {
	WebTopic *x = new WebTopic("webpage.html"); //or another web page – I haven’t
	//tested it extensively, but it should work for any basic html page
	x->ReadFile();
	x->printPage();
	return 0;
}
