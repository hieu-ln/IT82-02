#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

int a[MAX] ;
int sp;

void init(int a[], int &sp)
{
	sp = -1;
}


void process_list(int a[], int &sp)
{
	for(int i = 0; i < sp; i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl;
}

int isEmpty(int a[],int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}

int isFull(int a[], int sp)
{
	if(sp == MAX - 1)
		return 0;
	return 1;
}

int push(int a[], int &sp, int x)
{
	if(sp < MAX -1)
	{
		a[++sp] = x ;
		return 1;
	}
	return 0 ;
}

int cap(int a[], int &sp, int &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

int main()
{
	int a[MAX] , x;
	int choice ;
	int sp;int i;
	cout << "nhap vao dinh sp: "; cin >> sp;
	cout << "1.khoi tao stack rong \n" ;
	cout << "2.kiem tra stack rong \n" ;
	cout << "3.kiem tra stack day \n" ;
	cout << "4.them mot phan tu vao stack \n" ;
	cout << "5.xoa mot phan tu trong stack \n" ;
	cout << "6.thoat\n" ;
	do{
		cout << "chon so de thuc hien: "; cin>> choice ;
		switch(choice)
		{
		case 1:
			init( a, sp);
			cout << "khoi tao stack thanh cong! \n" ;
			break;
		case 2:
			if(isEmpty( a, sp) == 1)
				cout << "stack rong!\n" ;
			else
				cout << "stack khong rong \n";
			break;
		case 3:
			if(isFull( a, sp) == 0)
				cout << "stack da day!\n" ;
			else
				cout << "stack chua day \n";
			break;
		case 4:
			cout << "nhap gia tri can them: "; cin >> x;
			 i = push( a,  sp,  x);
			cout << "stack sau khi them la: \n" ;
			process_list( a, sp);
			break;
		case 5:
			cout << "phan tu xoa tu stack la: " << cap( a, sp,  x) << endl;
			cout << "stack sau khi xoa la: \n";
			process_list( a, sp);
			break;
		case 6:
			cout << "goodbye! \n";
			break;
		default:
			break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}
