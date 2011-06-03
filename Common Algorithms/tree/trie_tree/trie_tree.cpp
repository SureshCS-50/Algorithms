#include <iostream>

using namespace std;

struct trie_node {
	struct trie_node * lett [256];
	bool flag;

	trie_node () {

		for ( int i = 0; i < 256; i ++ ) {
			lett[i]  = NULL;
		}
	}
};

void insert ( struct trie_node * root, string );
void search ( struct trie_node * root, string );

int main () 
{
	struct trie_node * root;
	string s;
	string s1;

	cin >> s;

	root = new trie_node;

	insert ( root, s );

	cin >> s;
	insert ( root, s );
	cin >> s;
	insert ( root, s );
	cin >> s;
	insert ( root, s );
	cout <<"String to be searched for :: ";
	cin >> s1;

	search ( root, s1 );

	cout << endl;

	return 0; 
}
	
void insert ( struct trie_node * root, string s )
{
	struct trie_node * i_node;

	i_node = root;

	for ( int i = 0; i < (int)s.length(); i ++ ) {
		if ( i_node -> lett[(int)s[i]] == NULL ) {
			i_node -> lett[(int)s[i]] = new trie_node;
			i_node = i_node -> lett[(int)s[i]];
		} else {
			i_node = i_node -> lett[(int)s[i]];
		}
	}

	i_node -> flag = true;
}

void search ( struct trie_node * root, string s1 ) 
{
	struct trie_node *i_node;

	for ( int i = 0; i < (int)s1.length(); i ++ ) {
		if ( i_node -> lett[(int)s1[i]] == NULL ){
			cout << "Search NOT successfull" << endl;
			return;
		} else {
			i_node = i_node -> lett[(int)s1[i]];
		}
	}

	if ( i_node -> flag == true ) {
		cout << "Search Successfull" << endl;
	} else {
		cout << "Search NOT Successull" << endl;
	}
}








