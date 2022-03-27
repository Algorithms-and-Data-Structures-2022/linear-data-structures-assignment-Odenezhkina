#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {

    // эквивалентно очистке списка
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    // Write your code here ...
    if (Node* node = new Node(value)) {
      if (front_ != nullptr) {
        back_->next = node;
        back_ = node;
      } else {
        back_ = node;
        front_ = node;
      }
      size_++;
    }
  }

  bool LinkedList::Insert(int index, int value) {
    // Write your code here ...
    if (index < 0 || index > size_) {
      return false;
    }
    Node* newNode = new Node(value);
    if (IsEmpty()) {
      back_ = newNode;
      front_ = newNode;
    } else if (index == 0) {
      newNode->next = front_;
      front_ = newNode;
    } else if (index == size_) {
      back_->next = newNode;
      back_ = newNode;
    } else {
      newNode->next = FindNode(index - 1)->next;
      FindNode(index - 1)->next = newNode;
    }
    size_++;
    return true;
  }

  bool LinkedList::Set(int index, int new_value) {
    if (index < 0 || index >= size_) {
      return false;
    } else {
      FindNode(index)->value = new_value;
      return true;
    }
  }

  std::optional<int> LinkedList::Remove(int index) {
    // Write your code here ...
    if (index < 0 || index >= size_) {
      return std::nullopt;
    }
    int removeVal;
    if (index != 0) {
      removeVal = FindNode(index)->value;
      FindNode(index - 1)->next = FindNode(index)->next;
    } else {
      removeVal = (front_->value);
      front_ = (front_->next);
    }
    size_--;
    return removeVal;
  }

  void LinkedList::Clear() {
    // Write your code here ...
    Node* temp = front_;
    for (int i = 0; i < size_; i++) {
      Node* curr = temp->next;
      delete temp;
      temp = curr;
    }
    back_ = nullptr;
    front_ = nullptr;
    size_ = 0;
  }

  std::optional<int> LinkedList::Get(int index) const {
    // Write your code here ...
    if (index < 0 || index >= size_) {
      return std::nullopt;
    } else {
      Node* node = FindNode(index);
      return node->value;
    }
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    // Write your code here ...
    Node* temp = front_;
    for (int i = 0; i < size_; i++) {
      if (temp->value == value) {
        return i;
      }
      temp = temp->next;
    }
    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    if (IndexOf(value) != std::nullopt) {
      return true;
    }
    return false;
  }

  bool LinkedList::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    // Write your code here ...
    if (front_ == nullptr) {
      return std::nullopt;
    }
    return front_->value;
  }

  std::optional<int> LinkedList::back() const {
    // Write your code here ...
    if (back_ == nullptr) {
      return std::nullopt;
    }
    return back_->value;
  }

  Node* LinkedList::FindNode(int index) const {
    // Write your code here ...
    if (index < 0 || index >= size_) {
      return nullptr;
    }
    Node* node = front_;
    for (int i = 0; i < index; i++) {
      node = node->next;
    }
    return node;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedList::toVector() const {

    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment