#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

map<string, double> menu;
const string ownerPassword = "1234"; // รหัสผ่านของเจ้าของร้าน

void menudisplay() {
    if (menu.empty()) {
        cout << "\nMenu is empty!\n";
    } else {
        cout << "\n------ Menu ------\n";
        int index = 1;
        for (const auto &item : menu) {
            cout << "[" << index << "] " << item.first << " - $" << fixed << setprecision(2) << item.second << "\n";
            index++;
        }
    }
}

void orderfood() {
    if (menu.empty()) {
        cout << "\nMenu is empty! Cannot place an order.\n";
        return;
    }

    vector<pair<string, int>> order;
    string itemName;
    int quantity;
    char more;

    do {
        cout << "\nEnter the name of the menu item to order: ";
        cin.ignore();
        getline(cin, itemName);

        if (menu.find(itemName) != menu.end()) {
            cout << "Enter quantity: ";
            cin >> quantity;

            order.push_back({itemName, quantity});
            cout << "Added " << quantity << "x " << itemName << " to your order.\n";
        } else {
            cout << "Item not found in the menu!\n";
        }

        cout << "Do you want to order more? (y/n): ";
        cin >> more;
    } while (more == 'y' || more == 'Y');

    cout << "\n------ Your Order ------\n";
    double total = 0;
    for (const auto &item : order) {
        double price = menu[item.first] * item.second;
        cout << item.second << "x " << item.first << " - $" << fixed << setprecision(2) << price << "\n";
        total += price;
    }
    cout << "------------------------\n";
    cout << "Total: $" << fixed << setprecision(2) << total << "\n";
}

void customermode() {
    while (true) {
        char choice;
        cout << "\n-----   Customer Menu  -----";
        cout << "\n--- Please Make a Choice ---\n";
        cout << "[1] View Menu\n";
        cout << "[2] Order Food\n";
        cout << "[3] Search Menu\n";
        cout << "[4] Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case '1': menudisplay(); // ฟังก์ชั่นแสดงหน้าเมนู
            break;
            case '2': "orderfood()"; // ฟังก์ชั่นสั่งอาหาร
            break;
            case '3': "searchmenu()"; // ฟังก์ชั่นค้นหาเมนู
            break;
            case '4': return;
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
}
void addmenuitem() {
    string itemName;
    double itemPrice;

    cout << "\nEnter new menu item name: ";
    cin.ignore(); 
    getline(cin, itemName);

    cout << "Enter price for " << itemName << ": ";
    cin >> itemPrice;

    menu[itemName] = itemPrice;
    cout << itemName << " has been added to the menu with a price of $" << itemPrice << "\n";
}

void removemenuitem() {
    string itemName;
    cout << "\nEnter the name of the menu item to remove: ";
    cin.ignore();
    getline(cin, itemName);

    if (menu.erase(itemName)) { 
        cout << itemName << " has been removed from the menu.\n";
    } else {
        cout << "Item not found!\n";
    }
}

void changeprice() {
    string itemName;
    double newPrice;

    cout << "\nEnter the name of the menu item to change the price: ";
    cin.ignore();
    getline(cin, itemName);

    if (menu.find(itemName) != menu.end()) { 
        cout << "Enter new price for " << itemName << ": ";
        cin >> newPrice;

        menu[itemName] = newPrice; 
        cout << fixed << setprecision(2);
        cout << "Price for " << itemName << " has been updated to $" << newPrice << "\n";
    } else {
        cout << "Item not found!\n";
    }
}

void ownermode() {
    string password;
    cout << "Enter Owner Password: ";
    cin >> password;

    if (password != ownerPassword) {
        cout << "Incorrect password, GET OUT!!!\n";
        return;
    }

    while (true) {
        char choice;
        cout << "\n------   Owner Menu   ------";
        cout << "\n--- Please Make a Choice ---\n";
        cout << "[1] Add menu item\n";
        cout << "[2] Remove menu item\n";
        cout << "[3] Change menu price\n";
        cout << "[4] Exit owner mode\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case '1': addmenuitem(); // เพิ่มเมนู
            break;
            case '2': removemenuitem(); // ลบเมนูออก
            break;
            case '3': changeprice();  // เปลี่ยนราคาอาหาร
            break;
            case '4': return;
            default: cout << "Invalid input! Please try again.\n";
        }
    }
}

int main() {
    while (true) {
        char mode;
        cout << "\n---- Restaurant System -----";
        cout << "\n--- Please Make a Choice ---\n";
        cout << "[1] Customer\n";
        cout << "[2] Owner\n";
        cout << "[3] Exit Program\n";
        cout << "Enter choice: ";
        cin >> mode;

        switch (mode) {
            case '1': customermode();
            break;
            case '2': ownermode(); 
            break;
            case '3': cout << "Exiting program...\n"; 
            return 0;
            default: cout << "Invalid input! Please try again.\n";
        }
    }
}
