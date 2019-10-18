#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "../includes_usr/fileIO.h"
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	books.clear();
	ifstream myfile;
	myfile.open(filename);
	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	while (getline(myfile, line)) {
			book my_book;
			string title, author, book_id, l_t_p_id, stat;
			int numOne = 0;

			stringstream ss(line);

			getline(ss, book_id, ',');
			my_book.book_id = stoi(book_id);
			getline(ss, title, ',');
			my_book.title = title;
			getline(ss, author, ',');
			my_book.author = author;
			getline(ss, stat, ',');
			numOne = stoi(stat);

			switch (numOne) {
				case 0:
					my_book.state = UNKNOWN;
					break;
				case 1:
					my_book.state = IN;
					break;
				case 2:
					my_book.state = OUT;
					break;
			}
			getline(ss, l_t_p_id, ',');
			my_book.loaned_to_patron_id = stoi(l_t_p_id);

			books.push_back(my_book);
	}
	myfile.close();
	if (books.empty()) {
		return NO_BOOKS_IN_LIBRARY;
	}

	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	int i = 0;
	fstream myfile;
	myfile.open(filename, ios_base::out);
	if (!myfile.is_open()) {return COULD_NOT_OPEN_FILE;}

	while (i < books.size()) {
		myfile << books[i].book_id << "," << books[i].title << "," << books[i].author
		<< "," << books[i].state << "," << books[i].loaned_to_patron_id << endl;
		i++;
	}
	myfile.close();
	if (books.empty()) {
		return NO_BOOKS_IN_LIBRARY;
	}
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	patrons.clear();
	ifstream myfile;
	myfile.open(filename);
	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	while (getline(myfile, line)) {
		patron my_patron;
		string name, pid, num_checkout;
		int numOne = 0, numTwo = 0;

		stringstream ss(line);

		getline(ss, pid, ',');
		my_patron.patron_id = stoi(pid);
		getline(ss, name, ',');
		my_patron.name = name;
		getline(ss, num_checkout, ',');
		my_patron.number_books_checked_out = stoi(num_checkout);

		patrons.push_back(my_patron);
	}
	if (patrons.empty()) {
		return NO_PATRONS_IN_LIBRARY;
	}

	return SUCCESS;

}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	int i = 0;
	ofstream myfile;
	myfile.open(filename);
	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	while(i < patrons.size()) {
		myfile << patrons[i].patron_id << "," << patrons[i].name
		<< "," << patrons[i].number_books_checked_out << endl;
		i++;
	}
	if (patrons.empty()) {
		return NO_BOOKS_IN_LIBRARY;
	}
	return SUCCESS;

}
