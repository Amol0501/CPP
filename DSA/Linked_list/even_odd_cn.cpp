#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void push(Node *p, int ele){
	Node *t = new Node(ele);
	p -> next = t;
	p = t;
}

Node *EvenAfterOdd(Node *head){
	Node *p = NULL, *q = NULL, *temp = head, *r = q, *x = p;
	cout << "1 ";
	if(head == NULL || head -> next == NULL)
		return head;


	if(temp -> data % 2 == 0 && temp -> next != NULL){
		cout << "10 ";
		int data = temp -> data;
		Node *t = new Node(data);
		p = t;
		temp = temp -> next;
		while(temp -> data % 2 == 0 && temp -> next != NULL){
			cout << "11 ";
			int data = temp -> data;
			Node *t = new Node(data);
			p -> next = t;
			p = t;
			temp = temp -> next;
		}
		cout << "12 ";

	}
	if(temp -> data % 2 != 0 && temp -> next != NULL){
		cout << "13 ";
		int data = temp -> data;
		Node *t = new Node(data);
		q = t;
		temp = temp -> next;
		while(temp -> data % 2 != 0 && temp -> next != NULL){
			cout << "14 ";
			int data = temp -> data;
			Node *t = new Node(data);
			q -> next = t;
			q = t;
			temp = temp -> next;

		}
		cout << "15 ";
	}

	
	if(temp -> data % 2 == 0 && temp -> next != NULL){
		cout << "10.1 ";
		int data = temp -> data;
		Node *t = new Node(data);
		p = t;
		temp = temp -> next;
		while(temp -> data % 2 == 0 && temp -> next != NULL){
			cout << "11.1 ";
			int data = temp -> data;
			Node *t = new Node(data);
			p -> next = t;
			p = t;
			temp = temp -> next;
		}
		cout << "12.1 ";

	}
	if(temp -> data % 2 != 0 && temp -> next != NULL){
		cout << "13.1 ";
		int data = temp -> data;
		Node *t = new Node(data);
		q = t;
		temp = temp -> next;
		while(temp -> data % 2 != 0 && temp -> next != NULL){
			cout << "14.1 ";
			int data = temp -> data;
			Node *t = new Node(data);
			q -> next = t;
			q = t;
			temp = temp -> next;

		}
		cout << "15.1 ";
	}
	
	while(temp -> next != NULL){
		cout << "2 ";
		if(temp -> data % 2 == 0){
			cout << "3 ";
			// push(p, temp -> data);
			int data = temp -> data;
			Node *t = new Node(data);
			p -> next = t;
			p = t;
			temp = temp -> next;
			cout << "4 ";
		}
		else{
			cout << "5 ";
			// push(q, temp -> data);
			int data = temp -> data;
			Node *t = new Node(data);
			q -> next = t;
			q = t;
			temp = temp -> next;
			cout << "6 ";
		}
	}
	cout << "7 ";
	q -> next = p;
	// head = r -> next;
	cout << "9 ";
	return r -> next;
}

Node *evenAfterOdd(Node *head){
	Node *even = new Node(0);
    Node *p = even;
    Node *odd = new Node(0);
    Node *q = odd;
    cout << "1 ";
    while(head){
		cout << "2 ";
        if(head -> data % 2 == 0){
			cout << "3 ";
            Node *t = new Node(head -> data);
            p -> next = t;
            p = t;
            head = head -> next;
			cout << "4 ";
        }
        else{
			cout << "5 ";
            Node *t = new Node(head -> data);
            q -> next = t;
            q = t;
            head = head -> next;
			cout << "6 ";
        }
    }
	cout << "7 ";
    p -> next = odd -> next;
	cout << "8   ";
    return even -> next;

}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}