
//BÀI 4 -CHƯƠNG 6(TÌM CÂY KHUNG TỐI THIỂU CHO ĐỒ THỊ BẰNG Prim)
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;

//Khai báo ma trận bằng mảng hai chiều
#define MAX 20
int a[MAX][MAX];
int n; //số đỉnh của đồ thị
char vertex[MAX]; //tên đỉnh

void InitGraph()
{
	n=0;
}

//Nhap ma tran tu file text
void inPutGraphFromText()
{
	ifstream myfile ("nhap.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i=0;i<n;i++)
			myfile>>vertex[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				myfile>>a[i][j];
		}
	}
}

//Nhap ma tran
void inPutGraph()
{
	cout<<"Nhap so dinh cua do thi:";
	cin>>n;
	cout<<"Nhap ten dinh:";
	for(int i=0;i<n;i++)
		cin>>vertex[i];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap vao dong thu "<<i+1<<":";
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}

}

//xuat ma tran
void outPutGraph()
{
	cout<<setw(4)<<left;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<setw(4)<<left;
		cout<<endl;
	}
}
// Khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE=0; //So phan tu trong tap

//Khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0; //So phan tu trong tap

//Kiem tra 
int tonTai(int d, int D[], int nD)
{
	for(int i=0;i<nD;i++)
		if(D[i]==d)
			return 1;
	return 0;
}
void xoaViTriE( int i)
{
	for(int j=i;j<nE;j++)
	{
		E1[j]=E1[j+1];
		E2[j]=E2[j+1];
		wE[j]=wE[j+1];
	}
	nE--;
}
void xoaCanhE(int u, int v)
{
	for(int i=0;i<nE;i++)
		if(E1[i]==u&&E2[i]==v)
		{
			xoaViTriE(i);
			break;
		}
}
void Prim(int s) //s la dinh bat dau
{
	int u=s,min,d1,d2;
	while(nT<n-1)
	{
		for(int v=0;v<n;v++)
		if(a[u][v]!=0)
			if(tonTai(v,T2,nT)==0)
			{
				E1[nE]=u;
				E2[nE]=v;
				wE[nE]=a[u][v];
				nE++;
			}
			for(int i=0;i<nE;i++)
				if(tonTai(E2[i],T2,nT)==0)
				{
					min=wE[i];
					d1=E1[i];
					d2=E2[i];
					break;
				}
				for(int i=0;i<nE;i++)
					if(tonTai(E2[i],T2,nT)==0)
						if(min>wE[i])
						{
							min=wE[i];
							d1=E1[i];
							d2=E2[i];

						}
			T1[nT]=d1;
			T2[nT]=d2;
			wT[nT]=a[d1][d2];
			a[d1][d2]=0;
			a[d2][d1]=0;
			nT++;
			xoaCanhE(d1,d2);
			u=d2;
	}
}
void outPut(bool vertexName)
{
	int tong=0;
	for(int i=0;i<nT;i++)
	{
		if(vertexName)
			cout<<endl<<"("<<vertex[T1[i]]<<","<<vertex[T2[i]]<<") ="<<wT[i];
		else
			cout<<endl<<"("<<T1[i]<<","<<T2[i]<<") ="<<wT[i];
		tong+=wT[i];
	}
	cout<<"\n tong="<<tong;
}

int main()
{
	int choice,x;
	system("cls");
	cout<<"----------Bai tap chuong 6-Bai 4---------"<<endl;
	cout<<"1. Khoi tao ma tran ke rong"<<endl;
	cout<<"2. Nhap ma tran ke tu file text"<<endl;
	cout<<"3. Nhap ma tran ke"<<endl;
	cout<<"4. Xuat ma tran ke"<<endl;
	cout<<"5. Tim cay khung toi thieu bang Prim"<<endl;
	cout<<"6. thoat"<<endl;

	do{
		cout<<"Vui long chon so: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout<<"Khoi tao ma tran rong thanh cong"<<endl;
			break;
		case 2:
			inPutGraphFromText();
			cout<<"Ban vua nhap ma tran ke tu file"<<endl;
			outPutGraph();
			break;
		case 3:inPutGraph();
			break;
		case 4:
			outPutGraph();
			break;
		case 5:
			cout<<"Nhap dinh xuat phat: ";
			cin>>x;
			Prim(x);
			cout<<"Cay khung toi thieu bang Prim la: "<<endl;
			outPut(true);
			break;
		case 6:
			cout<<"to be continue"<<endl;
			break;
		default:
			break;
		}
	}while(choice!=6);
	system("pause");
	return 0;
}