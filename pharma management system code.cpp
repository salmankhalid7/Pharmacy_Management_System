                                             //PHARMACY MANAGEMENT SYSTEM
#include <iostream>
#include <limits>

using namespace std;

const int MAX_MEDICINES = 100;  // Maximum number of medicines
const int MAX_ORDERS = 100;     // Maximum number of orders

struct Pharmacy {
    int id;
    string name;
    int quantity;
    double price;
};

struct Order {              //order ke liya structure
    string medicineName;
    int quantityOrdered;
    double unitPrice;
};

Pharmacy medicines[MAX_MEDICINES];
Order orders[MAX_ORDERS];

int medicinesCount = 0;  // Counter for the number of medicines
int ordersCount = 0;     // Counter for the number of orders

void clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void clearScreenAndShowMenu() {          //screen clear and then show menu
    clearScreen();
    cout << "\tPharmacy Management System   ";
    cout << "\n---------------------------------" << endl;
    cout << "||1. Add Medicine                ||" << endl;
    cout << "||2. Take Order of Medicine      ||" << endl;
    cout << "||3. Display Orders              ||" << endl;
    cout << "||4. Search Medicine             ||" << endl;
    cout << "||5. Delete Medicine             ||" << endl;
    cout << "||6. Show All Medicines          ||" << endl;
    cout << "||7. Exit                        ||" << endl;
    cout << "----------------------------------" << endl;
}

void addMedicine() {                    //medicine add karne ke liye
    while (medicinesCount < MAX_MEDICINES) {
        Pharmacy med;

        // Serial number input handling
        while (true) {
            cout << "SERIAL NO: ";
            cin >> med.id;

            if (cin.fail() || med.id <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout <<"Invalid input!";
				cout<<"\n1.Serial number should be positive integers.";
				cout<<"\n2.Please enter a valid serial number." << endl;
            } else {
                break;
            }
        }
        cout << "Name: ";
        cin.ignore();
        getline(cin, med.name);

        // Quantity input handling
        while (true) {
            cout << "Quantity: ";
            cin >> med.quantity;

            if (cin.fail() || med.quantity < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid quantity." << endl;
            } else {
                break;
            }
        }
        
        // Price input handling
        while (true) {
            cout << "Price: ";
            cin >> med.price;
            
            if (cin.fail() || med.price < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid price." << endl;
            } else {
                break;
            }
        }

        medicines[medicinesCount++] = med;
        cout << "Medicine added successfully." << endl;

        char addMore;
        cout << "Do you want to add more medicines? (y/n): ";
        cin >> addMore;

        if (addMore != 'y' && addMore != 'Y') {
            clearScreenAndShowMenu();
            return;
        }
    }

    cout << "Medicine storage is full. Cannot add more medicines." << endl;
    clearScreenAndShowMenu();
}


void showAllMedicines() {
    if (medicinesCount == 0) {
        cout << "Inventory is empty." << endl;
    } else {
        cout << "\nMedicine Inventory:\n";
        cout << "--------------------------------------\n";
        for (int i = 0; i < medicinesCount; ++i) {
            cout << "Serial: " << medicines[i].id << endl;
            cout << "Name: " << medicines[i].name << endl;
            cout << "Quantity: " << medicines[i].quantity << endl;
            cout << "Price: Rupees " << medicines[i].price << endl;
            cout << "--------------------------------------\n";
        }
    }
}

bool isMedicineAvailable(const string & medicineName, int  quantityOrdered) {     //ye simple bool function h jo ke adwiyat ke availibilty ko check karega
    for (int i = 0; i < medicinesCount; ++i) {
        if (medicineName == medicines[i].name && quantityOrdered <= medicines[i].quantity) {
            return true;
        }
    }
    return false;
}

void placeOrder() {
    showAllMedicines();

    string medicineName;
    int quantityOrdered;
    
    cout << "\nEnter the name of the medicine to order: ";
    cin.ignore();
    getline(cin, medicineName);

    if (!isMedicineAvailable(medicineName, 0)) {
        cout << "Medicine not found in the inventory." << endl;

        char goBack;
        cout << "Do you want to place an order from the following medicines? (y/n): ";
        cin >> goBack;

        if (!(goBack == 'y' || goBack == 'Y')) {
            clearScreen();
            return;
        }

        clearScreenAndShowMenu();
        return;
    }

    cout << "Enter the quantity to order: ";
    cin >> quantityOrdered;

    while (cin.fail() || quantityOrdered <= 0) {
        cout << "Invalid input. Please enter a valid quantity greater than 0." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the quantity to order: ";
        cin >> quantityOrdered;
    }

    bool orderPlaced = false;

    for (int i = 0; i < medicinesCount; ++i) {
        if (medicineName == medicines[i].name && quantityOrdered <= medicines[i].quantity) {
            double unitPrice = medicines[i].price;
            double cost = unitPrice * quantityOrdered;
            
            Order newOrder{medicineName, quantityOrdered, unitPrice};
            orders[ordersCount++] = newOrder;

            medicines[i].quantity -= quantityOrdered;

            cout << "Order placed successfully!" << endl;
            cout << "Total Cost: Rupees " << cost << endl;

            orderPlaced = true;
            break;
        }
    }

    if (!orderPlaced) {
        cout << "Invalid quantity or insufficient stock. Order cannot be placed." << endl;
    }

    char goBack;
    cout << "Do you want to place another order? (y/n): ";
    cin >> goBack;

    if (goBack == 'y' || goBack == 'Y') {
        placeOrder();
    } else {
        clearScreenAndShowMenu();
    }
}


void displayOrders() {                           //orders ko display karne ke liye
    if (ordersCount == 0) {
        cout << "No orders placed yet." << endl;
    } else {
        double totalCost = 0.0;

        cout << "\nOrders:\n";
        cout << "--------------------------------------\n";
        for (int i = 0; i < ordersCount; ++i) {
            cout << "Medicine Name: " << orders[i].medicineName << endl;
            cout << "Quantity Ordered: " << orders[i].quantityOrdered << endl;
            cout << "Unit Price: Rupees " << orders[i].unitPrice << endl;
            cout << "Total Cost: Rupees " << (orders[i].unitPrice * orders[i].quantityOrdered) << endl;
            cout << "--------------------------------------\n";
            
            totalCost += (orders[i].unitPrice * orders[i].quantityOrdered);
        }

        cout << "Overall Total Cost: Rupees " << totalCost << endl;
    }

    char goBack;
    cout << "Do you want to go back to the main menu? (y/n): ";
    cin >> goBack;

    if (!(goBack == 'y' || goBack == 'Y')) {
        clearScreen();
        return;
    }

    clearScreenAndShowMenu();
}
void searchMedicine() {
    string medicineName;
    cout << "Enter the name of the medicine to search: ";
    cin.ignore();
    getline(cin, medicineName);

    bool medicineFound = false;

    for (int i = 0; i < medicinesCount; ++i) {
        if (medicineName == medicines[i].name) {
            cout << "Serial no: " << medicines[i].id << endl;
            cout << "Name: " << medicines[i].name << endl;
            cout << "Quantity: " << medicines[i].quantity << endl;
            cout << "Price: Rupees " << medicines[i].price << endl;

            medicineFound = true;
            break;
        }
    }

    if (!medicineFound) {
        cout << "Medicine not found in the inventory." << endl;
    }

    char goBack;
    cout << "Do you want to go back to the main menu? (y/n): ";
    cin >> goBack;

    if (!(goBack == 'y' || goBack == 'Y')) {
        clearScreen();
        return;
    }

    clearScreenAndShowMenu();
}



void deleteMedicine() {                          //medicine delete ke liye
    cout << "Here is the list of medicines:\n";
    showAllMedicines();
    
    string medicineName;
    cout << "Enter the name of the medicine you want to delete: ";
    cin.ignore();
    getline(cin, medicineName);

    for (int i = 0; i < medicinesCount; ++i) {
        if (medicineName == medicines[i].name) {
        	
            for (int j = i; j < medicinesCount - 1; ++j) {
                medicines[j] = medicines[j + 1];
            }
            medicinesCount--;

            cout << medicineName << " has been deleted from the database." << endl;
            break;
        }
    }

    char goBack;
    cout << "Do you want to go back to the main menu? (y/n): ";
    cin >> goBack;

    if (!(goBack == 'y' || goBack == 'Y')) {
        clearScreen();
        return;
    }

    clearScreenAndShowMenu();
}

void showMedicines() {            //medicine show ke liye
    showAllMedicines();

    char goBack;
    cout << "Do you want to go back to the main menu? (y/n): ";
    cin >> goBack;

    if (!(goBack == 'y' || goBack == 'Y')) {
        clearScreen();
        return;
    }

    clearScreenAndShowMenu();
}

int main() {                                                        //simple min functio ha yahase mera code execute function ke saath execute hoga
    int choice;
    while (true) {                 //simple choice h input k liye
        clearScreenAndShowMenu();
        cout << "Type Here: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                clearScreen();
                cout << "\t\t-<< NOW YOU CAN ADD A NEW MEDICINE >>-" << endl;
                cout << "\nPlease provide the following information:\n";
                addMedicine();
                break;
            case 2:
                clearScreen();
                cout << "-<< \nTAKE ORDER OF MEDICINE >>-" << endl;
                placeOrder();
                break;
            case 3:
                clearScreen();
                cout << "-<< \nDISPLAYING ORDERS >>-" << endl;
                displayOrders();
                break;
            case 4:
                clearScreen();
                cout << "-<< \t\tNOW YOU CAN SEARCH FOR A MEDICINE >>-" << endl;
                searchMedicine();
                break;
            case 5:
                clearScreen();
                cout << "-<< \t\tNOW YOU CAN DELETE A MEDICINE >>-" << endl;
                deleteMedicine();
                break;
            case 6:
                clearScreen();
                cout << "HERE IS THE DATA YOU'VE ENTERED ABOUT THE MEDICINES:" << endl;
                showMedicines();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
    
}
