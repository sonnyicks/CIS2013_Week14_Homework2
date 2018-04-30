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
	void print_file();
	delete [] list;
}
//add stuff
void ToDo::add(string item){
	if (next<length){
		list[next] = item;
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
	char x;
	int brk = 0;
	ifstream ins;
	
	ins.open("test.dat");
	if(ins.fail()){
		cout << "Unable to open file - Starting new list.";
	}
//Retrieves each line in file as string
//figure out how to save existing list
	for(int i=0; i<length; i++){
		do{
			ins.get(x);
			list[i]+=x;
			if (x=='\n'){
				brk++;
				cout << list[i];} 
		}while((x!='\n')&&(brk<=length));
	}
}

//HW 2 - Support ToDo Items w/ spaces
//use destructor to save to file
//use constructor to read from file if exists
//choose which ToDo to finish