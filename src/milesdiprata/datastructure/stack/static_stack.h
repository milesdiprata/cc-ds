#ifndef MILESDIPRATA_DATASTRUCTURE_STATIC_STACK_AS_ARRAY_H_
#define MILESDIPRATA_DATASTRUCTURE_STATIC_STACK_AS_ARRAY_H_

#include <algorithm>
#include <memory>
#include <utility>

#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class StaticStack : public Stack<T>{
 public:
    StaticStack();
    StaticStack(const size_t capacity);
    StaticStack(const StaticStack& stack);
    StaticStack(StaticStack&& stack);
    virtual ~StaticStack();

    // Implements Stack<T> ----------------------------------------------------
    void Push(const T& element) override;
    const T Pop() override;
    void Clear() override;
};

template<typename T>
StaticStack<T>::StaticStack() : Stack<T>() {}

template<typename T>
StaticStack<T>::StaticStack(const size_t capacity) : Stack<T>(capacity) {}

template<typename T>
StaticStack<T>::StaticStack(const StaticStack& stack) : Stack<T>(stack) {}

template<typename T>
StaticStack<T>::StaticStack(StaticStack&& stack) :
    Stack<T>(std::move(stack)) {}

template<typename T>
StaticStack<T>::~StaticStack() {}

template<typename T>
inline void StaticStack<T>::Push(const T& element) {
    Stack<T>::mutable_array().PushBack(element);
}

template<typename T>
inline const T StaticStack<T>::Pop() {
    return Stack<T>::mutable_array().PopBack();
}

template<typename T>
inline void StaticStack<T>::Clear() {
    Stack<T>::mutable_array().Clear();
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_STATIC_STACK_AS_ARRAY_H_
