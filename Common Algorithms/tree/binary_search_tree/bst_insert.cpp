#include <iostream>

using namespace std;

struct node
{
	int i;

	node *left;
	node *right;
};

void insert ( node *i_node, int x );
void bst_sort( node *i_node );

int main ()
{

	int x;

	node *root;

	root = new node;

	cin >> root -> i;

	cin >> x;
	while ( x != 0 ) {
		insert ( root, x );

		cin >> x;
	}

	cout << endl;
	bst_sort ( root );

	return 0;
}

void insert ( node *i_node, int x )
{
	node *ip_node;

	ip_node = new node;

	ip_node -> left = NULL;
	ip_node -> right = NULL;
	ip_node -> i = x;

	while ( i_node != NULL ) {
		if ( x < i_node -> i ) {
			if ( i_node -> left != NULL ) {
				i_node = i_node -> left;
			} else {
				cout << "Inserting " << x << " to the left of " << i_node -> i << endl;
				i_node -> left = ip_node;
				i_node = NULL;
			}
		} else {
			if ( i_node -> right != NULL ) {
				i_node = i_node -> right;
			} else {
				cout << "Inserting " << x << " to the right of " << i_node -> i << endl;
				i_node -> right = ip_node;
				i_node = NULL;
			}
		}
	}
}

void bst_sort ( node *i_node )
{
	if ( i_node -> left != NULL ) {
		bst_sort ( i_node -> left );
	}
	cout << i_node -> i << endl;
	
	if ( i_node -> right != NULL ) {
		bst_sort ( i_node -> right );
	}
}
