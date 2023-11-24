class Card {
public:
  char name;
  Card * next;
};

class CharStack {

public:
  Card* head;
  CharStack() { // constructor
    head = nullptr;
  }

  void push(char new_item) {
    //* สร้างอักขระ
    Card *newChar = new Card;
    newChar->name = new_item;

    if (head == nullptr) {
      head = newChar;
    } else {
      newChar->next = head;
      head = newChar;
    }
  }

  char pop() {
    char curr = head->name;
    head = head->next;

    return curr;
  }

  char top() {
    char curr = head->name;

    return curr;
  }

  bool isEmpty() {
    return head==nullptr;
  }
};
