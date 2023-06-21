/*****************************************************************//**
 * file : DataBase.cpp
 * Author : 陳彥儒
 * Create date : June 7, 2023
 * Last update : June 7, 2023
 * Description : DataBase.cpp
 *********************************************************************/
#include "DataBase.h"

 // Initial the dataBase container
vector<Book> DataBase::dataBase;

/**
 * Intent :	The insert function to insert the book to the dataBase
 * pre : None
 * post : store the data
 * \param title
 * \param author
 * \param edition
 */
void DataBase::insert(const string& title, const string& author, const int& edition)
{
	// Create a new book with title author and edition
	Book newBook(title, author, edition);
	if (std::count(begin(DataBase::dataBase), end(DataBase::dataBase), newBook)) throw "Datum already exist.\n"; // If the book is already exist then throw a error message

	DataBase::dataBase.push_back(newBook); // store the new book

	// Print the insert succesful message
	cout << "Insert " << newBook.getAuthor() << "'s " << newBook.getTitle()
		<< ", Edition: " << newBook.getEdition() << ".\n";

}

/**
 * Intent : delete book with all edition
 * pre : None
 * post : Delete the book with title abd the author
 * \param title
 * \param author
 */
void DataBase::deleted(const string& title, const string& author)
{
	bool hasBook = false; // Declare there had a book
	for (auto current = DataBase::dataBase.begin(); current != end(DataBase::dataBase);) {
		// Check if the book is exist and delete it then set the hasBook be true
		if ((*current).getTitle() == title && (*current).getAuthor() == author) {
			// delete the book and go next index
			current = DataBase::dataBase.erase(current);
			hasBook = true;
		}
		else current++;
	}

	// if there has no book then throw the error message
	if (!hasBook) throw "Book doesn't exist.\n";
	else cout << "Delete " << author << "'s " << title << ".\n"; // print the delete sucessful message
}

/**
 * Intent :	delete the book with edition
 * pre : none
 * post : delete the book with the title, author and edition
 * \param title
 * \param author
 * \param edition
 */
void DataBase::deleted(const string& title, const string& author, const int& edition)
{
	// Create a target book with with title, author and edition
	Book targetBook(title, author, edition);
	// If the book has not exist then throw an error message
	if (std::find(begin(DataBase::dataBase), end(DataBase::dataBase), targetBook) == DataBase::dataBase.end()) throw "Datum doesn't exist.\n";
	else
	{
		// use for loop to delete the target book
		for (auto current = DataBase::dataBase.begin(); current != DataBase::dataBase.end(); current++) {
			if ((*current) == targetBook) {
				DataBase::dataBase.erase(current);
				break;
			}
		}

		// print the delete successful message
		cout << "Delete " << author << "'s " << title << ", Edition: " << edition << ".\n";
	}
}

/**
 * Intent : find book
 * pre : none
 * post : print the all book information
 * \param title
 * \param author
 */
void DataBase::find(const string& title, const string& author)
{
	// use a vector to store the edition
	vector<int> editions;
	for (const auto& book : DataBase::dataBase) {
		// find the book and record the edition of the book
		if (book.getTitle() == title && book.getAuthor() == author) {
			editions.push_back(book.getEdition());
		}
	}
	sort(begin(editions), end(editions)); // sort the edition 

	// if the edition vector is empty then throw an error message
	if (!editions.size()) throw "Book doesn't exist.\n";
	else {
		// Print the message of the title author and the edition
		cout << "Title: " << title << '\t'
			<< "Author: " << author << '\t'
			<< "Edition: ";
		// print the editions use ',' to separate the edition
		for (int i = 0; i < editions.size(); i++) {
			cout << editions[i];
			if (i != editions.size() - 1) cout << ", ";
			else cout << '\n';
		}
	}
}

/**
 * Intent : find author
 * pre : none
 * post : print the all author's book
 * \param author
 */
void DataBase::find(const string& author)
{
	// use a string vector to store the titles
	vector<string> titles;
	// find the book with the author and record the title and store to the string vector
	for (const auto& book : DataBase::dataBase) {
		if (book.getAuthor() == author) {
			titles.push_back(book.getTitle());
		}
	}
	sort(begin(titles), end(titles));

	if (!titles.size()) throw "No book found.\n";
	else
	{
		cout << author << "'s Books: ";
		for (int i = 0; i < titles.size(); i++) {
			cout << titles[i];
			if (i != titles.size() - 1) cout << ", ";
			else cout << '\n';
		}
	}
}

void DataBase::sortByTitle()
{
	set<pair<string, string>> hasFind;

	sort(begin(DataBase::dataBase), end(DataBase::dataBase), [](const Book& a, const Book& b)
		{
			if (a.getTitle() == b.getTitle()) {
				return (a.getAuthor() < b.getAuthor());
			}
			else return (a.getTitle() < b.getTitle());
		});

	for (const auto& book : DataBase::dataBase) {
		if (!hasFind.count({ book.getTitle(), book.getAuthor() })) {
			DataBase::find(book.getTitle(), book.getAuthor());
			hasFind.insert({ book.getTitle(), book.getAuthor() });
		}
	}
}

void DataBase::sortByAuthor()
{
	set<pair<string, string>> hasFind;

	sort(begin(DataBase::dataBase), end(DataBase::dataBase), [](const Book& a, const Book& b)
		{
			if (a.getAuthor() == b.getAuthor()) {
				return (a.getTitle() < b.getTitle());
			}
			else return (a.getAuthor() < b.getAuthor());
		});

	for (const auto& book : DataBase::dataBase) {
		if (!hasFind.count({ book.getTitle(), book.getAuthor() })) {
			DataBase::find(book.getTitle(), book.getAuthor());
			hasFind.insert({ book.getTitle(), book.getAuthor() });
		}
	}
}
