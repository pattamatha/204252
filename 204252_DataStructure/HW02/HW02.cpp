#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:

    Station* header;
    Station* trailer;
    Trip()
    {
         /*WRITE YOUR CODE HERE*/
          //* create header and trailer
          header = new Station;
          trailer = new Station;
          header->prev = NULL;
          header->next = trailer;
          trailer->prev = header;
          trailer->next = NULL;
    }

    void printList()
    {
        cout << "[ ";
        Station* ptr = header->next;
        while (ptr != trailer) {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }

    void insert_front(string newItem)
    {
         /*WRITE YOUR CODE HERE*/
          //* create new station
          Station *newStation = new Station;
          newStation->name = newItem;

          //* insert_front เพิ่มต่อจาก header
          //* case: ไม่มีสถานีระหว่าง header กับ trailer
          if (header->next == trailer){
               newStation->next = trailer;
               newStation->prev = header;
               header->next = newStation;
               trailer->prev = newStation;
          } else { //* case: มีสถานีระหว่าง header กับ trailer
               newStation->next = header->next;
               newStation->prev = header;
               header->next->prev = newStation;
               header->next = newStation;
          }
    }

    void insert_back(string newItem)
    {
         /*WRITE YOUR CODE HERE*/
          //* create new station
          Station *newStation = new Station;
          newStation->name = newItem;

          //* insert_back เพิ่มจาก trailer (แทรกด้านหน้า trailer)
          //* case: ไม่มีสถานีระหว่าง header กับ trailer
          if (trailer->prev == header){
               newStation->next = trailer;
               newStation->prev = header;
               header->next = newStation;
               trailer->prev = newStation;
          } else { //* case: มีสถานีระหว่าง header กับ trailer
               newStation->next = trailer;
               newStation->prev = trailer->prev;
               trailer->prev->next = newStation;
               trailer->prev = newStation; 
          }
    }

    void remove_front()
    {
         /*WRITE YOUR CODE HERE*/
         //* สร้างตัวแปรมาเก็บ station ที่อยู่ถัดจาก header
          Station *curr = new Station;
          curr = header->next;

          //* case: มีสถานีอยู่ระหว่าง header และ trailer ถึงจะทำการ remove ได้
          if (header->next != trailer){
               header->next = curr->next;
               curr->next->prev = header;
               delete curr;
               curr = NULL;
          } 
    }

    void remove_back()
    {
         /*WRITE YOUR CODE HERE*/
          //* สร้างตัวแปรมาเก็บ station ที่อยู่ก่อนหน้า trailer
          Station *curr = new Station;
          curr = trailer->prev;

          //* case: มีสถานีอยู่ระหว่าง header และ trailer ถึงจะทำการ remove ได้
          if (trailer->prev != header){
               trailer->prev = curr->prev;
               curr->prev->next = trailer;
               delete curr;
               curr = NULL;
          }
    }

    Station* visit(int nStep, string stepText)
    {
         /*WRITE YOUR CODE HERE*/
          //* สร้างตัวแปรมาเก็บสถานีเริ่มต้น คือสถานีที่ถัดจาก header
          Station *curr = new Station;
          curr = header->next;

          for (int i=0; i<nStep; i++) {
               if (stepText[i] == 'R') {
                    if (curr->next != trailer){
                         curr = curr->next;
                    }
               } else {
                    if (curr->prev != header){
                         curr = curr->prev;
                    }
               }
          }

          return curr;
    }
};