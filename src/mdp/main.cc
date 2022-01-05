#include <iostream>

int main(int, const char*[]) {
  auto words = {"Hello, ", "world!", "\n"};
  for (const auto& word : words) {
    std::cout << word;
  }

  return 0;
}
