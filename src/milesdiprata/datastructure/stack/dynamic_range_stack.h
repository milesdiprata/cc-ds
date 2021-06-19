#ifndef MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_

#include <stdlib.h>

#include <utility>

#include <milesdiprata/datastructure/stack/dynamic_stack.h>
#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class DynamicRangeStack : public DynamicStack<T> {
 public:
    DynamicRangeStack();
    DynamicRangeStack(const size_t capacity);
    DynamicRangeStack(const DynamicRangeStack& stack);
    DynamicRangeStack(DynamicRangeStack&& stack);
    virtual ~DynamicRangeStack();

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

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack() : DynamicStack<T>() {}

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const size_t capacity) :
    DynamicStack<T>(capacity),
    minimum_array_(capacity),
    maximum_array_(capacity) {}

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const DynamicRangeStack& stack) :
    DynamicStack<T>(stack),
    minimum_array_(stack.minimum_array_),
    maximum_array_(stack.maximum_array_) {}

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(DynamicRangeStack&& stack) :
    DynamicStack<T>(std::move(stack)),
    minimum_array_(std::move(stack.minimum_array_)),
    maximum_array_(std::move(stack.maximum_array_)) {}

template<typename T>
DynamicRangeStack<T>::~DynamicRangeStack() {}

template<typename T>
inline const T& DynamicRangeStack<T>::Minimum() const {
    return minimum_array_.Back();
}

template<typename T>
inline const T& DynamicRangeStack<T>::Maximum() const {
    return maximum_array_.Back();
}

template<typename T>
inline void DynamicRangeStack<T>::Push(const T& element) {
    DynamicStack<T>::Push(element);
    if (minimum_array_.Empty() || element < minimum_array_.Back()) {
        if (minimum_array_.size() + 1 > minimum_array_.capacity())
            minimum_array_.Resize(minimum_array_.capacity() *
                DynamicStack<T>::kCapacityIncreaseFactor);
            minimum_array_.PushBack(element);
    }
    if (maximum_array_.Empty() || element > maximum_array_.Back()) {
        if (maximum_array_.size() + 1 > maximum_array_.capacity())
            maximum_array_.Resize(maximum_array_.capacity() *
                DynamicStack<T>::kCapacityIncreaseFactor);
            maximum_array_.PushBack(element);
    }
}

template<typename T>
inline const T DynamicRangeStack<T>::Pop() {
    auto element = DynamicStack<T>::Pop();
    if (!minimum_array_.Empty() && minimum_array_.Back() == element)
        minimum_array_.PopBack();
    if (!maximum_array_.Empty() && maximum_array_.Back() == element)
        maximum_array_.PopBack();
    return element;
}

template<typename T>
inline void DynamicRangeStack<T>::Clear() {
    DynamicStack<T>::Clear();
    if (minimum_array_.capacity() != DynamicStack<T>::initial_capacity())
        minimum_array_.Resize(DynamicStack<T>::initial_capacity());
    if (maximum_array_.capacity() != DynamicStack<T>::initial_capacity())
        maximum_array_.Resize(DynamicStack<T>::initial_capacity());
    minimum_array_.Clear();
    maximum_array_.Clear();
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_
