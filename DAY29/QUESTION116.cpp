#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Product {
private:
    int id;
    std::string name;
    int quantity;
    double price;

public:
    // Constructor
    Product(int p_id, std::string p_name, int p_qty, double p_price)
        : id(p_id), name(p_name), quantity(p_qty), price(p_price) {}

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // Setters
    void setQuantity(int qty) { quantity = qty; }
    void setPrice(double prc) { price = prc; }

    // Display individual product details
    void displayProduct() const {
        std::cout << std::setw(10) << id 
                  << std::setw(20) << name 
                  << std::setw(15) << quantity 
                  << std::setw(15) << std::fixed << std::setprecision(2) << price 
                  << std::setw(15) << (quantity * price) << "\n";
    }
};

class Inventory {
private:
    std::vector<Product> products;
    const int LOW_STOCK_THRESHOLD = 5; // Alert indicator for low items

public:
    // 1. Add a new product
    void addProduct() {
        int id;
        std::string name;
        int qty;
        double price;

        std::cout << "\nEnter Product ID (Integer): ";
        while (!(std::cin >> id)) {
            std::cout << "Invalid input. Enter an integer ID: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        // Check if ID already exists
        for (const auto& prod : products) {
            if (prod.getId() == id) {
                std::cout << "Error: Product ID " << id << " already exists!\n";
                return;
            }
        }

        std::cin.ignore(); // Clear buffer
        std::cout << "Enter Product Name: ";
        std::getline(std::cin, name);

        std::cout << "Enter Quantity: ";
        while (!(std::cin >> qty) || qty < 0) {
            std::cout << "Invalid quantity. Enter a positive integer: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        std::cout << "Enter Price: ";
        while (!(std::cin >> price) || price < 0) {
            std::cout << "Invalid price. Enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        products.push_back(Product(id, name, qty, price));
        std::cout << "Product successfully added!\n";
    }

    // 2. Display all products
    void displayInventory() const {
        if (products.empty()) {
            std::cout << "\nInventory is empty.\n";
            return;
        }

        printHeader();
        double totalInventoryValue = 0;

        for (const auto& prod : products) {
            prod.displayProduct();
            totalInventoryValue += (prod.getQuantity() * prod.getPrice());
        }

        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "Total Portfolio Value: $" << std::fixed << std::setprecision(2) << totalInventoryValue << "\n";
        std::cout << "--------------------------------------------------------------------------------\n";
    }

    // 3. Search product by ID
    void searchProduct() const {
        int id;
        std::cout << "\nEnter Product ID to search: ";
        std::cin >> id;

        for (const auto& prod : products) {
            if (prod.getId() == id) {
                printHeader();
                prod.displayProduct();
                return;
            }
        }
        std::cout << "Product with ID " << id << " not found.\n";
    }

    // 4. Update Product Details
    void updateProduct() {
        int id;
        std::cout << "\nEnter Product ID to update: ";
        std::cin >> id;

        for (auto& prod : products) {
            if (prod.getId() == id) {
                int choice;
                std::cout << "1. Update Quantity\n2. Update Price\nChoose option (1-2): ";
                std::cin >> choice;

                if (choice == 1) {
                    int newQty;
                    std::cout << "Current Quantity: " << prod.getQuantity() << "\nEnter New Quantity: ";
                    std::cin >> newQty;
                    prod.setQuantity(newQty);
                    std::cout << "Quantity updated successfully!\n";
                } else if (choice == 2) {
                    double newPrice;
                    std::cout << "Current Price: $" << prod.getPrice() << "\nEnter New Price: ";
                    std::cin >> newPrice;
                    prod.setPrice(newPrice);
                    std::cout << "Price updated successfully!\n";
                } else {
                    std::cout << "Invalid Option.\n";
                }
                return;
            }
        }
        std::cout << "Product not found.\n";
    }

    // 5. Delete product from tracking
    void deleteProduct() {
        int id;
        std::cout << "\nEnter Product ID to remove: ";
        std::cin >> id;

        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getId() == id) {
                products.erase(it);
                std::cout << "Product removed successfully!\n";
                return;
            }
        }
        std::cout << "Product ID not found.\n";
    }

    // 6. Alert low stock items
    void checkLowStock() const {
        bool lowStockFound = false;
        std::cout << "\n--- Low Stock Alerts (Threshold: < " << LOW_STOCK_THRESHOLD << " items) ---\n";
        
        for (const auto& prod : products) {
            if (prod.getQuantity() < LOW_STOCK_THRESHOLD) {
                std::cout << "⚠️ Warning: " << prod.getName() << " (ID: " << prod.getId() 
                          << ") only has " << prod.getQuantity() << " items left!\n";
                lowStockFound = true;
            }
        }
        if (!lowStockFound) {
            std::cout << "All items are sufficiently stocked.\n";
        }
    }

private:
    void printHeader() const {
        std::cout << "\n--------------------------------------------------------------------------------\n";
        std::cout << std::setw(10) << "Product ID" 
                  << std::setw(20) << "Name" 
                  << std::setw(15) << "Quantity" 
                  << std::setw(15) << "Price ($)" 
                  << std::setw(15) << "Total Value ($)\n";
        std::cout << "--------------------------------------------------------------------------------\n";
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        std::cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. View All Products\n";
        std::cout << "3. Search Product\n";
        std::cout << "4. Update Product Stock/Price\n";
        std::cout << "5. Delete Product\n";
        std::cout << "6. Check Low Stock Items\n";
        std::cout << "7. Exit\n";
        std::cout << "=======================================\n";
        std::cout << "Enter your choice (1-7): ";
        
        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid choice. Please enter a number between 1 and 7: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        switch (choice) {
            case 1: inventory.addProduct(); break;
            case 2: inventory.displayInventory(); break;
            case 3: inventory.searchProduct(); break;
            case 4: inventory.updateProduct(); break;
            case 5: inventory.deleteProduct(); break;
            case 6: inventory.checkLowStock(); break;
            case 7: std::cout << "\nExiting System. Goodbye!\n"; break;
        }
    } while (choice != 7);

    return 0;
}
