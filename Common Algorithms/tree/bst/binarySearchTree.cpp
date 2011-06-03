#include <iostream>

using namespace std;

struct node {
	int i;
	struct node *left;
	struct node *right;
};

void insert ( struct node *, int );
void display ( node *root );
void search ( struct node *, int );
void del ( struct node *, int );
void bst_preorder ( struct node * );
void bst_inorder ( struct node * );
void bst_postorder ( struct node * );

int main () 
{
	struct node *p;

	int x;
	int y;
	int z;

	p = new node;

	p -> i = 50;

	p -> left = NULL;
	p -> right = NULL;

	cout << "Enter no. to be inserted in the tree::";
	cin >> x;
	
	do {
		insert ( p, x );
		cout << "Enter no. to be inserted in the tree::";
		cin >> x;

	} while ( x != 0 );

	cout << "Preorder Traversal :" << endl;
	bst_preorder ( p );
	cout << "Inorder Traversal :" << endl;
	bst_inorder ( p );
	cout << "Postorder Traversal :" << endl;
	bst_postorder ( p );


	display ( p );
	cout << "Enter no. to be searched in the tree::";
	cin >> y;

	search ( p, y );
	cout << endl;
	
	display ( p );
	cout << "Enter no. to be delete from the tree ::";
	cin >> z;
	del ( p, z );

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

void search ( struct node *p, int y )
{ 
	node *pp;
	pp = NULL;
	bool flag;

	while ( p != NULL ) {
		pp = p;

		if ( y < p -> i ) {
			p = p -> left;
		} else if ( y > p -> i ) {
			p = p -> right;
		} else if ( y == p -> i ) {
			cout << "Search Successful";
			flag = true;
 			break;
		} 
	}

	if ( ! flag ) {
		cout << "search NOT Successful";
		cout << endl;
	}
}

void del ( struct node *p, int z )
{
	node *pp;
	pp = NULL;
	bool flag;

	while ( p != NULL ) {

		if ( z < p -> i ) {
			pp = p;
			p = p -> left;
		} else if ( z > p -> i ) {
			pp = p;
			p = p -> right;
		} else if ( z == p -> i ) {
			flag = true;
 			break;
		}
	}	

	if ( flag ) {
		if ( p -> right == NULL && p -> left == NULL ) {
		       if ( p -> i <= pp -> i ) {
			       delete p;

			       pp -> left = NULL;
		        } else {
			       delete p;

			       pp -> right = NULL;
		       }
		} else if ( p -> right == NULL && p -> left != NULL ) {
		       if ( p -> i <= pp -> i ) {

			       pp -> left = p -> left;

			       delete p;
		       } else {

			       pp -> right = p -> left;

			       delete p;
		       }
		} else if ( p -> left == NULL && p -> right != NULL ) {
		       if ( p -> i <= pp -> i )	{
		
			       pp -> left = p -> right;

			       delete p;
		       } else {

			       pp -> right = p -> right;

			       delete p;
		       }
		}

	} else {
		cout << "No. is not present in the tree";
		cout << endl;
	}
}

void bst_preorder ( struct node * p )
{
	cout << p -> i << endl;

	if ( p -> left != NULL ) {
		bst_preorder ( p -> left );
	} 
	if ( p -> right != NULL ) {
		bst_preorder ( p -> right );
	}
}                   

void bst_inorder ( struct node * p )
{

	if ( p -> left != NULL ) {
		bst_inorder ( p -> left );
	} 
	
	cout << p -> i << endl;
	
	if ( p -> right != NULL ) {
		bst_inorder ( p -> right );
	}
}

void bst_postorder ( struct node * p )
{

	if ( p -> left != NULL ) {
		bst_postorder ( p -> left );
	} 
	
	if ( p -> right != NULL ) {
		bst_postorder ( p -> right );
	}
	
	cout << p -> i << endl;
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
