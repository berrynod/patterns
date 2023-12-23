#include <iostream>
#include <vector>
using namespace std;

class GiftList {
public:
    static GiftList& getInstance() {
        static GiftList instance;
        return instance;
    }

    void addGift(const string& gift) {
        gifts.push_back(gift);
    }

    vector<string> getGifts() const {
        return gifts;
    }

private:
    GiftList() {}

    vector<string> gifts;
};

int main() {
    GiftList& giftList = GiftList::getInstance();

    giftList.addGift("Kalimba");
    giftList.addGift("Cookies");
    giftList.addGift("Plushie");

    cout << "Gift list: ";
    for (const string& gift : giftList.getGifts()) {
        cout << gift << " ";
    }
    cout << endl;

    system("PAUSE");
    return 0;
}
