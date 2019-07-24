#include <stdio.h>
#include <iostream>
using namespace std;

 
// 5.1 : Khai bao cau truc STACK 
#define MAX 100
int a[MAX];
int sp;

//5.2: Viet thu tuc khoi tao STACK rong
void Init ( int a[], int &sp)
{
	sp = -1;
}

//5.3: Viet thu tuc kiem tra STACK rong
int isEmpty (int a[], int sp)
{
	if (sp == -1 )
		return 1;
	return 0;
}

//5.4: Viet thu tuc kiem tra STACK day 
int isFull ( int a[], int sp)
{
	if (sp == MAX -1 )
		return 1;
	return 0;

}

//5.5: Viet thu tuc them mot phan tu vao STACK 
int Push( int a[], int &sp, int x)
{
	if (sp < MAX -1 )
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

//5.6 Viet thu tuc xoa mot phan tu trong STACK
int Pop ( int a[], int&sp, int x)
{
	if ( sp != -1 )
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//5.7: Xuat STACK 
 void Process_stack( int a[], int sp)
 {
	 for ( int i =0; i < sp + 1 ; i++ )
	 {
		 cout << a[i]<<"  " ;
	 }
	 cout << endl;
 }

 int main ()
 {
	 int a[MAX]; 
	 int choice, sp, x, i;
	 system ("cls");
	 cout << " --------- BAI TAP 5 _ CHUONG 2_ STACK ( NGAN XEP _ DS DAC )---------" << endl;
	 cout <<" 1. Khoi tao Stack rong . "<< endl;
	 cout <<" 2. Them phan tu vao Stack ."<< endl;
	 cout <<" 3. Lay phan tu ra khoi Stack ." << endl;
	 cout <<" 4. Kiem tra Stack co rong hay khong. "<< endl;
	 cout <<" 5. Kiem tra Stack co day hay khong . " << endl;
	 cout <<" 6. Xuat Stack. " << endl;
	 cout <<" 7. Thoat ! "<< endl;
	  do 
	  {
		  cout << "  Vui long chon thao tac thuc hien : " ;
		  cin >> choice;
		  switch ( choice )
		  {
		  case 1:
			  Init(a, sp);
			  cout << " Ban vua khoi tao thanh cong Stack rong !" << endl;
			  break;
		  case 2:
			  cout <<" Vui long nhap phan tu muon them vao Stack : ";
			  cin >> x;
			  i = Push(a,sp,x);
			  cout << " Ban da tham thanh cong phan tu x " << x << " vao Stack ! "<<endl;
			  cout << " Stack sau khi them la : "<< endl;
			  Process_stack(a, sp);
			  break;
		  case 3:
			  i = Pop(a,sp,x);
			  cout << " phan tu lay ra khoi Stack x = "<< x<< endl;
			  cout << " Stack sau khi lay phan tu la : " << endl;
			  Process_stack(a,sp);
			  break;
		  case 4:
			i = isEmpty(a,sp);
			if ( i == 0)
				cout << " STACK khong rong ! "<< endl;
			else 
				cout << " STACK rong ! "<< endl;
			break;
		  case 5:
			  i= isFull(a,sp);
			  if ( i == 0)
				  cout << " STACK chua day ! "<< endl;
			  else 
				  cout << " STACK da day! " << endl;
			  break;
		  case 6:
			  cout << " STACK hien tai la : " << endl;
			  Process_stack(a,sp);
			  break;
		  case 7:
			  cout << " ---- GOODBYE----"<< endl;
			  break;
		  }
	  }
	  while ( choice != 7);
	  system("pause");
	  return 0;
 }
