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
class Book {
private :
	string title;
	int bookID;
	string author;
	bool isAvailable;
public:
	Book(string t , int id , string a) {
		title = t;
		bookID = id;
		author = a;
		isAvailable = true ;
	}
	void displayBook () {
		cout<<"Book ID : "<<bookID<<endl;
		cout<<"Title : "<<title<<endl;
		cout<<"Author : "<<author<<endl;
		if (isAvailable) 
		    cout<<"Status : Available "<<endl;
		else
		    cout<<"Status : Borrowed "<<endl;
	}
void updateBook(string t) {
	title = t;
	cout<<"Book title update!"<<endl;
}
void updateBook(string t , string a) {
	title =t;
	author =a;
	cout<<"Book title and author update!"<<endl;
}
};
int main() {
	Member m1("Ali",101);
	Librarian l1("Sara",201,"Science");
	Book b1 ("C++ Programming",301,"John Smith");
	m1.displayInfo();
	m1.borrowBook();
	
	l1.displayInfo();
	l1.showSection();
	
	b1.displayBook();
	b1.updateBook("Java Programming");
	b1.displayBook();
	b1.updateBook("Python Programming " , "Mark Smith");
	b1.displayBook();
	
	
	return 0;
}
