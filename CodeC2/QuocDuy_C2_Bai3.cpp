////Chuong 2_Bai3_Danh sach LKD
//#include<iostream>
//#include<Windows.h>
//using namespace std;
//struct Node //Cau truc danh sach
//{
//	int info;
//	Node *link;
//};
//Node *first;
//void init() //Khoi tao danh sach rong
//{
//	first=NULL;
//}
//void output() //Thu tuc xuat danh sach
//{
//	Node *p;
//	p=first;
//	while(p!=NULL)
//	{
//		cout<<p->info<<" ";
//		p=p->link;
//	}
//	cout<<endl;
//}
//Node *Search(int x) //Tim phan tu x trong DSLK
//{
//	Node *p=first;
//	while(p!=NULL && p->info!=x)
//		p=p->link;
//	return p;
//}
//void Insert_first(int x) //Them mot phan tu vao dau danh sach
//{
//	Node *p;
//	p=new Node;
//	p->info=x;
//	p->link=first;
//	first=p;
//}
//int Delete_first() //Xoa mot phan tu dau danh sach
//{
//	while(first!=NULL)
//	{
//		Node *p=first;
//		first=first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void Insert_last(int x) //Them mot phan tu vao cuoi
//{
//	Node *p;
//	p=new Node;
//	p->info=x;
//	p->link=NULL;
//	if(first==NULL)
//		first=p;
//	else
//	{
//		Node *q=first;
//		while(q->link!=NULL)
//			q=q->link;
//		q->link=p;
//	}
//}
//int Delete_last() //Xoa cuoi danh sach
//{
//	Node *p,*q;
//	p=first;
//	q=NULL;
//	if(p!=NULL)
//	{	while(p->link!=NULL)
//		{
//			q=p;
//			p=p->link;
//		}
//		if(p!=first)
//			q->link=NULL;
//		else
//			first=NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int Search_Delete(int x) //Tim va xoa phan tu x
//{
//	if(first!=NULL)
//	{
//		Node *p,*q;
//		p=first;
//		q=first;
//		while(p->info!=x && p->link!=NULL)
//		{
//			q=p;
//			p=p->link;
//		}
//		if (p != first && p->link!= NULL)
//		{
//			if (p->link != NULL)
//				q->link = p->link;
//			else
//				q->link = NULL;
//			delete p;
//			return 1;
//		}
//		else
//		{
//			if (p == first)
//			{
//				first = p->link;
//				delete p;
//				return 1;
//			}
//			else
//			{
//				if (p->link == NULL && p->info == x)
//				{
//					q->link = NULL;
//					delete p;
//					return 1;
//				}
//				else
//					return 0;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice;
//	int x,i;
//	Node *p;
//	system("cls");
//	cout<<"--------Bai Tap 3, Chuong 2, DANH SACH LIEN KET DON--------"<<endl;
//	cout<<"1.Khoi tao danh sach rong\n";
//	cout<<"2.Them phan tu vao dau DSLK Don\n";
//	cout<<"3.Them phan tu vao cuoi DSLK Don\n";
//	cout<<"4.Xoa phan tu dau DSLK Don\n";
//	cout<<"5.Xoa phan tu cuoi DSLK Don\n";
//	cout<<"6.Xuat DSLK Don\n";
//	cout<<"7.Tim phan tu co gia tri x trong DSLK Don\n";
//	cout<<"8.Tim phan tu co gia tri x va xoa phan tu do\n";
//	cout<<"9.Thoat\n";
//	do
//	{
//		cout<<"Vui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			init();
//			cout<<"Ban da khoi tao thanh cong DSLK Don\n";
//			break;
//		case 2:
//			cout<<"Vui long nhap gia tri: ";
//			cin>>x;
//			Insert_first(x);
//			cout<<"Danh sach sau khi them la:\n";
//			output();
//			break;
//		case 3:
//			cout<<"Vui long nhap gia tri: ";
//			cin>>x;
//			Insert_last(x);
//			cout<<"Danh sach sau khi them la:\n";
//			output();
//			break;
//		case 4:
//			i=Delete_first();
//			if(i==0)
//				cout<<"Danh sach rong\n";
//			else
//			{
//				cout<<"Da xoa thanh cong phan tu dau cua DSLK Don !\n";
//				cout<<"Danh sach sau khi xoa la:\n";
//				output();
//			}
//			break;
//		case 5:
//			i=Delete_last();
//			if(i==0)
//				cout<<"Danh sach rong\n";
//			else
//			{
//				cout<<"Da xoa thanh cong phan tu cuoi cua DSLK Don !\n";
//				cout<<"Danh sach sau khi xoa la:\n";
//				output();
//			}
//			break;
//		case 6:
//			cout<<"Danh sach hien tai la:\n";
//			output();
//			break;
//		case 7:
//			cout<<"Vui long nhap gia tri can tim: ";
//			cin>>x;
//			p=Search(x);
//			if(p!=NULL)
//			{
//				cout<<"Tim thay phan tu co gia tri x= "<<x<<endl;
//			}
//			else
//				cout<<"Khong tim thay phan tu co gia tri x="<<x<<"!\n";
//			break;
//		case 8:
//			cout<<"Vui long gia tri can tim: ";
//			cin>>x;
//			i=Search_Delete(x);
//			if(i==1)
//			{
//				cout<<"Tim thay x= "<<x<<" va da xoa thanh cong\n";
//				cout<<"Danh sach sau khi xoa:\n";
//				output();
//			}
//			else
//				cout<<"Khong tim thay phan tu co gia tri x= "<<x<<" !!\n";
//			break;
//		case 9:
//			cout<<"Goodbye!!!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice!=9);
//	system("pause");
//	return 0;
//}