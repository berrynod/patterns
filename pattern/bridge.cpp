#include <iostream>
using namespace std;

class Gift {
public:
	virtual void Print() = 0;
};

class Price {
public:
    int price_;

    Price(int price) {
        price_ = price;
    }
};

class Category {
public:
    string category_;

    Category(string category) {
        category_ = category;
    }
};

class Book : public Gift {
private:
    Price* price_;
    Category* category_;

public:
    Book(int price, string category) {
        price_ = new Price(price);
        category_ = new Category(category);
    }

    void Print() override {
        cout << "Book price: " << price_->price_ << endl;
        cout << "Book category: " << category_->category_ << endl;
    }
};

class Toy : public Gift {
private:
    Price* price_;
    Category* category_;

public:
    Toy(int price, string category) {
        price_ = new Price(price);
        category_ = new Category(category);
    }

    void Print() override {
        cout << "Toy price: " << price_->price_ << endl;
        cout << "Toy category: " << category_->category_ << endl;
    }
};

class GiftFactory {
public:
    virtual Gift* CreateGift() = 0;
};

class BookFactory : public GiftFactory {
public:
    Gift* CreateGift() override {
        return new Book(124, "Books");
    }
};

class ToyFactory : public GiftFactory {
public:
    Gift* CreateGift() override {
        return new Toy(14, "Toys");
    }
};

int main() {
    GiftFactory* factory = new BookFactory();
    Gift* gift = factory->CreateGift();

    gift->Print();

    factory = new ToyFactory();
    gift = factory->CreateGift();

    gift->Print();

    system("PAUSE");
    return 0;
}
