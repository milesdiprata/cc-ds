#include <iostream>

#include <milesdiprata/datastructure/stack/range_stack.h>

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto s = milesdiprata::datastructure::RangeStack<int>(10);

    for (int i = 0; i < 10; ++i)
        s.Push(i);
    std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    std::cout << s.Minimum() << std::endl;
    std::cout << s.Maximum() << std::endl;

    s.Pop();

    std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;
    std::cout << s.Minimum() << std::endl;
    std::cout << s.Maximum() << std::endl;

    return 0;
}
