#ifndef MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_H_

#include <iostream>
#include <memory>
#include <utility>

#include <milesdiprata/datastructure/stack/base_stack.h>
#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class RangeStack;

template<typename T>
std::ostream& operator<<(std::ostream& os, const RangeStack<T>& stack);

template<typename T>
class RangeStack : public BaseStack<T> {
 public:
    RangeStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    RangeStack(const Stack<T>& stack);
    RangeStack(const RangeStack& stack);
    virtual ~RangeStack();

    const T& Minimum() const;
    const T& Maximum() const;

    // Implements BaseStack<T> ------------------------------------------------
    inline const size_t capacity() const final { return stack_->capacity(); }
    inline const size_t size() const final { return stack_->size(); }
    
    inline const bool Empty() const final { return stack_->Empty(); }
    inline const T& Top() const final { return stack_->Top(); }

    void Push(const T& element) final;
    const T Pop() final;
    void Clear() final;

    friend std::ostream& operator<< <>(std::ostream& os,
                                       const RangeStack& stack);

 protected:
    inline const Stack<T>& stack() const { return *stack_; }
    inline void set_stack(std::unique_ptr<Stack<T>>&& stack) {
        stack_ = std::move(stack);
    }
    inline Stack<T>* mutable_stack() { return stack_.get(); }

    inline const Stack<T>& minimum_stack() const { return *minimum_stack_; }
    inline void set_minimum_stack(std::unique_ptr<Stack<T>>&& stack) {
        minimum_stack_ = std::move(stack);
    }
    inline Stack<T>* mutable_minimum_stack() { return minimum_stack_.get(); }

    inline const Stack<T>& maximum_stack() const { return *maximum_stack_; }
    inline void set_maximum_stack(std::unique_ptr<Stack<T>>&& stack) {
        maximum_stack_ = std::move(stack);
    }
    inline Stack<T>* mutable_maximum_stack() { return maximum_stack_.get(); }

    std::unique_ptr<Stack<T>> stack_;
    std::unique_ptr<Stack<T>> minimum_stack_;
    std::unique_ptr<Stack<T>> maximum_stack_;
};

template<typename T>
RangeStack<T>::RangeStack(const size_t capacity) :
    stack_(new Stack<T>(capacity)),
    minimum_stack_(std::make_unique<Stack<T>>(capacity)),
    maximum_stack_(std::make_unique<Stack<T>>(capacity)) {}

template<typename T>
RangeStack<T>::RangeStack(const RangeStack& stack) :
    stack_(std::make_unique<Stack<T>>(*stack.stack_)),
    minimum_stack_(std::make_unique<Stack<T>>(*stack.minimum_stack_)),
    maximum_stack_(std::make_unique<Stack<T>>(*stack.maximum_stack_)) {}

template<typename T>
RangeStack<T>::~RangeStack() {}

template<typename T>
inline const T& RangeStack<T>::Minimum() const {
    return minimum_stack_->Top();
}

template<typename T>
inline const T& RangeStack<T>::Maximum() const {
    return maximum_stack_->Top();
}

template<typename T>
inline void RangeStack<T>::Push(const T& element) {
    stack_->Push(element);
    if (minimum_stack_->Empty() || element < minimum_stack_->Top())
        minimum_stack_->Push(element);
    if (maximum_stack_->Empty() || element > maximum_stack_->Top())
        maximum_stack_->Push(element);
}

template<typename T>
inline const T RangeStack<T>::Pop() {
    auto element = stack_->Pop();
    if (!minimum_stack_->Empty() && minimum_stack_->Top() == element)
        minimum_stack_->Pop();
    if (!maximum_stack_->Empty() && maximum_stack_->Top() == element)
        maximum_stack_->Pop();
    return element;
}

template<typename T>
inline void RangeStack<T>::Clear() {
    stack_->Clear();
    minimum_stack_->Clear();
    maximum_stack_->Clear();
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const RangeStack<T>& stack) {
    os << *stack.stack_;
    return os;
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_H_
