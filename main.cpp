#include <iostream>
#include <string>
using namespace std;
class Person {
protected :
	string name;
	int id;
public:
	Person (string n , int i ) {
		name = n;
		id = i;
	}
	void displayInfo () {
		cout<<"ID : "<<id<<" , Name : "<<name<<endl;
	}
};
class Member : public Person {
private :
	int borrowedBooks;
public:
	Member(string n , int i) : Person (n,i) {
		borrowedBooks=0; }
	void borrowBook () {
		borrowedBooks++;
		cout<<name<<" borrowed a book . Total : "<<borrowedBooks<<endl;}
};
class Librarian : public Person {
private :
	string section;
public:
	Librarian(string n , int i , string s) : Person (n , i) {
		section = s;
	}
	void showSection(){
		cout<<name<<" works in section : "<<section<<endl; }
};
int main() {
	Member m1("Ali",101);
	Librarian l1("Sara",201,"Science");
	m1.displayInfo();
	m1.borrowBook();
	
	l1.displayInfo();
	l1.showSection();
	
	return 0;
}
