/* ----- File Include ----- */
#include "header.h"

/* ----- Test List Kosong ----- */
boolean isEmpty (List L) {
	return (First(L)==Nil && Last(L)==Nil);
}

boolean isAkhir (List L, address P) {
	if(Next(P)!=Nil)
	{
		return 0;
	} else
	{
		return 1;
	}
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L){
	First(*L) = Nil;
	Last(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi(infotype X, simboltype Y){
	address P;
	P = (address)malloc(sizeof(ElmtList));
	if(P!=Nil)
	{
		Info(P) = X;
		Simbol(P) = Y;
		Next(P) = Nil;
		Prev(P) = Nil;
		Jump(P) = Nil;
		//printf("Alamat Alokasi : %p\n", &P);
		return P;
	} else
	{
		return Nil;
	}
}

void Dealokasi(address *P) {
	free(*P);
}

/* ----- Pencarian Sebuah Elemen List ----- */
address Search (List L, infotype X) {
	boolean Found;
	address P;
	Found = false;
	P = First(L);
	while(!Found && P!=Nil)
	{
		if(Info(P)==X)
		{
			Found = true;
			return P;
		} else
		{
			P = Next(P);
		}
	}
	return Nil;
}

boolean FSearch (List L, address P) {
	address P2;
	boolean Found = false;
	P = First(L);
	while(!Found && P!=NULL)
	{
		if(P2==P)
		{
			Found = true;
		} else
		{
			P = Next(P);
		}
	}
	return false;
}

address SearchPrec (List L, infotype X) {
    /* Kamus Lokal */
    address P;
    boolean Found;
    /* Algoritma */
    P = First(L);
    Found = false;
    while (P != Nil && !Found) {
    	printf("X : %d\n",X);
    	printf("INFO : %d\n",Info(P));
    	if (X == Info(P)){
    		Found = true;
			return Prev(P);
	    } else {
	       	P = Next(P);
	   	}
   	}
   	return Nil;
}

address SearchNext (List L, infotype X) {
    /* Kamus Lokal */
    address P;
    boolean Found;
    /* Algoritma */
    P = First(L);
    Found = false;
    while (P != Nil && !Found) {
    	printf("X : %d\n",X);
    	printf("INFO : %d\n",Info(P));
    	if (X == Info(P)){
    		Found = true;
			return Next(P);
	    } else {
	       	P = Next(P);
	   	}
   	}
   	return Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst(List *L, infotype X, simboltype Y, address J) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = Alokasi(X, Y);
    if (P != Nil) {
    	InsertFirst(L,P);
    }
}

void InsVMiddle (List *L, infotype X, infotype Y, simboltype Z) {
    /* Kamus Lokal */
    address P, Prec;
    /* Algoritma */
    Prec = Search (*L, X);
    if(Prec != Nil)
    {
	    P = Alokasi(Y, Z);
	    if(P != Nil){
			InsertAfter(L, P, Prec);
	    }
	}
	else
	{
		printf("Elemen Tidak Ditemukan\n");
	}
}

void InsVLast (List *L, infotype X, simboltype Y) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = Alokasi(X, Y);
    if (P != Nil) {
    	InsertLast(L,P);
    }
}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
	Prev(First(*L)) = Nil;
    Next(P) = Nil;
	Dealokasi(&P);
    PrintInfo(*L);
}

void DelVMiddle (List *L, infotype *X, infotype Y) {
    /* Kamus Lokal */
    address P, Prec;

    /* Algoritma */
	Prec = Search(*L, Y);
    if(Prec != Nil)
    {
		*X = Info(Next(Prec));
		DelAfter(L, &P, Prec);
	    Dealokasi(&P);
	    PrintInfo(*L);
	} else
	{
		printf("Elemen Tidak Ditemukan\n");
	}
}

void DelVLast (List *L, infotype *X) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    DelLast(L,&P);
    (*X) = Info(P);
    Dealokasi(&P);
    PrintInfo(*L);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P) {
    /* Kamus Lokal */

    /* Algoritma */
	if(isEmpty(*L))
	{
	    Next(P) = First(*L);
	    Prev(P) = Nil;
	    First(*L) = P;
	    Last(*L) = P;
	} else
	{
	    Next(P) = First(*L);
	    Prev(First(*L)) = P;
	    First(*L) = P;
	}
}

void InsertAfter (List *L, address P, address Prec){
	/* Kamus Lokal */

	/* Algoritma */
	if(isAkhir(*L, Prec))
	{
		Next(Prec) = P;
		Prev(P) = Prec;
		Next(P) = NULL;
		Last(*L) = P;
	} else
	{
		Next(P) = Next(Prec);
		Prev(P) = Prec;
		Prev(Next(Prec)) = P;
		Next(Prec) = P;
	}
}

void InsertLast (List *L, address P) {
    /* Kamus Lokal */
    address Node;
    /* Algoritma */
    if (isEmpty(*L)){
    	InsertFirst(L,P);
    } else {
      	InsertAfter(L,P,Last(*L));
    }
}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P) {
    /* Kamus Lokal */
    /* Algoritma */
    *P = First(*L);
    First(*L) = Next(First(*L));
}

void DelP (List *L, infotype X) {
	/* Kamus Lokal */
	address P, Prec;
	infotype Y;
	boolean kehapus;

	/* Algoritma*/
  	kehapus = false;
  	P = First(*L);
  	if (Info(P) == X) {
    	DelVFirst(L,&Y);
  	} else {
    	Prec = Nil;
    	while ((P != Nil)&&(!kehapus)) {
	      	if (Info(P) == X) {
	        	DelAfter(L,&P,Prec);
	        	Dealokasi(&P);
	        	kehapus = true;
	      	} else {
	        	Prec = P;
	        	P = Next(P);
	      	}
    	}
  	}
}

void DelLast (List *L, address *P) {
	/* Kamus Lokal */
	address Preclast;

	/* Algoritma */
	Preclast = Prev(Last(*L));
	Next(Preclast) = Nil;
	(*P) = Last(*L);
}

void DelAfter (List *L, address *Pdel, address Prec) {
    /* Kamus Lokal */
	address P;

    /* Algoritma */
    *Pdel = Next(Prec);
	if(Next(Next(Prec)) != NULL)
	{
		P = Next(Next(Prec));
	    Next(Prec) = P;
		Prev(P) = Prec;
	    Next(*Pdel) = Nil;
	    Prev(*Pdel) = Nil;
	} else
	{
	    Next(*Pdel) = Nil;
	    Prev(*Pdel) = Nil;
	    Next(Prec) = Nil;
	}
}

/* Proses Semua Elemen List */
void PrintInfo (List L) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(L);
    if (P == Nil) {
      printf("List kosong\n");
    } else {
    	while(Next(P) != Nil) {
    		printf("%d->",Info(P));
    		P = Next(P);
    	}
      	printf("%d", Info(P));
		printf("\n");
    }
}

void PrintInfoReverse(List L) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Last(L);
    if (P == Nil) {
      printf("List kosong\n");
    } else {
    	while(Prev(P) != Nil) {
    		printf("%c->",Info(P));
    		P = Prev(P);
    	}
      	printf("%c", Info(P));
		printf("\n");
    }
}

int NbElmt (List L) {
    /* Kamus Lokal */
    address P;
    int i;

    /* Algoritma */
    i = 0;
    P = First(L);
    while (P != Nil) {
       i++;
       P = Next(P);
    }
    return i;
}

/* Prekondisi untuk Max/Min/rata-rata : List tidak kosong */
infotype Max (List L) {
    /* Kamus Lokal */
    infotype maksimum;
    address P;
    /* Algoritma */
	if(!isEmpty(L))
	{
	    P = First(L);
	    maksimum = Info(P);
	    P = Next(P);
	    while (P != Nil) {
	    	if (maksimum < Info(P)) {
	    		maksimum = Info(P);
	      	}
	      	P = Next(P);
	    }
	    return maksimum;
	} else
	{
		return false;
	}
}

address AdrMax (List L) {
    /* Kamus Lokal */
    infotype maksimum;
    address P;
    /* Algoritma */
	if(!isEmpty(L))
	{
	    maksimum = Max(L);
	    P = Search(L,maksimum);
	    return P;
	} else
	{
		return Nil;
	}
}

infotype Min (List L) {
    /* Kamus Lokal */
    infotype minimum;
    address P;

    /* Algoritma */
	if(!isEmpty(L))
	{
	    P = First(L);
	    minimum = Info(P);
	    P = Next(P);
	    while (P!=Nil) {
	    	if (minimum>Info(P)) {
	        	minimum = Info(P);
	      	}
	      	P = Next(P);
	    }
	    return minimum;
	}
	else
	{
		return 0;
	}
}

address AdrMin (List L) {
    /* Kamus Lokal */
    infotype minimum;
    address P;

    /* Algoritma */
	if(!isEmpty(L))
	{
	    minimum = Min(L);
	    P = Search(L,minimum);
	    return P;
	} else
	{
		return Nil;
	}
}

infotype Average (List L) {
    /* Kamus Lokal */
    float sum;
    address P;

    /* Algoritma */
    if (NbElmt(L) != 0) {
    	P = First(L);
    	sum = Info(P);
    	P = Next(P);
      	while (P != Nil) {
    		sum += Info(P);
        	P = Next(P);
      	}
      	return sum/NbElmt(L);
    } else {
      	return 0;
    }
}

/* ----- Proses Terhadap List */
void DelAll (List *L) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    while (P != Nil) {
    	First(*L) = Next(First(*L));
    	Next(P) = Nil;
    	Dealokasi(&P);
    	P = First(*L);
    }
    CreateList(L);
}

void InversList (List *L) {
    /* Kamus Lokal */
    address P, Pt;
    /* Algoritma */
    P = First(*L);
   	while (Next(P) != Nil) {
       	DelAfter(L,&Pt,P);
       	InsertFirst(L,Pt);
   	}
   	printf("\nInvers Berhasil\n");
   	PrintInfo(*L);
}

List FInversList (List L) {
    /* Kamus Lokal */
    List Li;
    address P, Pt;
    boolean gagal;

    /* Algoritma */
    gagal = false;
    CreateList(&Li);
    P = First(L);
    while (P != Nil && !gagal) {
    	Pt = Alokasi(Info(P), Simbol(P));
    	if (Pt != Nil) {
        	InsertLast(&Li, Pt);
        	P = Next(P);
      	} else {
        	DelAll(&Li);
        	gagal = true;
      	}
    }
    return Li;
}

void CopyList (List L1, List *L2) {
    /* Kamus Lokal */

    /* Algoritma */
    First(*L2) = First(L1);
}

List FCopyList (List L) {
    /* Kamus Lokal */
    address P, Pt;
    List Lt;
    boolean gagal;

    /* Algoritma */
    gagal = false;
    CreateList(&Lt);
    P = First(L);
    while ((P != Nil)&&(!gagal)) {
    	Pt = Alokasi(Info(P), Simbol(P));
    	if (Pt != Nil) {
        	InsertLast(&Lt,Pt);
        	P = Next(P);
      	} else {
        	gagal = true;
        	DelAll(&Lt);
      	}
    }
    return Lt;
}

void CpAlokList (List Lin, List *Lout) {
    /* Kamus Lokal */
    address P, Pt;
    boolean gagal;

    /* Algoritma */
    CreateList(Lout);
    gagal = false;
    P = First(Lin);
    while ((P != Nil)&&(!gagal)) {
    	Pt = Alokasi(Info(P), Simbol(P));
      	if (Pt != Nil) {
        	InsertLast(Lout,Pt);
        	P = Next(P);
      	} else {
        	gagal = true;
        	DelAll(Lout);
      	}
    }
}

void Konkat (List L1, List L2, List *L3) {
    /* Kamus Lokal */
    address P, Pt;
    boolean gagal;

    /* Algoritma */
    CreateList(L3);
    gagal = false;
    P = First(L1);
    while ((P != Nil)&&(!gagal)) {
    	Pt = Alokasi(Info(P), Simbol(P));
      	if (Pt != Nil) {
        	InsertLast(L3,Pt);
        	P = Next(P);
      	} else {
        	gagal = true;
        	DelAll(L3);
      	}
    }
    if (!gagal) {
    	P = First(L2);
      	while ((P != Nil)&&(!gagal)) {
        	Pt = Alokasi(Info(P), Simbol(P));
        	if (Pt != Nil) {
          		InsertLast(L3,Pt);
          		P = Next(P);
        	} else {
          		gagal = true;
          		DelAll(L3);
        	}
      	}
    }
}

void Konkat1 (List *L1, List *L2, List *L3) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L1);
    CreateList(L3);
    First(*L3) = First(*L1);
    if (P != Nil) {
    	while (Next(P) != Nil) {
        	P = Next(P);
      	}
    }
    Next(P) = First(*L2);
    CreateList(L1);
    CreateList(L2);
}

void PecahList (List *L1, List *L2, List L) {
    /* Kamus Lokal */
    address P, Pt;
    boolean gagal;
    int i, N;


    /* Algoritma */
    CreateList(L1);
    CreateList(L2);
    gagal = false;
    i = 1;
    N = NbElmt(L)/2;
    P = First(L);
    while ((P != Nil) && (!gagal)) {
    	Pt = Alokasi(Info(P), Simbol(P));
    	if (i <= N) {
        	if (Pt != Nil) {
          		InsertLast(L1,Pt);
          		P = Next(P);
          		i++;
        	} else {
          		gagal = true;
          		DelAll(L1);
        	}
      	} else {
        	if (Pt != Nil) {
	          	InsertLast(L2,Pt);
	          	P = Next(P);
	          	i++;
	        } else {
	        	gagal = true;
	          	DelAll(L2);
	        }
      	}
    }
}
