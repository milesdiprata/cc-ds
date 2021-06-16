#include <iostream>

#include <milesdiprata/datastructure/stack/dynamic_stack.h>
#include <milesdiprata/datastructure/stack/range_stack.h>

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto ds = milesdiprata::datastructure::DynamicStack<int>(2);
    for (int i = 0; i < 5; ++i)
        ds.Push(i);
    while (ds.size())
        std::cout << ds.Pop() << std::endl;

    return 0;
}
