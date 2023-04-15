/****************************************************************
 
    Following is the class structure of the Node class:

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

*****************************************************************/




#include <iostream>
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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
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
Node *push(Node *head, int ele){
    Node *t = new Node(ele);
    cout << "1";
    if(head == NULL){
        head = t;
        t -> next = NULL;
        cout << "2";
    }
    cout << "3";
    Node *p = head;
    while(p != NULL){
        cout << "4";
        p = p -> next;
        cout << "5";
    }
    cout << "6";
    p= t;
    // p = t;
    cout << "7";
    return head;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    
    if(head1 == NULL && head2 == NULL)
        return head1;
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    
    Node *head = NULL;
    Node *p = head1, *q = head2;
    
    while(p != NULL && q != NULL){
        if(p -> data <= q -> data){
			head = push(head, p -> data);
            p = p -> next;
        }
        else{
            head = push(head, q -> data);
            q = q -> next;
        }
    }
    while(p != NULL){
        head = push(head, p -> data);
        p = p -> next;
    }
    while(q != NULL){
        head = push(head, q -> data);
        q = q -> next;
    }
    return head;
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}