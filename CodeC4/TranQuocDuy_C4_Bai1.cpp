////Bai 1_Chuong 4_Cay nhi phan tim kiem
//#include<iostream>
//#include<windows.h>
//using namespace std;
//struct Node
//{
//	int info;
//	Node* right, * left;
//};
//Node* root;
//void tree_empty()
//{
//	root = NULL;
//}
//void insertNode(Node *&p,int x)
//{
//	if (p == NULL)
//	{
//		p = new Node;
//		p->info = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else
//	{
//		if (p->info == x)
//			return;
//		else
//			if (p->info > x)
//				insertNode(p->left, x);
//			else
//				insertNode(p->right, x);
//	}
//}
//Node *Search(Node* p, int x)
//{
//	if (p != NULL)
//	{
//		if (p->info == x)
//			return p;
//		else
//			if (x > p->info)
//				Search(p->right, x);
//			else
//				Search(p->left, x);
//	}
//	else
//		return NULL;
//}
//void SearchStandFor(Node*& p, Node*& q)
//{
//	if (q->left == NULL)
//	{
//		p->info = q->info;
//		p = q;
//		q = q->right;
//	}
//	else
//		SearchStandFor(p, q->left);
//}
//int Delete(Node*& T, int x)
//{
//	if (T == NULL)
//		return 0;
//	if (T->info == x)
//	{
//		Node* p = T;
//		if (T->left == NULL)
//			T = T->right;
//		else
//			if (T->right == NULL)
//				T = T->left;
//			else
//				SearchStandFor(p, T->right);
//		delete p;
//		return 1;
//	}
//	if (T->info < x) return Delete(T->right, x);
//	if (T->info > x) return Delete(T->left, x);
//}
//void duyetLNR(Node* p)
//{
//	if (p != NULL) {
//		duyetLNR(p->left);
//		cout << p->info << " ";
//		duyetLNR(p->right);
//	}
//}
//void duyetNLR(Node* p)
//{
//	if (p != NULL) {
//		cout << p->info << " ";
//		duyetNLR(p->left);
//		duyetNLR(p->right);
//	}
//}
//void duyetLRN(Node *p)
//{
//	if (p != NULL) {
//		duyetLRN(p->left);
//		duyetLRN(p->right);
//		cout << p->info << " ";
//	}
//}
//int main()
//{
//	int x, choice, i;
//	system("cls");
//	cout << "======== Bai 1, Chuong 4, Cay Nhi Phan Tim Kiem ========" << endl;
//	cout << "1. Khoi tao cay rong\n";
//	cout << "2. Them 1 Node vao cay\n";
//	cout << "3. Tim 1 phan tu trong cay\n";
//	cout << "4. Xoa 1 phan tu trong cay\n";
//	cout << "5. Duyet cay theo NLR\n";
//	cout << "6. Duyet cay theo LNR\n";
//	cout << "7. Duyet cay theo LRN\n";
//	cout << "8. Thoat\n";
//	do
//	{
//		cout << "Vui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			tree_empty();
//			cout << "Khoi tao cay rong thanh cong!\n";
//			break;
//		case 2:
//			cout << "Nhap vao phan tu x can them:";
//			cin >> x;
//			insertNode(root,x);
//			cout << "Cay sau khi them phan tu x = " << x << " la:\n";
//			duyetNLR(root);
//			cout<<endl;
//			break;
//		case 3:
//			cout << "Nhap vao phan tu x can tim: ";
//			cin >> x;
//			if (Search(root,x) != NULL)
//				cout << "Tim thay phan tu x = " << x << endl;
//			else
//				cout << "Khong tim thay phan tu x = " << x << endl;
//			break;
//		case 4:
//			cout << "Nhap vao phan tu x can xoa: ";
//			cin >> x;
//			i = Delete(root, x);
//			if (i == 1)
//			{
//				cout << "Cay sau khi xoa phan tu x:\n";
//				duyetNLR(root);
//				cout << endl;
//			}
//			else
//				cout << "Khong tim thay phan tu x = " << x << " trong cay\n";
//			break;
//		case 5:
//			cout << "Duyet mang theo NLR:\n";
//			duyetNLR(root);
//			cout << endl;
//			break;
//		case 6:
//			cout << "Duyet mang theo LNR:\n";
//			duyetLNR(root);
//			cout << endl;
//			break;
//		case 7:
//			cout << "Duyet mang theo LRN:\n";
//			duyetLRN(root);
//			cout << endl;
//			break;
//		case 8:
//			cout << "GoodBye!!!\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 8);
//	system("pause");
//	return 0;
//}
