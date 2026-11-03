#include <iostream>
#include <memory>
#include <queue>

#include "coroutines.h"

using namespace std;

void demo_random_numbers();

int main() {
    demo_random_numbers();
    return 0;
}

void demo_random_numbers() {
    cout << "demo of random_numbers coroutine (with NumberGenerator return type)" << endl;
    auto numbers = make_shared<queue<int>>();
    auto seq = random_numbers(numbers);

    for (int i = 1; i <= 6; i++) {
        seq.resume();
        cout << "Resume " << i << ": ";
        while (!numbers->empty()) {
            cout << numbers->front() << " ";
            numbers->pop();
        }
        cout << endl;
    }
    cout << endl;
}