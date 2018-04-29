#include <iostream>
#include <string>
#include "ToDo.h"
using namespace std;

ToDo::ToDo(int len){
	length = len;
	list = new string[length];
	
}

ToDo::~ToDo(){
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

//HW 2 - Support ToDo Items w/ spaces
//use destructor to save to file
//use constructor to read from file if exists
//choose which ToDo to finish