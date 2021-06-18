#include <iostream>

#include <milesdiprata/datastructure/stack/dynamic_range_stack.h>

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto s = milesdiprata::datastructure::DynamicRangeStack<int>(10);

    for (int i = 0; i < 10; ++i)
        s.Push(i);
    std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    std::cout << s.Minimum() << std::endl;
    std::cout << s.Maximum() << std::endl;

    s.Push(10);
    std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    std::cout << s.Minimum() << std::endl;
    std::cout << s.Maximum() << std::endl;

    s.Pop();
    std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    std::cout << s.Minimum() << std::endl;
    std::cout << s.Maximum() << std::endl;

    // std::cout << s.Minimum() << std::endl;
    // std::cout << s.Maximum() << std::endl;

    // for (int i = 12; i < 22; ++i)
    //     s.Push(i);
    // std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    // s.Pop();
    // std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    // s.Clear();
    // std::cout << s << " s: " << s.size() << " c: " << s.capacity() << std::endl;

    return 0;
}
