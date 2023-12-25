#include <iostream>
#include <vector>
using namespace std;

class AutoService {
public:
    static AutoService& GetInstance() {
        static AutoService instance;
        return instance;
    }

    void AddOrder(const string& customer_name, const string& car_make,
        const string& car_model, const string& service_type) {
        orders_.push_back({ customer_name, car_make, car_model, service_type });
    }

    const vector<Order>& GetOrders() const { return orders_; }

private:
    AutoService() {}
    ~AutoService() {}

    AutoService(const AutoService&) = delete;
    AutoService& operator=(const AutoService&) = delete;

    vector<Order> orders_;
};

class Order {
public:
    Order(const string& customer_name, const string& car_make,
        const string& car_model, const string& service_type)
        : customer_name_(customer_name),
        car_make_(car_make),
        car_model_(car_model),
        service_type_(service_type) {}

    const string& customer_name() const { return customer_name_; }
    const string& car_make() const { return car_make_; }
    const string& car_model() const { return car_model_; }
    const string& service_type() const { return service_type_; }

private:
    string customer_name_;
    string car_make_;
    string car_model_;
    string service_type_;
};

int main() {
    AutoService& auto_service = AutoService::GetInstance();

    auto_service.AddOrder("Hryhorenko", "Toyota", "Corolla", "Oil change");
    auto_service.AddOrder("Lypko", "Lexus", "NX", "Tire rotation");

    for (const Order& order : auto_service.GetOrders()) {
        cout << "Customer name - " << order.customer_name() << endl;
        cout << "Car make - " << order.car_make() << endl;
        cout << "Car model - " << order.car_model() << endl;
        cout << "Service type - " << order.service_type() << endl;
    }

    system("PAUSE");
    return 0;
}
