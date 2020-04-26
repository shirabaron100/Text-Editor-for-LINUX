#pragma once

#include <iostream>
#include "Document.h"
using namespace std;

class Editor {
public:
	Editor();
	~Editor();
	void loop();


private:
	Document* edi;
	string Search;
	bool isNumber(string s);
};
