#ifndef MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_

#include <vector>

#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class DynamicStack;

template<typename T>
std::ostream& operator<<(std::ostream& os, const DynamicStack<T>& stack);

template<typename T>
class DynamicStack {
 public:
    DynamicStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    DynamicStack(const Stack<T>& stack);
    DynamicStack(const DynamicStack& stack);
    virtual ~DynamicStack();

    inline const size_t size() const { return stack_->size(); }
    inline const size_t capacity() const { return stack_->capacity(); }

    const bool Empty() const;
    const T& Top() const;

    virtual void Push(const T& element);
    virtual const T Pop();
    virtual void Clear();

    friend std::ostream& operator<< <>(std::ostream& os, const DynamicStack& stack);

    static constexpr int kCapacityIncreaseFactor = 2;

 private:
    size_t initial_capacity_;
    std::unique_ptr<Stack<T>> stack_;
};

template<typename T>
DynamicStack<T>::DynamicStack(const size_t capacity) :
    initial_capacity_(capacity),
    stack_(std::make_unique<Stack<T>>(capacity)) {}

template<typename T>
DynamicStack<T>::DynamicStack(const Stack<T>& stack) :
    initial_capacity_(stack.capacity_),
    stack_(std::make_unique<Stack<T>>(stack)) {}

template<typename T>
DynamicStack<T>::DynamicStack(const DynamicStack& stack) :
    initial_capacity_(stack.initial_capacity_),
    stack_(std::make_unique<Stack<T>>(stack.stack_)) {}

template<typename T>
DynamicStack<T>::~DynamicStack() {
    initial_capacity_ = 0;
    stack_ = nullptr;
}

template<typename T>
inline const bool DynamicStack<T>::Empty() const {
    return stack_->Empty();
}

template<typename T>
inline const T& DynamicStack<T>::Top() const {
    return stack_->Top();
}

template<typename T>
void DynamicStack<T>::Push(const T& element) {
    try {
        stack_->Push(element);
    } catch (const std::exception& error) {
        auto elements = std::vector<T>();
        while (!stack_->Empty())
            elements.push_back(stack_->Pop());
        stack_ = std::make_unique<Stack<T>>(stack_->capacity() * kCapacityIncreaseFactor);
        for (auto it = elements.rbegin(); it != elements.rend(); ++it)
            stack_->Push(*it);
        
        stack_->Push(element);
    }
}

template<typename T>
inline const T DynamicStack<T>::Pop() {
    return stack_->Pop();
}

template<typename T>
inline void DynamicStack<T>::Clear() {
    if (stack_->capacity() != initial_capacity_) {
        stack_ = std::make_unique<Stack<T>>(initial_capacity_);
    } else {
        stack_->Clear();
    }
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const DynamicStack<T>& stack) {
    os << *stack.stack_;
	return os;
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_DYNAMIC_STACK_H_
