#include <iostream>

#include <milesdiprata/datastructure/stack/stack.h>

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto s = milesdiprata::datastructure::Stack<int>();
    s.Pop();

    return 0;
}
