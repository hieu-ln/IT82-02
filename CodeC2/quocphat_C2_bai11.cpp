//BAI 11-CHUONG02
#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node* link;
};Node* rear, *font ;

void init()
{
	rear = NULL;
	font = NULL ;
}

int isEmpty()
{
	if(font == rear)
		return 1;
	return 0;
}

void push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL ;
	if(rear == NULL)
		font = p ;
	else
		rear->link = p;
	rear = p;
}

void pop(int &x)
{
	if(font!=NULL)
	{
		Node* p= font ;
		x = p->info;
		font = p->link;
		delete p;
	}
}

void process_queue()
{
	Node* p = font;
	cout << "<--" ;
	while(p != NULL)
	{
		cout << p->info << " ";
		cout <<"<--" ;
		p = p ->link;
	}
}
int main()
{
	int choice = 0;
	int x;
	system("cls");
	cout << "............BAI TAP 11- CHUONG 02- QUEUE LKD......\n" ;
	cout << "1.khoi tao QUEUE rong \n" ;
	cout<<"2.kiem tra QUEUE rong \n" ;
	cout <<"3.them phan tu vao QUEUE \n" ;
	cout <<"4.xoa phan tu trong QUEUE \n" ;
	cout <<"5.thoat \n" ;
	do{ 
		cout <<"nhap so de chon: ";cin >> choice ;
		switch(choice)
		{
		case 1:
			init();
			cout <<"khoi tao QUEUE rong thanh cong! \n";
			break;
		case 2:
			if(isEmpty() == 1)
				cout <<"QUEUE rong! \n";
			else
				cout <<"QUEUE ko rong \n";
			break;
		case 3:
			cout <<"nhap gia tri can them: ";cin >> x;
			push( x);cout <<"QUEUE sau khi them la: \n" ;
			process_queue();
			break;
		case 4:
			pop( x);cout <<"QUEUE sau khi xoa la: \n" ;
			process_queue();
			break;
		case 5:
			cout <<"GOODBYE! \n" ;
		default:
			break;
		}
	}while(choice != 5);
	system("pause");
	return 0;
}