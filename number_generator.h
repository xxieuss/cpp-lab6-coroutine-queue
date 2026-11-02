#pragma once
#include <coroutine>
#include <exception>

class NumberGenerator {
public:
    struct promise_type;
    using handle = std::coroutine_handle<promise_type>;

    void resume() { coro.resume(); }

    struct promise_type {
        void unhandled_exception() { std::terminate(); }
        auto initial_suspend() { return std::suspend_always{}; }
        auto final_suspend() noexcept { return std::suspend_always{}; }
        auto get_return_object() {
            return NumberGenerator{handle::from_promise(*this)};
        }
        void return_void() {}
    };

    NumberGenerator(NumberGenerator const &) = delete;
    NumberGenerator &operator=(NumberGenerator const &) = delete;
    NumberGenerator(NumberGenerator &&other) : coro(other.coro) { other.coro = nullptr; }
    ~NumberGenerator() {
        if (coro) coro.destroy();
    }

private:
    NumberGenerator(handle h) : coro(h) {}
    handle coro;
};