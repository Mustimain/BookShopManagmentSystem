#include <iostream>
#include "Book.h"
#include "BookManager.h"
#include <sstream>
#include <Windows.h>

using namespace std;

class Menu
{
public:
    
	void menu()
	{

	baslangic:

		cout << "*****************************\n" << endl;
		cout << "        HOSGELDINIZ\n" << endl;
		cout << "*****************************\n" << endl;

		cout << "1-) Kitap Ekleme" << endl;
		cout << "2-) Kitap Guncelleme" << endl;
		cout << "3-) Kitap Silme" << endl;
		cout << "4-) Kitap Kontrol" << endl;
		cout << "5-) Kitaplari Listele" << endl;
		cout << "6-) Cikis\n\n" << endl;

		BookManager bookManager;

		cout << "Lutfen Seciminizi Giriniz:  ";
		int secim;
		cin >> secim;

		switch (secim)
		{
		case 1:
		{
			system("cls");

			string bName;
			string aName;
			double uPrice;
			int uStock;

			cout << "Kitap Ismi:  ";
			getline(cin >> ws, bName);
			cout << "Yazar Ismi:  ";
			getline(cin >> ws, aName);
			cout << "Kitap Fiyati:  ";
			cin >> uPrice;
			cout << "Stock Adedi:  ";
			cin >> uStock;

			Book book(bName, aName, uPrice, uStock);

			bookManager.addBook(book);


			cout << book.getBookName() + " adli kitap Basariyla Eklenmistir..." << endl;

			Sleep(1000);
			system("cls");
			goto baslangic;

			break;

		}


		case 2:
		{
			system("cls");

			cout << "Lutfen degistirilecek kitap ismini giriniz: " << endl;

			string bookName;
			cin >> bookName;


			bookManager.updateBook(bookName);
			break;

		}

		case 3: {

			system("cls");

			cout << "Lutfen silinecek kitap ismini giriniz: " << endl;

			string bookName;
			cin >> bookName;


			bookManager.deleteBook(bookName);
			break;
		}


		case 4:
		{
			system("cls");

			cout << "Lutfen aradiginiz kitap ismini giriniz: " << std::endl;

			string bookName;
			cin >> bookName;


			bookManager.getBook(bookName);
			break;

		}

		case 5:
		{
			system("cls");
			bookManager.getAll();
		}

		case 6:
		{
			break;
		}

		default:
		{
			cout << "\nLutfen Gecerli secim giriniz...!";
			Sleep(2000);
			system("cls");

			goto baslangic;
		}
		}
	}

};



int main()
{
	Menu m1;
	m1.menu();
    
}
