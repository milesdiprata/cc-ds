#pragma once

#include "mdp/ds/stack.h"

namespace mdp {
namespace ds {

template <typename T>
class StaticStack : public Stack<T> {
 public:
  StaticStack(const std::size_t capacity = Stack<T>::kDefaultCapacity);
  StaticStack(const StaticStack& stack);
  StaticStack(StaticStack&& stack);
  virtual ~StaticStack();

  // Implements Stack<T> ----------------------------------------------------
  void Push(const T& element) override;
  const T Pop() override;
  void Clear() override;
};

template <typename T>
StaticStack<T>::StaticStack(const std::size_t capacity) : Stack<T>(capacity) {}

template <typename T>
StaticStack<T>::StaticStack(const StaticStack& stack) : Stack<T>(stack) {}

template <typename T>
StaticStack<T>::StaticStack(StaticStack&& stack) : Stack<T>(std::move(stack)) {}

template <typename T>
StaticStack<T>::~StaticStack() {}

template <typename T>
inline void StaticStack<T>::Push(const T& element) {
  try {
    Stack<T>::array().PushBack(element);
  } catch (const std::length_error& error) {
    throw typename Stack<T>::OverflowError();
  }
}

template <typename T>
inline const T StaticStack<T>::Pop() {
  try {
    return Stack<T>::array().PopBack();
  } catch (const std::out_of_range& error) {
    throw typename Stack<T>::UnderflowError();
  }
}

template <typename T>
inline void StaticStack<T>::Clear() {
  Stack<T>::array().Clear();
}

}  // namespace ds
}  // namespace mdp
