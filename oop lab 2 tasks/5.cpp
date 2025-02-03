#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Entity {
    int id;
    string name;
};

bool compareById(const Entity &a, const Entity &b) {
    return a.id < b.id;
}

bool compareByFirstChar(const Entity &a, const Entity &b) {
    return a.name[0] < b.name[0];
}

int main() {
    int N;

    cout << "Enter the number of entities: ";
    cin >> N;

    vector<Entity> entities(N);

    for (int i = 0; i < N; ++i) {
        cout << "Enter ID for entity " << i + 1 << ": ";
        cin >> entities[i].id;
        cin.ignore();
        cout << "Enter Name for entity " << i + 1 << ": ";
        getline(cin, entities[i].name);
    }

    cout << "\nSorting by ID:\n";
    sort(entities.begin(), entities.end(), compareById);
    for (const auto &entity : entities) {
        cout << "ID: " << entity.id << ", Name: " << entity.name << endl;
    }

    cout << "\nSorting by first character of Name:\n";
    sort(entities.begin(), entities.end(), compareByFirstChar);
    for (const auto &entity : entities) {
        cout << "ID: " << entity.id << ", Name: " << entity.name << endl;
    }

    return 0;
}
