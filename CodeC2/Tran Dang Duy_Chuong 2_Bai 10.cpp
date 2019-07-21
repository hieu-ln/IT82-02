#include<iostream>
#include<stdio.h>
using namespace std;
//10.1
struct Node
{
	int info;
	Node *link;
};
Node *sp;
//10.2
void Init()
{
	sp = NULL;
}
//10.3
int isEmpty()
{
	if(sp==NULL)
		return 1;
	return 0;
}
//10.4
void Push(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}
//10.5
int Pop(int &x)
{
	if(sp != NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}
void Process()
{
	Node *p=sp;
	do{
		cout<<p->info<<" ";
		p=p->link;
	}while (p!=NULL);
	cout<<endl;
}
int main()
{
	int choice,x, i;
	system("cls");
	cout<<"Bai tap chuong 10: ";
	cout<<"1. Khoi tao stack rong"<<endl;
	cout<<"2. Them phan tu vao stack"<<endl;
	cout<<"3. Lay phan tu ra khoi stack"<<endl;
	cout<<"4 .Xuat stack"<<endl;
	cout<<"5 .Thoat"<<endl;
do
{
	cout<<"\nVui long chon so de thuc hien: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			Init();
			cout<<"Khoi tao STACK thanh cong: "<<endl;
			break;
		case 2:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			Push(x);
			cout<<"Stack sau khi them la: ";
			Process();
			break;
		case 3:
			Pop(x);
			cout<<"Phan tu lay ra tu Stack la: x="<<x<<endl;
			cout<<"Stack sau khi lay ra la: ";
			Process();
			break;
		case 4:
			cout<<"STACK hien tai la: ";
			Process();
			break;
		case 5:
			cout<<"Goodbye...!"<<endl;
			break;
		default:
			break;
	}
}while(choice!=5);
system("pause");
return 0;
}