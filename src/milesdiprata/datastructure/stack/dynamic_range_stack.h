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
    DynamicRangeStack(const RangeStack<T>& stack);
    DynamicRangeStack(const DynamicRangeStack<T>& stack);
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
DynamicRangeStack<T>::DynamicRangeStack(const RangeStack<T>& stack) :
    RangeStack<T>(stack) {
    RangeStack<T>::set_stack(
        std::make_unique<DynamicStack<T>>(RangeStack<T>::stack()));
    RangeStack<T>::set_minimum_stack(
        std::make_unique<DynamicStack<T>>(RangeStack<T>::minimum_stack()));
    RangeStack<T>::set_maximum_stack(
        std::make_unique<DynamicStack<T>>(RangeStack<T>::maximum_stack()));
}

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const DynamicRangeStack<T>& stack) :
    DynamicRangeStack<T>(stack) {}

template<typename T>
DynamicRangeStack<T>::~DynamicRangeStack() {}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_
