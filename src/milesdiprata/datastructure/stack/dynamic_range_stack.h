#ifndef MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_

#include <milesdiprata/datastructure/stack/dynamic_stack.h>
#include <milesdiprata/datastructure/stack/range_stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class DynamicRangeStack : public RangeStack<T> {
 public:
    DynamicRangeStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    DynamicRangeStack(const Stack<T>& stack);
    virtual ~DynamicRangeStack();
};

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const size_t capacity) {
    RangeStack<T>::set_stack(
        std::make_unique<DynamicStack<T>>(capacity));
    RangeStack<T>::set_minimum_stack(
        std::make_unique<DynamicStack<T>>(capacity));
    RangeStack<T>::set_maximum_stack(
        std::make_unique<DynamicStack<T>>(capacity));
}

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const Stack<T>& stack) :
    DynamicRangeStack<T>(stack) {
    RangeStack<T>::PushFromStack(stack);
}

template<typename T>
DynamicRangeStack<T>::~DynamicRangeStack() {}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_
