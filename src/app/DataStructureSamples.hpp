#pragma once

#include "../include/app/Visualizable.hpp"
#include <concepts>
#include <cstddef>
#include <optional>
#include <type_traits>

/**
 * @brief Concept ensuring types are both Colorable and totally ordered
 * @tparam T The type to check
 */
template<typename T>
concept ColorableAndOrdered = std::is_base_of<Colorable, T>::value && std::totally_ordered<T>;

/**
 * @brief Node structure for singly linked list
 * @tparam T The data type stored in the node
 */
template <ColorableAndOrdered T>
struct SingleLinkedNode {
  T data;
  // Have to decide if the visualization works using
  // just a next node or if we also need the previous node
  SingleLinkedNode * next;
};

/**
 * @brief A singly linked list implementation with visualization capabilities
 * @tparam T The data type stored in the list
 */
template <ColorableAndOrdered T>
class LinkedList : public Visualizable {
  private:
    SingleLinkedNode<T> * head {nullptr};
    SingleLinkedNode<T> * last {nullptr};
    int saved_elements {0};

  public:
    /**
     * @brief Iterator class for LinkedList
     */
    class Iterator {
      private:
        SingleLinkedNode<T>* current;

      public:

        Iterator(SingleLinkedNode<T> * starting_point) : current(starting_point) {};

        T& operator*() { return current->data; }

        bool operator!=(const Iterator& other) const {
          return current != other.current;
        }

        Iterator& operator++() {
          current = current->next;
          return *this;
        }

        Iterator operator++(int) {
          Iterator temp = *this;
          current = current->next;
          return temp;
        }

        bool operator==(const Iterator& other) const {
          return current == other.current;
        }

    };

    /**
     * @brief Const iterator class for LinkedList
     */
    class ConstIterator {
      private:
        const SingleLinkedNode<T>* current;

      public:
        ConstIterator(const SingleLinkedNode<T>* starting_point) : current(starting_point) {}

        const T& operator*() const { return current->data; }

        ConstIterator& operator++() {
          current = current->next;
          return *this;
        }

        ConstIterator operator++(int) {
          ConstIterator temp = *this;
          current = current->next;
          return temp;
        }

        bool operator==(const ConstIterator& other) const {
          return current == other.current;
        }

        bool operator!=(const ConstIterator& other) const {
          return current != other.current;
        }
    };

    // Constructors
    LinkedList() : head(nullptr), last(nullptr), saved_elements(0) {}

    LinkedList(const LinkedList& other) : head(nullptr), last(nullptr), saved_elements(0) {
      for (const T& item : other) {
        push_back(item);
      }
    }

    inline std::optional<T> getFirst() const {
      if (empty()) {
        return std::nullopt;
      }
      return head->data;
    }

    inline std::optional<T> getLast() const {
      if (empty()) {
        return std::nullopt;
      }
      return last->data;
    }

    /**
     * @brief Add element to the end of the list
     * @param data The data to add
     * @return true if added successfully
     */
    bool pushBack(const T& data);

    /**
     * @brief Add element to the beginning of the list
     * @param data The data to add
     * @return true if added successfully
     */
    bool pushFront(const T& data);

    /**
     * @brief Remove element from the list
     * @param data The data to remove
     * @return true if found and removed
     */
    bool remove(const T& data);

    /**
     * @brief Remove element at iterator position
     * @param it Iterator pointing to the element to remove
     * @return Iterator pointing to the next element
     */
    Iterator erase(const Iterator& it);

    /**
     * @brief Check if element exists in the list
     * @param data The data to search for
     * @return true if found
     */
    bool contains(const T& data) const;

    /**
     * @brief Get element at index
     * @param idx The index
     * @return Optional containing the element or nullopt if invalid index
     */
    std::optional<T> at(size_t idx) const;

    /**
     * @brief Get element at index (unchecked)
     * @param idx The index
     * @return Reference to the element
     * @throws std::out_of_range if index is invalid
     */
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;

    // Iterator methods
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    ConstIterator begin() const { return ConstIterator(head); }
    ConstIterator end() const { return ConstIterator(nullptr); }
    ConstIterator cbegin() const { return ConstIterator(head); }
    ConstIterator cend() const { return ConstIterator(nullptr); }

    std::optional<T> pop_front();
    std::optional<T> pop_back();

    bool remove_first() { return pop_front().has_value(); }
    bool remove_last() { return pop_back().has_value(); }

    bool empty() const { return saved_elements == 0; }
    size_t size() const { return saved_elements; }

    std::optional<T> front() const;
    std::optional<T> back() const;

    /**
     * @brief Clear all elements from the list
     */
    void clear();

    // interface
    std::string to_string() const override;
    std::string get_type_name() const override;
    std::vector<std::string> get_visualization_data() const override;
    bool is_valid() const override;

};

