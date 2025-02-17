#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string partNum, string partDesc, int qty, double price) {
        partNumber = partNum;
        partDescription = partDesc;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0) ? price : 0.0;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

    string getPartNumber() const {
        return partNumber;
    }

    string getPartDescription() const {
        return partDescription;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPricePerItem() const {
        return pricePerItem;
    }
};

int main(int argc, char* argv[]) {
    string partNumber = argv[1];
    string partDescription = argv[2];
    int quantity = atoi(argv[3]);
    double pricePerItem = atof(argv[4]);
    Invoice invoice(partNumber, partDescription, quantity, pricePerItem);
    cout << "Part Number: " << invoice.getPartNumber() << endl;
    cout << "Part Description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per Item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice Amount: $" << invoice.getInvoiceAmount() << endl;
    return 0;
}