//bai03
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};Node *first ;

void init()
{
	first = NULL;
}

void process_list()
{
	Node *p = first ;
	while(p!= NULL)
	{
		cout << p ->info  << endl;
		p = p ->link ;
	}
}

Node *serch(int x)
{
	Node *p = first ;
	while(p!= NULL && p ->info != x)
	{
		p = p ->link;
	}
	return p;
}

void insert_first(int x)
{
	Node *p;
	p = new Node ;
	p ->info = x;
	p ->link = first ;
	first = p;
}

int delete_first()
{
	if(first != NULL)
	{
		Node *p = first ;
		first = p ->link;
		delete p;
		return 1;
	}
	return 0;
}

void insert_last(int x)
{
	Node *p;
	p = new Node ;
	p -> info = x;
	p -> link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first ;
		while(q ->link != NULL)
			q = q ->link;
		q ->link = p;
	}
}

int delete_last()
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first, q = NULL;
		if(p != NULL)
			while(p ->link != NULL)
			{
				q = p;
				p = q ->link;
			}
		if(p!=first)
			q ->link = NULL;
		else
			first = NULL ;
		delete p;
		return 1;
	}
	return 0;
}


int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	cout << ".............BAI TAP 01, CHUONG 01 - DSLK DON \n" ;
	cout << "1.khoi tao danh sach lien ket don \n";
	cout << "2.them phan tu vao dau DSLK don \n";
	cout << "3.them phan tu vao cuoi DSLK don \n";
	cout << "4.xoa phan tu dau DSLK don \n" ;
	cout << "5.xoa phan tu cuoi DSLK don \n" ;
	cout << "6.tim phan tu voi gia tri x va xoa no \n" ;
	cout << "7. Thoat\n";
	do{
		cout <<"chon so de thuc hien! \n";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "khoi tao DSLK don thanh cong! \n";
			break;
		case 2:
			cout << "nhap gia tri can them: ";cin >> x;
			insert_first( x);
			cout << "danh sach sau khi them la: \n";
			process_list();
			break;
		case 3:
			cout << "nhap gia tri can them: ";cin >> x;
			insert_last( x);
			cout << "danh sach sau khi them la: \n";
			process_list();
			break;
		case 4:
			i = delete_first();
			if( i == 0)
				cout << "danh sach rong !\n";
			else
			{
				cout << "da xoa dau thanh cong!\n ";
				cout << "danh sach sau khi xoa la: \n";
				process_list();
			}
			break;
		case 5:
			i = delete_last();
			if( i == 0)
				cout << "danh sach rong !\n";
			else
			{
				cout << "da xoa dau thanh cong!\n ";
				cout << "danh sach sau khi xoa la: \n";
				process_list();
			}
			break;

		case 7:
			cout << "TAM BIET !\n";
			break;
		default:
			break;
		}
	}while(choice != 7);
	system("pause");
	return 0;

}
