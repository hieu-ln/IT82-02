////Chuong 2_Bai11_QUEUE LKD
//#include<iostream>
//#include<Windows.h>
//using namespace std;
//struct Node
//{
//	int info;
//	Node* link;
//};
//Node* front, * rear;
//void init()
//{
//	front = NULL;
//	rear = NULL;
//}
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void Push(int x)
//{
//	Node* p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//void Pop(int& x)
//{
//	if (front != NULL)
//	{
//		Node* p = front;
//		front = p->link;
//		x = p->info;
//		if (front == NULL)
//		{
//			rear = NULL;
//		}
//		delete p;
//	}
//}
//void Process_queue()
//{
//	if (front != NULL)
//	{
//		Node* p = front;
//		cout << "<---  ";
//		do
//		{
//			cout << p->info << "  ";
//			p=p->link;
//		} while (p != NULL);
//		cout << "<---" << endl;
//	}
//}
//int main()
//{
//	int choice, x, i;
//		system("cls");
//		cout<<"-----BAI TAP 10, CHUONG 2, QUEUE(DSLKD)-----"<<endl;
//		cout<<"1.Khoi tao QUEUE rong"<<endl;
//		cout<<"2.Them phan tu vao QUEUE"<<endl;
//		cout<<"3.Lay phan tu ra khoi QUEUE\n";
//		cout<<"4.Kiem tra QUEUE Rong\n";
//		cout<<"5.Xuat QUEUE\n";
//		cout<<"6.Thoat\n";
//		do
//		{
//			cout << "Vui long nhap so de thuc hien: ";
//			cin >> choice;
//			switch (choice)
//			{
//			case 1:
//				init();
//				cout << "Khoi tao QUEUE rong Thanh Cong!!!\n";
//				break;
//			case 2:
//				cout << "Vui long nhap gia tri: ";
//				cin >> x;
//				Push(x);
//				cout << "QUEUE sau khi them la: ";
//				Process_queue();
//				break;
//			case 3:
//				Pop(x);
//				cout << "Phan tu lay ra tu QUEUE la x= " << x << endl;
//				cout << "QUEUE sau khi lay phan tu x: ";
//				Process_queue();
//				break;
//			case 4:
//				i = isEmpty();
//				if (i == 1)
//					cout << "QUEUE rong\n";
//				else
//					cout << "QUEUE khong rong\n";
//				break;
//			case 5:
//				cout << "QUEUE hien tai la\n";
//				Process_queue();
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