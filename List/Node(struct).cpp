#include<iostream>
using namespace std;

typedef struct node {
	int data;
	node *next;
}Node;

typedef struct head {
	node *head;
	int size;
}Head;

bool nodePush(Head* &head, int data) {//Head* &head=>참조자, 별명 같은거
	try {
		Node *tmp = new Node;
		tmp->data = data;
		tmp->next = head->head;
		head->head = tmp;
		head->size++;
		return true;
	}
	catch (const exception &e) {
		return false;
	}
	//tmp->next= NUL


}
int nodePop(Head*&head) {
	if (head->size == 0)
	{
		return -1;
	}
	Node *tmp = head->head;
	head->head = head->head->next;

	int data = tmp->data;
	delete tmp;

	return data;
}
void nodePrint(Head* &head) {
	Node *tmp = head->head;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << "\n";
}


void nodeDestroy(Head* &head) {
	Node *curr= head->head;
	while (curr	!=NULL)
	{
		Node *tmp = curr;
		curr=curr->next;
		delete tmp;
	}
	delete head;	
}

int main() {
	Head *head = new Head;
	head->head = NULL;
	head->size = 0;

	cout << nodePop(head) << "\n";

	nodePush(head, 10);
	nodePush(head, 20);
	nodePush(head, 30);

	nodePrint(head);
	cout <<"Pop: " <<nodePop(head) << "\n";
	nodePrint(head);
	cout << "Pop: " << nodePop(head) << "\n";
	nodePrint(head);




	/*Node *node1 = new Node;
	node1->data = 10;
	node1->next = NULL;

	Node *node2 = new Node;
	node2->data = 20;
	node2->next = NULL;

	head->head = node1;
	node1->next = node2;
	head->size = 2;*/


	/*cout << head->head->data << "\n";
	cout << head->head->next->data << "\n";
	cout << head->head->next->data << "\n";*/


	nodeDestroy(head);

	return 0;
}