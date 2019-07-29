#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;
#define MAX 2000
//1.1
int a[MAX];
int n;
//1.0
void init(int a[], int &n)
{
	cout<<"Nhap vao so luong phan tu: ";
	cin	>>n;
	for (int i=0;i<n;i++)
		a[i]=rand() % 10000+1;
	cout<<"Danh sach ngua nhien da nhap la: "<<endl;
	for (int i=0;i>n;i++)
	{
		cout<< a[i] <<" ";
	}
}
//1.2
void input(int a[], int &n)
{
	cout<<"Nhap vao so luong phan tu: ";
	cin	>>n;
	cout<<"Nhap vao cac phan tu: "<<endl;
	for (int i=0;i>n;i++)
	{
		cout<< "a["<<i<<"]=";
		cin >> a[i];
	}
}
//1.3
void output(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void CopyArray(int a[], int b[], int n)
{
	for (int i=0; i<n;i++)
		b[i]=a[i];
}
//1.4
void insertion(int a[], int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
//1.5
void selection(int a[], int n)
{
	int i,j, min_idx;
	for(i=0;i<n-1;i++)
	{
		min_idx=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min_idx])
				min_idx=j;
		swap(a[min_idx],a[i]);
	}
}
//1.6
void interchange(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
//1.7
void bubble(int arr[], int n)
{
	int i,j;
	bool haveswap=false;
	for(i=0;i<n-1;i++)
	{
		haveswap=false;
			for(int j=i+1;j<n;j++)
			{
				if(arr[j]>arr[j+1])
				{
					swap(arr[j],a[j+1]);
					haveswap=true;
				}
			}
		if(haveswap==false)
			break;
	}
}
//1.8
void quick(int a[], int left, int right)
{
	int x=a[left+right/2];
	int i=left;
	int j=right;
	while(i>j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if (left<j)
		quick(a,left,j);
	if(i<right)
		quick(a,i,right);
}
//1.9
void shift(int a[], int n, int i)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+i])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a,j,n);
	}
}
void heap(int a[], int n)
{
	int i=n/2-1;
	while (i>=0)
	{
		shift(a,i,n);
		i--;
	}
	int right=n-1;
	while(right > 0)
	{
		swap(a[0],a[right]);
		right--;
		if(right>0)
			shift(a,0,right);
	}
}
//1.10
int searchS(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i]!=x)
	{
		i++;
	}
	if(i==n)
		return -1;
	else
		return 1;
}
//1.11
int searchB(int a[], int l, int r, int x)
{	if(r>=1)
	{
		int mid=l+(r-1)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return searchB(a,l,mid-1,x);
		return searchB(a,mid+1,r,x);
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout<<"BAI TAP 1, CHUONG 3"<<endl;
	cout<<"0 . Khoi tao danh sach ngau nhien "<<endl;
	cout<<"1 . Nhap danh sach "<<endl;
	cout<<"2 . Xuat danh sach "<<endl;
	cout<<"3 . Xep thu tu danh sach bang Selection "<<endl;
	cout<<"4 . Xep thu tu danh sach bang Insertion "<<endl;
	cout<<"5 . Xep thu tu danh sach bang Bubble "<<endl;
	cout<<"6 . Xep thu tu danh sach bang Interchange "<<endl;
	cout<<"7 . Xep thu tu danh sach bang Quick "<<endl;
	cout<<"8 . Xep thu tu danh sach bang Heap "<<endl;
	cout<<"9 . Tim kiem phan tu x bang Tiem Kiem Tuan Tu "<<endl;
	cout<<"10 . Tim kiem phan tu x bang Tiem Kiem Nhi Phan "<<endl;
	cout<<"11 . Thoat "<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 0:
				init(a,n);
				break;
			case 1:
				input(a,n);
				break;
			case 2:
				cout<<"Danh sach la: "<<endl;
				output(a,n);
				break;
			case 3:
				CopyArray(a,b,n);
				start=clock();
				selection(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep voi Selection la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian Selection la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 4:
				CopyArray(a,b,n);
				start=clock();
				insertion(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep voi Insertion la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian Insertion la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 5:
				CopyArray(a,b,n);
				start=clock();
				bubble(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep voi Bubble la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian Bubble la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 6:
				CopyArray(a,b,n);
				start=clock();
				interchange(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep voi Interchange la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian Interchange la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 7:
				CopyArray(a,b,n);
				start=clock();
				quick(b,0,n-1);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep voi Quick la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian Quick la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 8:
				CopyArray(a,b,n);
				start=clock();
				heap(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep voi Heap la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian Heap la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 9:
				cout<<"Vui long nhap x: ";
				cin>>x;
				start=clock();
				i=searchS(a,n,x);
				if(i==-1)
					cout<<"Khong tim thay x="<<x<<" trong mang !"<<endl;
				else
					cout<<"Tim thay x="<<x<<" tai vi tri i="<<i<<endl;
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(duration>0)
					cout<<"\nThoi gian tim kiem tuan tu la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 10:
				cout<<"Vui long nhap x: ";
				cin>>x;
				start=clock();
				i=searchB(b,0,n,x);
				if(i==-1)
					cout<<"Khong tim thay x="<<x<<" trong mang !"<<endl;
				else
					cout<<"Tim thay x="<<x<<" tai vi tri i="<<i<<endl;
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(duration>0)
					cout<<"\nThoi gian tim kiem tuan tu la: "<<duration*1000000<<" Mircoseconds"<<endl;
				break;
			case 11:
				cout<< "Goodbye....!"<<endl;
				break;
			default:
				break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}