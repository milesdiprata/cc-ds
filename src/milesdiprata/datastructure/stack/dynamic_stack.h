#ifndef MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_

#include <stdlib.h>

#include <stdexcept>
#include <utility>

#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class DynamicStack : public Stack<T> {
 public:
    DynamicStack();
    DynamicStack(const size_t capacity);
    DynamicStack(const DynamicStack& stack);
    DynamicStack(DynamicStack&& stack);
    virtual ~DynamicStack();

    // Implements Stack<T> ----------------------------------------------------
    void Push(const T& element) override;
    const T Pop() override;
    void Clear() override;

    static constexpr int kCapacityIncreaseFactor = 2;

 private:
    size_t initial_capacity_;
};

template<typename T>
DynamicStack<T>::DynamicStack() :
    Stack<T>(),
    initial_capacity_(Stack<T>::capacity()) {}

template<typename T>
DynamicStack<T>::DynamicStack(const size_t capacity) :
    Stack<T>(capacity),
    initial_capacity_(Stack<T>::capacity()) {}

template<typename T>
DynamicStack<T>::DynamicStack(const DynamicStack& stack) :
    Stack<T>(stack),
    initial_capacity_(stack.initial_capacity_) {}

template<typename T>
DynamicStack<T>::DynamicStack(DynamicStack&& stack) :
    Stack<T>(std::move(stack)),
    initial_capacity_(std::exchange(stack.initial_capacity_, 0)) {}

template<typename T>
DynamicStack<T>::~DynamicStack() {}

template<typename T>
void DynamicStack<T>::Push(const T& element) {
    // if (Stack<T>::size() + 1 > Stack<T>::capacity()) {
    //     auto elements = std::make_unique<T[]>(Stack<T>::size());
    //     std::copy(Stack<T>::elements().get(),
    //               Stack<T>::elements().get() + Stack<T>::size(),
    //               elements.get());

    //     Stack<T>::set_capacity(Stack<T>::capacity() * kCapacityIncreaseFactor);
    //     Stack<T>::clear_elements();
    //     std::copy(elements.get(),
    //               elements.get() + Stack<T>::size(),
    //               Stack<T>::mutable_elements().get());
    // }
        
    // Stack<T>::mutable_elements()[Stack<T>::size()] = element;
    // Stack<T>::set_size(Stack<T>::size() + 1);

    try {
        Stack<T>::mutable_array().PushBack(element);
    } catch (const std::length_error& error) {
        Stack<T>::mutable_array().Resize(Stack<T>::capacity() * kCapacityIncreaseFactor);
        Stack<T>::mutable_array().PushBack(element);
    }
}

template<typename T>
inline const T DynamicStack<T>::Pop() {
    return Stack<T>::mutable_array().PopBack();
}

template<typename T>
inline void DynamicStack<T>::Clear() {
    if (Stack<T>::capacity() != initial_capacity_) {
        Stack<T>::mutable_array().Resize(initial_capacity_);
    }
    Stack<T>::mutable_array().Clear();
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
