#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {}
    virtual void display() = 0;
    virtual ~Books() {}
};

class Novel : public Books {
private:
    string title;
    string author;
public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << ", Title: " << title << ", Author: " << author << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;
public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << ", Title: " << title << ", Author: " << author << endl;
    }
};

int main() {
    vector<Books*> library;
    library.push_back(new Novel("Pride and Prejudice", "Jane Austen"));
    library.push_back(new Mystery("The Hound of the Baskervilles", "Arthur Conan Doyle"));
    
    for (auto book : library) book->display();
    
    for (auto book : library) delete book;
}
