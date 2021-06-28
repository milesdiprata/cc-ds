#include <iostream>

#include "milesdiprata/datastructure/stack/static_range_stack.h"

int main(const int argc, const char* const argv[]) {
  auto words = {"Hello, ", "world!", "\n"};
  for (const auto& word : words) {
    std::cout << word;
  }

  auto s = milesdiprata::datastructure::StaticRangeStack<int>();

  for (int i = 0; i < 10; ++i) {
    s.Push(i + 1);
  }
  std::cout << s.Maximum() << "\n";
  std::cout << s.Minimum() << "\n";
  std::cout << s << "\n";

  s.Pop();
  std::cout << s.Maximum() << "\n";
  std::cout << s.Minimum() << "\n";
  std::cout << s << "\n";

  s.Pop();
  std::cout << s.Maximum() << "\n";
  std::cout << s.Minimum() << "\n";
  std::cout << s << "\n";

  std::cout << s << "\n";

  s.Clear();

  std::cout << s << "\n";

  s.Pop();
  std::cout << s << "\n";

  return 0;
}
