#include <iostream>

using namespace std;

struct pq {
	int priority;
	pq *next;
	pq *prev;
};

void enqueue ( pq* &( head ), pq* &( tail ), int new_pri );
int size ( pq *head );
int top ( pq *head );
int dequeue ( pq* &head, pq* &tail );

void display ( pq *head );

int main ()
{
	pq *head;
	pq *tail;

	head = tail = NULL;
	
	int new_pri;

	cin >> new_pri;

	while ( new_pri != 0 ) {
		if ( new_pri > 0 ) {
			enqueue ( head, tail, new_pri );

			display ( head );

			cout << size( head ) << endl;

			cout << top ( head ) << endl;
		} else { 

			display ( head );

			cout << dequeue ( head, tail ) << endl;

			cout << size ( head ) << endl;
			cout << top ( head ) << endl;

			display ( head );
		}

		cin >> new_pri;
	}

	return 0;

}

void enqueue ( pq* &( head ), pq* &( tail ), int new_pri ) 
{
	pq *ip_node;
	ip_node = new pq;

	ip_node -> next = NULL;
	ip_node -> prev = NULL;
	ip_node -> priority = new_pri;
		
	if ( head == NULL ) {
		
		head = tail = ip_node;

	} else if ( head == tail ) {

		if ( new_pri > head -> priority ) {
			
			head -> next = ip_node;
			ip_node -> prev = head;
			tail = ip_node;
		} else { 
			
			ip_node -> next = head;
			head = ip_node;
		}


	}  else if ( new_pri < head -> priority ) {
			
		ip_node -> next = head;
		head = ip_node;

	} else {

		pq* i_node;

		i_node = head;

		while ( i_node -> next != NULL && new_pri > i_node -> next -> priority ) {
			i_node = i_node -> next;
		}

		if ( i_node == tail ) {

			ip_node -> prev = tail;
			tail -> next = ip_node;
			tail = ip_node;

		} else { 

			ip_node -> next = i_node -> next;
			i_node -> next = ip_node;
			ip_node -> prev = i_node;
			ip_node -> next -> prev = ip_node;
		}
	}
	
}

void display ( pq *head )
{
	pq *i_node;

	i_node = head;

	while ( i_node != NULL ) {
		cout << i_node -> priority << " -> ";
		i_node = i_node -> next;
	}

	cout << " NULL " << endl;

}

int size ( pq *head )
{

	int s;

	s = 0;

	pq *i_node;

	i_node = head;

	while ( i_node != NULL ) {
		s++;
		i_node = i_node -> next;
	}

	return s;
}

int top ( pq *head )
{
	return head -> priority;
}

int dequeue ( pq* &head, pq* &tail )
{
	if ( head == NULL ) {
		cout << "Underflow!!!" << endl;
		return 0;
	} else if ( head == tail ) {
		int tmp;

		pq *temp = head;

		head = tail = NULL;

		tmp = temp -> priority;
		delete temp;

		return tmp;
	} else {
		int tmp;
		pq *temp = head;

		head = temp -> next;

		head -> prev = NULL;

		tmp = temp -> priority;

		delete temp;

		return tmp;
	}
}
