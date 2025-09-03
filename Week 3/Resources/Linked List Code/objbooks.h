#pragma once
#include <iostream>
using namespace std;

class objBook
{
private:
    string title;
    string author;
    int pages;
    double price;

public:
    // Default constructor
    objBook() : title(""), author(""), pages(0), price(0.0) {}

    // Parameterized constructor - you can choose to add data to the object this way 
   /*    objBook(const string& t, const string& a, int p, double pr)
           : title(t), author(a), pages(p), price(pr) {
       }
       */
       // Getters
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    int getPages() const
    {
        return pages;
    }
    double getPrice() const
    {
        return price;
    }

    // Setters
    void setTitle(const string& t)  // string being passed by reference avoids copying it - more efficient
    {
        title = t;
    }
    void setAuthor(const string& a)
    {
        author = a;
    }
    void setPages(int p)
    {
        pages = p;
    }
    void setPrice(double pr)
    {
        price = pr;
    }
};
