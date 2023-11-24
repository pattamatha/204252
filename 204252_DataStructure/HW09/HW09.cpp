#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Frequency {
public:
	vector<char> c; // ตัวอักษร
	vector<int> f;  // ความถี่
	int numChar; // จำนวนตัวอักษรทั้งหมด
};

class treeNode {
public:
	string character;
	int frequency;
	treeNode *leftChild;
	treeNode *rightChild;
};

class HuffmanTree {
private:
	treeNode *root;

public:
	queue<treeNode*> singleQueue;
    queue<treeNode*> mergeQueue;

	HuffmanTree() {
		root = nullptr;
	}

	void buildTree(Frequency *freq) {
		/* Write your code here */
		for (int i=0; i<freq->numChar; i++){
			treeNode *t = new treeNode;
			t->character = freq->c[i];
			t->frequency = freq->f[i];
			t->leftChild = NULL;
			t->rightChild = NULL;
			singleQueue.push(t);
		}

		//While (จํานวนข้อมูลใน singleQueue และ mergeQueue รวมกันมากกว่า 1):
		while (singleQueue.size() + mergeQueue.size() > 1){
			//สร้างโหนด leftChild ด้วยข้อมูลจากโหนดที่มีความถี่น้อยที่สุดระหว่าง singleQueue และ mergeQueue
			treeNode *tLeft = new treeNode;
			if (singleQueue.empty() && !mergeQueue.empty()){
				tLeft = mergeQueue.front();
				mergeQueue.pop();
			} else if (!singleQueue.empty() && mergeQueue.empty()) {
				tLeft = singleQueue.front();
				singleQueue.pop();
			} else if (!singleQueue.empty() && !mergeQueue.empty()) {
				if (singleQueue.front()->frequency <= mergeQueue.front()->frequency){
				tLeft = singleQueue.front();
				singleQueue.pop();
				} else {
				tLeft = mergeQueue.front();
				mergeQueue.pop();
				}
			}
			
			//สร้างโหนด rightChild ด้วยข้อมูลจากโหนดที่มีความถี่น้อยที่สุดระหว่าง singleQueue และ mergeQueue
			treeNode *tRight = new treeNode;
			if (singleQueue.empty() && !mergeQueue.empty()){
				tRight = mergeQueue.front();
				mergeQueue.pop();
			} else if (!singleQueue.empty() && mergeQueue.empty()) {
				tRight = singleQueue.front();
				singleQueue.pop();
			} else if (!singleQueue.empty() && !mergeQueue.empty()) {
				if (singleQueue.front()->frequency <= mergeQueue.front()->frequency){
				tRight = singleQueue.front();
				singleQueue.pop();
				} else {
				tRight = mergeQueue.front();
				mergeQueue.pop();
				}
			}
			
			//สร้างโหนด parent และกําหนด frequency เป็นผลรวมของ frequency ใน leftChild และrightChild
			treeNode *tParent = new treeNode;
			tParent->frequency = tLeft->frequency + tRight->frequency;
			tParent->character = tLeft->character + tRight->character;
			tParent->leftChild = tLeft;
			tParent->rightChild = tRight;
			//Push parent ไปที3 mergeQueue
			mergeQueue.push(tParent);
		}
		//Return โหนดที่เหลือ 1 ตัวใน mergeQueue ซึ่งก็คือ root ของ Huffman Tree
		root = mergeQueue.front();
	}

	void decode(string code) {
    /* Write your code here */
	treeNode *rootCopy = root;
		for (int i=0; i<code.length(); i++){
			if (code[i] == '0'){
				rootCopy = rootCopy->leftChild;
			} else {
				rootCopy = rootCopy->rightChild;
			}
			
			if (rootCopy->leftChild==NULL && rootCopy->rightChild==NULL){
				cout << rootCopy->character;
				rootCopy = root;
			}
		}
	}
	
};
