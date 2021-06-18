#ifndef MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_

#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class DynamicStack : public Stack<T> {
 public:
    DynamicStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    DynamicStack(const Stack<T>& stack);
    DynamicStack(const DynamicStack& stack);
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
DynamicStack<T>::DynamicStack(const size_t capacity) :
    Stack<T>(capacity),
    initial_capacity_(capacity) {}

template<typename T>
DynamicStack<T>::DynamicStack(const Stack<T>& stack) :
    Stack<T>(stack),
    initial_capacity_(stack.capacity()) {}

template<typename T>
DynamicStack<T>::DynamicStack(const DynamicStack& stack) :
    Stack<T>(stack),
    initial_capacity_(stack.initial_capacity_) {}

template<typename T>
DynamicStack<T>::~DynamicStack() {}

template<typename T>
void DynamicStack<T>::Push(const T& element) {
    if (Stack<T>::size() + 1 > Stack<T>::capacity()) {
        auto elements = std::make_unique<T[]>(Stack<T>::size());
        std::copy(Stack<T>::elements().get(),
                  Stack<T>::elements().get() + Stack<T>::size(),
                  elements.get());

        Stack<T>::set_capacity(Stack<T>::capacity() * kCapacityIncreaseFactor);
        Stack<T>::clear_elements();
        std::copy(elements.get(),
                  elements.get() + Stack<T>::size(),
                  Stack<T>::mutable_elements().get());
    }
        
    Stack<T>::mutable_elements()[Stack<T>::size()] = element;
    Stack<T>::set_size(Stack<T>::size() + 1);
}

template<typename T>
inline const T DynamicStack<T>::Pop() {
    auto element = Stack<T>::Top();
    Stack<T>::set_size(Stack<T>::size() - 1);
    return element;
}

template<typename T>
inline void DynamicStack<T>::Clear() {
    if (Stack<T>::capacity() != initial_capacity_) {
        Stack<T>::set_capacity(initial_capacity_);
        Stack<T>::clear_elements();
    }

    Stack<T>::clear_size();
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
