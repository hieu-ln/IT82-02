//Bai4_C6: Do Thi
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
#define MAX 20
#define ST 100
int A[MAX][MAX], n;
char vertex[MAX];
int a[ST];
int sp;//dinh stack
int front, rear;//front: vi tri lay ra, rear: vi tri tri them vao
//STACK DSD
void initS(int a[],int&sp)
{
	sp = -1;
}
void PushS(int a[], int& sp, int x)
{
	if (sp < ST - 1)
	{
		a[++sp] = x;
	}
}
void PopS(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
	}
}
int isEmptyS(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
//QUEUE DSD
void initQ(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
void PushQ(int a[], int& front, int& rear, int x)
{
	if (rear - front == ST - 1)
		return;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == ST - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = ST - 1 - front;
			front = 0;
		}
		a[++rear] = x;
	}
}
void PopQ(int a[], int& front, int& rear, int& x)
{
	if (front == -1)
		return;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
	}
}
//Nhap ma tran ke
void initG()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream file ("matranke.txt");
	if (file.is_open())
	{
		file >> n;
		for (int i = 0; i < n; i++)
			file >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				file >> A[i][j];
		}
	}
}
//Xuat Ma tran ke
void outputG()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
void output(int a[],int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
//Duyet BFS
int C[100];
int bfs[100], nbfs = 0;
void BFS(int v)
{
	int w, p;
	PushQ(a, front, rear, v);
	C[v] = 0;
	while (front != -1)
	{
		PopQ(a, front, rear, p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if(C[w]&&A[p][w]==1)
			{
				PushQ(a, front, rear, w);
				C[w] = 0;
			}
	}
}
void Khoitao()
{
	for (int i = 0; i < n; i++)
	{
		C[i] = 1;
	}
}
//DFS
int dfs[100], ndfs = 0;
void DFS(int s)
{
	PushS(a, sp, s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (!isEmptyS(a, sp))
	{
		if (v == n)
			PopS(a, sp, u);
		for(v=0;v<n;v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				PushS(a, sp, v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}
int main()
{
	int choice, x;
	system("cls");
	cout << " -------- BAI TAP 4, CHUONG 5, DO THI --------- " << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text" << endl;
	cout << "3. Xuat MA TRAN KE" << endl;
	//cout << "4. Duyet do thi theo chieu rong BFS" << endl;
	cout << "5. Duyet do thi theo chieu sau DFS" << endl;
	cout << "6. Thoat" << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initG();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file:\n";
			outputG();
			break;
		case 3:
			outputG();
			break;
		//case 4:
		//	initQ(a,front,rear);
		//	Khoitao();
		//	cout << "Vui long chon dinh xuat phat: ";
		//	cin >> x;
		//	nbfs = 0;
		//	BFS(x);
		//	cout << "Thu tu dinh sau khi duyet BFS: " << endl;
		//	output(bfs, n);
		//	cout << endl;
		//	break;
		case 5:
			initS(a,sp);
			Khoitao();
			cout << "Vui long chon dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(dfs, n);
			cout << endl;
			break;
		case 6:
			cout << "GOODBYE........!!!!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}