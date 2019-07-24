////Chuong 2_Bai5_Stack DSD
//#include<iostream>
//#include<Windows.h>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int sp;
//void init(int a[], int &sp)
//{
//	sp=-1;
//}
//int isEmpty(int a[], int sp)
//{
//	if(sp==-1)
//		return 1;
//	return 0;
//}
//int isFull(int a[], int sp)
//{
//	if(sp==MAX-1)
//		return 1;
//	return 0;
//}
//int Push(int a[], int &sp, int x)
//{
//	if(sp<MAX-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
//int Pop(int a[], int &sp, int &x)
//{
//	if(sp!=-1)
//	{
//		x=a[sp--];
//		return 1;
//	}
//	return 0;
//}
//void Process_stack(int a[], int sp)
//{
//	for(int i=0;i<sp+1;i++)
//	{
//		cout<<a[i]<<"\t";
//	}
//	cout<<endl;
//}
//void swap(int& a, int& b)
//{
//	int c;
//	c = a;
//	a = b;
//	b = c;
//}
//void Sort(int a[], int sp)
//{
//	for (int i = 0; i < sp; i++)
//	{
//		for (int j = i + 1; j < sp + 1; j++)
//			if (a[i] > a[j])
//				swap(a[i], a[j]);
//	}
//}
//void SortDesc(int a[], int sp)
//{
//	for (int i = 0; i < sp; i++)
//	{
//		for (int j = i + 1; j < sp + 1; j++)
//			if (a[i] < a[j])
//				swap(a[i], a[j]);
//	}
//}
//int main()
//{
//	int a[MAX];
//	int choice, x,i;
//	system("cls");
//	cout<<"-----BAI TAP 5, CHUONG 2, STACK(DSD)-----"<<endl;
//	cout<<"1.Khoi tao STACK rong"<<endl;
//	cout<<"2.Them phan tu vao STACK"<<endl;
//	cout<<"3.Lay phan tu ra khoi STACK\n";
//	cout<<"4.Kiem tra STACK Rong\n";
//	cout<<"5.Kiem tra STACK Day\n";
//	cout<<"6.Xuat STACK\n";
//	cout<<"7.Sap xep tang dan\n";
//	cout<<"8.Sap xep giam dan\n";
//	cout<<"9.Thoat\n";
//	do
//	{
//		cout<<"Vui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			init(a,sp);
//			cout<<"Khoi STACK thanh cong\n";
//			break;
//		case 2:
//			cout<<"Nhap gia tri phan tu can them: ";
//			cin>>x;
//			i=Push(a,sp,x);
//			cout<<"STACK vua them la: ";
//			Process_stack(a,sp);
//			break;
//		case 3:
//			i=Pop(a,sp,x);
//			cout<<"Phan tu lay ra tu STACK la x = "<<x<<endl;
//			cout<<"STACK sau khi them la: ";
//			Process_stack(a,sp);
//			break;
//		case 4:
//			i=isEmpty(a,sp);
//			if(i==1)
//				cout<<"STACK rong\n";
//			else
//				cout<<"STACK khong rong\n";
//			break;
//		case 5:
//			i=isFull(a,sp);
//			if(i==1)
//				cout<<"STACK day \n";
//			else
//				cout<<"STACK chua day\n";
//			break;
//		case 6:
//			cout<<"STACK hien tai:\n";
//			Process_stack(a,sp);
//			break;
//		case 7:
//			Sort(a, sp);
//			cout << "STACK da xep tang dan:\n";
//			Process_stack(a, sp);
//			break;
//		case 8:
//			SortDesc(a, sp);
//			cout << "STACK da xep giam dan:\n";
//			Process_stack(a, sp);
//			break;
//		case 9:
//			cout<<"Goodbye!!!\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 9);
//	system("pause");
//	return 0;
//}