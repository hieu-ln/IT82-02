// BAI 6_CHUONG 5_ MA TRAN KE ( DANH SACH DAC)

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;


// khai bao cau truc ma tran ke
#define MAX 20
int A[MAX][MAX];// mang 2 chieu 
int n; // so phan tu cua mang
char vertex[MAX]; // ten dinh 
int a[MAX];
int sp; // khai bao taon cuc cho Stack
int front, rear; // Khai bao toan cuc cho Queue

// STACK
// khoi tao Stack rong
void InitS()
{
	 sp= -1;
}

// Kiem tra Stack rong 
int isEmptyS()
{
	if ( sp == -1)
		return 1;
	return 0;
}

// them mot phan tu vao stack
int PushS( int x)
{
	if ( sp < MAX -1 )
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

// Xoa mot phan tu trong Stack
int PopS( int &x)
{
	if ( sp != -1 )
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

// QUEUE
// khoi tao Queue rong
 void InitQ()
 {
	  front = -1;
	  rear =-1;
 }

 // kiem tra Queue rong 
 int isEmptyQ()
 {
	 if ( front == -1)
		 return 1;
	 else
		 return 0;
 }
 
 // Them phan tu vao Queue
 void PushQ( int x)
 {
	 if ( rear == -1)
	 {
		 a[0] = x;
		 rear = 0;
		 front = 0;
	 }
	 else 
	 {
		 front =0;
		 rear++;
		 a[rear] = x;
	 }
 }
 // xoa moth phan tu trong Queue
 void PopQ( int &x)
 {
	 if (  rear == 0)
	 {
		 rear --;
		 x = a[0];
	 }
	 else if ( rear > 0)
	 {
		 int m = rear;
		 x = a[0];
		 for ( int i = m; i> 0; i--)
			 a[i-1] = a[i];
		 rear--;
	 }
	 if ( rear == -1)
	 {
		 front = -1;
	 }
 }

 // nhap ma tran tu file 
 void InitGraph()
 {
	  n = 0;
 }

 void InputGraphFromText()
 {
	 string line ;
	ifstream myfile ("matranke1.txt");
	if ( myfile.is_open())
	{
		myfile >> n;
		for ( int i=0; i<n; i++)
			myfile >> vertex[i];
		for ( int i = 0; i< n; i++)
		{
			for ( int j = 0; j< n; j++)
				myfile >> A[i][j];

		}
	}
 }

 //6.1 Nhap ma tran kecua do thi
 void InputGraph ()
 {
	 cout << " Nhap so dinh cua do thi n : ";
	 cin >> n;
	 cout <<" Nhap vao ten dinh: "<< endl;
	for ( int i=0; i< n;i++)
	{
		cin >> vertex[i];
	}
	for ( int i=0; i< n;i++)
	{
		cout <<" Nhap vao dong thu "<< i+1 <<" :";
		for (int j = 0;j< n; j++)
		{
			cin >>A[i][j];
		}
	}
 }

 //6.2 Xuat ma tran ke cua do thi 
void OutputGraph()
{
	for ( int i = 0; i<n;i++)
	{
		for ( int j = 0; j<n ; j++)
		{
			cout << A[i][j]<<"  ";
		}
		cout << endl;
	}
}

void output ( int b[], int n)
{
	for ( int i= 0;i<n;i++)
	{
		cout << vertex[b[i]]<<"  ";
	}
}

//6.3: Duyet do thi theo BFS _ dung QUEUE & DS DAC 
int C[100];
int bfs[100];
int nbfs = 0;

void InitC()
{
	for (int i = 0; i< n; i++) 
		C[i] = 1;
}

void BFS( int v)
{
	int w, p;
	PushQ(v);
	C[v] =0;
	while ( front != -1)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for( w = 0; w<n; w++)
		{
			if ( C[w] && A[p][w]== 1)
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}

//6.4 Duyet do thi theo DFS _ dung STACK & DS DAC 
int dfs[100];
int ndfs = 0;

void DFS ( int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while ( isEmptyS() == 0)
	{
		if ( v == n)
			PopS(u);
		for ( v = 0;v<n;v++)
			if ( A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

//6.5 Dung BFS tim x tren do thi 
void Search_by_BFS ( int x, int v) // v la dinh bat dau 
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while ( isEmptyQ() == 0)
	{
		PopQ(p);
		if( x == p)
		{
			cout << " Tim thay x = "<< x << endl;
			return ;
		}
		for ( w = 0; w< n; w++)
			if ( C[w] && A[p][w] == 1 )
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main ()
{
	 InitQ();
	 int choice , x, i;
	 system ("cls");
	 cout <<" ---- BAI 6_CHUONG 5 : MA TRAN KE _ DANH SACH DAC ----"<< endl;
	 cout <<"1. Khoi tao ma tran ke rong ."<< endl;
	 cout <<"2. Nhap ma tran ke tu file  text."<<endl;
	 cout <<"3. Nhap Ma tran ke "<< endl;
	 cout <<"4. Xuat ma tran ke "<< endl;
	 cout <<"5. Duyet do thi theo chieu rong BFS-QUEUE & DS DAC."<< endl;
	 cout <<"6. Duyet do thi theo chieu sau DFS-STACK & DS DAC."<< endl;
	 cout <<"7. Tim dinh co gia tri x theo BFS "<< endl;
	 cout <<"8. Thoat ."<< endl;

	 do 
	 {
		 cout << " Vui long chon thao tac thuc hien : ";
		 cin >> choice;
		 switch( choice)
		 {
		 case 1:
			 InitGraph();
			 cout<< " Ban vua khoi tao MA TRAN KE rong thanh cong ."<<endl;
			 break;
		 case 2:
			 InputGraphFromText();
			 cout<< " Ban vua nhap MA TRAN KE tu file: "<< endl;
			 OutputGraph();
			 break;
		 case 3:
			 InputGraph();
			 break;
		 case 4:
			 OutputGraph();
			 break;
		 case 5:
			 InitQ();
			 InitC();
			 cout <<" Vui long  nhap dinh xuat phat :";
			 cin >> x;
			 nbfs = 0;
			 BFS(x);
			 cout <<" Thu tu dinh sau khi duyet BFS:"<< endl;
			 output(bfs,n);
			 cout << endl;
			 break;
		 case 6:
			 InitS();
			 InitC();
			 cout<<" Vui long nhap dinh xuat phat :"<< endl;
			 cin>>x;
			 DFS(x);
			 cout <<" Thu tu dinh sau khi duyet DFS;"<< endl;
			 output(dfs,n);
			 cout<< endl;
			 break;
		 case 7:
			 InitQ();
			 InitC();
			 nbfs=0;
			 cout<<" Vui long nhap gia tri x can tim :";
			 cin>> x;
			 Search_by_BFS(x,0);
			 break;
		 case 8:
			 cout<<" --- GOODBYE----!"<< endl;
			 break;
		 default:
			 break;
		 }
	 }
	 while ( choice != 8);
	 system ("pause");
	 return 0;
}