#include <iostream>
#include <vector>

#define SIZE 10

using namespace std;

template <typename T>
class p_q {
	private:
		vector <T> a;

		void max_heapify ( int i, int heap_size )
		{
			int l;
			int r;
			int largest;

			l = 2 * i;
			r = 2 * i + 1;

			if ( l <= heap_size && a[l] > a[i] ) {
				largest = l;
			} else {
				largest = i;
			}
			if ( r <= heap_size && a[r] > a[largest] ) {
				largest = r;
			}

			if ( largest != i ) {
				T temp;
				temp = a[i];
				a[i] = a[largest];
				a[largest] = temp;
	
				max_heapify ( largest, heap_size );
			}
	
		}

		void increment_key ( int i, T val )
			{
				T temp;
				a[i] = val;
				if ( i/2 > 0 && val >= a[i/2] ) {
					temp = a[i/2];
					a[i/2] = a[i];
					a[i] = temp;
					i = i/2;
					increment_key ( i, val );
				}
			}


	public:
		p_q ()
		{
			a.push_back( (T) 0 );
		}

		int size ()
		{
			return ( a.size() -1 );
		}

		T maximum ( int heap_size )
		{
				if ( heap_size < 1 ) {
					return - 1;
				} else {
					return a [1];
				}
		}

		void enqueue ( T val, int heap_size )
		{	
			a.push_back ( val );
			heap_size ++;
			increment_key ( heap_size, val );
		}

		T dequeue ( int heap_size )
		{
			if ( heap_size > 1 ) {
				T max;
	
				max = a[1];

				a[1] = a[heap_size];
				heap_size--;
				max_heapify ( 1, heap_size );
				a.pop_back();

				return max;
			}
		}

		
		void display ()
		{
			cout << endl;
			for ( int i = 1; i < (int)a.size (); i ++ ) {
				cout << a [i] << endl;
			}
		}
		
};

int main ()
{
	p_q <int> x;

	for ( int i = 0; i < SIZE; i ++ ) {
		x.enqueue ( rand(), x.size() );
	}

	cout << " Maximum : " << x.maximum ( x.size() );

	cout << endl << endl;

	x.display();
	
	return 0;

}
