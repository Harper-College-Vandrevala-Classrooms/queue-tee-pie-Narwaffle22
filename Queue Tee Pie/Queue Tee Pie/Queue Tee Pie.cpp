#include <iostream>

using namespace std;

class Cutie {
    virtual string description() = 0;
    virtual int cuteness_rating() = 0;
};

class Puppy : public Cutie {
    string description() override {
        return "A little puppy with big, sad eyes";
    }

    int cuteness_rating() override {
        return 11;
    }
};

class Queue {
public:

private:
    Cutie queue[10];
};

int main() {
    cout << "Hello World!\n";
}