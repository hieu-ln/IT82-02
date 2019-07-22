// BAI 11 : Quan ly 1 QUEUE co so phan tu kha lon, moi phan tu co kieu INT ( QUEUE DSLK DON)

#include <stdio.h>
#include <iostream>
using namespace std;


//11.1 Khai bao cau truc QUEUE
struct Node 
{
	int info;
	Node *link;
};
Node *front , *rear;
//11.2 Viet thu tuc khoi tao QUEUE rong
void Init ()
{
	front = NULL;
	rear = NULL;
}
//11.3 Viet thu tuc kiem tra QUEUE rong
int isEmpty ( )
{
	if( front == NULL)
		return 1;
	else
		return 0;
}
//11.4 Viet thu tuc them mot phan tu vao QUEUE
void Push ( int x)
{
	Node *p = new Node ;
	p->info = x;
	p->link = NULL;
	if (rear == NULL )
		front = NULL;
	else
		rear->link = p;

	rear = p;
}
//11.5 Viet thu tuc xoa mot phan tu trong QUEUE
 int Pop ( int &x)
 {
	 if ( front != NULL )
	 {
		 Node *p = front ;
		 front = p->link;
		 x = p->info;
		 if ( front == NULL)
		 {
			 rear = NULL;
		 }
		 delete p;
		 return 1;
	 }
	 return 0;
 }
//11.6 XUat QUEUE
 void Process_queue()
 {
	 if ( front != NULL)
	 { 
		 Node *p = front ;
		 cout << "<---   ";
		 do 
		 {
			 cout << p->info << "  ";
			 p = p->link;
		 }
		 while ( p!= NULL );
		 cout << " <---  "<< endl;
	 }
 }

 int main ()
{
	int choice, x,i;
	system ("cls");
	 
	cout << " ----BAI 7_CHUONG 2_HANG DOI QUEUE ( DANH SACH DAC )-----"<< endl;
	cout <<" 1. Khoi tao QUEUE rong ." << endl;
	cout <<" 2. Them phan tu vao QUEUE >"<< endl;
	cout <<" 3. Lay mot phan tu khoi QUEUE ."<< endl;
	cout <<" 4. Kiem tra QUEUE rong ."<< endl;
	cout <<" 5. XUat QUEUE . "<< endl;
	cout <<" 7. Thoat ! "<< endl;

	do
	{
		cout << " Vui long chon thao tac thuc hien :" ;
		cin >> choice;
		switch ( choice)
		{
		case 1:
			Init();
			cout << " Ban da khoi tao thanh cong mot QUEUE rong ! "<< endl;
			break;
		case 2:
			cout << " Vui long nhap phan tu can them vao QUEUE : ";
			cin >> x;
			Push(x);
			cout << " Ban da thm thanh con phan tu x = "<< x ;
			cout << " QUEUE sau khi them la : "<< endl;
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << " Phan tu lay ra tu QUEUE la x= "<< x << endl;
			cout << " QUEUE sau khi lay ra la : "<< endl;
			Process_queue();
			break;
		case 4:
			i= isEmpty();
			if ( i== 0)
				cout << " QUEUE khong rong !"<< endl;
			else
				cout << " QUEUE rong !"<< endl;
			break;
		case 5 :
			cout << " QUEUE hien tai la: "<< endl;
			Process_queue();
			break;
		case 6:
			cout << " --- GOODBYE---"<< endl;
			break;
		}
	}
	while (choice !=7);
	system ("pause");
	return 0;
 }