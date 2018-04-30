#include <iostream>
#include <string>
#include <fstream>
#include "ToDo.h"
using namespace std;
	
ToDo::ToDo(){

}

int main(){
	char next = 'y';
	int len = 0;
	string action;
	
	
	cout << "How long do you want your list?: ";
	cin >> len;
	
	ToDo list(len);
	list.retrieve();

	//Array of ToDo objects
	//Make sure you have a () constructor 
	
	while (next != 'x'){
		
		cout << "Add to list (a)" << endl;
		cout << "Done list item (d)" << endl;
		cout << "Print list (p)" << endl;
		cout << "Exit list app (x)" << endl;
		cout << "What do you want to do: ";
		cin >> next;
		cin.ignore();
		
		switch(next){
			case 'a':
			cout << "add...";
			getline(cin, action, '\n');
			cout << action;
			list.add(action);
			break;
			case 'd':
			list.done();
			break;
			case 'p':
			list.print();
			break;
			case 'x':
			//all done with list
			break;
			
		}
	}
	return 0;
}