#include "../include/app/Visualizable.hpp"
#include <type_traits>

// type_trait
// similar to the extension of generic types in Java
template<typename T>
concept ColorableType = std::is_base_of<Colorable, T>::value;

template <typename T>
struct SingleLinkedNode {
  T data;
  SingleLinkedNode * next;
};

template <typename T>
class LinkedList;

template <typename T>
class LinkedList : public Visualizable {
  public:
  private:
    SingleLinkedNode<T> * head {};
};

