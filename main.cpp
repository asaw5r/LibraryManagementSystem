#include <iostream>
#include <string>
using namespace std;
class Book {
private:
	string title;
	int id;
public:
	Book(string t , int i) {
		title =t;
		id=i;
		cout<<"Book created : "<<title<<endl;
	}
	~Book () {
		cout<<"Book destroyed : "<<title<<endl;
	}
	string getTitle() {return title ; }
	int getId () {return id; }
};
int main () {
	Book b1("Harry Potter",1);
	Book b2("The Hobbit",2);
	
	cout<<b1.getId()<<" - "<<b1.getTitle()<<endl;
	cout<<b2.getId()<<" - "<<b2.getTitle()<<endl;
	return 0;
}
