#include <iostream>

#include <milesdiprata/datastructure/stack/stack.h>

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto s = milesdiprata::datastructure::Stack<int>();

    for (int i = 0; i < 10; ++i)
        s.Push(i);
    std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    return 0;
}
