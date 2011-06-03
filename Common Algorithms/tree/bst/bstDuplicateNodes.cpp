#include <iostream>

using namespace std;

struct node {
	int i;
	struct node *left;
	struct node *right;
};

void insert ( struct node *, int );
void display ( node *root );
void duplicate ( node *root );

int main () 
{
	struct node *p;

	int x;

	p = new node;
	p -> i = 2;
	p -> left = NULL;
	p -> right = NULL;

	cin >> x;
	
	do {
		insert ( p, x );
		cin >> x;

	} while ( x != 0 );

	cout << endl;
	display ( p );

	duplicate ( p );
	cout << endl;
	display ( p );

	return 0; 
}

void insert ( struct node * p, int x )
{ 
	node *pp;
	pp = NULL;

	while ( p != NULL ) {
		pp = p;

		if ( x <= p -> i ) {
			p = p -> left;
		} else {
			p = p -> right;
		}
	}

	if ( x <= pp -> i ) {
		p = new node;
		p -> i = x;

		p -> left = NULL;
		p -> right= NULL;
		
		pp -> left = p;
	} else {
		p = new node;
		p -> i = x;

		p -> left = NULL;
		p -> right= NULL;
		
		pp -> right= p;
	}
}

void display ( node *root )
{
	node *temp;
	temp = root;

	if ( temp -> left != NULL ) {
		cout << ( temp -> left -> i ) << " <- ";
	} else { 
		cout << "NULL <- ";
	}
	cout << temp -> i;
	if ( temp -> right != NULL ) {
		cout << " -> " << ( temp -> right -> i);
	} else { 
		cout << " -> NULL";
	}
	cout << endl;

	if ( temp -> left != NULL ) {
		display ( temp -> left );
	}
	if ( temp -> right != NULL ) {
		display ( temp -> right );
	}
}

void duplicate ( node *root )
{
	if ( root != NULL ) {
		node *new_node;
		new_node = new node;

		new_node -> i = root -> i;
		new_node -> left = root -> left;
		new_node -> right = NULL;
		root -> left = new_node;
		duplicate ( new_node -> left );
		duplicate ( root -> right );
	}
}
