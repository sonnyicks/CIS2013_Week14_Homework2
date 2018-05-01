#include <iostream>
#include <string>
#include <fstream>
#include "ToDo.h"
using namespace std;

ToDo::ToDo(int len){
	length = len;
	list = new string[length];
}

ToDo::~ToDo(){
	// void print_file();
	delete [] list;
}
//add stuff
void ToDo::add(string i){
	if (next<length){
		// cin.ignore();
		// getline(i, '\n');
		list[next] = i;
		next++;
	}
}
		
//completed stuff
void ToDo::done(){
	next--;
	list[next] = "";
}
		
//print stuff
void ToDo::print(){
	for(int i=0; i<next; i++){
		cout << " * " << list[i] << endl;
	}		
}

void ToDo::print_file(){
	out.open("test.dat");
	for (int i=0; i<=length; i++){
		out << list[i] << endl;
	}
}

void ToDo::retrieve(){ 
	ifstream ins;
	string a;
	
	ins.open("test.dat");
	if(ins.fail()){
		cout << "Unable to open file - Starting new list.";
	}
	for(int i=0; i<=length; i++){
		while(!ins.eof()){
			getline(ins, a);
			cout << a << endl;
			// list[i]=a;
			add(a);
		}
	}
	ins.close();
}

//HW 2 - Support ToDo Items w/ spaces
//use destructor to save to file
//use constructor to read from file if exists
//choose which ToDo to finish