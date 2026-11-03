#include "coroutines.h"
#include "odd_awaiter.h"
#include <random>

using namespace std;

NumberGenerator random_numbers(shared_ptr<queue<int>> numbers) {
    mt19937 engine{random_device{}()};
    uniform_int_distribution<int> distribution{1, 256};
    while (true) {
        int number = distribution(engine);
        numbers->push(number);
        co_await OddAwaiter{number};
    }
}