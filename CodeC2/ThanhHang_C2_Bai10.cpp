// Quan ly mot Stack co so phan tu kha lon , bien dong . Moi phan tu co kieu INT ( DSLK DON )
 
#include <stdio.h>
#include <iostream>
using namespace std;

//10.1 Khai bao cau truc STACK
struct Node 
{
	int info;
	 Node *link;
};
Node *sp;
//10.2 Viet thu tuc tao STACK rong 
void Init ()
{
	sp = NULL;
}
// 10.3 Viet thu tuc kiem tra STACK rong
 int isEmpty ()
	 {
	if (sp == NULL )
		return 1;
	return 0;
}
//10.4 Viet thu tuc them mot phan tu vao STACK 
 void Push ( int x)
 {
	 Node *p = new Node;
	 p->info = x;
	 p->link = sp;
	 sp = p;
 }

//10.5 Viet thu tuc xoa mot phan tu trong STACK
 int Pop ( int &x)
 {
	 if ( sp != NULL )
	 {
		 Node *p = sp;
		 x = p->info;
		 sp = p->link;
		 delete p;
		 return 1;
	 }
	 return 0;
 }

//10.6  Ap dung STACK da xay dung giai bai toan doi mot so tu he thap phan sang he nhi phan 

//10.7 Ap dung STACK da xay dung giaibai toan THAP HA NOI

// 10.8 Xuat STACK
 void Process_stack()
 {
	 Node *p = sp;
	 do 
	 {
		 cout << p->info << "  " ;
		 p = p->link;
	 }
	 while ( p != NULL);
	 cout<< endl;
 }


 int main ()
 {
	 int choice, sp, x, i;
	 system ("cls");
	 cout << " --------- BAI TAP 10_ CHUONG 2_ STACK ( NGAN XEP _ DSLK DON )---------" << endl;
	 cout <<" 1. Khoi tao Stack rong . "<< endl;
	 cout <<" 2. Them phan tu vao Stack ."<< endl;
	 cout <<" 3. Lay phan tu ra khoi Stack ." << endl;
	 cout <<" 4. Xuat Stack. "<< endl;
	 cout <<" 5. Thoat  . " << endl;

	 do 
	  {
		  cout << "  Vui long chon thao tac thuc hien : " ;
		  cin >> choice;
		  switch ( choice )
		  {
		  case 1:
			  Init();
			  cout << " Ban vua khoi tao thanh cong Stack rong !" << endl;
			  break;
		  case 2:
			  cout <<" Vui long nhap phan tu muon them vao Stack : ";
			  cin >> x;
			  Push(x);
			   cout << " Stack sau khi them la : "<< endl;
			  Process_stack();
			  break;
		  case 3:
			  Pop(x);
			  cout<<" Phan tu lay ra khoi Stack x = "<< x<< endl;
			  cout << " Stack sau khi lay phan tu la : " << endl;
			  Process_stack();
			  break;
		  case 4:
			  cout << " STACK hien tai la : " << endl;
			  Process_stack();
			  break;
		  case 5:
			  cout << " ---- GOODBYE----"<< endl;
			  break;
		  }
	  }
	  while ( choice != 5);
	   system("pause");
	  return 0;
 }
