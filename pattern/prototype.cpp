#include <iostream>
#include <vector>
using namespace std;

class Gift {
public:
    virtual Gift* clone() const = 0;

    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
};

class Book : public Gift {
public:
    Book(const string& title, double price) : title(title), price(price) {}

    virtual Book* clone() const override {
        return new Book(*this);
    }

    virtual string getName() const override { return title; }
    virtual double getPrice() const override { return price; }

private:
    string title;
    double price;
};

class Plush : public Gift {
public:
    Plush(const string& name, double price) : name(name), price(price) {}

    virtual Plush* clone() const override {
        return new Plush(*this);
    }

    virtual string getName() const override { return name; }
    virtual double getPrice() const override { return price; }

private:
    string name;
    double price;
};

int main() {
    Book dino("\"Dinosaurs. New Vision of a Lost World\" - M. Benton", 389);
    Plush poke("Shinx Sitting Cuties", 11);

    vector<Gift*> gifts;
    gifts.push_back(dino.clone());
    gifts.push_back(poke.clone());

    for (Gift* gift : gifts) {
        cout << gift->getName() << ", " << gift->getPrice() << std::endl;
    }

    return 0;
}

