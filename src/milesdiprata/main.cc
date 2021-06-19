#include <iostream>

#include <milesdiprata/datastructure/stack/static_stack.h>

using namespace std;
using namespace milesdiprata::datastructure;

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto s = StaticStack<int>();
    for (int i = 0; i < 10; ++i)
        s.Push(i);
    cout << s << " s: " << s.size() << " c: " << s.capacity() << endl;

    auto f = std::move(s);

    cout << s << " s: " << s.size() << " c: " << s.capacity() << endl;
    cout << f << " s: " << f.size() << " c: " << f.capacity() << endl;

    return 0;
}
