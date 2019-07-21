//#include<iostream>
//#include<stdio.h>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int n;
////Cau 1.2
//void input(int a[],int &n)
//{
//	cout<<"nhap so luong phan tu: ";
//	cin >>n;
//	for (int i=0; i<n; i++)
//	{
//		cout<<"nhap a["<<i<<"]= ";
//		cin>>a[i];
//	}
//}
////Cau 1.3
//void output(int a[], int n)
//{
//	for (int i=0; i<n; i++)
//		cout<<a[i]<<endl;
//}
////Cau 1.4
//int search(int a[],int n, int x)
//{
//	int i=0;
//	while((i<n)&&(a[i]!=x))
//		i++;
//	if(i==n)
//		return -1;
//	return i;
//}
////Cau 1.5
//int insert_last(int x, int a[], int &n)
//{
//	if(n<MAX)
//	{
//		a[n]=x;
//		n++;
//		return 1;
//	}
//	else
//		return 0;
//}
////Cau 1.6
//int delete_last(int a[], int &n)
//{
//	if(n>0)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
////Cau 1.7
//int del (int a[], int&n, int i)
//{
//	if(i>=0&&i<n)
//	{
//		for(int j=i;j<n-1;j++)
//		{
//			a[j]=a[j+1];
//		}
//		n--;
//		return 1;
//	}
//	return 0;
//}
////Cau 1.8
//int searchanddelete(int a[], int &n, int x)
//{
//	for (int i=0; i<n; i++)
//	{
//		if(a[i]==x)
//		{
//			del(a,n,i);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice=0;
//	int x,i;
//	system("cls");
//	cout<<" Bai tap 1, Chuong 1 "<<endl;
//	cout<<"1. Nhap Danh Sach"<<endl;
//	cout<<"2. Xuat Danh Sach"<<endl;
//	cout<<"3. Tim phan tu co gia tri x trong danh sach"<<endl;
//	cout<<"4. Them phan tu vao cuoi danh sach"<<endl;
//	cout<<"5. Xoa phan tu cuoi danh sach"<<endl;
//	cout<<"6. Xoa phan tu tai vi tri i"<<endl;
//	cout<<"7. Tim phan tu voi gia tri x va xoa no neu co"<<endl;
//	cout<<"8. Thoat"<<endl;
//	do
//	{
//		cout<<"Vui long chon so de thuc hien: ";
//		cin >>choice;
//		switch(choice)
//		{
//		case 1:
//			input(a,n);
//			cout<<"nhap danh sach thanh cong!\n";
//			break;
//		case 2:
//			cout<<"danh sach da nhap la: !\n";
//			output(a,n);
//			break;
//		case 3:
//			cout<<"vui long nhap x can tim:";
//			cin>>x;
//			i=search(a,n,x);
//			if(i==-1)
//				cout<<"Tim khong thay phan tu co gia tri "<<x<<endl;
//			else
//				cout<<"Tim thay tai vi tri i="<<i<<endl;
//			break;
//		case 4:
//			cout<<"vui long nhap x can them vao cuoi danh sach: ";
//			cin>>x;
//			i=insert_last(x,a,n);
//			if(i==0)
//				cout<<"Danh sach da day, khong the them"<<x<<endl;
//			else
//			{
//				cout<<"da them phan tu x="<<i<<" vao cuoi danh sach!"<<endl;
//				cout<<"danh sach sau khi them la: ";
//				output(a,n);
//			}
//			break;
//		case 5:
//			i=delete_last(a,n);
//			if(i>0)
//			{
//				cout<<"Xoa thanh cong!"<<endl;
//				cout<<"Danh sach sau khi xoa la: "<<endl;
//				output(a,n);
//			}
//			else
//				cout<<"Danh sach dang rong, ko co phan tu nao: "<<endl;
//			break;
//		case 6:
//			cout<<"vui long nhap vi tri can xoa i=";
//			cin>>i;
//			i=del(a,n,i);
//			if(i=1)
//			{
//				cout<<"Xoa thanh cong !"<<endl;
//				cout<<"Danh sach sau khi xoa la:\n";
//				output(a,n);
//			}
//			else
//				cout<<"khong co phan tu nao de !"<<endl;
//			break;
//		case 7:
//			cout<<"nhap gia tri can xoa: x=";
//			cin>>x;
//			i=searchanddelete(a,n,x);
//			if(i==1)
//			{
//				cout<<"xoa thanh cong phan tu co gia tri x="<<endl;
//				cout<<"danh sach sau khi xoa la:\n";
//				output(a,n);
//			}
//			else
//				cout<<"khong co phan tu nao de xoa!"<<endl;
//			break;
//		case 8:
//			cout<<"Goodbye!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while (choice!=8);
//system("pause");
//return 0;
//}