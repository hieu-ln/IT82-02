// BAI 7 : Quan ly 1 QUEUE co toi da 100 phan tu, moi phan tu co kieu INT ( QUEUE DS DAC)

#include <stdio.h>
#include <iostream>
using namespace std;


//7.1 Khai bao cau truc QUEUE
#define MAX 100
int a[MAX];
int front, rear;
//7.2 Viet thu tuc khoi tao QUEUE rong 
void Init ( int a[], int &front, int &rear)
{
	front = -1;
	rear = -1 ;
}
// 7.3 Viet thu tuc kiem tra QUEUE rong 
int isEmpty (int a[], int &front , int &rear )
{
	if( front == rear)
		return 1;
	else
		return 0;
}
//7.4 Viet thu tuc kiem tra QUEUE day
int isFull(int a[], int &front, int &rear)
{
	if((front == 0 && rear == MAX-1)||( front-rear==1))
		return 1;
	else 
		return 0;
}

// 7.5 Viet thu tuc them mot phan tu vao QUEUE
int Push ( int a[], int &front, int &rear, int x)
{
	if (rear - front == MAX-1)
		return 0;
	else
	{
		if ( front == -1 )
			front = 0;
		if ( rear == MAX-1 )
		{
			for (int i =front ;i<= rear; i++)
			{
				a[i-front]= a[i];
			}
			rear = MAX-1-front ;
			front= 0;
		}
		a[++rear]= x;
		return 1;
	}
}

// 7.6  Viet thu tuc xoa mot phan tu trong QUEUE
int Pop ( int a[], int &front, int &rear, int &x)
{
	if( front==-1 )
		return 0;
	else
	{
		x = a[front++];
		if(front > rear)
		{
			front = -1;
			rear = -1 ;
		}
		return 1;
	}
}
// 7.7 Xuat QUEUE 
void Process_queue( int a[], int f, int r)
{
	cout<<" front = "<< f<<"   rear = "<< r << endl;
	if( f<= r && f!= -1 )
	{
		cout << " <--     ";
		for ( int i= f; i < r+1; i++)
		{
			cout << a[i]<< "   " ;
		}
		cout << " <---     "<< endl;
	}
}


int main ()
{
	int a[MAX];
	int choice, f, r, x,i;
	system ("cls");
	 
	cout << " ----BAI 7_CHUONG 2_HANG DOI QUEUE ( DANH SACH DAC )-----"<< endl;
	cout <<" 1. Khoi tao QUEUE rong ." << endl;
	cout <<" 2. Them phan tu vao QUEUE >"<< endl;
	cout <<" 3. Lay mot phan tu khoi QUEUE ."<< endl;
	cout <<" 4. Kiem tra QUEUE rong ."<< endl;
	cout <<" 5. Kiem tra QUEUE day . "<< endl;
	cout <<" 6. Xuat QUEUE . "<< endl;
	cout <<" 7. Thoat ! "<< endl;

	do
	{
		cout << " Vui long chon thao tac thuc hien :" ;
		cin >> choice;
		switch ( choice)
		{
		case 1:
			Init(a,f,r);
			cout << " Ban da khoi tao thanh cong mot QUEUE rong ! "<< endl;
			break;
		case 2:
			cout << " Vui long nhap phan tu can them vao QUEUE : ";
			cin >> x;
			i = Push(a,f,r,x);
			cout << " Ban da thm thanh con phan tu x = "<< x ;
			cout << " QUEUE sau khi them la : "<< endl;
			Process_queue(a,f,r);
			break;
		case 3:
			i= Pop(a,f,r,x);
			cout << " Phan tu lay ra tu QUEUE la x= "<< x << endl;
			cout << " QUEUE sau khi lay ra la : "<< endl;
			Process_queue(a,f,r);
			break;
		case 4:
			i= isEmpty(a,f,r);
			if ( i== 0)
				cout << " QUEUE khong rong !"<< endl;
			else
				cout << " QUEUE rong !"<< endl;
			break;
		case 5:
			i = isFull(a,f,r);
			if ( i==0 )
				cout <<" QUEUE chua day !"<< endl;
			else
				cout << " QUEUE da day ! "<< endl;
			break;
		case 6 :
			cout << " QUEUE hien tai la: "<< endl;
			Process_queue(a,f,r);
			break;
		case 7:
			cout << " --- GOODBYE---"<< endl;
			break;
		}
	}
	while (choice !=7);
	system ("pause");
	return 0;

}