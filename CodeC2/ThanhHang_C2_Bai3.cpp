// chương 2 _ bài 3 _ danh sach Lien ket
#include <stdio.h>
#include <iostream>
using namespace std;

// Cau 3.1: Khai bao cau truc ds
struct Node {
	int info;
	Node *link;};
Node *first;

// Cảu.2: Khi tao ds rong
 void Init ()
 {
	 first = NULL;
 }

 // Cau 3.3: Xuat cac phan tu trong ds
 void Process_list()
 {
	 Node *p ;
	 p = first;
	 while(p != NULL)
	 {
		 cout << p->info <<"\t";
		 p = p->link;
	 }
	  cout << endl;
 }

 // Cau 3.4: Tim mot phan tu trong ds
 Node *Search ( int x)
 {
	 Node *p = first;
	 while (p != NULL && p->info != x)
	 {
		 p= p->link;
	 }
	 return p;
 }

// Cau 3.5: them phan tu vao dau ds
 void Insert_first( int x)
 {
	 Node *p;
	 p = new Node ;
	 p->info = x;
	 p->link = first;
	 first = p;
 }


 // Cau 3.6: Xoa phan tu dau ds
  int Delete_first()
  {
	  if ( first != NULL)
	  {
		  Node *p = first ;
		  first = first->link;
		   delete p;
		   return 1;
	  }
	  return 0;
  }

  // Cau 3.7: Them phan tu cuoi ds
  void Insert_last( int x)
  {
	  Node * p ;
	  p = new Node;
	  p ->info= x;
	  p->link = NULL;
	  if ( first == NULL)
		  first = p;
	  else 
	  {
		  Node *q = first ;
		  while ( q->link != NULL)
			  q= q->link;
		  q->link = p;
	  }
  }

  // Cau 3.8: xoa phan tu cuoi ds
 int Delete_last ()
 {
	 if ( first != NULL)
	 {
		 Node *p, *q;
		  p = first ;
		  q = NULL;
		  if (p != NULL)
			  while (p->link != NULL)
			  {
				  q = p; p=p->link;
			  }
		if (p != first )
				q ->link = NULL;
		else first = NULL;	 
		delete p;
		
		return 1;
	 }
	 return 0;
 }

 // Cau 3.9:  tim pt trong ds , roi xoa pt nay neu co
 int searchAndDelete( int x)
 {
	 if ( first != NULL)
	 {
		 Node *p, *q;
		  p = first ;
		  q = first;
		  while ( p->info != x)
		  {
			  q= p;
			  p=p->link;
		  }
		   if (p != first && p != NULL)
		   {
			   if ( p->link != NULL)
				   q->link = p->link;
			   else
				   q->link = NULL;
			   delete p;
			   return 1;
		   }
		   else if (p == first )
		   {
			   first = p->link;
			   delete p;
			   return 1;
		   }
		   else
			   return 0;
	 }
	  return 0;
 }

 // Cau 3.10: 
void Sort ()
 {
 }
 // Cau 3.11: 
void SortDesc()
{
}


 int main()
 { 
	 int choice = 0;
	  int x, i ;
	  Node *p;
	  system("cls");
	  cout << " -------BAI TAP 3 _ CHUONG 2 _ DANH SACH LIEN KET DON--------"<< endl;;
	  cout << "1.Khoi tao DSLK DON rong"<< endl;
	  cout << "2.Them phan tu vao dau DSLK DON "<<endl;
	  cout << "3.Them phan tu vao cuoi DSLK DON"<<endl;
	  cout << "4.Xoa phan tu dau DSLK DON"<< endl;
	  cout << "5.Xoa phan tu cuoi DSLK DON"<< endl;
	  cout << "6.Xuat DSLK DON" << endl;
	  cout << "7.Tim phan tu co gia tri x trong DSLK DON"<< endl;
	  cout << "8.Tim phan tu co gia tri x  va xoa no neu co "<< endl;
	  cout << "9. Sap xep DSLK DON tang dan"<< endl;
	  cout << "10. Sap xep DSLK DON giam dan"<< endl;
	  cout << "11.Thoat"<< endl;
	  do 
	  {
		  cout << " Vui long chon so de thuc hien:";
		   cin>> choice;
		   switch ( choice)
		   {
		   case 1:
			   Init ();
			   cout<<" khoi ta DSLK DON thanh cong!"<<endl;
			   break;
		   case 2:
			   cout <<" Vui long nhap gtri x:";
			   cin>> x;
			   Insert_first(x);
			   cout << " DS sau khi them la:";
			   Process_list();
			   break;
		   case 3:
			   cout <<"Vui long nhap gtri x:";
			   cin>> x;
			   Insert_last(x);
			   cout << " DS sau khi them la:";
			   Process_list();
			   break;
		   case 4:
			   i = Delete_first ();
			   if (i == 0)
				   cout << " DS rong khong the xoa!"<< endl;
			   else
			   {
				    cout << " Da xoa thanh cong phan tu dau trong DSLK DON!"<< endl;
					cout << " DS sau khi xoa:"<< endl;
					 Process_list();
			   }
			    break;
		   case 5:
			   i = Delete_last ();
			   if (i == 0)
				   cout << " DS rong khong the xoa!"<< endl;
			   else
			   {
				    cout << " Da xoa thanh cong phan tu cuoi trong DSLK DON!"<< endl;
					cout << " DS sau khi xoa:"<< endl;
					 Process_list();
			   }
			    break;
		   case 6:
			   cout << " DS hien tai la:";
			   Process_list();
			   break;
		   case 7:
			   cout << " Vui long nhap gia tri can tim :";
			   cin >> x;
			   p = Search (x);
			   if (p != NULL)
			   {
				   cout <<" Tim thay phan tu co gia tri x = "<< x<< endl;
			   }
			   else 
				   cout << "Khong tim thay phan tu co gia tri x = "<< x<< endl;
			   break;
		   case 8:
			   cout << " Vui long nhap gia tri can tim :";
			   cin >> x;
			   i = searchAndDelete (x);
			   if ( i ==1 )
			   {
				   cout << "Tim thay x ="<< x<< " va da xoa thanh cong "<< endl;
				    cout <<"DS sau khi xoa:"<< endl;
					Process_list();
			   }
			   else 
				   cout <<"Khong tim thay phan tu co gia tri x = "<< x<< endl;
			   break;
		   case 9:
			   Sort();
			   cout<< " DS sau khi sap xep tang dan la:";
			   Process_list(); 
			   break;
		   case 10:
			   SortDesc();
			   cout<< " DS sau khi sap xep giam dan la:";
			   Process_list(); 
			   break;
		   case 11:
			   cout << " Goodbye......!"<< endl;
		   }
	  }while ( choice != 11);
	  system (" pause");
	  return 0;

 }