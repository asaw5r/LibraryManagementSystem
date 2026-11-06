#include <iostream>
#include <string>
using namespace std;
class Book {
	string title;
	int id;
public:
	void setTitle (string t ) { title = t;}
	string getTitle () { return title ;}
	void setId (int i) {id = i ; }
	int getId () {return id ; }
};
int main () {
	Book b1;
	b1.setTitle("Harry Potter");
	b1.setId(1);
	
	cout<<b1.getId() << " - "<<b1.getTitle() <<endl;
	return 0;
}
