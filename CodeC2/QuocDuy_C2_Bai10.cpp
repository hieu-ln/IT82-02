////Chuong 2_Bai10_STACK LKD
//#include<iostream>
//#include<Windows.h>
//using namespace std;
//struct Node //Cau truc stack
//{
//	int info;
//	Node* link;
//};
//Node* sp;
//void init() // Khoi tao stack rong
//{
//	sp = NULL;
//}
//int isEmpty() // Kiem tra stack rong
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void Push(int& x) //Them 1 phan tu vao stack
//{
//	Node* p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//void Pop(int& x) //Lay 1 phan tu ra khoi stack
//{
//	if (sp != NULL)
//	{
//		Node* p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//	}
//}
//void Process_stack() // Xuat stack
//{
//	Node* p = sp;
//	do
//	{
//		cout << p->info << "\t";
//		p = p->link;
//	} while (p != NULL);
//	cout << endl;
//}
//int main()
//{
//	int choice, x, i;
//		system("cls");
//		cout<<"-----BAI TAP 10, CHUONG 2, STACK(DSLKD)-----"<<endl;
//		cout<<"1.Khoi tao STACK rong"<<endl;
//		cout<<"2.Them phan tu vao STACK"<<endl;
//		cout<<"3.Lay phan tu ra khoi STACK\n";
//		cout<<"4.Kiem tra STACK Rong\n";
//		cout<<"5.Xuat STACK\n";
//		cout<<"6.Thoat\n";
//		do
//		{
//			cout << "Vui long nhap so de thuc hien: ";
//			cin >> choice;
//			switch (choice)
//			{
//			case 1:
//				init();
//				cout << "Khoi tao STACK rong Thanh Cong!!!\n";
//				break;
//			case 2:
//				cout << "Vui long nhap gia tri: ";
//				cin >> x;
//				Push(x);
//				cout << "STACK sau khi them la: ";
//				Process_stack();
//				break;
//			case 3:
//				Pop(x);
//				cout << "Phan tu lay ra tu STACK la x= " << x << endl;
//				cout << "STACK sau khi lay phan tu x: ";
//				Process_stack();
//				break;
//			case 4:
//				i = isEmpty();
//				if (i == 1)
//					cout << "STACK rong\n";
//				else
//					cout << "STACK khong rong\n";
//				break;
//			case 5:
//				cout << "STACK hien tai la\n";
//				Process_stack();
//				break;
//			case 6:
//				cout << "GOODBYE!!!\n";
//				break;
//			default:
//				break;
//			}
//		} while (choice != 6);
//		system("pause");
//		return 0;
//}