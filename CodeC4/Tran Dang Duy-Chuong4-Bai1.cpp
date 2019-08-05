#include <stdio.h>
#include <iostream>
using namespace std;

#define COUNT 10
//1.1
struct Node {
	int info;
	Node *left;
	Node *right;
};
Node *root;
//1.2
void Init()
{
	root=NULL;
}
//1.3
void InsertNode(Node *&p, int x)
{
	if (p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if (p->info==x)
			return;
		else 
		{
			if(p->info > x)
				return InsertNode(p->left,x);
			else
				return InsertNode(p->right,x);
		}
	}
}
//1.3
int Insert_Node_Recursive(int x, Node *q)
{
	if (q->info ==x)
		return 0;
	else if(q->info > x)
	{
		if(q->left==NULL)
		{
			Node *p = new Node;
			p->info=x;
			p->left=NULL;
			p->right=NULL;
			q->left=p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x,q->left);
	}
	else
	{
		if(q->right==NULL)
		{
			Node *p = new Node;
			p->info=x;
			p->left=NULL;
			p->right=NULL;
			q->right=p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x,q->right);
	}
}
//1.4
Node *Search(Node *p,int x)
{
	if (p!=NULL)
	{
		if (p->info==x)
			return p;
		else
			if (x>p->info)
				return Search(p->right,x);
			else
				return Search(p->left,x);
	}
	return NULL;
}
//1.5
void SSF(Node *&p, Node *&q)
{
	if (q->left==NULL)
	{
		p->info==q->info;
		p = q;
		q = q->right;
	}
	else
		SSF(p,q->left);
}

int Delete(Node *&T, int x)
{
	if(T==NULL) return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left==NULL)
			T=T->right;
		else
			if (T->right == NULL)
				T=T->left;
			else
				SSF(p,T->right);
		delete p;				
		return 1;
	if(T->info<x) return Delete(T->right, x);
	if(T->info>x) return Delete(T->left, x);
	}
}
//1.6
void LNR(Node *p)
{
	if(p!=NULL)
	{
		LNR(p->left);
		cout<<p->info<<" ";
		LNR(p->right);
	}
}
//1.7
void NLR(Node *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		LNR(p->left);
		LNR(p->right);
	}
}
//1.8
void LRN(Node *p)
{
	if(p!=NULL)
	{
		LNR(p->left);
		LNR(p->right);
		cout<<p->info<<" ";
	}
}

void print2DUtil(Node *p, int space)
{
	if(p==NULL)
		return;
	space += COUNT;
	print2DUtil(p->right,space);
	cout<<endl;
	for(int i=COUNT;i<space;i++)
		cout<<" ";
	cout<<p->info<<"\n";
	print2DUtil(p->left,space);
}
void Process_Tree()
{
	print2DUtil(root,0);
}
int main()
{
	int choice=0;
	int x,i;
	Node* p;
	system("cls");
	cout<<"Bai tap chuong 10: "<<endl;
	cout<<"1. Khoi tao NPTK rong"<<endl;
	cout<<"2. Them phan tu vao cay NPTK"<<endl;
	cout<<"3. Tim phan tu co gia tri x trong cay NPTK"<<endl;
	cout<<"4 .Xoa phan tu co gia tri x trong cay NPTK"<<endl;
	cout<<"5 .Duyet cay theo LNR"<<endl;
	cout<<"6 .Duyet cay theo NLR"<<endl;
	cout<<"7 .Duyet cay theo LRN"<<endl;
	cout<<"8 .Xuat cay NPTK"<<endl;
	cout<<"9 .Thoat"<<endl;
do
{
	cout<<"\nVui long chon so de thuc hien: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			Init();
			cout<<"Khoi tao cay NPTK thanh cong: "<<endl;
			break;
		case 2:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			InsertNode(root,x);
			cout<<"Cay NPTK sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout<<"Vui long nhap gia tri x can tim";
			cin>>x;
			p=Search(root,x);
			if(p!=NULL)
				cout<<"Tim thay x trong cay NPTK"<<endl;
			break;
		case 4:
			cout<<"Vui long nhap gia tri x can xoa";
			cin>>x;
			i=Delete(root,x);
			if(i==0)
				cout<<"Khong tim thay x de xoa"<<endl;
			else
			{
				cout<<"Da xoa thanh cong x trong cay NPTK"<<endl;
				cout<<"Cay NPTK sau khi xoa la:";
				Process_Tree();
			}
			break;
		case 5:
			cout<<"Cay NPTK duyet theo LNR la: ";
			LNR(root);
			break;
		case 6:
			cout<<"Cay NPTK duyet theo NLR la: ";
			NLR(root);
			break;
		case 7:
			cout<<"Cay NPTK duyet theo LRN la: ";
			LRN(root);
			break;
		case 8:
			cout<<"Cay NPTK nhu sau:";
			Process_Tree();
		case 9:
			cout<<"Goodbye...!"<<endl;
			break;
		default:
			break;
	}
}while(choice!=9);
system("pause");
return 0;
}