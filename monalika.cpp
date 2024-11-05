#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Product {
    int id;   
    string name;
    double price;
    string manufacturer;
    string expiryDate;
    int quantity;};

struct Customer {
    int id;
    string name;
    string contact;};

struct Supplier {
    int id;
    string name;
    string contact;
    string address;
};

vector<Product> inventory;
vector<Customer> customers;
vector<Supplier> suppliers;

void addOrUpdateProduct() {
    int productId, quantity;
    bool productFound = false;
    Product newProduct;

    cout << "\nEnter Product ID: ";
    cin >> productId;

    for (auto &product : inventory) {
        if (product.id == productId) {
            productFound = true;
            cout << "Product already exists. Enter additional quantity to add: ";
            cin >> quantity;
            product.quantity += quantity;
            cout << "Updated product quantity successfully.\n";
            return;  }  }

    if (!productFound) {
        newProduct.id = productId;
        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, newProduct.name);
        cout << "Enter Price: ";
        cin >> newProduct.price;
        cout << "Enter Manufacturer: ";
        cin.ignore();
        getline(cin, newProduct.manufacturer);
        cout << "Enter Expiry Date (dd-mm-yyyy): ";
        getline(cin, newProduct.expiryDate);
        cout << "Enter Quantity: ";
        cin >> newProduct.quantity;

        inventory.push_back(newProduct);
        cout << "Product added successfully.\n";
    }}

void displayProducts() {
    cout << "\n--- Product Details ---\n";
    cout << "ID\tName\t\tPrice\tManufacturer\tExpiry Date\tQuantity\n";
    for (const auto &product : inventory) {
        cout << product.id << "\t" << product.name << "\t\t" << product.price << "\t" 
             << product.manufacturer << "\t\t" << product.expiryDate << "\t" 
             << product.quantity << "\n";
    }}

void addCustomer() {
    Customer newCustomer;
    cout << "\nEnter Customer ID: ";
    cin >> newCustomer.id;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, newCustomer.name);
    cout << "Enter Contact Information: ";
    getline(cin, newCustomer.contact);

    customers.push_back(newCustomer);
    cout << "Customer added successfully.\n";
}

void displayCustomers() {
    cout << "\n--- Customer Details ---\n";
    cout << "ID\tName\t\tContact\n";
    for (const auto &customer : customers) {
        cout << customer.id << "\t" << customer.name << "\t\t" << customer.contact << "\n";}}

void addSupplier() {
    Supplier newSupplier;
    cout << "\nEnter Supplier ID: ";
    cin >> newSupplier.id;
    cout << "Enter Supplier Name: ";
    cin.ignore();
    getline(cin, newSupplier.name);
    cout << "Enter Contact Information: ";
    getline(cin, newSupplier.contact);
    cout << "Enter Address: ";
    getline(cin, newSupplier.address);

    suppliers.push_back(newSupplier);
    cout << "Supplier added successfully.\n";}

void displaySuppliers() {
    cout << "\n--- Supplier Details ---\n";
    cout << "ID\tName\t\tContact\t\tAddress\n";
    for (const auto &supplier : suppliers) {
        cout << supplier.id << "\t" << supplier.name << "\t\t" << supplier.contact << "\t\t" 
             << supplier.address << "\n";}}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Cosmetic Shop Management System ---\n";
        cout << "1. Add or Update Product\n";
        cout << "2. Display Products\n";
        cout << "3. Add Customer\n";
        cout << "4. Display Customers\n";
        cout << "5. Add Supplier\n";
        cout << "6. Display Suppliers\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addOrUpdateProduct(); break;
            case 2: displayProducts(); break;
            case 3: addCustomer(); break;
            case 4: displayCustomers(); break;
            case 5: addSupplier(); break;
            case 6: displaySuppliers(); break;
            case 7: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}