// BÀI 4_CHUONG 5_ ĐỒ THỊ_MA TRAN KE _ DSLK DON 

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;


// khai báo cấu trúc ma trận kề 
#define MAX 20
int A[MAX][MAX];// mảng 2 chiều 
int n; // số phần tử của mảng 
char vertex[MAX]; // tên đỉnh

struct Node 
{
	int info;
	Node *link;
};
Node *sp;
Node *front, *rear;

//  STACK
void InitStack()
{
	sp = NULL;
}

int isEmptyStack()
{
	if ( sp == NULL)
		return 1;
	return 0;
}

void PushStack(int x)
{
	Node *p = new Node ;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopStack ( int &x)
{
	int result = isEmptyStack();
	if ( result == 0)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// QUEUE
void InitQueue()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQueue()
{
	if ( front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
{
	int result = isEmptyQueue();
	Node *p = new Node ;
	p->info = x;
	p->link = NULL;
	if ( rear == NULL)
		front = p;
	else
		rear->link =p;
	rear = p;
}

int PopQ( int &x)
{
	int result = isEmptyQueue();
	if ( result == 0)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if ( front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}


// khởi tạo cấu trúc rỗng 
void InitGraph ()
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
//1. Viết hàm nhập ma trận của đồ thi 5.1
void InputGraph()
{
	cout <<" nhap vao so dinh cua do thi: ";
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

//2. Viết hàm xuất ma trận này ra mh máy tính 
void OutputGraph ()
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

void Output ( int a[], int n )
{
	for ( int i= 0;i<n;i++)
	{
		cout << vertex[a[i]]<<"  ";
	}
}

//3. Viết hàm duyệt đồ thị theo chiều rộng ( dựa trêm QUEUE bằng kỹ thuật cài đặt danh sách liên kết đơn)
int C[100]; // lưu trữ đỉnh chưa xét , 1 là chưa xét , 0 là đã xét
int bfs[100]; //lưu DS phần tử đã duyệt
int nbfs = 0; // chỉ số lưu đỉnh đã xét
 
void InitC()
{
	for ( int i = 0; i< n; i++) 
		C[i] = 1;
}
void BFS( int v)
{
	int w, p;
	PushQ(v);
	C[v] =0;
	while ( front != NULL)
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

//4. Viết hàm duyệt đồ thị theo chiều sâu DFS( dựa trêm STACK bằng kỹ thuật cài đặt danh sách liên kết đơn)
int dfs[100];
int ndfs = 0;

void DFS ( int s)
{
	PushStack(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while ( isEmptyStack() == 0)
	{
		if ( v == n)
			PopStack(u);
		for ( v = 0;v<n;v++)
			if ( A[u][v] != 0 && C[v] ==1)
			{
				PushStack(u);
				PushStack(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}


//5. Nhập vào một đỉnh X,hãy kiểm tra đỉnh X có trên đồ thi hay không ( dựa trên phép duyệt BFS)
void Search_by_BFS ( int x, int v) // v là đỉnh bắt đầu
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while ( front != NULL)
	{
		PopQ(p);
		if( x==p)
		{
			cout << " Tim thay x = "<< x << endl;
			return ;
		}
		for ( w = 0; w< n; w++)
			if ( C[w] && A[p][w] ==1 )
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main ()
{
	 int a[MAX];
	 int b[MAX];
	 int choice , x, i;
	 system ("cls");
	 cout <<" ---- BAI 4_CHUONG 5 : MA TRAN KE (DSLK)----"<< endl;
	 cout <<"1. Khoi tao ma tran ke rong ."<< endl;
	 cout <<"2. Nhap ma tran ke tu file  text."<<endl;
	 cout <<"3. Nhap Ma tran ke "<< endl;
	 cout <<"4. Xuat ma tran ke "<< endl;
	 cout <<"5. Duyet do thi theo chieu rong BFS-DSL."<< endl;
	 cout <<"6. Duyet do thi theo chieu sau DFS-DSLK."<< endl;
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
			 InitQueue();
			 InitC();
			 cout <<" Vui long  nhap dinh xuat phat :";
			 cin >> x;
			 nbfs = 0;
			 BFS(x);
			 cout <<" Thu tu dinh sau khi duyet BFS:"<< endl;
			 Output(bfs,n);
			 cout << endl;
			 break;
		 case 6:
			 InitStack();
			 InitC();
			 cout<<" Vui long nhap dinh xuat phat :"<< endl;
			 cin>>x;
			 DFS(x);
			 cout <<" Thu tu dinh sau khi duyet DFS;"<< endl;
			 Output(dfs,n);
			 cout<< endl;
			 break;
		 case 7:
			 InitQueue();
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