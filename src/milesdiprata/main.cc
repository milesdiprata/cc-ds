#include <iostream>

#include <milesdiprata/datastructure/stack/static_range_stack.h>

using namespace std;
using namespace milesdiprata::datastructure;

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    auto s = StaticRangeStack<int>();
    for (int i = 0; i < 10; ++i)
        s.Push(i);
    cout << s << " s: " << s.size() << " c: " << s.capacity() << endl;
    cout << s.Minimum() << ", " << s.Maximum() << endl;

    auto f = StaticRangeStack<int>(s);

    cout << s << " s: " << s.size() << " c: " << s.capacity() << endl;
    cout << s.Minimum() << ", " << s.Maximum() << endl;

    cout << f << " s: " << f.size() << " c: " << f.capacity() << endl;
    cout << f.Minimum() << ", " << f.Maximum() << endl;

    return 0;
}
