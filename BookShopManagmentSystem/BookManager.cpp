#include "BookManager.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>



void baseVector(vector<Book>& newManagementVector)
{
	string textData;
	string strBook, strAuthor, strPrice,strStock;

	double uPrice1;
	int uStock1;

	vector<string> temporary;

	fstream file;
	file.open("Books.txt");

	while (getline(file, textData))
	{
		temporary.push_back(textData);
	}
	

	file.close();

	for (int i = 0; i < temporary.size(); i++)
	{
		strBook = temporary[i];
		i ++;

		strAuthor = temporary[i];
		i ++;

		strPrice = temporary[i];
		i++; 

		strStock = temporary[i];

		stringstream convert(strPrice);
		convert >> uPrice1;

		uStock1 = stod(strStock);
		
		Book newBook(strBook, strAuthor, uPrice1,uStock1);
		newManagementVector.push_back(newBook);
	}
}


void addFileBase(vector<Book>& fileVector) {

	fstream file("Books.txt", ios::app | ios::in | ios::out);

	if (!file.is_open())
	{
		cout << "Hatalı dosya..." << endl;

	}
	else
	{
		for(auto book : fileVector)

		file << book.getBookName() << endl << book.getAuthorName() << endl << book.getUnitPrice() << endl << book.getUnitsInStock() << endl;

	}


	file.close();

}


void BookManager::addBook(Book book)
{
	myStore.push_back(book);

	addFileBase(myStore);
	
}

void BookManager::updateBook(string bookName )
{
	vector<Book> updateVector;

	baseVector(updateVector);

	string bName;
	string aName;
	double uPrice;
	int uStock;


	for (int i = 0; i < updateVector.size(); i++)
	{
		if (bookName == updateVector[i].getBookName())
		{

			cout << "Yeni Fiyat Bilgisi: " << endl;
			cin >> uPrice;

			updateVector[i].setUnitPrice(uPrice);

			cout << "Yeni Stok Adedi: " << endl;
			cin >> uStock;

			updateVector[i].setUnitsInStock(uStock);

		}

	}

	remove("Books.txt");

	addFileBase(updateVector);
	
}


void BookManager::deleteBook(string bookName)
{
	vector<Book> deleteVector;

	baseVector(deleteVector);

	for (int i = 0; i < deleteVector.size(); i++)
	{
		if (bookName == deleteVector[i].getBookName())
		{
			deleteVector.erase(deleteVector.begin() + (i));

			remove("Books.txt");
			
		}

	}

	addFileBase(deleteVector);

	
}

void BookManager::getBook(string bookName)
{
	vector<Book> getVector;

	baseVector(getVector);


	for (auto book : getVector) {

		if (bookName == book.getBookName())
		{
			cout << "\nBook Name: " << book.getBookName() << endl;
			cout << "Author Name: " << book.getAuthorName() << endl;
			cout << "Unit Price: " << book.getUnitPrice() << endl;
			cout << "Units In Stock: " << book.getUnitsInStock() << endl;
		}

	}


}

void BookManager::getAll()
{

	vector<Book> bookVector;
	
	baseVector(bookVector);

	cout << "Book Name\t"  "Author Name\t"  "Unit Price\t"  "Unit Stock\n" << endl;
	
	for (auto book : bookVector)
	{
		cout << book.getBookName() + "\t\t" + book.getAuthorName() + "\t\t" << book.getUnitPrice() << "\t\t" << book.getUnitsInStock() << "\t" << endl;
	}
	
	
}


