#ifndef MILESDIPRATA_DATASTRUCTURE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_STACK_H_

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class Stack;

template<typename T>
std::ostream& operator<<(std::ostream &os, const Stack<T>& stack);

template<typename T>
class Stack {
 public:
    Stack(const size_t capacity = kDefaultCapacity);
    Stack(const Stack& stack);
    virtual ~Stack();

    inline const size_t size() const { return size_; }
    inline const size_t capacity() const { return capacity_; }

    const bool Empty() const;
    const T& Top() const;

    virtual void Push(const T& element);
    virtual const T Pop();
    virtual void Clear();

    friend std::ostream& operator<< <>(std::ostream& os, const Stack& stack);

    static constexpr size_t kDefaultCapacity = 10;

 private:
    size_t capacity_;
    size_t size_;
    std::unique_ptr<T[]> elements_;

    struct UnderflowError : public std::exception {
        inline const char* what() const noexcept { return kErrorMessage.c_str(); }

        inline static const std::string kErrorMessage = "Stack Underflow!";
    };

    struct OverflowError : public std::exception {
        inline const char* what() const noexcept { return kErrorMessage.c_str(); }

        inline static const std::string kErrorMessage = "Stack Overflow!";
    };
};

template<typename T>
Stack<T>::Stack(const size_t capacity) :
    capacity_(std::max((size_t)1, capacity)),
    size_(0),
    elements_(std::make_unique<T[]>(capacity)) {}

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
        throw UnderflowError();
    return elements_[size_ - 1];
}

template<typename T>
void Stack<T>::Push(const T& element) {
    if (size_ + 1 > capacity_)
        throw OverflowError();
    elements_[size_] = element;
    ++size_;
}

template<typename T>
const T Stack<T>::Pop() {
    auto element = Top();
    --size_;
    return element;
}

template<typename T>
void Stack<T>::Clear() {
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
