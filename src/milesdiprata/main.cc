#include <iostream>

#include "milesdiprata/datastructure/stack/dynamic_stack.h"

int main(const int argc, const char* const argv[]) {
  auto words = {"Hello, ", "world!", "\n"};
  for (const auto& word : words) {
    std::cout << word;
  }

  auto s = milesdiprata::datastructure::DynamicStack<int>();

  for (int i = 0; i < 10; ++i) {
    s.Push(i + 1);
  }

  std::cout << s << "\n";
  s.Push(11);
  std::cout << s << "\n";

  s.Clear();

  std::cout << s << "\n";

  s.Pop();
  std::cout << s << "\n";

  return 0;
}
