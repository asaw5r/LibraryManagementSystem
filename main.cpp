#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
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
	virtual ~Person() { }
	void displayInfo () {
		cout<<"ID : "<<id<<" , Name : "<<name<<endl;
	}
virtual void displayRole () {
	cout<<"I am a Person "<<endl;
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
	virtual void displayRole()  {
	    cout<<"I am a Library Member "<<endl; }
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
	void displayRole()  {
	    cout<<"I am a librarian" <<endl; }
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
	~Book () {
		cout<<"Book object destroyed!"<<endl;
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
	cout<<"Book title updated!"<<endl;
}
void updateBook(string t , string a) {
	title =t;
	author =a;
	cout<<"Book title and author updated!"<<endl;
}
void borrowBook () {
	if (isAvailable) {
		isAvailable=false;
		cout<<"Book borrowed successfully!"<<endl;
	}
	else {
		cout<<"Sorry , Book is already borrowed! "<<endl;
	}
}
void returnBook () {
	if (!isAvailable) {
		isAvailable = true;
		cout<<"Book returned sccessfully ! "<<endl;
	}
	else {
		cout<<"Book is already available! "<<endl;
	}
}
int getBookID (){
	return bookID;
}
void saveToFile(ofstream & file) {
	file<<bookID<<endl;
	file<<title<<endl;
	file<<author<<endl;
	file<<isAvailable<<endl;
}
void loadFromFile (ifstream & file ){
	file>>bookID;
	file.ignore();
	getline(file , title );
	getline(file , author );
	file>>isAvailable;
	file.ignore();
}
};
class Library {
private:
	vector<Book> books;
public:
	void addBook (Book b) {
		for (int i=0 ; i<books.size() ; i++ ) {
			if (books[i].getBookID() == b.getBookID()){
				cout<<"Book ID already exists!"<<endl;
				return ;
			}
		}
		books.push_back(b);
		saveBooks();
		cout<<"Book added to library!"<<endl;
	}
	void displayAllBooks() {
		for (int i=0 ; i<books.size() ; i++){
			books[i].displayBook();
			cout<<"__________________"<<endl;
		}
	}
void searchBook(int id) {
	bool found = false;
	for (int i=0 ; i<books.size() ; i++ ){
		if (books[i].getBookID() == id){
			cout<<"Book Found!"<<endl;
			books[i].displayBook();
			found = true;
			break;
		}
	}
	if (!found){
		cout<<"Book Not Found !"<<endl;
	}
}
void borrowBook (int id) {
	for(int i=0 ; i<books.size() ; i++ ) {
		if(books[i].getBookID() ==id) {
			books[i].borrowBook();
			saveBooks();
			return ;
		}
	}
	cout<<"Book Not Found!"<<endl;
}
void returnBook(int id) {
	for(int i=0 ; i<books.size() ; i++ ) {
		if (books[i].getBookID()==id) {
			books[i].returnBook();
			saveBooks();
			return ;
		}
	}
	cout<<"Book Not Found!"<<endl;
}
void removeBook (int id) {
	for (int i=0 ; i<books.size() ; i++){
		if (books[i].getBookID()==id) {
			books.erase(books.begin() +i );
			saveBooks();
			cout<<"Book removed successfuly!"<<endl;
			return ;
		}
	}
	cout<<"Book Not Found!"<<endl;
}
void saveBooks(){
	ofstream file ("books.txt");
	for (int i=0 ; i<books.size() ; i++ ) {
		books[i].saveToFile(file);
	}
	file.close();
	cout<<"Books saved successfuly! "<<endl;
}
void loadBooks() {
	ifstream file ("books.txt");
	if (!file) {
		cout<<"No saved books found!"<<endl;
		return ;
	}
	books.clear();
	while (file.peek() != EOF ) {
		Book b("" , 0 , "");
		b.loadFromFile(file);
		if (file.fail()) {
			break ;
		}
		books.push_back(b);
	}
	file.close();
	cout<<"Books loaded successfuly!"<<endl;
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
	
	Person* p1 = &m1;
	Person* p2 = &l1;
	
	p1->displayRole();
	p2->displayRole();
	b1.borrowBook();
	b1.displayBook();
	b1.returnBook();
	b1.displayBook();
	
	Library lib;
	lib.loadBooks();
	cout<<"\n All Library Books : \n";
	lib.displayAllBooks();
	
	lib.searchBook(302);
	lib.searchBook(999);
	int choice;
	do {
	cout<<"\n====Library Management sysrem ===="<<endl;
	cout<<"1. Add Book "<<endl;
	cout<<"2. Display All Books "<<endl;
	cout<<"3. Search Book"<<endl;
	cout<<"4. Remove Book "<<endl;
	cout<<"5. Borrow Book "<<endl;
	cout<<"6. Return Book "<<endl;
	cout<<"7. Exit"<<endl;
	
	cout<<"Enter your choice : ";
	cin>>choice;
	
	switch(choice) {
		case 1: {
			string title , author;
			int bookID;
			cout<<"Enter Book ID : ";
			cin>>bookID;
			cin.ignore();
			cout<<"Enter Book Title : ";
			getline(cin , title);
			cout<<"Enter Author Name : ";
			getline(cin , author);
			Book newBook(title , bookID , author);
			lib.addBook(newBook);
			break;
		}
		case 2:
			lib.displayAllBooks();
			break;
		case 3:{
			int id;
			cout<<"Enter Book ID : "<<endl;
			cin>>id;
			lib.searchBook(id);
			break;
	    }
		case 4: {
			int removeID;
			cout<<"Enter Book ID to remove : ";
			cin>>removeID;
			lib.removeBook(removeID);
			break;
		}
		case 5:{
			int id;
			cout<<"Enter Book ID to borrow : ";
			cin>>id;
			lib.borrowBook(id);
			break;
		}
		case 6: {
			int id;
			cout<<"Enter Book ID to return : ";
			cin>>id;
			lib.returnBook(id);
			break;
		}
		case 7:
			lib.saveBooks();
			cout<<"Goodbye!"<<endl;
			break;
		default:
			cout<<"Invalid choice!"<<endl;
	}
}
 while (choice !=7);
	return 0;
}
