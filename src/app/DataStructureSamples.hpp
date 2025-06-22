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
    SingleLinkedNode<T> * head {nullptr};
    SingleLinkedNode<T> * prev {nullptr};
    SingleLinkedNode<T> * last {head};
    int saved_elements {0};

  public:
    class Iterator {
      using Node = SingleLinkedNode<T>;
      private:
        Node * current;

      public:

        Iterator(Node * starting_point) : current(starting_point) {};

        T& operator*() { return current->data; }

        // const means: We won't modify the Iterator
        bool operator!=(const Iterator& other) const {
          return current != other.current;
        }

        Iterator& operator++() {
          current = current->next;
          return *this;
        }

    };

    // Add element if not found
    // @return true if not found -> added
    bool add(T data);

    // Remove element which returns 0 when
    // compared with <=>
    // @return true if found -> deleted
    bool remove(T data);

    // Errase the node at the iterator
    // @return true if erased
    bool erase(const Iterator& it);

    // @return true if element is present at List
    bool contains(T data);

    // @return Element at index
    // @return std::nullopt if invalid idx
    std::optional<T> get(int idx);

    Iterator begin() {
      return Iterator(head);
    }

    Iterator end() {
      return Iterator(nullptr);
    }

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

    inline bool isEmpty() const {
      return size() == 0;
    }

    inline int size() const {
      return saved_elements;
    }

    inline std::optional<T> getFirst() const {
      if (isEmpty()) {
        return std::nullopt;
      }
      return head->data;
    }

    inline std::optional<T> getLast() const {
      if (isEmpty()) {
        return std::nullopt;
      }
      return last->data;
    }

};

