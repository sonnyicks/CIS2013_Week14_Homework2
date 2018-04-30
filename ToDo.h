#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ToDo{
	private:
	
		string *list;
		int length = 0;
		int next = 0;
		ifstream ins;
		ofstream out;
	
	public:
	
		//Default constructor 
		ToDo();
	
		//create list of length l
		ToDo(int len);
		
		//Destroy out list
		~ToDo();
		
		//add item to list
		void add(string i);
		
		//completed and removes
		void done();
		
		//print list
		void print();
		
		void print_file();
		
		void openstream();
		
		void retrieve();
		
		void file();
};