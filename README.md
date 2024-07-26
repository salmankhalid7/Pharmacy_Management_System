                                                # Pharmacy Management System



This is a simple Pharmacy Management System implemented in C++. It allows users to add, search, delete medicines, place orders, and display all orders and medicines in the inventory.

## Features

- **Add Medicine**: Add new medicines to the inventory with details such as serial number, name, quantity, and price.
- **Take Order of Medicine**: Place orders for available medicines.
- **Display Orders**: Show all the placed orders along with their details.
- **Search Medicine**: Search for medicines by name in the inventory.
- **Delete Medicine**: Remove medicines from the inventory.
- **Show All Medicines**: Display all the medicines available in the inventory.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- A terminal or command prompt

### Running the Program

1. **Clone the Repository:**
    ```sh
    git clone https://github.com/your-username/pharmacy-management-system.git
    cd pharmacy-management-system
    ```

2. **Compile the Program:**
    ```sh
    g++ -o pharmacy_management_system main.cpp
    ```

3. **Run the Program:**
    ```sh
    ./pharmacy_management_system
    ```

## Usage

Upon running the program, the main menu will be displayed with the following options:

1. **Add Medicine**: Add new medicines to the inventory.
2. **Take Order of Medicine**: Place an order for medicines from the inventory.
3. **Display Orders**: Display all the placed orders.
4. **Search Medicine**: Search for a specific medicine in the inventory.
5. **Delete Medicine**: Delete a medicine from the inventory.
6. **Show All Medicines**: Show all medicines in the inventory.
7. **Exit**: Exit the program.

## Code Overview

The program consists of the following main parts:

- **Structures**:
  - `Pharmacy`: Represents a medicine with `id`, `name`, `quantity`, and `price`.
  - `Order`: Represents an order with `medicineName`, `quantityOrdered`, and `unitPrice`.

- **Functions**:
  - `clearScreen()`: Clears the console screen.
  - `clearScreenAndShowMenu()`: Clears the console screen and shows the main menu.
  - `addMedicine()`: Adds a new medicine to the inventory.
  - `showAllMedicines()`: Displays all medicines in the inventory.
  - `isMedicineAvailable()`: Checks if a medicine is available in the inventory.
  - `placeOrder()`: Places an order for a medicine.
  - `displayOrders()`: Displays all placed orders.
  - `searchMedicine()`: Searches for a medicine in the inventory.
  - `deleteMedicine()`: Deletes a medicine from the inventory.
  - `showMedicines()`: Shows all medicines in the inventory.

- **Main Function**:
  - The `main()` function serves as the entry point of the program, displaying the menu and handling user input.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project was developed as a part of learning C++ programming and data structures.

## Contact

If you have any questions or feedback, feel free to reach out:

- **Email**: [M.SALMANKHALID123@GMAIL.COM](mailto:your.M.SALMANKHALID123@GMAIL.COM)
- **GitHub**: [SALMANKHALID7](https://github.com/SALMANKHALID7)

---
