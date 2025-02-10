#include <iostream>
#include <string>
using namespace std;
class User
{
public:
    int Age;
    string Name;
};

int main(int argc, char *argv[])
{
    User user;
    user.Name = argv[1];
    user.Age = stoi(argv[2]);

    cout << "My name is " << user.Name << " and I'm " << user.Age << " years old." << endl;

    return 0;
}
