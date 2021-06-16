#ifndef MILESDIPRATA_DATASTRUCTURE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_STACK_H_

#include <algorithm>
#include <iostream>
#include <memory>
#include <type_traits>

#include <exception/exception.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class Stack;

template<typename T>
std::ostream& operator<<(std::ostream &os, const Stack<T>& stack);

template<typename T>
class Stack {
 public:
    Stack(const size_t capacity = kInitialCapacity);
    ~Stack();

    inline const size_t size() const {return size_; }
    inline const size_t capacity() const {return capacity_; }

    const bool Empty() const;
    const T& Top() const;

    void Push(const T& element);
    const T& Pop();
    void Clear();

    friend std::ostream& operator<< <>(std::ostream& os, const Stack& stack);

    static constexpr size_t kInitialCapacity = 10;
    static constexpr int kCapacityIncreaseFactor = 2;

 private:
    size_t capacity_;
    size_t size_;
    std::unique_ptr<T[]> elements_;
};

template<typename T>
Stack<T>::Stack(const size_t capacity) :
    capacity_(std::max((size_t)1, capacity)),
    size_(0),
    elements_(std::make_unique<T[]>(capacity)) {}

template<typename T>
Stack<T>::~Stack() {
    capacity_ = 0;
    size_ = 0;
    elements_ = nullptr;
}

template<typename T>
inline const bool Stack<T>::Empty() const {
    return size_ == 0;
}

template<typename T>
inline const T& Stack<T>::Top() const {
    if (Empty())
        throw Underflow();
    return elements_[size_ - 1];
}

template<typename T>
void Stack<T>::Push(const T& element) {
    if (size_ + 1 > capacity_) {
        capacity_ *= kCapacityIncreaseFactor;
        auto new_elements = std::make_unique<T[]>(capacity_);
        std::copy(elements_.get(),
                  elements_.get() + size_,
                  new_elements.get());
        elements_ = std::move(new_elements);
    }

    elements_[size_] = element;
    ++size_;
}

template<typename T>
const T& Stack<T>::Pop() {
    if (Empty())
        throw Underflow();
    --size_;
    return elements_[size_];
}

template<typename T>
void Stack<T>::Clear() {
    if (capacity_ != kInitialCapacity) {
        capacity_ = kInitialCapacity;
        elements_ = std::make_unique<T[]>(capacity_);
    }
    size_ = 0;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const Stack<T>& stack) {
    os << "[";
    for (int i = stack.size_ - 1; i >= 0; --i) {;
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
