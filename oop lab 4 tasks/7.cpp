#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
    Book(string author, string title, double price, string publisher, int stock) {
        this->author = author;
        this->title = title;
        this->price = price;
        this->publisher = publisher;
        this->stock = stock;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }

    int getStock() const {
        return stock;
    }

    void setStock(int newStock) {
        stock = newStock;
    }

    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << endl;
    }
};

class BookStore {
private:
    vector<Book> inventory;

public:
    void addBook(const Book& book) {
        inventory.push_back(book);
    }

    void searchBook(const string& title, const string& author) {
        bool found = false;

        for (auto& book : inventory) {
            if (book.getTitle() == title && book.getAuthor() == author) {
                found = true;
                book.displayBookDetails();

                int requestedCopies;
                cout << "Enter number of copies required: ";
                cin >> requestedCopies;

                if (requestedCopies <= book.getStock()) {
                    double totalCost = requestedCopies * book.getPrice();
                    cout << "Total cost for " << requestedCopies << " copies: $" << totalCost << endl;
                    book.setStock(book.getStock() - requestedCopies);
                } else {
                    cout << "Required copies not in stock." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Book not available in stock." << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    string author = argv[1];
    string title = argv[2];
    double price = atof(argv[3]);
    string publisher = argv[4];
    int quantity = atoi(argv[5]);
    BookStore store;
    store.addBook(Book(author, title, price, publisher, quantity));
    store.searchBook(title, author);
    return 0;
}
