#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

const string ownerPassword = "1234"; // รหัสผ่านของเจ้าของร้าน


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
            case '1': "menu()"; // ฟังก์ชั่นแสดงหน้าเมนู
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
            case '1': "addmenuitem()"; // เพิ่มเมนู
            break;
            case '2': "removemenuitem()"; // ลบเมนูออก
            break;
            case '3': "changeprice()";  // เปลี่ยนราคาอาหาร
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