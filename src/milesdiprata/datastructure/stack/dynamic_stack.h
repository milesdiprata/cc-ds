#ifndef CC_DS_MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
#define CC_DS_MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_

#include "milesdiprata/datastructure/stack/static_stack.h"

namespace milesdiprata {
namespace datastructure {

template <typename T>
class DynamicStack : public Stack<T> {
 public:
  DynamicStack(const std::size_t capacity = Stack<T>::kDefaultCapacity);
  DynamicStack(const DynamicStack& stack);
  DynamicStack(DynamicStack&& stack);
  virtual ~DynamicStack();

  // Implements Stack<T> ----------------------------------------------------
  void Push(const T& element) override;
  const T Pop() override;
  void Clear() override;

  static constexpr int kCapacityIncreaseFactor = 2;

 protected:
  inline const std::size_t initial_capacity() const {
    return initial_capacity_;
  }

  inline void set_initial_capacity(const std::size_t capacity) {
    initial_capacity_ = capacity;
  }

 private:
  std::size_t initial_capacity_;
};

template <typename T>
DynamicStack<T>::DynamicStack(const std::size_t capacity)
    : Stack<T>(capacity), initial_capacity_(Stack<T>::capacity()) {}

template <typename T>
DynamicStack<T>::DynamicStack(const DynamicStack& stack)
    : Stack<T>(stack), initial_capacity_(stack.initial_capacity_) {}

template <typename T>
DynamicStack<T>::DynamicStack(DynamicStack&& stack)
    : Stack<T>(std::move(stack)),
      initial_capacity_(std::exchange(stack.initial_capacity_, 0)) {}

template <typename T>
DynamicStack<T>::~DynamicStack() {}

template <typename T>
void DynamicStack<T>::Push(const T& element) {
  if (Stack<T>::size() + 1 > Stack<T>::capacity()) {
    Stack<T>::array().Resize(Stack<T>::capacity() * kCapacityIncreaseFactor);
  }

  Stack<T>::array().PushBack(element);
}

template <typename T>
inline const T DynamicStack<T>::Pop() {
  try {
    return Stack<T>::array().PopBack();
  } catch (const std::out_of_range& error) {
    throw typename Stack<T>::UnderflowError();
  }
}

template <typename T>
inline void DynamicStack<T>::Clear() {
  if (Stack<T>::capacity() != initial_capacity_) {
    Stack<T>::array().Resize(initial_capacity_);
  }

  Stack<T>::array().Clear();
}

}  // namespace datastructure
}  // namespace milesdiprata

#endif  // CC_DS_MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
