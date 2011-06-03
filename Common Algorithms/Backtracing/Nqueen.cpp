/** 
 * @file Nqueen.cpp
 * @brief 
 * @author Sapan Diwakar
 * @date 2008-04-15
 */

#include <iostream>
#include <vector>

using namespace std;

void put_queen ( vector < vector < bool > > &, int );
bool attack ( vector < vector < bool > >, int, int );
int min ( int, int );

int main () 
{
	int N;

	cin >> N;

	vector < vector < bool > > board ( N, vector < bool > ( N ) );

	put_queen ( board, N );
	
	for ( int i = 0; i < N; i ++ ) {
		for ( int j = 0; j < N; j ++ ) {
			cout << board [i][j] << "\t";
		}
		cout << endl;
	}

	return 0; 
}

void put_queen ( vector < vector < bool > > &board, int N )
{
	for ( int i = 0; i < N; i ++ ) {
		for ( int j = 0; j < N; j ++ ) {
			if ( !attack ( board, i, j )  ) {
				board[j][i] = true;
				break;
			}
		}
	}
}

bool attack ( vector < vector < bool > > board, int y, int x )
{
	for ( int i = 0; i < y; i ++ ) {
		if ( board [x][i] == true ) {
			return true;
		} 
	}

	for ( int j = 0; j <= min ( x, y ); j ++ ) {
		if ( board [x - j][y - j] == true ) {
			return true;
		}
	}
	
	for ( int j = 0; j <= ( x + y ) - min ( x, y ) && ( x + j ) < (int) board.size() && ( y - j ) > 0; j ++ ) {
		if ( board [x + j][y - j] == true ) {
			return true;
		}
	}

	return false;
}

int min ( int x, int y )
{
	if ( x <= y ) {
		return x;
	} else {
		return y;
	}
}
