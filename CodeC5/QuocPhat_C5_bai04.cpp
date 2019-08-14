#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

//DSLK su dung cho stack va queue
struct Node{
	int info;
	Node *link;
}; Node *front, *rear, *sp;

//STACk
void InitStack()
{
	sp = NULL;
}

int isEmptyS()
{
	if(sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p = new Node ;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if(sp!= NULL)
	{
		Node *p = sp;
		x = p->info ;
		sp = p->link ;
		delete p;
		return 1;
	}
	return 0;
}

//QUEUE

void initQueue()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front ;
		front = p->link;
		x = p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
//end QUEUE

void InitGraph()
{
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i = 0; i< n; i++)
			myfile>>vertex[i];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				myfile>>A[i][j];
		}
	}
}

//cau 4.1
void inputGraph()
{
	cout <<"nhap so dinh do thi n: ";
	cin>> n;
	for(int i= 0; i < n; i++)
	{
		cout <<"nhap ten dinh: ";
		cin >> vertex[i];
		cout <<"nhap vao dong thu " << i + 1<< ":  ";
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

//cau 4.2
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n;j++)
			cout <<A[i][j]<< " ";
		cout << endl;
	}
}

void outPut(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]]<< " ";
}

//cau 4.3:vduyet do thi theo chieu rong BFS
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for(int i = 0; i < n; i++)
		C[i] = 1;
}

void BFS(int v)
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
		{
			if(C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}

//cau 4.4: duyet do thi theo DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while(isEmptyS() == 0)
	{
		if(v == n)
			PopS(u);
		for(v = 0; v < n;v++)
			if(A[u][v]!=0 && C[v] == 1)
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

//cau 4.5: Dng BFS tim x tren do thi
void Search_By_BFS(int x, int v)
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout <<"tim tahy x="<< x << endl;
			return;
		}
		for(w = 0; w < n; w++)
			if(C[w] && A[p][w] == 1)
		{
			PushQ(w);
			C[w] = 0;
		}
		
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp, sp_b, x, i;
	system("cls");
	cout <<"------------BAI TAP 4, CHUONG 5, DO THI------------" << endl;
	cout <<"1.khoi tao ma tran ke rong \n";
	cout <<"2.nhap ma tran ke tu file text \n";
	cout <<"3.nhap ma tran ke \n";
	cout <<"4.xuat ma tran ke \n";
	cout <<"5.duyet do thi theo BFS - DSLK \n" ;
	cout <<"6.duyet do thi theo dfs - DSLK \n ";
	cout <<"7.tim dinh co gia tri x theo bfs \n";
	cout <<"8.thoat \n" ;
	do{
		cout <<"vui long chon so de thuc hien: ";
		cin>> choice ;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "ban vua khoi tao ma tran ke rong thanh cong! \n";
			break;
		case 2:
			inputGraphFromText();
			cout <<"ban vau nhap ma tran ke tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue();
			initC();
			cout <<"vui long nhap dnh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout <<"thu tu dinh sau khia duyet BFS: " << endl;
			outPut(bfs, n);
			break;
		case 6:
			InitStack();
			initC();
			cout <<"vui long nhap dnh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout <<"thu tu dinh sau khia duyet BFS: " << endl;
			outPut(dfs, n);
			break;
		case 7:
			cout <<"vui long nhap gia tri x can tim: ";
			cin >> x;
			Search_By_BFS(x, 0);
			break;
		case 8:
			cout <<"goodbye........!" << endl;
			break;
		default:
			break;
		}
	}while(choice !=8);
	system("pause");
	return 0;
}