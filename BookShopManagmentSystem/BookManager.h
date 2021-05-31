#include <vector>
#include "Book.h"

class BookManager
{
	
public:

	vector<Book> myStore;
	void addBook(Book book);
	void deleteBook(string bookName);
	void updateBook(string bookName);
	void getBook(string bookName);
	void getAll();
	
};
