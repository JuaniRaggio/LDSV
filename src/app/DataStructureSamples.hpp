#pragma once

#include "../include/app/Visualizable.hpp"
#include <concepts>
#include <optional>
#include <type_traits>

// type_trait
// similar to the extension of generic types in Java
template<typename T>
concept ColorableAndOrdered = std::is_base_of<Colorable, T>::value && std::totally_ordered<T>;

template <ColorableAndOrdered T>
struct SingleLinkedNode {
  T data;
  SingleLinkedNode * next;
};

template <ColorableAndOrdered T>
class LinkedList;

template <ColorableAndOrdered T>
class LinkedList : public Visualizable {

  private:
    SingleLinkedNode<T> * head {};
    SingleLinkedNode<T> * last {head};
    int saved_elements {0};

  public:
    bool add(T data);
    bool remove(T data);
    bool contains(T data);
    std::optional<T> get(int idx);

    // Removes and returns head
    inline std::optional<T> pull() {
      T return_value = getFirst();
      removeFirst();
      return return_value;
    }

    inline bool removeFirst() {
      return remove(getFirst());
    }

    inline bool removeLast() {
      return remove(getLast());
    }

    inline int size() {
      return saved_elements;
    }

    inline T getFirst() {
      return head->data;
    }

    inline T getLast() {
      return last->data;
    }

};

