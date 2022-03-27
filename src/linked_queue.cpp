#include "assignment/linked_queue.hpp"

namespace assignment {

  LinkedQueue::~LinkedQueue() {

    // эквивалентно очистке очереди
    LinkedQueue::Clear();
  }

  void LinkedQueue::Enqueue(int value) {
    // Write your code here ...
    Node* node = new Node(value);
    if (IsEmpty()) {
      back_ = node;
      front_ = node;
    } else {
      back_->next = node;
      back_ = node;
    }
    size_++;
  }

  bool LinkedQueue::Dequeue() {
    // Write your code here ...
    if (IsEmpty()){
      return false;
    }
    Node* node = front_;
    front_ = nullptr;
    front_ = node->next;
    return true;
  }

  void LinkedQueue::Clear() {
    // Write your code here ...
    back_ = nullptr;
    front_ = nullptr;
    size_ = 0;
  }

  std::optional<int> LinkedQueue::front() const {
    // Write your code here ...
    if (front_ == nullptr) {
      return std::nullopt;
    }
    return front_->value;
  }

  std::optional<int> LinkedQueue::back() const {
    // Write your code here ...
    if (back_ == nullptr) {
      return std::nullopt;
    }
    return back_->value;
  }

  bool LinkedQueue::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedQueue::size() const {
    return size_;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedQueue::LinkedQueue(const std::vector<int>& values) {

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

  std::vector<int> LinkedQueue::toVector() const {
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