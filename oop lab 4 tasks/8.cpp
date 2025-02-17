#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class MenuItem {
public:
    string item;
    string type;
    double price;

    MenuItem(string item, string type, double price) {
        this->item = item;
        this->type = type;
        this->price = price;
    }
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName) {
        name = shopName;
    }

    void addMenuItem(string item, string type, double price) {
        menu.push_back(MenuItem(item, type, price));
    }

    void addOrder(string itemName) {
        bool itemFound = false;
        for (const auto& menuItem : menu) {
            if (menuItem.item == itemName) {
                orders.push_back(itemName);
                itemFound = true;
                break;
            }
        }
        if (!itemFound) {
            cout << "This item is currently unavailable" << endl;
        }
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        } else {
            return "All orders have been fulfilled";
        }
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& menuItem : menu) {
                if (menuItem.item == order) {
                    total += menuItem.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items in menu";

        MenuItem cheapest = menu[0];
        for (const auto& menuItem : menu) {
            if (menuItem.price < cheapest.price) {
                cheapest = menuItem;
            }
        }
        return cheapest.item;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& menuItem : menu) {
            if (menuItem.type == "drink") {
                drinks.push_back(menuItem.item);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (const auto& menuItem : menu) {
            if (menuItem.type == "food") {
                food.push_back(menuItem.item);
            }
        }
        return food;
    }
};

int main(int argc, char* argv[]) {
    string shopName = argv[1];
    CoffeeShop shop(shopName);

    for (int i = 2; i < argc; i += 3) {
        string item = argv[i];
        string type = argv[i + 1];
        double price = atof(argv[i + 2]);
        shop.addMenuItem(item, type, price);
    }

    string orderItem = argv[argc - 3];
    shop.addOrder(orderItem);

    cout << shop.fulfillOrder() << endl;
    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks only: ";
    for (const auto& drink : drinks) {
        cout << drink << " ";
    }
    cout << endl;

    vector<string> food = shop.foodOnly();
    cout << "Food only: ";
    for (const auto& foodItem : food) {
        cout << foodItem << " ";
    }
    cout << endl;

    return 0;
}
