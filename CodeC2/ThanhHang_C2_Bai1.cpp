//Bai Thuc Hanh so 1 _ DS DAC

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

// cau 1 : khai bao cau truc 
int a[MAX];
int n;

//cau 2: Viet thu tuc nhap ds
void input( int a[], int &n)
{
	cout << " Nhap so luong phan tu cua DS: ";
	cin >> n;
	for(int i = 0; i< n ;i++)
	{
		cout << " a["<<i<<"] =";
		cin >> a[i];
		cout << endl;
	}
}

//cau 3 : Xuat DS ra man hinh
void output ( int a[], int n)
{
	for ( int i = 0; i< n ; i++)
	{
		cout << a[i]<< " \t" ;
	}
	 cout << endl;
}

// cau 4: Tim mot ptu trong Ds
int search ( int a[], int n, int x)
{
	int i = 0;
	while (i< n && a[i]!= x)
		i++;
	if ( i== n)
		return -1 ;
	else
		return i;
}

// cau 5: Them mot ptu vao cuoi Ds
int Insert_last ( int a[], int &n, int x)
{
	if ( n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return -1;
}

// Cau 6: Xoa mot ptu cuoi Ds
int Delete_last( int a[], int &n)
{
	if ( n> 0)
	{
		n--;
		return 1;
	}
	return -1;
}


// cau 7: Xoa mot ptu tai vtri thu i
 int Delete ( int a[], int &n, int i)
 {
	 if ( i >= 0 && i<= n)
	 {
		 for ( int j = i; j < n-1 ; j++)
		 {
			 a[j]= a[j+1];
		 }
		 n--;
		 return 1;
	 }
	 return 0;
 }

// Cau 8: Tim mot ptu trong Ds va xoa no neu tim thay trong Ds
 int  SearchAndDelete (int a[], int &n, int x)  // tim thay nhung 
 {
	 for ( int i = 0 ; i<n ; i++ )
	 {
		 if ( a[i]== x)
		 {
			 Delete ( a, n, i);
			 return 1;
		 }
	 }
	 return 0;
 }


 int main ()
 {
	 int choice =0;
	 int i, x;
	 system ("cls");
	 cout << " ----- BAI TAP THUC HANH 2 _ DANH SACH DAC----- "<< endl;
	 cout << " 1.Viet thu tuc nhap ds" << endl;
	 cout << " 2.Xuat DS ra man hinh " << endl;
	 cout << " 3.Tim mot ptu trong Ds " << endl;
	 cout << " 4.Them mot ptu vao cuoi Ds " << endl;
	 cout << " 5.Xoa mot ptu cuoi Ds " << endl;
	 cout << " 6.Xoa mot ptu tai vtri thu i " << endl;
	 cout << " 7.Tim mot ptu trong Ds va xoa no neu tim thay trong Ds " << endl;
	 cout << " 8.Thoat!"<< endl;
	 do 
	 {
		 cout << " Vui long chon thao tac thuc hien : " ;
		 cin >> choice;
		 switch ( choice)
		 {
		 case 1:
			 input (a, n);
			 cout << " Nhap DS thanh cong !"<< endl;
			 break;
		 case 2:
			 cout << " DS da nhap la : " << endl;
			 output( a,n);
			 break;
		 case 3:
			 cout << " Nhap phan tu can tim trong Ds: ";
			 cin >> x;
			 i = search ( a, n , x);
			 if ( i == -1 )
				  cout << " Khong tim thay phan tu "<< x << " trong Ds ."<< endl;
			 else
				cout << " Tim thay phan tu "<< x << " trong Ds" << endl;
			 break;
		 case 4:
			 cout << " Vuilong nhap phan tu can them vao Ds: ";
			 cin >> x;
			 i = Insert_last(a,n,x);
			 if ( i == 1 )
			 {
				  cout << " Them thanh cong phan tu "<< x << " vao Ds ! "<< endl;
				 cout << " Ds sau khi them thanh cong la : " << endl;
				 output( a, n);
			 }
			 else
			 {
				cout << " Khong the them phan tu "<< x << "vao Ds , Ds da day !"<< endl;
			 }
			 break;
		 case 5:
			 i = Delete_last(a,n);
			 if ( i == 1 )
			 {
				 cout << " Xoa thanh cong phan tu cuoi cung cua Ds !"<< endl;
				 cout << "Ds sau khi xoa la : " << endl;
				 output (a, n);
			 }
			 else
			 {
				  cout << " Ds rong khong the xoa phan tu cuoi cung  !" << endl;
			 }
			 break;
		 case 6:
			 cout << " Vui long nhap vi tri phan tu can xoa : " ;
			 cin >> x;
			 i = Delete(a, n, x);
			 if (  i == 1 )
			 {
				 cout << " Xoa thanh cong phan tu vi tri i = " << x << endl;
				 cout << " Ds sau khi xoa thanh cong la : "<< endl;
				 output (a, n);
			 }
			 else
			 {
				 cout << " Khong tim thay vi tri i = "<< x << "  de xoa ! " << endl;
			 }
			 break;
		 case 7:
			 cout << " Vui long nhap phan tu can xoa : ";
			 cin >> x;
			 i = SearchAndDelete (a, n ,x);
			 if (i == 1)
			 {
				 cout << " Tim thay phan tu x = "<< x<< " , Xoa thanh cong !"<< endl;
				 cout << " Ds sau khi xoa la : "<< endl;
				 output(a, n);
			 }
			 else
				 cout << " Khong tim thay phan tu x = " << x << endl;
			 break;
		 case 8:
			 cout << " ---- GoodBye....!-----"<< endl;
			 break;
		 default :
			 break;

		 }
	 }
	 while (choice != 8);
	 system ("pause");
	 return 0;
 }