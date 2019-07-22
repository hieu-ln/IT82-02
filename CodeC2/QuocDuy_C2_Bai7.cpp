////Chuong 2_Bai7_QUEUE DSD
//#include<iostream>
//#include<Windows.h>
//using namespace std;
//#define MAX 100
//int a[MAX];
//void init(int a[], int& front, int& rear)
//{
//	front = -1;
//	rear = -1;
//}
//int isEmpty(int a[], int& front, int& rear) // Kiem tra QUEUE Rong
//{
//	if (front == rear)
//		return 1;
//	else
//		return 0;
//}
//int isFull(int a[], int& front, int& rear) //Kiem tra QUEUE Day
//{
//	if ((front == 0 && rear == MAX - 1) || (front - rear == 1))
//		return 1;
//	else
//		return 0;
//}
//int Push(int a[], int& front, int& rear, int x) // Them 1 phan tu vao QUEUE
//{
//	if (rear - front == MAX - 1)
//		return 0;
//	else {
//		if (front == -1)
//			front = 0;
//		if (rear == MAX - 1)
//		{
//			for (int i = 0; i <= rear; i++)
//			{
//				a[i - front] = a[i];
//			}
//			rear = MAX - 1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//	return 0;
//}
//int Pop(int a[], int& front, int& rear, int& x) //Lay 1 phan tu ra khoi QUEUE
//{
//	if (front == -1)
//		return 0;
//	else {
//		x = a[front++];
//		if (front > rear) {
//			front = -1;
//			rear = -1;
//		}
//		return 1;
//	}
//	return 0;
//}
//void Process_queue(int a[], int f, int r) //Xuat Queue
//{
//	cout << "f= " << f << "\t r= " << r << endl;
//	if (f <= r && f != -1)
//	{
//		cout << "<---  ";
//		for (int i = f; i < r + 1; i++)
//		{
//			cout << a[i] << " ";
//		}
//		cout << " <---" << endl;
//	}
//}
//int main()
//{
//	int a[MAX];
//	int choice, f,r,x ,i;
//	system("cls");
//	cout << "-----BAI TAP 7, CHUONG 2, QUEUE(DSD)-----" << endl;
//	cout << "1.Khoi tao QUEUE rong" << endl;
//	cout << "2.Them phan tu vao QUEUE" << endl;
//	cout << "3.Lay phan tu ra khoi QUEUE\n";
//	cout << "4.Kiem tra QUEUE Rong\n";
//	cout << "5.Kiem tra QUEUE Day\n";
//	cout << "6.Xuat QUEUE\n";
//	cout << "7.Thoat\n";
//	do
//	{
//		cout << "Vui long nhap so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init(a, f, r);
//			cout << "Khoi tao QUEUE Rong Thanh Cong!!!\n";
//			break;
//		case 2:
//			cout << "Nhap gia tri can them: ";
//			cin >> x;
//			i = Push(a, f, r, x);
//			cout << "QUEUE sau khi them phan tu x= " << x << endl;
//			Process_queue(a, f, r);
//			break;
//		case 3:
//			i = Pop(a, f, r, x);
//			cout << "QUEUE sau khi lay phan tu x=" << x << endl;
//			Process_queue(a, f, r);
//			break;
//		case 4:
//			i = isEmpty(a, f, r);
//			if (i == 1)
//				cout << "Queue Rong\n";
//			else
//				cout << "Queue khong rong\n";
//			break;
//		case 5:
//			i = isFull(a, f, r);
//			if (i == 1)
//				cout << "Queue Day\n";
//			else
//				cout << "Queue chua day\n";
//			break;
//		case 6:
//			cout << "Goodbye!!!\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 6);
//	system("pause");
//	return 0;
//}