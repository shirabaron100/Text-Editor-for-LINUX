#include "Document.h"

Document::Document() :currentLine(0) { lines.clear(); }
Document::~Document() {}


void Document::printAllTxt(){ //%p    
    for(int i = 0; i < lines.size(); i++){
        cout << lines[i] << endl;
    }
}

void Document::printLineWithNum(int n) {
	cout <<to_string(n) << "\t" << lines.at(n-1) << endl; 
    currentLine = n;
}

void Document::appendTxt(){ 
    bool txt = true;
    string s;
    while(txt){
        getline(cin, s);
        if(s.length() == 1 && s.at(0) == '.'){
            txt = false;
        }
        else{
            lines.insert(lines.begin()+currentLine, s);
            currentLine++;
        }
    }
}
void Document::addLines(int i, int j)//3,4j
{	
	lines.at(i-1) = lines.at(i-1) + lines.at(j-1);;
	lines.erase(lines.begin() + j - 1);
	currentLine = i;
	
}

void Document::insertTxt(){ //i
	
    bool txt = true;
  	string s;

    while(txt){
        std::getline(std::cin, s);
		
        if(s.length() == 1 && s.at(0) == '.'){
            txt = false;
        }
        else{
            lines.insert(lines.begin()+currentLine-1, s);
            currentLine++;
        }
    }
}



void Document::changeTxt(){ //c
	
    bool txt = true;
    string s;
    getline(cin, lines[currentLine-1]);
	
    while(txt){
		string s;
        getline(std::cin, s);
        if(s.length() == 1 && s.at(0) == '.'){
            txt = false;
        }
        else{
            lines.insert(lines.begin()+currentLine, s); //or -1?
            currentLine++;
        }
    }
}

void Document::deleteLine(int line){ 
    
    lines.erase(lines.begin()+line-1);
    
}



void Document::searchF(string text) {
	bool run = false;
	int index;
	for (int i = currentLine -1;i < lines.size()&&!run;i++) {
		index = lines.at(i).find(text);
		if (index != string::npos) {
			currentLine = i+1;
			cout << lines.at(i) << endl;
			run = true;
		}
	}
	if (!run) {
		currentLine = lines.size();
	}
}
void Document::searchB(string text) {
	bool run = false;
	int pos;
	for (int i = currentLine -2;i > 0;i--) {
		pos = lines.at(i).find(text);
		if (pos != std::string::npos) {
			currentLine = i + 1;
			cout << lines.at(i) << endl;
			run = true;
		}
	}
	if (!run) {
			currentLine = 0;
	}
}
void Document::replaceText(string old , string newT) {
	size_t index = 0;
	index = lines.at(currentLine-1).find(old, index);
	if (index != std::string::npos)
		lines.at(currentLine-1).replace(index, old.length(), newT);
}