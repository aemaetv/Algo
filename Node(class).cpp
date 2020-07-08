#include<iostream>
using namespace std;

class Node {
private:
	int data;
	Node *next;
	
public:
	//생성자
	Node() {
		this->data = 0;
		this->next = nullptr;
	}
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
	void setNext(Node *next) {
		this->next = next;
	}
	void setData(int data) {
		this->data = data < 0 ? 0 : data;
	}
	int getData() {
		return this->data;
	}
	Node *getNext() {
		return this->next;
	}
};
class LinkedList {
private:
	Node *head;
	int size;

public:
	LinkedList() {
		this->head = nullptr;
		this->size=0;
	}
	~LinkedList() {
		Node *curr = head;
		while (curr !=nullptr)
		{
			Node *tmp = curr;
			curr = curr->getNext();
			delete tmp;
		}
		cout << "Linked Clear\n";
	}
	void addSize() { this->size++; }
	void subsize() { this->size--; }
	void setHead(Node *target) { this->head = target;}
	Node *getHead() { return head; }

	void nodePush(int data);//함수의 프로토타입(정의x)
	void nodePrint();
	int nodePop();

};

void LinkedList::nodePush(int data) {
	if (size == 0) {
		head = new Node(data);
	}
	else {
		Node *tmp = new Node(data);
		tmp->setNext(head);
		setHead(tmp);
	}
	addSize();
}
void LinkedList::nodePrint() {
	Node *tmp = head;
	cout << "Linked List data:";
	for(int i=0;i<size;i++)
	{
		cout << tmp->getData() << " ";
		tmp = tmp->getNext();
	}
	cout << "\n";
}
int LinkedList::nodePop() {
	if (size == 0)
	{
		return -1;
	}
	Node *tmp = head;
	head= head->getNext();

	int data = tmp->getData();
	delete tmp;

	size--;
	return data;
}

int main() {
	LinkedList *list = new LinkedList();
	list->nodePush(10);
	list->nodePush(20);
	list->nodePush(30);
	list->nodePrint();

	cout << "pop: " << list->nodePop() << "\n";
	list->nodePrint();

	delete list;

	return 0;
}