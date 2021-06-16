#ifndef MILESDIPRATA_DATASTRUCTURE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_STACK_H_

#include <cstddef>

namespace milesdiprata {
namespace datastructure {

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

    static constexpr size_t kInitialCapacity = 10;

 private:
    size_t size_;
    size_t capacity_;

};

}; // namespace datastructure
}; // namespace milesdiprata

#endif // MILESDIPRATA_DATASTRUCTURE_STACK_H_
