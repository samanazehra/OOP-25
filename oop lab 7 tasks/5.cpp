#include <iostream>
#include <vector>
using namespace std;

class Media
{
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isAvailable;

public:
    Media(string t, string pDate, string id, string pub)
    {
        title = t;
        publicationDate = pDate;
        uniqueID = id;
        publisher = pub;
        isAvailable = true;
    }

    virtual void displayInfo() const
    {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << "\nAvailable: " << (isAvailable ? "Yes" : "No") << "\n";
    }

    void checkOut()
    {
        if (isAvailable)
        {
            isAvailable = false;
            cout << title << " has been checked out.\n";
        }
        else
        {
            cout << title << " is currently unavailable.\n";
        }
    }

    void returnItem()
    {
        isAvailable = true;
        cout << title << " has been returned.\n";
    }
};

class Book : public Media
{
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pDate, string id, string pub, string a, string isbn, int pages)
        : Media(t, pDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override
    {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

class DVD : public Media
{
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string t, string pDate, string id, string pub, string d, int dur, string r)
        : Media(t, pDate, id, pub), director(d), duration(dur), rating(r) {}

    void displayInfo() const override
    {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " min\nRating: " << rating << "\n";
    }
};

class CD : public Media
{
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pDate, string id, string pub, string a, int tracks, string g)
        : Media(t, pDate, id, pub), artist(a), numberOfTracks(tracks), genre(g) {}

    void displayInfo() const override
    {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << "\n";
    }
};

class Magazine : public Media
{
private:
    int issueNumber;

public:
    Magazine(string t, string pDate, string id, string pub, int issue)
        : Media(t, pDate, id, pub), issueNumber(issue) {}

    void displayInfo() const override
    {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << "\n";
    }
};

int main()
{
    Book b1("Peer-e-Kamil", "2004", "B001", "Ferozsons", "Umera Ahmed", "978-9690012345", 385);
    DVD d1("Bol", "2011", "D001", "ShoMan Productions", "Shoaib Mansoor", 165, "PG-13");
    CD c1("Junoon: Azadi", "1997", "C001", "EMI Pakistan", "Junoon", 12, "Rock");
    Magazine m1("Herald", "March 2024", "M001", "Dawn Media Group", 330);
    b1.displayInfo();
    d1.displayInfo();
    c1.displayInfo();
    m1.displayInfo();
    b1.checkOut();
    b1.displayInfo();
    b1.returnItem();
    b1.displayInfo();
    return 0;
}