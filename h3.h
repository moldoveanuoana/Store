#include<iostream>
using namespace std;



class   dispozitive   {
	int  taxa_timbru_verde;
public:
	dispozitive ();
	dispozitive (  int x );
	virtual  int   cost  () = 0;
	virtual void da ( );
	virtual void nu ( );
	 int taxat ( ) ;
};

void dispozitive :: nu ( ) { }




void dispozitive :: da ( ){ }



int  dispozitive :: taxat ( ) {

	return taxa_timbru_verde;
}


//constructors;

dispozitive :: dispozitive ( ) {
	taxa_timbru_verde= 0;
}


dispozitive :: dispozitive (int x ) {
	taxa_timbru_verde= x;
}





class cuptor :  public dispozitive {
	int  cons_prep;
	int  nr_prep;
public:
	cuptor ( );
	cuptor ( int, int, int );
	void coace ( int , int );
	int cost ( );
	
};



//constructors;


cuptor :: cuptor ( ) {
	cons_prep = 0;
	nr_prep = 0;
}


 cuptor :: cuptor ( int x, int y, int z): dispozitive ( z) {
	cons_prep = x;
	nr_prep = y;
}


//virtual method;


int cuptor :: cost ( ) {
	return  cons_prep*nr_prep;
}




class frigider : public dispozitive {
	int energie;
	int merge;
public:
	frigider ( );
	frigider ( int, int );
	int cost ( );
	void da ( );
	void nu ( );
	
};



//constuctors;


frigider :: frigider ( ) {
	energie = 0;
	merge =  0;
}


frigider :: frigider ( int x , int t ): dispozitive ( t ) {
	energie  =  x;
	merge  =  0;

}


//virtual method;

int frigider :: cost (  ) {
	
	return merge *energie;

}

void frigider :: da ( ) {
	merge =1;

}
void frigider :: nu ( ) {
	merge = 0;
}
