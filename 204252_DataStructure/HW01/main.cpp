#include<iostream>
#include "HW01.cpp"
using namespace std;

int main()
{
  CardList L;
  L.insert_back("Pokemon");
  L.insert_back("Natu");
  L.insert_back("Steelix");
  L.insert_back("Dragonite");
  //L.insert_back("Mewtwo");
  //L.pop_back();
  L.shuffle(2);
  L.printCardList();
  Card * curr = L.head;
  while(curr!=NULL) {
    cout << curr->name << endl;
    curr = curr->next;
  }
  return 0;
}
