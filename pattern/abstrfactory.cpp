#include <iostream>
using namespace std;

class IGift {
public:
    virtual void open() const = 0;
};

class CoolGift : public IGift {
public:
    virtual void open() const override {
        cout << "This is so cool!" << std::endl;
    }
};

class MehGift : public IGift {
public:
    virtual void open() const override {
        cout << "Oh.. uhm.. thanks." << std::endl;
    }
};

class IGiftFactory {
public:
    virtual IGift* createGift() const = 0;
};

class CoolGiftFactory : public IGiftFactory {
public:
    virtual IGift* createGift() const override {
        return new CoolGift();
    }
};

class MehGiftFactory : public IGiftFactory {
public:
    virtual IGift* createGift() const override {
        return new MehGift();
    }
};

int main() {
    IGiftFactory* coolGiftFactory = new CoolGiftFactory();

    IGift* coolGift = coolGiftFactory->createGift();
    coolGift->open();

    IGiftFactory* mehGiftFactory = new MehGiftFactory();

    IGift* mehGift = mehGiftFactory->createGift();
    mehGift->open();

    delete coolGift;
    delete mehGift;
    delete coolGiftFactory;
    delete mehGiftFactory;

    return 0;
}
