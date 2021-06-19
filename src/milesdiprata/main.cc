#include <iostream>

#include <milesdiprata/datastructure/stack/dynamic_stack.h>

using namespace std;
using namespace milesdiprata::datastructure;

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto s = DynamicStack<int>();
    for (int i = 0; i < 10; ++i)
        s.Push(i);
    cout << s << " s: " << s.size() << " c: " << s.capacity() << endl;

    s.Push(10);
    cout << s << " s: " << s.size() << " c: " << s.capacity() << endl;

    s.Clear();
    cout << s << " s: " << s.size() << " c: " << s.capacity() << endl;


    // cout << s.Minimum() << ", " << s.Maximum() << endl;

    return 0;
}
