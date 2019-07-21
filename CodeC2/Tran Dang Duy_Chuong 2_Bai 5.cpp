//#include<iostream>
//#include<stdio.h>
//using namespace std;
//#define MAX 100
////5.2
//void init(int a[], int &sp)
//{
//	sp=-1;
//}
////5.3
//int isEmpty(int a[], int sp)
//{
//	if(sp==-1)
//		return 1;
//	return 0;
//}
////5.4
//int isFull(int a[], int sp)
//{
//	if(sp==MAX-1)
//		return 1;
//	return 0;
//}
////5.5
//int Push(int a[], int &sp, int &x)
//{
//	if(sp < MAX-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
////5.6
//int Pop(int a[], int &sp, int &x)
//{
//	if(sp !=-1)
//	{
//		x=a[sp--];
//		return 1;
//	}
//	return 0;
//}
//void Process(int a[], int sp)
//{
//	for(int i=0; i<sp+1; i++)
//	{
//		cout<<a[i]<<"\t";
//	}
//	cout<<endl;
//}
//int main()
//{
//	int a[MAX];
//	int choice, sp, x, i;
//	system("cls");
//	cout<<"Bai tap chuong 5: ";
//	cout<<"1. Khoi tao stack rong"<<endl;
//	cout<<"2. Them phan tu vao stack"<<endl;
//	cout<<"3. Lay phan tu ra khoi stack"<<endl;
//	cout<<"4. Kiem tra stack co rong hay khong"<<endl;
//	cout<<"5. Kiem tra stack co day hay khong"<<endl;
//	cout<<"6 .Xuat stack"<<endl;
//	cout<<"7 .Thoat"<<endl;
//do
//{
//	cout<<"\nVui long chon so de thuc hien: ";
//	cin>>choice;
//	switch(choice)
//	{
//		case 1:
//			init(a,sp);
//			cout<<"Khoi tao STACK thanh cong: "<<endl;
//			break;
//		case 2:
//			cout<<"Vui long nhap gia tri x=";
//			cin>>x;
//			i=Push(a,sp,x);
//			cout<<"STack sau khi them la: ";
//			Process(a,sp);
//			break;
//		case 3:
//			i=Pop(a,sp,x);
//			cout<<"Phan tu lay ra tu Stack la: x="<<x<<endl;
//			cout<<"Stack sau khi lay ra la: ";
//			Process(a,sp);
//			break;
//		case 4:
//			i=isFull(a,sp);
//			if(i==0)
//				cout<<"STACK chua day"<<x<<endl;
//			else
//				cout<<"STACK da day"<<endl;
//			break;
//		case 5:
//			i=isEmpty(a,sp);
//			if(i==0)
//				cout<<"STACK khong rong"<<x<<endl;
//			else
//				cout<<"STACK rong"<<endl;
//			break;
//		case 6:
//			cout<<"STACK hien tai la: ";
//			Process(a,sp);
//			break;
//		case 7:
//			cout<<"Goodbye...!"<<endl;
//			break;
//		default:
//			break;
//	}
//}while(choice!=7);
//system("pause");
//return 0;
//}