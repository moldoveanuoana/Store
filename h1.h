#include <iostream>

using namespace std;

template <class T>
	class vector
	{
		T *p;
		int n;
	public:
		vector( ){}
		
		
		vector( int o )
		{
			n = o;
		p = new T[ o];
		
		}
		
		vector ( vector<T> &a)
		{n = a.n;
	p = new T[ n ];
	for( int i =0; i< n; i ++ )
		p[ i ]= a.p [i ];
		}
		
		
		~vector( ){
			delete []p;
		}
		
		
		vector<T> & operator +( vector<T> &a )
		
		{
			int x;
		
			if (n==a.n)
		  x=n;
			else
				if(n<a.n)
					x= a.n;
				else
					x=n;
			vector<T> *c = new vector<T>(x);
			
		c->n=x;
			if (x==n && x == a.n )
				for( int i = 0; i < x; i ++ )
					c->p[ i ] = p[ i ] + a.p[ i ];
				else
				
	for( int i = 0; i < x; i ++ )
		if(i <n && i < a.n )
			c->p[ i ] = p[ i ] + a.p[ i ];
		else
			if( i < n && i >= a.n)
				c->p[ i ] = p[ i ];
			else
				if( i >= n && i< a.n)
					c->p[ i ] = a.p[ i ];
			
				
				return *c;
		}
		
		vector<T> operator =(vector<T> &a)
		{
			n = a.n;
	p = new T[ n ];
	for( int i =0; i< n; i ++ )
		p[ i ]= a.p [i ];
	return *this;
		}
		
		
		friend int daca ( vector<T> a, T x)
		
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

		friend istream & operator >> ( istream &cin, vector<T> &a)
		{
			
	cout<<"introdu:\n";
	for( int i =0; i< a.n; i ++)
		cin >> a.p[ i ];
	return cin;
		}
		friend ostream & operator <<  ( ostream &cout, vector<T> a)
		{
			
	for(int i = 0; i< a.n; i ++)
		cout << a.p[ i ]<<' ';
	cout<<'\n';
	return cout;
		}
	};
	