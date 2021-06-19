#ifndef MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_AS_ARRAY_H_
#define MILESDIPRATA_DATASTRUCTURE_RANGE_STACK_AS_ARRAY_H_

#include <algorithm>

#include <milesdiprata/datastructure/stack/stack.h>

namespace milesdiprata {
namespace datastructure {

template<typename T>
class RangeStack : virtual public Stack<T> {
 public:
    RangeStack(const size_t capacity = Stack<T>::kDefaultCapacity);
    RangeStack(const RangeStack& stack);
    virtual ~RangeStack();

    const T& Minimum() const;
    const T& Maximum() const;

    // Implements Stack<T> ----------------------------------------------------
    virtual void Push(const T& element) = 0;
    virtual const T Pop() = 0;
    virtual void Clear() = 0;

 protected:
    inline const typename Stack<T>::Array& minimum_elements() const {
        return minimum_elements;
    }
    inline typename Stack<T>::Array* mutable_minimum_elements() {
        return minimum_elements;
    }

    inline const typename Stack<T>::Array& maximum_elements() const {
        return maximum_elements_;
    }
    inline typename Stack<T>::Array* mutable_maximum_elements() {
        return maximum_elements_;
    }

 private:
    typename Stack<T>::Array minimum_elements_;
    typename Stack<T>::Array maximum_elements_;
};

template<typename T>
RangeStack<T>::RangeStack(const size_t capacity) : Stack<T>(capacity) {
    size_t bounded_capacity = std::max(Stack<T>::kMinimumCapacity, capacity);
    minimum_elements_.capacity = bounded_capacity;
    minimum_elements_.size = 0;
    minimum_elements_.elements = std::make_unique<T[]>(bounded_capacity);

    maximum_elements_.capacity = bounded_capacity;
    maximum_elements_.size = 0;
    maximum_elements_.elements = std::make_unique<T[]>(bounded_capacity);
}

template<typename T>
RangeStack<T>::RangeStack(const RangeStack& stack) : Stack<T>(stack) {
    minimum_elements_.capacity = stack.array_.capacity;
    minimum_elements_.size = stack.array_.size;
    minimum_elements_.elements = std::make_unique<T[]>(minimum_elements_.capacity);
    std::copy(stack.array_.elements.get(),
              stack.array_.elements.get() + stack.array_.size,
              minimum_elements_.elements.get());

    maximum_elements_.capacity = stack.array_.capacity;
    maximum_elements_.size = stack.array_.size;
    maximum_elements_.elements = std::make_unique<T[]>(maximum_elements_.capacity);
    std::copy(stack.array_.elements.get(),
              stack.array_.elements.get() + stack.array_.size,
              maximum_elements_.elements.get());
}

template<typename T>
RangeStack<T>::~RangeStack() {}

template<typename T>
inline const T& RangeStack<T>::Minimum() const {
    if (minimum_elements_.size == 0)
        throw typename Stack<T>::UnderflowError();
    return minimum_elements_.elements[minimum_elements_.size - 1];
}

template<typename T>
inline const T& RangeStack<T>::Maximum() const {
    if (maximum_elements_.size == 0)
        throw typename Stack<T>::UnderflowError();
    return maximum_elements_.elements[maximum_elements_.size - 1];
}

} // namespace datastructure
} // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_STATIC_RANGE_STACK_AS_ARRAY_H_
