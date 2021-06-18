#ifndef MILESDIPRATA_DATASTRUCTURE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_STACK_H_

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <milesdiprata/datastructure/stack/base_stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class Stack;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack);

template<typename T>
class Stack : public BaseStack<T>{
 public:
    Stack(const size_t capacity = kDefaultCapacity);
    Stack(const Stack& stack);
    virtual ~Stack();

    // Implements BaseStack<T> ------------------------------------------------
    inline const size_t capacity() const override { return capacity_; }

    inline const size_t size() const override { return size_; }
    
    const bool Empty() const override;

    const T& Top() const override;

    void Push(const T& element) override;

    const T Pop() override;

    void Clear() override;

    friend std::ostream& operator<< <>(std::ostream& os, const Stack& stack);

    struct UnderflowError : public std::underflow_error {
        UnderflowError() : std::underflow_error(kErrorMessage) {}

        inline static const char* const kErrorMessage = "Stack Underflow!";
    };

    struct OverflowError : public std::overflow_error {
        OverflowError() : std::overflow_error(kErrorMessage) {}

        inline static const char* const kErrorMessage = "Stack Overflow!";
    };

    static constexpr size_t kDefaultCapacity = 10;

    static constexpr size_t kMinimumCapacity = 1;

 protected:
    inline void clear_capacity() { capacity_ = 0; }

    inline void set_capacity(const size_t capacity) { capacity_ = capacity; }

    inline void clear_size() { size_ = 0; }

    inline void set_size(const size_t size) { size_ = size; }
    
    inline void clear_elements() {
        elements_ = std::make_unique<T[]>(capacity_);
    }

    inline const std::unique_ptr<T[]>& elements() const { return elements_; }

    inline std::unique_ptr<T[]>& mutable_elements() { return elements_; }

 private:
    size_t capacity_;
    size_t size_;
    std::unique_ptr<T[]> elements_;
};

template<typename T>
Stack<T>::Stack(const size_t capacity) :
    capacity_(std::max(kMinimumCapacity, capacity)),
    size_(0),
    elements_(std::make_unique<T[]>(capacity_)) {}

template<typename T>
Stack<T>::Stack(const Stack& stack) :
    capacity_(stack.capacity_),
    size_(stack.size_),
    elements_(std::make_unique<T[]>(stack.capacity_)) {
        std::copy(stack.elements_.get(),
                  stack.elements_.get() + stack.size_,
                  elements_.get());
    }

template<typename T>
Stack<T>::~Stack() {}

template<typename T>
inline const bool Stack<T>::Empty() const {
    return size_ == 0;
}

template<typename T>
inline const T& Stack<T>::Top() const {
    if (Empty())
        throw UnderflowError();
    return elements_[size_ - 1];
}

template<typename T>
inline void Stack<T>::Push(const T& element) {
    if (size_ + 1 > capacity_)
        throw OverflowError();
    elements_[size_] = element;
    ++size_;
}

template<typename T>
inline const T Stack<T>::Pop() {
    auto element = Top();
    --size_;
    return element;
}

template<typename T>
inline void Stack<T>::Clear() {
    size_ = 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
    os << "[";
    for (int i = stack.size_ - 1; i >= 0; --i) {
        os << stack.elements_[i];
        if (i != 0)
            os << " ";
    }
    os << "]";

    return os;
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_STACK_H_
