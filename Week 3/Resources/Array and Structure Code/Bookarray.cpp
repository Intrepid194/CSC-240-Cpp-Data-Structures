#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "book.h"
using namespace std;
// function prototype
void DisplayBooks(const Book[], const int); //const makes the array non-updatable

const int array_size = 10;

int main() {
    Book books[array_size];
    ifstream file("books.txt");

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    int count = 0;

    while (getline(file, line) && count < 10) {
        stringstream ss(line);
        string title, author, pagesStr, priceStr;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, pagesStr, ',');
        getline(ss, priceStr, ',');

        books[count].title = title;
        books[count].author = author;
        books[count].pages = stoi(pagesStr);
        books[count].price = stod(priceStr);

        count++;
    }

    file.close();

    // Display the books
    DisplayBooks(books, array_size);

    return 0;
}
void DisplayBooks(const Book books[], const int array_size)
{
    cout << endl << "Book List - Array Version " << endl << endl;

    for (int i = 0; i < array_size; ++i)
    {
        cout << "Title:       " << books[i].title << endl;
        cout << "Author:      " << books[i].author << endl;
        cout << "No of Pages: " << books[i].pages << endl;
        cout << "Price       $" << books[i].price << endl;
        cout << endl;
    }
}
