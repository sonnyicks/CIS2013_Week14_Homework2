#include <iostream>
#include <string>
#include <fstream>
#include "ToDo.h"
using namespace std;

ToDo::ToDo(int len){
	length = len;
	list = new string[length];
	retrieve();
}

ToDo::~ToDo(){
	print_file();
	cout << "Saving..." << endl;
	delete [] list;
}
//add stuff
void ToDo::add(string i){
	if (next<length){
		list[next] = i;
		next++;
	}
}
		
//completed stuff
void ToDo::done(){
	int rmv=0;
	cout << "Enter the number of the finished task: ";
	cin >> rmv;
	next--;
	//move the items up the list
	for (int i=rmv; i<=next; i++){
		list[i-1]=list[i];
	}
	list[next] = "";
}
		
//print stuff
void ToDo::print(){
	for(int i=0; i<next; i++){
		cout << i+1 << ". " << list[i] << endl;
	}	
	cout << endl;
}

void ToDo::print_file(){
	out.open("savedlist.dat");
	if (out.fail()){
		cout << "Save failed -" << endl;
	}
	for (int i=0; i<=next; i++){
		out << list[i] << endl;
	}
	out.close();
}

void ToDo::retrieve(){ 
	ifstream ins;
	string a;
	
	ins.open("savedlist.dat");
	if(ins.fail()){
		cout << "Unable to open file - Starting new list. \n";
	}
	else{
		cout << "Saved list found. Importing..." << endl;
		for(int i=0; i<=length; i++){
			while(!ins.eof()){
				getline(ins, a);
				add(a);
			}
		}
		print();
		ins.close();
	}
}

//HW 2 - Support ToDo Items w/ spaces
//use destructor to save to file
//use constructor to read from file if exists
//choose which ToDo to finish