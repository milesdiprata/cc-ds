#ifndef MILESDIPRATA_DATASTRUCTURE_BASE_STACK_H_
#define MILESDIPRATA_DATASTRUCTURE_BASE_STACK_H_

namespace milesdiprata {
namespace datastructure {

template<typename T>
class BaseStack {
 public:
    inline BaseStack() {}
    virtual ~BaseStack();

    virtual const size_t capacity() const = 0;
    virtual const size_t size() const = 0;
    
    virtual const bool Empty() const = 0;
    virtual const T& Top() const = 0;

    virtual void Push(const T& element) = 0;
    virtual const T Pop() = 0;
    virtual void Clear() = 0;
};

template<typename T>
BaseStack<T>::~BaseStack() {}

} // namespace datastructure
} // namespace milesdiprata


#endif // MILESDIPRATA_DATASTRUCTURE_BASE_STACK_H_
