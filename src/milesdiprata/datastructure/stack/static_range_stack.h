#ifndef CC_DS_MILESDIPRATA_DATASTRUCTURE_STATIC_RANGE_STACK_H_
#define CC_DS_MILESDIPRATA_DATASTRUCTURE_STATIC_RANGE_STACK_H_

#include "milesdiprata/datastructure/stack/static_stack.h"

namespace milesdiprata {
namespace datastructure {

template <typename T>
class StaticRangeStack : public StaticStack<T> {
 public:
  StaticRangeStack(const size_t capacity = Stack<T>::kDefaultCapacity);
  StaticRangeStack(const StaticRangeStack& stack);
  StaticRangeStack(StaticRangeStack&& stack);
  virtual ~StaticRangeStack();

  const T& Minimum() const;
  const T& Maximum() const;

  // Implements Stack<T> ----------------------------------------------------
  void Push(const T& element) override;
  const T Pop() override;
  void Clear() override;

 private:
  typename Stack<T>::DynamicArray minimum_array_;
  typename Stack<T>::DynamicArray maximum_array_;
};

template <typename T>
StaticRangeStack<T>::StaticRangeStack(const size_t capacity)
    : StaticStack<T>(capacity),
      minimum_array_(capacity),
      maximum_array_(capacity) {}

template <typename T>
StaticRangeStack<T>::StaticRangeStack(const StaticRangeStack& stack)
    : StaticStack<T>(stack),
      minimum_array_(stack.minimum_array_),
      maximum_array_(stack.maximum_array_) {}

template <typename T>
StaticRangeStack<T>::StaticRangeStack(StaticRangeStack&& stack)
    : StaticStack<T>(std::move(stack)),
      minimum_array_(std::move(stack.minimum_array_)),
      maximum_array_(std::move(stack.maximum_array_)) {}

template <typename T>
StaticRangeStack<T>::~StaticRangeStack() {}

template <typename T>
inline const T& StaticRangeStack<T>::Minimum() const {
  try {
    return minimum_array_.Back();
  } catch (const std::out_of_range& error) {
    throw typename Stack<T>::UnderflowError();
  }
}

template <typename T>
inline const T& StaticRangeStack<T>::Maximum() const {
  try {
    return maximum_array_.Back();
  } catch (const std::out_of_range& error) {
    throw typename Stack<T>::UnderflowError();
  }
}

template <typename T>
inline void StaticRangeStack<T>::Push(const T& element) {
  StaticStack<T>::Push(element);
  if (minimum_array_.Empty() || element < minimum_array_.Back()) {
    minimum_array_.PushBack(element);
  }
  if (maximum_array_.Empty() || element > maximum_array_.Back()) {
    maximum_array_.PushBack(element);
  }
}

template <typename T>
inline const T StaticRangeStack<T>::Pop() {
  auto element = StaticStack<T>::Pop();
  if (!minimum_array_.Empty() && minimum_array_.Back() == element) {
    minimum_array_.PopBack();
  }
  if (!maximum_array_.Empty() && maximum_array_.Back() == element) {
    maximum_array_.PopBack();
  }

  return element;
}

template <typename T>
inline void StaticRangeStack<T>::Clear() {
  StaticStack<T>::Clear();
  minimum_array_.Clear();
  maximum_array_.Clear();
}

}  // namespace datastructure
}  // namespace milesdiprata

#endif  // CC_DS_MILESDIPRATA_DATASTRUCTURE_STATIC_RANGE_STACK_H_
