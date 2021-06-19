#ifndef MILESDIPRATA_DATASTRUCTURE_STATIC_RANGE_STACK_AS_ARRAY_H_
#define MILESDIPRATA_DATASTRUCTURE_STATIC_RANGE_STACK_AS_ARRAY_H_

#include <iostream>
#include <memory>
#include <utility>

#include <milesdiprata/datastructure/stack/range_stack.h>
#include <milesdiprata/datastructure/stack/static_stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class StaticRangeStack : public StaticStack<T>, public RangeStack<T> {
 public:
    StaticRangeStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    StaticRangeStack(const StaticRangeStack& stack);
    virtual ~StaticRangeStack();

    // Implements Stack<T> ----------------------------------------------------
    inline void Push(const T& element) override { StaticStack<T>::Push(element); }
    inline const T Pop() override { return StaticStack<T>::Pop(); }
    inline void Clear() override { StaticStack<T>::Clear(); }
};

template<typename T>
StaticRangeStack<T>::StaticRangeStack(const size_t capacity) :
    RangeStack<T>(capacity) {}

template<typename T>
StaticRangeStack<T>::StaticRangeStack(const StaticRangeStack& stack) :
    RangeStack<T>(stack) {}

template<typename T>
StaticRangeStack<T>::~StaticRangeStack() {}

// template<typename T>
// inline void StaticRangeStack<T>::Push(const T& element) {
//     stack_->Push(element);
//     if (minimum_stack_->Empty() || element < minimum_stack_->Top())
//         minimum_stack_->Push(element);
//     if (maximum_stack_->Empty() || element > maximum_stack_->Top())
//         maximum_stack_->Push(element);
// }

// template<typename T>
// inline const T StaticRangeStack<T>::Pop() {
//     auto element = stack_->Pop();
//     if (!minimum_stack_->Empty() && minimum_stack_->Top() == element)
//         minimum_stack_->Pop();
//     if (!maximum_stack_->Empty() && maximum_stack_->Top() == element)
//         maximum_stack_->Pop();
//     return element;
// }

// template<typename T>
// inline void StaticRangeStack<T>::Clear() {
//     stack_->Clear();
//     minimum_stack_->Clear();
//     maximum_stack_->Clear();
// }

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_STATIC_RANGE_STACK_AS_ARRAY_H_
