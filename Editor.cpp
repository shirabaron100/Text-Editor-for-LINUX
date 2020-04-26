
#include<iostream>
#include <string>
#include "Editor.h"
using namespace std;
Editor::Editor() :edi(new Document()) {}
Editor::~Editor() { delete edi; }
void Editor::loop() {
	int k = 0;
	while (true) {
		string s;
		getline(cin, s);
		if (s.compare("a") == 0){
			edi->appendTxt();
		}
		
		else if((isNumber(s.substr(0,s.find("d"))))&&(s.find("d") != std::string::npos) ){ 
			edi->deleteLine(stoi(s.substr(0,2)));
		}

		else if (s.compare("i") == 0){
			edi->insertTxt();
		}
		else if (s.compare("%p") == 0){
			edi->printAllTxt();
		}
		
		else if (s.compare("/") != 0 && s[0] == '/') {
			Search = s.substr(1);
			edi->searchF(Search);
		}
		
		else if (s[0] == '?'){
			edi->searchB(s.substr(1));
		}
		else if (s.compare("c") == 0){
			edi->changeTxt();
		}
		else if (s[0] == 's' && s[1] == '/'){
			int i = s.find('/');
			string s2 = s.substr(i + 1);
			i = s2.find('/');
			string oldstring = s2.substr(0, i);
	
			string newstring = s2.substr(i + 1);
			newstring=newstring.substr(0,newstring.size()-1);
	
			edi->replaceText(oldstring, newstring);	
		}
		else if(s.length() == 2  && (s[1] == 'n' )) {
			edi->printLineWithNum(stoi(s.substr(0,1)));
		}
		else if(isNumber((s.substr(0,1)))&& s.length()== 4) {
			edi ->addLines(stoi(s.substr(0,1)),stoi(s.substr(2,3)));
		}
		else if (s.compare("Q") == 0){exit(0);}
		
	}
}


bool Editor::isNumber(string s) {
	try {
		int x = stoi(s);
	}
	catch (exception e) { return false; }
	return true;
}
