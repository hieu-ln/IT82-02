//bai01
#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;

int a[MAX];
int n;

void input(int a[], int &n)
{
	for(int i = 0; i < n; i++)
		a[i] = rand() % 10;
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " " ;
	cout << endl;
}

int search(int a[],int n, int x)
{
	int i = 0;
	while(i < n && a[i] !=x)
		i++;
	if(i == n)
		return -1;
	return i;
}

void insert_last(int a[], int &n, int x)
{
	if(n < MAX)
	{
		a[n] = x;
		n++;
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << " " ;
	cout << endl;
}

void delete_last(int a[], int &n, int i)
{
	if(i >= 0 && i < n)
	{
		for(int j = i;j < n - 1;j++ )
			a[j] = a[j + 1] ;
		n--;
	}

}


void search_delete(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			delete_last( a,n, i);
	for(int i = 0; i < n; i++)
		cout << a[i] << " " ;
	cout << endl;
}

int main()
{
	int choice;
	int x,n, i;
	system("cls");
	cout << "nhap so phan tu ban can: ";cin >> n;
	cout <<"1.nhap danh sach\n";
	cout << "2.xuat danh sach\n";
	cout << "3.tim phan tu co gai tri x trong danh sach\n";
	cout <<"4.them phan tu vao cuoi danh sach\n";
	cout << "5.xoa phan tu cuoi danh sach\n";
	cout << "6.xoa phan tu tai vi tri i\n";
	cout << "7.tim phan tu x neu co va xoa\n" ;
	cout << "8.thoat\n";
	do{
		cout << "chon so de thuc hien: " ;
		cin >> choice ;
		switch(choice)
		{
			case 1:

				input(a,n);
				cout << "nhap danh sach vua xog\n" ;
				break;
			case 2:
				cout << "danh sach da nhap la: \n" ;
				output( a,  n);
				break;
			case 3:
				cout << "nhap gia tri can tim: ";cin >> x ;
				if(search( a, n,  x) != -1)
					cout << "x tai vi tri " << search( a, n,  x) << endl;
				break;
			case 4:
				cout <<  "them phan tu cuoi danh sach\n" ;cin >> x;
				insert_last(a,n, x) ;
				break;
			case 6:
				cout << "nhap vi tri can xoa: ";cin >> i ;
				delete_last( a,n,  i) ;output( a, n);
				break;
			case 7:
				cout << "tim phan tu x va xoa\n";
				cin >> x;
				search_delete( a,  n,  x);
			case 8:
					cout << "tam biet!\n";
					break;
			default:
				break;
		}
	}while(choice != 8 );
	system("pause");
	return 0;
}
