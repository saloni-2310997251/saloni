#include <iostream>
#include <vector>
#include <string>

class MenuItem {
protected:
    std::string name;
    double price;

public:
    MenuItem(const std::string& name, double price) : name(name), price(price) {}

    virtual double calculateCost() const {
        return price;
    }

    virtual void display() const {
        std::cout << name << " - $" << price << std::endl;
    }
};

class FoodItem : public MenuItem {
public:
    FoodItem(const std::string& name, double price) : MenuItem(name, price) {}

    double calculateCost() const override {
      
        return price;
    }
};

class BeverageItem : public MenuItem {
public:
    BeverageItem(const std::string& name, double price) : MenuItem(name, price) {}

    double calculateCost() const override {
        
        return price;
    }
};

class DessertItem : public MenuItem {
public:
    DessertItem(const std::string& name, double price) : MenuItem(name, price) {}

    double calculateCost() const override {
       
        return price;
    }
};

class Order {
private:
    std::vector<MenuItem*> items;

public:
   
    void addItem(MenuItem* item) {
        items.push_back(item);
    }

    double calculateTotalCost() const {
        double totalCost = 0.0;
        for (const auto& item : items) {
            totalCost += item->calculateCost();
        }
        return totalCost;
    }
};

class Bill {
private:
    Order order;

public:
    void addOrder(const Order& newOrder) {
        order = newOrder;
    }

    double calculateTotalBill() const {
        return order.calculateTotalCost();
    }

    void display() const {
        std::cout << "------------------- Bill -------------------" << std::endl;
        std::cout << "Items Ordered:" << std::endl;
       
        for (const auto& item : order.getItems()) {
            item->display();
        }
        std::cout << "Total Amount: $" << calculateTotalBill() << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
    }
};

int main() {
   
    FoodItem burger("Burger", 8.99);
    BeverageItem coke("Coke", 1.99);
    DessertItem iceCream("Ice Cream", 4.50);

    Order customerOrder;
    customerOrder.addItem(&burger);
    customerOrder.addItem(&coke);
    customerOrder.addItem(&iceCream);

    Bill customerBill;
    customerBill.addOrder(customerOrder);

    customerBill.display();

    return 0;
}

