#pragma once
#include <iostream>

using namespace std;

class Book
{
private:

	string bookName;
	string authorName;
	double unitPrice;
	int unitsInStock;

public:

	Book()
	{
		
	}
	
	Book(string bookName,string authorName,double unitPrice,int unitsInStock)
	{

		this->bookName = bookName;
		this->authorName = authorName;
		this->unitPrice = unitPrice;
		this->unitsInStock = unitsInStock;

	}


	string getBookName()
	{
		return this->bookName;
	}

	void setBookName(string bookName)
	{
		this->bookName = bookName;
	}

	string getAuthorName()
	{
		return this->authorName;
	}

	void setAuthorName(string authroName)
	{
		this->authorName = authroName;
	}

	double getUnitPrice()
	{
		return this->unitPrice;
	}

	void setUnitPrice(double unitPrice)
	{
		this->unitPrice = unitPrice;
	}

	int getUnitsInStock()
	{
		return this->unitsInStock;
	}

	void setUnitsInStock(int unitsInStock)
	{
		this->unitsInStock = unitsInStock;
	}

	
};
