#include <iostream>
using namespace std;

class OldClass {
public:
    void DoSomething() {
        cout << "When there is in" << endl;
    }
};

class NewClass {
public:
    void DoSomethingNew() {
        cout << "There is never out" << endl;
    }
};

class Adapter {
public:
    Adapter(OldClass* old_class) : old_class_(old_class) {}

    void DoSomethingNew() {
        old_class_->DoSomething();
    }

private:
    OldClass* old_class_;
};

int main() {
    OldClass old_class;
    Adapter adapter(&old_class);

    adapter.DoSomethingNew();

    system("PAUSE");
    return 0;
}

