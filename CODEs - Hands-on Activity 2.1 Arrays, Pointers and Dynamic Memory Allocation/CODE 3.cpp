
// 3.

#include <iostream>
#include <string>

using namespace std;

// Base class
class GroceryItem {
public:
    virtual ~GroceryItem() {}  // Virtual destructor
    virtual double calculateTotal() const = 0;
    virtual void display() const = 0;
};

// Derived class Fruit
class Fruit : public GroceryItem {
private:
    string itemName;
    double itemPrice;
    int itemQuantity;

public:
    // Constructor
    Fruit(const string& name, double price, int quantity) 
        : itemName(name), itemPrice(price), itemQuantity(quantity) {}

    // Copy Constructor
    Fruit(const Fruit& other) 
        : itemName(other.itemName), itemPrice(other.itemPrice), itemQuantity(other.itemQuantity) {}

    // Copy Assignment Operator
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            itemName = other.itemName;
            itemPrice = other.itemPrice;
            itemQuantity = other.itemQuantity;
        }
        return *this;
    }

    // Destructor
    ~Fruit() override {}

    // Function to calculate total cost
    double calculateTotal() const override {
        return itemPrice * itemQuantity;
    }

    // Function to display details
    void display() const override {
        cout << "Fruit: " << itemName << ", Price: $" << itemPrice << ", Quantity: " << itemQuantity << endl;
    }
};

// Derived class Vegetable
class Vegetable : public GroceryItem {
private:
    string itemName;
    double itemPrice;
    int itemQuantity;

public:
    // Constructor
    Vegetable(const string& name, double price, int quantity) 
        : itemName(name), itemPrice(price), itemQuantity(quantity) {}

    // Copy Constructor
    Vegetable(const Vegetable& other) 
        : itemName(other.itemName), itemPrice(other.itemPrice), itemQuantity(other.itemQuantity) {}

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            itemName = other.itemName;
            itemPrice = other.itemPrice;
            itemQuantity = other.itemQuantity;
        }
        return *this;
    }

    // Destructor
    ~Vegetable() override {}

    // Function to calculate total cost
    double calculateTotal() const override {
        return itemPrice * itemQuantity;
    }

    // Function to display details
    void display() const override {
        cout << "Vegetable: " << itemName << ", Price: $" << itemPrice << ", Quantity: " << itemQuantity << endl;
    }
};

int main() {
    const int LIST_SIZE = 5; // Example size

    // Create a Grocery List
    GroceryItem* groceryList[LIST_SIZE];
    groceryList[0] = new Fruit("Apple", 1.50, 10);
    groceryList[1] = new Vegetable("Carrot", 0.75, 5);
    groceryList[2] = new Fruit("Banana", 1.20, 6);
    groceryList[3] = new Vegetable("Lettuce", 2.00, 1);
    groceryList[4] = new Fruit("Orange", 1.80, 4);

    // Display details about all items
    cout << "Original Grocery List:" << endl;
    for (int i = 0; i < LIST_SIZE; ++i) {
        groceryList[i]->display();
    }

    // Calculate and display total sum
    double totalCost = 0.0;
    for (int i = 0; i < LIST_SIZE; ++i) {
        totalCost += groceryList[i]->calculateTotal();
    }
    cout << "Total Cost: $" << totalCost << endl;

    // Delete Lettuce and deallocate memory
    delete groceryList[3]; // Lettuce
    groceryList[3] = nullptr;

    // Display details about remaining items
    cout << "Updated Grocery List:" << endl;
    for (int i = 0; i < LIST_SIZE; ++i) {
        if (groceryList[i] != nullptr) {
            groceryList[i]->display();
        }
    }

    // Clean up remaining items
    for (int i = 0; i < LIST_SIZE; ++i) {
        if (groceryList[i] != nullptr) {
            delete groceryList[i];
        }
    }

    return 0;
}
