// BAI 5 _ CHUONG 5_ DO THI _ DANH SACH KE(DSLK)

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20

struct Node 
{
	int info;
	Node *link;
};

Node *first[MAX]; // Danh sach cac DSLK
int n; // so dinh
char Ver[MAX]; // ten dinh

Node *sp;
Node *front, *rear;

// STACK
void InitS()
{
	sp = NULL;
}

int isEmptyS()
{
	if ( sp == NULL)
		return 1;
	return 0;
}

void PushS( int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if ( sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
}

// QUEUE
void InitQ()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQ ()
{
	if( front == NULL)
		return 1;
	return 0;
}

void PushQ( int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if ( rear == NULL)
		front = p;
	else 
		rear->link = p;
	rear = p;
}

int PopQ( int &x)
{
	if ( front != NULL)
	{
		Node *p = front ;
		x = p->info;
		front = front->link;
		if ( front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//GRAPH
void InitGraph()
{
	n = 0;
}

void Insertlast( Node *&first, Node *p)
{
	if ( first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while  (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

void InputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if ( myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i< n; i++)
			myfile >> Ver[i];

		string str;
		int i = 0;
		while ( getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				Node *p = new Node;
				p -> info = u;
				p -> link = NULL;
				Insertlast(first[i-1], p);
			}
			i++;
		}
	}
}

//5.1  Nhap danh sach ke cua do thi vi dụ 5.1
 void InputGraph()
 {
	 cout << " Nhap so dinh cua do thi .";
	 cin >> n;
	 cout << " Nhap ten dinh :";
	 for( int i = 0; i< n; i++)
	 {
		 cin >> Ver[i];
	 }
	 for ( int i = 0; i< n; i++)
	 {
		 cout << " Nhap danh sach ke cua dinh thu "<< i <<"("<< Ver[i]<<") :" ;
		 int u;
		 while ( cin >> u)
		 {
			 Node *p = new Node ;
			 p->info = u;
			 p->link = NULL;
			 Insertlast(first[i-1],p);
		 }
	 }
 }

 //5.2 Xuat danh sach ke cua do thi 
 void OutputGraph()
 {
	 for (int i = 0; i< n; i++)
	 {
		 cout << " Dinh "<< i <<"("<<Ver[i]<<"):";
		 Node *p = first[i];
		 while ( p != NULL)
		 {
			 cout << p->info << "\t";
			 p = p->link;
		 }
		 cout << endl;
	 }
 }

 void Output ( int a[], int n)
 {
	 for (int i = 0; i< n; i++)
	 {
		 cout << Ver[a[i]]<<"\t";
	 }
 }
 
// 5.3 Duyet do thi theo BFS _ QUEUE & DSLK
int C[MAX];
int bfs[MAX];
int nbfs = 0;

void InitC()
{
	for ( int i = 0; i< n; i++)
		C[i]= 1;
}

void BFS (int v) // v la ding bat dau 
{
	int p;
	Node *w;
	PushQ(v);
	C[v]= 0;
	while ( front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;

		while ( w != NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info]=0;
			}
			w = w->link;
		}
	}
}

// 5.4 Duyet do thi theo DFS _ STACK & DSLK 
int dfs[MAX];
int ndfs=0;

void DFS( int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	
	int u = s; // u la dinh dang xet 
	Node *v = NULL; // v la dinh ke 
	
	while ( isEmptyS() == 0)
	{
		if ( v == NULL)
			PopS(u);
		v = first[u];
		while ( v != NULL)
		{
			if (C[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info]=0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

//5.5 Kiem tra dinh X có trong do thi theo BFS
void Search_by_BFS( int x, int v) // v la dinh bat dau 
{
	int p;
	Node *w;
	PushQ(v);
	C[v] = 0;

	while ( front != NULL)
	{
		PopQ(p);
		if ( x == p)
		{
			cout << " Tim thay dinh x = "<< x <<" trong do thi."<< endl;
			return;
		}
		w = first[p];
		while ( w != NULL)
		{
			if ( C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
	cout << " Khong tim thay dinh x = "<< x <<" trong do thi "<< endl;
}

int main ()
{
	int a[MAX];
	int b[MAX];
	int choice, x , i;
	system("cls");
	cout <<" ---- CHUONG 5- BAI 5- DO THI - DANH SACH KE ( DSLK)----"<<endl;
	cout <<" 1. Khoi tao DANH SACH KE rong ."<< endl;
	cout << "2. Nhap DANH SACH KE tu file text" << endl;
	cout << "3. Nhap DANH SACH KE" << endl;
	cout << "4. Xuat DANH SACH KE" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu rong DFS - DSLK" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	do 
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << " Ban da khoi tao thanh cong DANH SACH KE rong ."<< endl;
			break;
		case 2:
			InputGraphFromText();
			cout << " Ban vua nhap thanh cong DANH SACH KE tu file."<<endl;
			OutputGraph();
			cout<< endl;
			break;
		case 3:
			InputGraph();
			break;
		case 4:
			cout << " DANH SACH KE cua do thi :"<<endl;
			OutputGraph();
			break;
		case 5:
			InitQ();
			InitC();
			cout << " Vui long nhap dinh xuat phat :";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << " Do thi sau khi duyet BFS la :"<< endl;
			Output(bfs,n);
			cout << endl;
			break;
		case 6:
			InitS();
			InitC();
			cout << " Vui long nhap dinh xuat phat :";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << " Do thi sau khi duyet theo DFS la :"<< endl;
			Output(dfs,n);
			cout<< endl;
			break;
		case 7:
			InitQ();
			InitC();
			cout << " Vui long nhap dinh can tim :";
			cin >> x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout << "----GOODBYE------"<< endl;
			break;
		default:
			break;

		}
	}
	while ( choice != 8);
	system("pause");
	return 0;
}