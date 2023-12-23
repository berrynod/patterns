#include <iostream>
using namespace std;

class Gift {
public:
    Gift(string name, string description) : name_(name), description_(description) {}

    string name() const { return name_; }
    string description() const { return description_; }

private:
    string name_;
    string description_;
};

class GiftFactory {
public:
    virtual Gift* createGift(string name) = 0;
};

class AccsFactory : public GiftFactory {
public:
    Gift* createGift(string name) override {
        if (name == "bracelets") {
            return new Gift("Bracelets", "Hand made!!! >_<");
        }
        else if (name == "choker") {
            return new Gift("Choker", "Vivienne Westwood mini bas relief :o");
        }
        else {
            return nullptr;
        }
    }
};

class BookFactory : public GiftFactory {
public:
    Gift* createGift(std::string name) override {
        if (name == "philoBook") {
            return new Gift("PhiloBook", "\"Meditations\" - Marcus Aurelius");
        }
        else if (name == "fou") {
            return new Gift("Fou", "\"101 Essays that will Change the way You Think\" - Brianna Wiest");
        }
        else {
            return nullptr;
        }
    }
};


int main() {
    GiftFactory* accsFactory = new AccsFactory();
    GiftFactory* bookFactory = new BookFactory();

    Gift* gift1 = accsFactory->createGift("bracelets");
    Gift* gift2 = bookFactory->createGift("fou");

    cout << gift1->name() << ": " << gift1->description() << endl;
    cout << gift2->name() << ": " << gift2->description() << endl;

    delete gift1;
    delete gift2;
    delete accsFactory;
    delete bookFactory;

    system("PAUSE");
    return 0;
}
