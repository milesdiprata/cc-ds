#ifndef MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_

#include <vector>

#include <milesdiprata/datastructure/stack/dynamic_stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class DynamicRangeStack : public DynamicStack<T> {
 public:
    DynamicRangeStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    DynamicRangeStack(const Stack<T>& stack);
    DynamicRangeStack(const DynamicRangeStack& stack);
    virtual ~DynamicRangeStack();

    const T Minimum() const;
    const T Maximum() const;

    // Implements Stack<T> ----------------------------------------------------
    void Push(const T& element) override;
    const T Pop() override;
    void Clear() override;

 private:
    std::unique_ptr<DynamicStack<T>> minimum_stack_;
    std::unique_ptr<DynamicStack<T>> maximum_stack_;
};

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const size_t capacity) :
    DynamicStack<T>(capacity),
    minimum_stack_(std::make_unique<DynamicStack<T>>(capacity)),
    maximum_stack_(std::make_unique<DynamicStack<T>>(capacity)) {}

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const Stack<T>& stack) :
    DynamicRangeStack(stack.capacity_) {
    auto elements = std::vector<T>();
    while (!stack.Empty())
        elements.push_back(stack.Pop());
    for (auto it = elements.rbegin(); it != elements.rend(); ++it)
        Push(*it);
}

template<typename T>
DynamicRangeStack<T>::DynamicRangeStack(const DynamicRangeStack& stack) :
    DynamicStack<T>(stack),
    minimum_stack_(std::make_unique(stack.minimum_stack_)),
    maximum_stack_(std::make_unique(stack.maximum_stack_)) {}

template<typename T>
DynamicRangeStack<T>::~DynamicRangeStack() {
    minimum_stack_ = nullptr;
    maximum_stack_ = nullptr;
}

template<typename T>
inline const T DynamicRangeStack<T>::Minimum() const {
    return minimum_stack_->Top();
}

template<typename T>
inline const T DynamicRangeStack<T>::Maximum() const {
    return maximum_stack_->Top();
}

template<typename T>
inline void DynamicRangeStack<T>::Push(const T& element) {
    DynamicStack<T>::Push(element);
    if (minimum_stack_->Empty() || element < minimum_stack_->Top())
        minimum_stack_->Push(element);
    if (maximum_stack_->Empty() || element > maximum_stack_->Top())
        maximum_stack_->Push(element);
}

template<typename T>
inline const T DynamicRangeStack<T>::Pop() {
    auto element = DynamicStack<T>::Pop();
    if (!minimum_stack_->Empty() && minimum_stack_->Top() == element)
        minimum_stack_->Pop();
    if (!maximum_stack_->Empty() && maximum_stack_->Top() == element)
        maximum_stack_->Pop();
    return element;
}

template<typename T>
inline void DynamicRangeStack<T>::Clear() {
    DynamicStack<T>::Clear();
    minimum_stack_->Clear();
    maximum_stack_->Clear();
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_DYNAMIC_RANGE_STACK_H_
