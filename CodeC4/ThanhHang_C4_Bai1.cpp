// Bai 1 : Quan ly motj cay nhi phan ( moi phan tu co kieu int)
#include <stdio.h>
#include <iostream>
using namespace std;


#define COUNT 10
//1.1 Khao bao cau truc cay nhi phan tim kiem 
struct Node 
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//1.2 Viet thu tuc khoi tao cay rong
void Tree_empty ()
{
	root = NULL;
}
//1.3 Viet thu tuc them mot phan tu vao cay ( dung de quy) 
// CACH 1: SU DUNG DIA CHI CON TRO 
void InsertNode( Node *&p, int x)
{
	if ( p == NULL)
	{
		p =new Node ;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else 
	{
		if( p->info == x)
			return;
		else if ( p->info > x)
			return InsertNode(p->left, x);
		else 
			return InsertNode(p->right, x);
	}
}

//1.3 Viet thu tuc them mot phan tu vao cay ( dung de quy) 
// CACH 2: KHONG SU DUNG DIA CHI CON TRO 
int Insert_Node ( int x, Node *q)
{
	if ( q->info == x)
	{
		return 0;
	}
	else if (q->info > x)
	{
		if (q->left==NULL)
		{
			Node *p = new Node ;
			p->info = x;
			p->left =NULL;
			p->right;
			q->left = p;
			return 1;
		}
		else 
			return Insert_Node (x,q->left);
	}
	else 
	{
		if (q->right == NULL)
		{
			Node *p= new Node ;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else 
			return Insert_Node (x,q->right);
	}
}

//1.4 Viet thu tuc tim mot phan tu trong cay ( dung de quy )
Node *Search ( Node *p, int x) 
{// Node *p tuong du
	if ( p!= NULL)
	{
		if ( p->info == x)
		{
			return p;
		}
		else 
		{
			if ( p->info > x)
			{
				return Search (p->left,x);
			}
			else 
			{
				return Search (p->right,x);
			}
		}
	}
	return NULL;
}
//1.5 Viet thu tuc xoa mot Node trong cay ( dung de quy )
// ham chinh lien ket
void SearchStandFor ( Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor (p,q->left);
}

// ham xoa 
int Delete ( Node *&T , int x)
{
	if ( T == NULL)
		return 0;
	if ( T->info == x)
	{
		Node *p = T;
		if ( T->left == NULL) // xoa bac 1 
			T= T->right;
		else if ( T->right == NULL) // xoa bac 1
			T= T->left;
		else // co 2 con 
			SearchStandFor (p,T->right);
		delete p;
		return 1;
	}
	if ( T->info < x)
		return Delete (T->right, x);
	if (T->info > x)
		return Delete (T->left, x);
}
//1.6 Viet thu tuc duyet cay theo thu tu NLR ( dung de quy)
void DuyetNLR ( Node *p)
{
	if ( p != NULL)
	{
		cout << p->info <<"  ";
		DuyetNLR (p->left);
		DuyetNLR(p->right);
	}
}
//1.7 Viet thu tuc duyet cay theo thu tu LNR ( dung de quy)
void DuyetLNR ( Node *p)
{
	if (p != NULL)
	{
		DuyetLNR( p->left);
		cout<< p->info <<"  ";
		DuyetLNR(p->right);
	}
}
//1.8 Viet thu tuc duyet cay theo thu tu LRN ( dung de quy)
void DuyetLRN ( Node *p)
{
	if ( p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout <<p->info <<"  ";
	}
}


//HAM IN CAY NHI PHAN 
void print2DUtil ( Node *p, int space)
{
	// base case
	if ( p == NULL)
		return ;
	// Increase distance between levels 
	space += COUNT;

	//Process right child first 
	print2DUtil(p->right,space);

	// print current Node after space 
	// count 
	cout << endl;
	for ( int i = COUNT ; i< space ; i++)
	{
		cout<< "  ";
	}
	cout << p->info<< "\n";

	// Process left child 
	print2DUtil (p->left,space );
}

//Wrapper over print2DUtil ()
void Process_tree()
{
	//Pass initial space count as 0
	print2DUtil ( root,0);
}


// HAM MAIN CHINH 
int main ()
{
	int choice ;
	int x,i;
	Node *p;
	system ("cls");
	cout <<"----- BAI 1 _CHUONG 4 _ CAY NHI PHAN TIM KIEM-----";
	cout <<"1. Khoi tao cay NPTK rong "<< endl;
	cout <<"2. Them phan tu vao cay NPTK "<< endl;
	cout <<"3. Tim phan tu co gia tri x trong cay NPTK"<< endl;
	cout <<"4. Xoa phan tu co gia tri x trong cay NPTK"<< endl;
	cout <<"5. Duyet cay NPTK theo NLR"<< endl;
	cout <<"6. Duyet cay NPTK theo LNR"<< endl;
	cout <<"7. Duyet cay NPTK theo LRN"<< endl;
	cout <<"8. Xuat cay NPTK "<< endl;
	cout <<"9. Thoat "<< endl;
	do 
	{
		cout <<" Vui long chon thao tac thuc hien:";
		cin >> choice ;
		switch(choice)
		{
		case 1:
			Tree_empty();
			cout << " Ban da khoi tao thanh cong cay NPTK."<< endl;
			break;
		case 2:
			cout <<" Vui long nhap gia tri can them :";
			cin >> x;
			InsertNode(root,x);
			cout <<" Cay NPTK sau khi them la ."<< endl;
			Process_tree();
			break;
		case 3:
			cout <<" Vui long nhap gia tri x can tim:";
			cin >> x;
			p = Search (root,x);
			if ( p != NULL)
				cout << " Tim thay x = "<< x << " trong cay NPTK."<<endl;
			else 
				cout << " Khong tim thay x=" << x<<" trong cay NPTK"<< endl;
			break;
		case 4:
			cout <<" Vui long nhap gia tri can xoa x = ";
			cin>> x;
			i = Delete(root,x);
			if ( i == 0)
				cout << " Khong tim thay gia tri x can xoa"<< endl;
			else 
			{
				cout << " Xoa thanh cong x = "<< x << endl;
				cout << " Cay NPTK sau khi xoa x ="<< x << " la :"<< endl;
				Process_tree();
			}
			break;
		case 5: 
			cout << " Duyet cay NPTK theo NLR la :"<< endl;
			DuyetNLR(root);
			cout<< endl;
			break;
		case 6:
			cout <<" Duyet cay NPTK theo LNR la :"<< endl;
			DuyetLNR(root);
			cout<< endl;
			break;
		case 7:
			cout <<" Duyet cay NPTK theo LRN la :"<< endl;
			DuyetLRN(root);
			cout<< endl;
			break;
		case 8:
			cout << " Cay NPTK nhu sau :"<< endl;
			Process_tree();
			break;
		case 9:
			cout <<"---GOODBYE!---"<<endl;
			break;
		default:
			break;
		}
	}
	while ( choice != 9);
	system ("pause");
	return 0;
}