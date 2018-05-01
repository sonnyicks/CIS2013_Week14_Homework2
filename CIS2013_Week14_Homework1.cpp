#include <iostream>
#include <string>
#include <fstream>
#include "ToDo.h"
using namespace std;

int main(){
	char nxt = 'y';
	int len = 0;
	string action;
	
	
	cout << "How long do you want your list?: ";
	cin >> len;
	
	ToDo listing(len);

	//Array of ToDo objects
	//Make sure you have a () constructor 
	
	while (nxt != 'x'){
		
		cout << "Add to list (a)" << endl;
		cout << "Done list item (d)" << endl;
		cout << "Print list (p)" << endl;
		cout << "Exit list app (x)" << endl;
		cout << "What do you want to do: ";
		cin >> nxt;
		// cin.ignore();
		
		switch(nxt){
			case 'a':
			cout << "add...";
			cin.ignore();
			getline(cin, action, '\n');
			listing.add(action);
			break;
			case 'd':
			listing.done();
			break;
			case 'p':
			listing.print();
			break;
			case 'x':
			//all done with list
			break;
			case 'r':
			listing.retrieve();
			break;
			
		}
	}
	return 0;
}