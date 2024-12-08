#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Cutie {
public:
    virtual string description() = 0;
    virtual int cuteness_rating() = 0;
    virtual ~Cutie() = default; // Virtual destructor for proper cleanup
};

class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes";
    }
    int cuteness_rating() override {
        return 12;
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A little kitty with big, sad eyes";
    }
    int cuteness_rating() override {
        return 5;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A tiny pygmy marmoset with big, curious eyes";
    }
    int cuteness_rating() override {
        return 11;
    }
};



class Queue {
public:
    Queue();
    int size();
    void add(shared_ptr<Cutie> cutie);
    shared_ptr<Cutie> remove();
private:
    static const int MAX_SIZE = 10;
    shared_ptr<Cutie> queue[MAX_SIZE];
    int currElem;
};
Queue::Queue() : currElem(0) {}
int Queue::size() {
    return currElem;
}
void Queue::add(shared_ptr<Cutie> cutie) {
    if (currElem >= MAX_SIZE) {
        cout << "\nsorry, too big\n";
    } else {
        queue[currElem] = cutie;
        currElem++;
    }
}
shared_ptr<Cutie> Queue::remove() {
    if (currElem == 0) {
        cout << "\nUm... there's nothing in the queue\n";
        return nullptr;
    } else {
        shared_ptr<Cutie> thisElem = queue[0];
        for (int i = 1; i < currElem; i++) {
            queue[i - 1] = queue[i];
        }
        queue[currElem - 1] = nullptr;
        currElem--;
        return thisElem;
    }
}

int main() {
    auto puppy = make_shared<Puppy>();
    auto kitty = make_shared<Kitty>();
    auto marmoset = make_shared<PygmyMarmoset>();

    Queue queue;

    // The size of the queue should equal zero since there are no objects in it
    cout << "Queue size: " << queue.size() << endl;

    // Add the cuties to the queue
    queue.add(puppy);
    queue.add(kitty);
    queue.add(marmoset);

    // The size of the queue should equal three since there are three objects in it
    cout << "Queue size: " << queue.size() << endl;

    // The first dequeue should return the puppy
    auto removed = queue.remove();
    if (removed) cout << "Removed: " << removed->description() << endl;

    // The second dequeue should return the kitty
    removed = queue.remove();
    if (removed) cout << "Removed: " << removed->description() << endl;

    // The third dequeue should return the pygmy marmoset
    removed = queue.remove();
    if (removed) cout << "Removed: " << removed->description() << endl;

    return 0;

}