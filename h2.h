// clasa magazin
#include<iostream>
#include"h1.h"
#include"h3.h"

using namespace std;

 class magazin {
	 
	 produs      *P [1000];
	 dispozitive *D [1000];
	 //activitate magazin cu profit ...
	 int  nr_pateuri_i,  nr_sucuri_i,  nr_cuptoare,  nr_frigidere,  s;
 public:
	 
	 magazin ( )  {
		 cout << "suma de inceput:\n";

		 cin >> s;
		 
		 cout << "nr pateuri, nr sucuri nr cuptoare, nr frigidere: ";
		
		 cin >> nr_pateuri_i >> nr_sucuri_i >> nr_cuptoare >> nr_frigidere;
		 

		 int i, taxa, consum, numar, energy, x;  //mai mult pt dispozitive
		 
		 int  pret_achizitie, pret_vanzare, nr_bucati, timp;  //produse
		 x = nr_pateuri_i;
		cout << "pentru pateuri:\n";
		 for ( i = 0; i < nr_pateuri_i; i++)
				{
					cout << " pret_achizitie >> pret_vanzare  >>  nr_bucati >>timp \n";
					
					cin >> pret_achizitie >> pret_vanzare  >>  nr_bucati >>timp;
					
				P [ i ] = new pateuri(timp, nr_bucati, i+1, pret_achizitie, pret_vanzare);

				 s = s - nr_bucati*pret_achizitie;

				 }
		 
				cout << "pentru sucuri: \n";
				
		 for ( i = 0; i < nr_sucuri_i; i++)
			 {
				 cout << "pret_achizitie >> pret_vanzare >> nr_bucati >> timp\n";
				 
				 cin >> pret_achizitie >> pret_vanzare >> nr_bucati >> timp;
				 
				 P [ x ] = new sucuri( timp, nr_bucati, x+1,pret_achizitie, pret_vanzare);
				 
				 s = s - nr_bucati * pret_achizitie;
				 
				 x ++;
			 }
		 
		 for ( i = 0; i < nr_cuptoare; i++)
			 {
				 cout << " taxa >> consum >> numar;\n";
				 
				 cin >> taxa >> consum >> numar;
				 
				 D [ i ] = new cuptor ( consum, numar, taxa);
				
				 
			 }
		 
		 x = nr_cuptoare;
		  
		 for ( i = 0; i < nr_frigidere; i++)
			 {
				 cout << "energy >> ok >> taxa\n";
				 
				 cin >> energy >> taxa;
				 
				 D [ x ] = new frigider (energy, taxa );
				 
				 x ++;
			 }
	 }
	 
	 //facem aprovizionarea dispozitivelor separat de produse, fiindca produsele se aprovizioneaza pe ora



void aprovizionare_produse ( ) {
	int  i, x; 
	
	for ( i = 0; i < nr_pateuri_i + nr_sucuri_i; i ++)
			{x = P [ i ]->bucati( );
				if ( x < 20 && s > 0 )
				{
					P [ i  ]-> aprov ( 20 );
					
					s = s-  ( 20- x )* P [ i ]->pret( );
				}
			

			}
			cout<<"s apr"<<s<<'\n';
}

void vanzare ( ) {
	int nr_pateu, nr_suc, i,k, *v;
	cout<< "nr_pateu:\n";
	cin >>nr_pateu;
		cout <<" nr_suc:\n";
		cin>>nr_suc;
	
	v = new int [nr_pateu + nr_suc ];
	
	for (i = nr_cuptoare ; i < nr_cuptoare+nr_frigidere; i ++ )
		
					D [ i ] ->nu ( );
	if( nr_suc%10 == 0 )
		 k = nr_suc/10;
	else
		k = nr_suc/10+1;
	
	if ( nr_suc > 0)
		for( i = nr_cuptoare ; i < nr_cuptoare+k; i ++ )
					D [ i ] ->da ( );         //merge// initializez ora de folosire cu 1;
					
				
			     
	for ( i = 0; i < nr_pateu + nr_suc; i ++)
		{cout<<"introdu nr buc\n";
			cin >> v [ i ];

			if ( P  [v [ i ] - 1]->bucati( ) > 0 )
				{
					s = s + P [ v[ i ] -1]->pret( );

					P [ i ] ->scade( );
				 }
				else
				{
					int ok =0;
					
					for ( int j = 0; j < nr_pateuri_i; i++ )
						
						if ( v [ i ] -1 != j )
							if ( P [ j ]-> bucati( ) > 0) 
							{
								P [ j ] ->scade( );
							
							s = s + P [ j ]->pret( );

							ok = 1;
							
							cout << "produsul nu a fost gasit si a fost inlocuit cu" << j+1<<'\n';
							}
						
						if ( ok == 0 )
							cout << " nu mai exista produse pe stoc\n";
				}
			}
	cout<<"vanzare"<<s<<'\n';
}
	int  consum_dispozitive ( ) {
		
         int i, c = 0;
		 
		 for ( i = 0; i < nr_cuptoare+nr_frigidere; i ++ )
			
			 c = c + D [ i ] ->cost ( );
		 cout<<"consum disp"<< c<<'\n';
		 return c;

	}

	int costul_taxelor ( ) {
		
		int i, c= 0;
		
		for ( i = 0; i < nr_cuptoare + nr_frigidere; i++ )
			c = c + D [ i ] ->taxat ( );
		cout<<"consum taxe"<<c<<'\n';
		return c;
	}
			
	 void functionare ( ) {
		 
		 for( int i = 0; i < 8; i ++ )
			{
					aprovizionare_produse ( );  //aprovizionare();//citeste produsele;
		 
					vanzare ( );//vanzare()//cate pateuri si cate suc am vandut;
					
					s = s - consum_dispozitive ( );
					
				
			}
			
			 s = s - costul_taxelor( );  //consum_dispozitive()//consum dispozitive;
			 cout<<"cifra afaceri"<<s<<'\n';
	 }
	 
	 
 };
