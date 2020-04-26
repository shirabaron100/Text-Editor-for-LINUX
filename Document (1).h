#include <iostream>
#include <vector>
using namespace std;


class Document{
    public:
        Document();
		~Document();
		void printLineWithNum(int num); //6n
        void printAllTxt(); //%p
        void appendTxt(); //a
        void insertTxt(); //i
		void changeTxt(); //c
        void addLines(int i, int j);//3,4j
        void deleteLine(int line); //d
		void searchF(string text);// /
		void searchB(string text);// ?
		void replaceText(string old , string newT);
		
	
	private:
        vector<string> lines;
        int currentLine = 0;
};