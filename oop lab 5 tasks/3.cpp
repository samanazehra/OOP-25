#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(string title, string author, string isbn) : title(title), author(author), isbn(isbn) {}

    string getISBN() const {
        return isbn;
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

class Catalog {
private:
    vector<Book*> books;

public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    void removeBook(string isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getISBN() == isbn) {
                books.erase(books.begin() + i);
                return;
            }
        }
    }

    Book* findBook(string isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getISBN() == isbn) {
                return books[i];
            }
        }
        return nullptr;
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "Catalog is empty.\n";
            return;
        }
        cout << "Books in catalog:\n";
        for (int i = 0; i < books.size(); i++) {
            books[i]->display();
        }
    }
};

class Library {
private:
    string name;
    Catalog catalog;
    vector<Book*> books;

public:
    Library(string name) : name(name) {}

    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book);
    }

    void removeBook(string isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getISBN() == isbn) {
                books.erase(books.begin() + i);
                catalog.removeBook(isbn);
                return;
            }
        }
    }

    void findBookInCatalog(string isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            cout << "Book found in catalog:\n";
            book->display();
        } else {
            cout << "Book not found in catalog.\n";
        }
    }

    void listBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "Books in " << name << " Library:\n";
        for (int i = 0; i < books.size(); i++) {
            books[i]->display();
        }
    }
};

int main() {
    Library myLibrary("Central Library");

    Book book1("The Catcher in the Rye", "J.D. Salinger", "978-0316769480");
    Book book2("1984", "George Orwell", "978-0452284234");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    cout << "Library books after adding:\n";
    myLibrary.listBooks();

    cout << "\nSearching for ISBN 978-0452284234:\n";
    myLibrary.findBookInCatalog("978-0452284234");

    cout << "\nRemoving a book:\n";
    myLibrary.removeBook("978-0316769480");
    myLibrary.listBooks();

    return 0;
}
