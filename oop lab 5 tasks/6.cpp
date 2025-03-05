#include <iostream>
#include <vector>

using namespace std;

struct MenuItem {
    string name;
    double price;
    string type;
};

class CoffeeShop {
public:
    const string Name;
    vector<MenuItem> Menu;
    vector<string> orders;

    CoffeeShop(string shopName) : Name(shopName) {}

    void addMenuItem(string name, double price, string type) {
        Menu.push_back({name, price, type});
    }

    string addOrder(string itemName) {
        for (size_t i = 0; i < Menu.size(); i++) {
            if (Menu[i].name == itemName) {
                orders.push_back(itemName);
                return "Order added!";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string fulfilled = orders[0];
            orders.erase(orders.begin());
            return "The " + fulfilled + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (size_t i = 0; i < orders.size(); i++) {
            for (size_t j = 0; j < Menu.size(); j++) {
                if (Menu[j].name == orders[i]) {
                    total += Menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (Menu.empty()) return "No items available!";
        
        MenuItem cheapest = Menu[0];
        for (size_t i = 1; i < Menu.size(); i++) {
            if (Menu[i].price < cheapest.price) {
                cheapest = Menu[i];
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (size_t i = 0; i < Menu.size(); i++) {
            if (Menu[i].type == "drink") {
                drinks.push_back(Menu[i].name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (size_t i = 0; i < Menu.size(); i++) {
            if (Menu[i].type == "food") {
                foods.push_back(Menu[i].name);
            }
        }
        return foods;
    }
};

int main() {
    CoffeeShop myShop("Morning Brew");

    myShop.addMenuItem("Espresso", 3.0, "drink");
    myShop.addMenuItem("Cappuccino", 4.5, "drink");
    myShop.addMenuItem("Muffin", 2.5, "food");
    myShop.addMenuItem("Sandwich", 5.0, "food");
    myShop.addMenuItem("Tea", 2.0, "drink");

    cout << myShop.addOrder("Espresso") << endl;
    cout << myShop.addOrder("Muffin") << endl;
    cout << myShop.addOrder("Pizza") << endl;

    cout << "\nOrders List:\n";
    vector<string> orders = myShop.listOrders();
    for (size_t i = 0; i < orders.size(); i++) {
        cout << orders[i] << endl;
    }

    cout << "\nTotal Due: $" << myShop.dueAmount() << endl;

    cout << "\n" << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;

    cout << "\nCheapest Item: " << myShop.cheapestItem() << endl;

    cout << "\nDrinks Only:\n";
    vector<string> drinks = myShop.drinksOnly();
    for (size_t i = 0; i < drinks.size(); i++) {
        cout << drinks[i] << endl;
    }

    cout << "\nFood Only:\n";
    vector<string> foods = myShop.foodOnly();
    for (size_t i = 0; i < foods.size(); i++) {
        cout << foods[i] << endl;
    }

    return 0;
}
