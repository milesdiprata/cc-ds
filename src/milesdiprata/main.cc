#include <iostream>

using namespace std;
using namespace milesdiprata::datastructure;

int main(const int argc, const char* const argv[]) {
    auto words = {"Hello, ", "world!", "\n"};
    for (const auto& word : words) {
        std::cout << word;
    }

    return 0;
}
