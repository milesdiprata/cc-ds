#pragma once

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

namespace mdp {
namespace ds {

template <typename T>
class Stack;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack);

template <typename T>
class Stack {
 public:
  static constexpr std::size_t kDefaultCapacity = 10;

  Stack(const std::size_t capacity = kDefaultCapacity);
  Stack(const Stack& stack);
  Stack(Stack&& stack);
  virtual ~Stack();

  inline const std::size_t capacity() const { return array_.capacity(); }
  inline const std::size_t size() const { return array_.size(); }

  const bool Empty() const;
  const T& Top() const;

  virtual void Push(const T& element) = 0;
  virtual const T Pop() = 0;
  virtual void Clear() = 0;

  friend std::ostream& operator<<<>(std::ostream& os, const Stack<T>& stack);

 protected:
  class DynamicArray {
   public:
    static constexpr std::size_t kMinimumCapacity = 1;

    DynamicArray(const std::size_t capacity);
    DynamicArray(const DynamicArray& array);
    DynamicArray(DynamicArray&& array);
    virtual ~DynamicArray();

    inline const std::size_t capacity() const { return capacity_; }
    inline const std::size_t size() const { return size_; }

    const bool Empty() const;
    const T& Front() const;
    const T& Back() const;
    void Resize(const std::size_t capacity);

    virtual void PushBack(const T& element);
    virtual const T PopBack();
    virtual void Clear();

    inline T& operator[](std::size_t i) { return array_[i]; }
    inline const T& operator[](std::size_t i) const { return array_[i]; }

   private:
    struct OutOfRangeError : public std::out_of_range {
      static constexpr const char* const kErrorMessage =
          "DynamicArray out of range!";

      OutOfRangeError() : std::out_of_range(kErrorMessage) {}
    };

    struct LengthError : public std::length_error {
      static constexpr const char* const kErrorMessage =
          "DynamicArray exceeded its capacity!";

      LengthError() : std::length_error(kErrorMessage) {}
    };

    std::size_t capacity_;
    std::size_t size_;
    std::unique_ptr<T[]> array_;
  };

  struct UnderflowError : public std::out_of_range {
    inline static const char* const kErrorMessage = "Stack underflow!";

    UnderflowError() : std::out_of_range(kErrorMessage) {}
  };

  struct OverflowError : public std::out_of_range {
    inline static const char* const kErrorMessage = "Stack overflow!";

    OverflowError() : std::out_of_range(kErrorMessage) {}
  };

  inline const DynamicArray& array() const { return array_; }
  inline DynamicArray& array() { return array_; }

 private:
  DynamicArray array_;
};

template <typename T>
Stack<T>::Stack(const std::size_t capacity) : array_(capacity) {}

template <typename T>
Stack<T>::Stack(const Stack& stack) : array_(stack.array_) {}

template <typename T>
Stack<T>::Stack(Stack&& stack) : array_(std::move(stack.array_)) {}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
inline const bool Stack<T>::Empty() const {
  return array_.Empty();
}

template <typename T>
inline const T& Stack<T>::Top() const {
  try {
    return array_.Back();
  } catch (const std::out_of_range& error) {
    throw UnderflowError();
  }
}

template <typename T>
Stack<T>::DynamicArray::DynamicArray(const std::size_t capacity)
    : capacity_(std::max(kMinimumCapacity, capacity)),
      size_(0),
      array_(std::make_unique<T[]>(capacity_)) {}

template <typename T>
Stack<T>::DynamicArray::DynamicArray(const DynamicArray& array)
    : capacity_(array.capacity_),
      size_(array.size_),
      array_(std::make_unique<T[]>(capacity_)) {
  std::copy(array.array_.get(), array.array_.get() + array.size_, array_.get());
}

template <typename T>
Stack<T>::DynamicArray::DynamicArray(DynamicArray&& array)
    : capacity_(std::exchange(array.capacity_, 0)),
      size_(std::exchange(array.size_, 0)),
      array_(std::move(array.array_)) {}

template <typename T>
Stack<T>::DynamicArray::~DynamicArray() {}

template <typename T>
inline const bool Stack<T>::DynamicArray::Empty() const {
  return size_ == 0;
}

template <typename T>
inline const T& Stack<T>::DynamicArray::Front() const {
  if (Empty()) {
    throw OutOfRangeError();
  }

  return array_[0];
}

template <typename T>
inline const T& Stack<T>::DynamicArray::Back() const {
  if (Empty()) {
    throw OutOfRangeError();
  }

  return array_[size_ - 1];
}

template <typename T>
void Stack<T>::DynamicArray::Resize(const std::size_t capacity) {
  capacity_ = std::max(kMinimumCapacity, capacity);
  auto new_array = std::make_unique<T[]>(capacity_);
  std::copy(array_.get(), array_.get() + size_, new_array.get());
  array_ = std::move(new_array);
}

template <typename T>
void Stack<T>::DynamicArray::PushBack(const T& element) {
  if (size_ + 1 > capacity_) {
    throw LengthError();
  }

  array_[size_++] = element;
}

template <typename T>
const T Stack<T>::DynamicArray::PopBack() {
  auto element = Back();
  --size_;

  return element;
}

template <typename T>
void Stack<T>::DynamicArray::Clear() {
  size_ = 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
  os << "[";
  for (std::size_t i = stack.array_.size(); i-- > 0;) {
    os << stack.array_[i];
    if (i != 0) {
      os << " ";
    }
  }
  os << "]";

  return os;
}

}  // namespace ds
}  // namespace mdp
