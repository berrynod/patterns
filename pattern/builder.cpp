#include <iostream>
using namespace std;

class Gift {
public:
    Gift(const string& name, int price, const string& description)
        : name_(name)
        , price_(price)
        , description_(description)
    {}

    const string& name() const { return name_; }
    int price() const { return price_; }
    const string& description() const { return description_; }

private:
    string name_;
    int price_;
    string description_;
};

class Builder {
public:
    Builder() {}

    Builder& withName(const string& name) { name_ = name; return *this; }
    Builder& withPrice(int price) { price_ = price; return *this; }
    Builder& withDescription(const string& description) { description_ = description; return *this; }

    Gift build() { return Gift(name_, price_, description_); }

private:
    string name_;
    int price_;
    string description_;
};

int main() {
    bool Working = true;
    while (Working) {
        int choice;
        cout << "1 - Create gift\n2 - End" << endl; cin >> choice;

        Builder builder;
        Gift product = builder.build();

        switch (choice) {
        case 1:
            builder.withName("Ferrofluid")
                .withPrice(20)
                .withDescription("Cool thing in the bottle :p");

            product = builder.build();

            cout << product.name() << endl;
            cout << product.price() << endl;
            cout << product.description() << endl;
            break;
        case 2:
            cout << "Success" << endl;
            Working = false;
            break;
        default:
            cout << "error" << endl;
            break;
        }
    }


    return 0;
}