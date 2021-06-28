#include <iostream>

#include "milesdiprata/datastructure/stack/static_stack.h"

int main(const int argc, const char* const argv[]) {
  auto words = {"Hello, ", "world!", "\n"};
  for (const auto& word : words) {
    std::cout << word;
  }

  auto s = milesdiprata::datastructure::StaticStack<int>();

  for (int i = 0; i < 10; ++i) {
    s.Push(i + 1);
  }

  std::cout << s << "\n";

  for (int i = 0; i < 10; ++i) {
    std::cout << s.Pop() << "\n";
  }

  std::cout << s << "\n";

  s.Pop();

  return 0;
}
