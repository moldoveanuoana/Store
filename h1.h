#include<iostream.h>
#include<string.h>
using namespace std;

class produs {
	int  pret_achizitionare, pret_vanzare;
public:
	 
	produs ( );
	produs ( int , int );
	virtual void pateu (int, int, int );
	virtual void suc ( int, int, int );
	virtual int bucati ( );
	virtual void aprov (int x);
	int pret ( ) { return pret_achizitionare;}
	virtual void scade ( );
};
 void produs :: scade ( ) { }
void  produs :: aprov (int x) { }
void  produs :: pateu ( int , int , int ) {
	
}
void produs :: suc ( int, int, int ) {
}

int produs :: bucati ( ) { } 

class pateuri : public  produs {
	 int timp_prep , nr_buc_int;
	 int tip_pateu;
public:
	void pateu( int , int , int );
	pateuri ( );
	int bucati ( );
	pateuri ( int x, int y, int z,int t, int a );
	void aprov (int x);
	void scade ( );

};


class sucuri : public produs {
	int tip_suc;
	int timp_racire , nr_buc_i;
public :
	void suc ( int , int , int );
	sucuri ( ) ;
	int bucati ( );
	sucuri ( int x, int y, int z, int t, int a);
	void aprov (int x);
	void scade ( );

};



//constructor produs;

produs:: produs ( ) {
	pret_achizitionare = pret_vanzare = 0;
}
 produs :: produs ( int x, int y )
{
	pret_achizitionare = x;
	
	pret_vanzare = y;
}


//constructor pateuri;
pateuri :: pateuri ( ) {
	timp_prep = nr_buc_int = tip_pateu = 0;
}

 pateuri :: pateuri ( int x , int y , int z, int t,int a ): produs(t,a) {
	timp_prep = x;
	nr_buc_int = y;
	tip_pateu = z;
}

//functia virtuala

void  pateuri :: pateu ( int x , int y , int z ) {
	timp_prep = x;
	nr_buc_int = y;
	tip_pateu = z;
}

int pateuri :: bucati ( ) {
	 return  nr_buc_int;
}

void pateuri :: aprov (int x ) {
	nr_buc_int = x;
	
}


void pateuri :: scade ( ) {
	nr_buc_int --;
}
//constructori  suc;	
sucuri :: sucuri ( ) {
	timp_racire = nr_buc_i = tip_suc = 0;
}


sucuri :: sucuri ( int  x , int  y, int z , int t,int a):produs (t,a) {
	timp_racire  = x;
	nr_buc_i  = y;
	tip_suc  = z;
	
}

//functia virtuala

void  sucuri :: suc ( int  x , int  y, int z ) {
	timp_racire  = x;
	nr_buc_i  = y;
	tip_suc  = z;
	
}

int sucuri :: bucati ( ) {
	  return nr_buc_i;
}

void sucuri :: aprov ( int x ) {
	 nr_buc_i = x;
}


void sucuri :: scade ( ) {
	nr_buc_i --;
}
