//bai10- chuong 02
#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node* link;
};Node* sp;

void init()
{
	sp = NULL;
}

int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}

void push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p ;
}

int cap(int &x)
{
	if(sp != NULL)
	{
		Node* p = sp ;
		x = p->info ;
		sp = p->link ;
		delete p;
		return 1;
	}
	return 0;
}

void process_stack()
{
	Node* p = sp;
	while(p != NULL)
	{
		cout << p->info << " ";
		p = p->link ;
	}
	cout << endl;
}

int main()
{
	int choice = 0;
	system("cls");
	int x;
	cout << ".............BAI TAP 10, CHUONG 02 - STACK \n" ;
	cout << "1.khoi tao STACK rong \n";
	cout << "2.kiem tra STACK rong \n";
	cout << "3.them 1 phan tu vao STACK \n";
	cout << "4.xoa 1 phan tu trong STack\n" ;
	cout << "5. Thoat\n";
	do{
		cout <<"chon so de thuc hien! \n";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(); 
			cout << "tao STACK rong thanh cong! \n";
			break;
		case 2:
			if(isEmpty() == 1)
				cout <<"STACk rong! \n";
			else
				cout << "STACk ko rong \n";
			break;
		case 3:
			cout << "nhap gia tri ban can them: ";cin >> x;
			push( x);cout << "STACk sau khi them la: \n";
			 process_stack();
			 break;
		case 4:
			if(cap(x) == 0)
				cout << "STACK rong! \n" ;
			else
			{
				cout << "STACk sau khi lay ra la: \n";
				process_stack();
			}
			break;
		case 5:
			cout << "GOODBYE!\n";
			break;
		default:
			break;
		}
	}while(choice != 5);
	system("pause");
	return 0;
}

