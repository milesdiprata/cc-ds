#ifndef MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_H_

#include <vector>

#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class RangeStack : public Stack<T> {
 public:
    RangeStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    RangeStack(const Stack<T>& stack);
    RangeStack(const RangeStack& stack);
    virtual ~RangeStack();

    const T& Minimum() const;
    const T& Maximum() const;

    // Implements Stack<T> ----------------------------------------------------
    void Push(const T& element) override;
    const T Pop() override;
    void Clear() override;

 protected:
    inline const Stack<T>& minimum_stack() const { return minimum_stack_; }
    inline Stack<T>& mutable_minimum_stack() { return minimum_stack_; }

    inline const Stack<T>& maximum_stack() const { return minimum_stack_; }
    inline Stack<T>& mutable_maximum_stack() { return maximum_stack_; }

 private:
    Stack<T> minimum_stack_;
    Stack<T> maximum_stack_;
};

template<typename T>
RangeStack<T>::RangeStack(const size_t capacity) :
    Stack<T>(capacity),
    minimum_stack_(Stack<T>(capacity)),
    maximum_stack_(Stack<T>(capacity)) {}

template<typename T>
RangeStack<T>::RangeStack(const Stack<T>& stack) :
    RangeStack(stack.capacity_) {
    for (const auto& element : stack.elements())
        Push(element);
}

template<typename T>
RangeStack<T>::RangeStack(const RangeStack& stack) :
    Stack<T>(stack),
    minimum_stack_(Stack<T>(stack.minimum_stack_)),
    maximum_stack_(Stack<T>(stack.maximum_stack_)) {}

template<typename T>
RangeStack<T>::~RangeStack() {}

template<typename T>
inline const T& RangeStack<T>::Minimum() const {
    return minimum_stack_.Top();
}

template<typename T>
inline const T& RangeStack<T>::Maximum() const {
    return maximum_stack_.Top();
}

template<typename T>
inline void RangeStack<T>::Push(const T& element) {
    Stack<T>::Push(element);
    if (minimum_stack_.Empty() || element < minimum_stack_.Top())
        minimum_stack_.Push(element);
    if (maximum_stack_.Empty() || element > maximum_stack_.Top())
        maximum_stack_.Push(element);
}

template<typename T>
inline const T RangeStack<T>::Pop() {
    auto element = Stack<T>::Pop();
    if (!minimum_stack_.Empty() && minimum_stack_.Top() == element)
        minimum_stack_.Pop();
    if (!maximum_stack_.Empty() && maximum_stack_.Top() == element)
        maximum_stack_.Pop();
    return element;
}

template<typename T>
inline void RangeStack<T>::Clear() {
    Stack<T>::Clear();
    minimum_stack_.Clear();
    maximum_stack_.Clear();
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_H_
