//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//
//struct node
//{
//	int info;
//	node *left;
//	node *right;
//};
//node *root;
//void init()
//{
//	root=NULL;
//}
//void searchstandfor(node *&p, node *&q)
//{
//	if (q->left == NULL)
//	{
//		p->info=q->info;
//		p=q;
//		q=q->right;
//	}
//	else 
//		(searchstandfor(p, q->left));
//}
//int delete_node(node *&a, int x)
//{
//	if (a==NULL) return 0;
//	if (a->info == x)
//	{
//		node *p=a;
//		if (a->left==NULL)
//			a=a->right;
//		else if (a->right ==NULL)
//			a=a->left;
//		else
//			searchstandfor(p, a->right);
//		delete (p);
//		return 1;
//	}
//	else if (a->info<x) 
//		return delete_node(a->right, x);
//	else
//		return delete_node(a->left, x);
//}
//void add(node *&p, int x)
//{
//	if (p==NULL)
//	{
//		p=new node;
//		p->info =x;
//		p->left=NULL;
//		p->right = NULL;
//	}
//	else
//	{
//		if (p-> info ==x)
//			return;
//		else if (x<p->info) 
//			add(p->left, x);
//		else
//			add(p->right, x);
//	}
//
//}
//int search(int x, node *p)
//{
//	if (p!= NULL)
//	{
//		if (p->info == x)
//		return 1;
//	else if (x > p->info)
//		search(x, p->right);
//	else
//		search(x, p->left);
//	}
//	else 
//		return 0;
//}
//void NLR(node *p)
//{
//	if (p!= NULL)
//	{
//		cout<<p->info<<" ";
//		NLR(p->left);
//		NLR(p->right);
//	}
//}
//void LNR(node *p)
//{
//	if (p!= NULL)
//	{
//		LNR(p->left);
//		cout<<p->info<<" ";
//		LNR(p->right);
//	}
//}
//void LRN(node *p)
//{
//	if (p!= NULL)
//	{
//		LRN(p->left);
//		LRN(p->right);
//		cout<<p->info<<" ";
//	}
//}
//int COUNT =3;
//void print(node *p, int space)
//{
//	if (p==NULL)
//		return;
//	space += COUNT;
//	print(p->right, space);
//	cout<<endl;
//	for (int i=COUNT; i<space; i++)
//		cout<<" ";
//	cout<<p->info<<"\n";
//	print(p->left, space);
//}
//int main()
//{
//	int so, x;
//	bool end =true;
//	cout<<"----------MENU----------";
//	cout<<"\nNhap so 1 de khoi tao cay rong. ";
//	cout<<"\nNhap so 2 de them 1 phan tu vao cay. ";
//	cout<<"\nNhap so 3 de tim 1 phan tu. ";
//	cout<<"\nNhap so 4 de xoa 1 phan tu. ";
//	cout<<"\nNhap so 5 de duyet NLR. ";
//	cout<<"\nNhap so 6 de duyet LNR. ";
//	cout<<"\nNhap so 7 de duyet LRN. ";
//	cout<<"\nNhap so 8 de in. ";
//	cout<<"\nNhap so khac de thoat. ";
//	do {
//		cout<<"\nNhap so: "; cin>>so;
//		switch (so)
//		{
//			case 1:
//				init();
//				cout<<"Da khoi tao cay rong. ";
//				break;
//			case 2:
//				cout<<"Nhap gia tri node can them: ";
//				cin>>x;
//				add(root,x);
//				break;
//			case 3:
//				cout<<"Nhap gia tri node can tim: ";
//				cin>>x;
//				if (search(x, root)==1)
//					cout<<"tim thay";
//				else
//					cout<<"tim khong thay";
//				break;
//			case 4:
//				cout<<"Nhap gia tri node can xoa: ";
//				cin>>x;
//				if (delete_node(root, x)==1)
//					cout<<"Xoa thanh cong ";
//				else
//					cout<<"Khong co node de xoa.";
//				break;
//			case 5:
//				cout<<"Danh sach duyet theo NLR: ";
//				NLR(root);
//				break;
//			case 6:
//				cout<<"Danh sach duyet theo LNR: ";
//				LNR(root);
//				break;
//			case 7:
//				cout<<"Danh sach duyet theo LRN: ";
//				LRN(root);
//				break;
//			case 8:
//				print(root, 4);
//				break;
//			default: 
//				end=false;
//				break;
//		}	
//	}
//	while (end);
//	cout<<endl;
//	system("pause");
//	return 1;
//}