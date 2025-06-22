#include "../include/app/Visualizable.hpp"
#include <memory>
#include <type_traits>

// type_trait
// similar to the extension of generic types in Java
template<typename T>
concept ColorableType = std::is_base_of<Colorable, T>::value;

template <typename T>
struct SingleLinkedNode {
  T data;
  std::unique_ptr<SingleLinkedNode> next;
};

template <typename T>
class LinkedList;

template <typename T>
class LinkedList : public Visualizable {
  private:
    std::unique_ptr<SingleLinkedNode<T>> head {};
};

