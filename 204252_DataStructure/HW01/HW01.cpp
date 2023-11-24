#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card* head;
    CardList(){
        /*WRITE YOUR CODE HERE*/
        head = NULL;
    }

	void pop_back(){
        /*WRITE YOUR CODE HERE*/
        Card *curr = head;

        //* เช็คว่ามี card อยู่ใน list ไหม? ถ้ามีถึงจะ pop ได้
        if (head != NULL){
            if (head->next==NULL){
                head = NULL;
            } else {
                while (curr->next->next!=NULL){
                    curr = curr->next;
                }
                delete curr->next;
                curr->next = NULL;
            }
        }
	}

    void insert_back(string newItem){
        /*WRITE YOUR CODE HERE*/
        //* create new card
        Card *newCard = new Card;
        newCard->name = newItem;
        newCard->next = NULL;

        Card *curr = head;

        if (head == NULL){
            head = newCard;
        } else {
            while (curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = newCard;
        }
    }

    void shuffle(int pos){ //1<=pos<=size-1
        /*WRITE YOUR CODE HERE*/
        Card *curr = head;

        if (head != NULL){
            //* วนหา card สุดท้าย แล้วเปลี่ยนให้มาชี้ head (ทำให้หัวและท้ายต่อกัน)
            while (curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = head;

            //* เลื่อน curr ไปที่ตำแหน่ง pos
            for (int i = 0; i < pos; i++) {
                curr = curr->next;
            }

            head = curr->next;
            curr->next = NULL;
        }
    }
    
    void printCardList(){
        /*DO NOT DELETE OR EDIT*/
        cout << "[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
};
