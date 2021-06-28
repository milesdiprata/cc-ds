#ifndef CC_DS_MILESDIPRATA_DATASTRUCTURE_STATIC_STACK_H_
#define CC_DS_MILESDIPRATA_DATASTRUCTURE_STATIC_STACK_H_

#include "milesdiprata/datastructure/stack/stack.h"

namespace milesdiprata {
namespace datastructure {

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
  return Stack<T>::array().PopBack();
}

template <typename T>
inline void StaticStack<T>::Clear() {
  Stack<T>::array().Clear();
}

}  // namespace datastructure
}  // namespace milesdiprata

#endif  // CC_DS_MILESDIPRATA_DATASTRUCTURE_STATIC_STACK_H_
