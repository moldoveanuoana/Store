#include<iostream>
#include<math.h>
#include"h1.h"

using namespace std;
//constructors
template <class T>
vector<T> :: vector ( ) 
	{ }
	
template <class T>
	vector<T> :: vector ( int o)
	{
		n = o;
		p = new T[ o];
	}

	template <class T>
vector<T> :: vector ( vector<T> &a)
{
	n = a.n;
	p = new T[ n ];
	for( int i =0; i< n; i ++ )
		p[ i ]= a.p [i ];
	
}

	template <class T>
vector <T> vector<T> ::operator = ( vector<T> &a)
{
	n = a.n;
	p = new T[ n ];
	for( int i =0; i< n; i ++ )
		p[ i ]= a.p [i ];
	return *this;
	
}

	
//destructor
	
template <class T>
	vector<T> :: ~vector ( )
	{
		delete []p;
	}
//citire &afis
	
/*template <class T>
istream & operator >> (istream &cin, vector<T> &a)
{
	cout<<"introdu:\n";
	for( int i =0; i< a.n; i ++)
		cin >> a.p[ i ];
	return cin;
}
template <class T >
ostream & operator <<  (ostream &cout, vector<T> a)
{
	for(int i = 0; i< a.n; i ++)
		cout << a.p[ i ]<<' ';
	cout<<'\n';
	return cout;
}

/*
template <class T>
vector<T> & vector<T> ::  operator + ( vector <T> &a)
{
	int x = n+ abs(n-a.n);
		vector<T> *c = new vector<T>[x];
		c->n = x;
	for( int i = 0; i < x; i ++ )
		if(i < n && i < a.n )
			c->p[ i ] = p[ i ] + a.p[ i ];
		else
			if( i < n && i > a.n)
				c->p[ i ] = p[ i ];
			else
				if( i > n && i< a.n)
					c->p[ i ] = a.p[ i ];
	return *c;
}	

template < class T>
int daca ( vector<T> a, T x)
	{
		for( int i = 0; i< a.n; i ++ )
			if ( a.p[ i ] == x)
			{
				cout<<"Exista\n";
				return 0;
			}
	cout <<"Nu exista\n";
return 0;
}
*/