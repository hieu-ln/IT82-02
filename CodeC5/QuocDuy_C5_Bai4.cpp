////Bai4_C5: Do Thi
//#include<iostream>
//#include<stdio.h>
//#include<fstream>
//using namespace std;
//#define MAX 20
//int A[MAX][MAX], n;
//char vertex[MAX];
/////Cau truc DSLK
//struct Node
//{
//	int info;
//	Node* link;
//};
//Node* sp;
//Node* front,* rear;
/////STACK
//void initS()
//{
//	sp = NULL;
//}
//int isEmptyS()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void PushS(int x)
//{
//	Node* p;
//	p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//void PopS(int& x)
//{
//	if (sp != NULL)
//	{
//		Node* p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//	}
//}
/////QUEUE
//void initQ()
//{
//	front = NULL;
//	rear = NULL;
//}
//int isEmptyQ()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void PushQ(int x)
//{
//	Node* p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//void PopQ(int& x)
//{
//	if (front != NULL)
//	{
//		Node* p = front;
//		x = p->info;
//		front = front->link;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//	}
//}
//void initG()
//{
//	n = 0;
//}
//void inputGraphFromText()
//{
//	string line;
//	ifstream file ("matranke.txt");
//	if (file.is_open())
//	{
//		file >> n;
//		for (int i = 0; i < n; i++)
//			file >> vertex[i];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//				file >> A[i][j];
//		}
//	}
//}
////Nhap ma tran ke cua do thi
//void inputG()
//{
//	cout << "Nhap so dinh cua do thi: ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap ten dinh: ";
//		cin >> vertex[i];
//		cout << "Nhap vao dong thu " << i + 1 << ": ";
//		for (int j = 0; j < n; j++)
//			cin >> A[i][j];
//	}
//}
////Xuat ma tran ke cua do thi
//void outputG()
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << A[i][j] << " ";
//		cout << endl;
//	}
//}
//void output(int a[],int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << vertex[a[i]] << " ";
//}
////Duyet do thi theo chieu rong BFS
//int C[100];
//int bfs[100], nbfs = 0;
//void initC()
//{
//	for (int i = 0; i < n; i++)
//		C[i] = 1;
//}
//void BFS(int v)
//{
//	int w, p;
//	PushQ(v);
//	C[v] = 0;
//	while (front != NULL)
//	{
//		PopQ(p);
//		bfs[nbfs] = p;
//		nbfs++;
//		for(w=0;w<n;w++)
//			if (C[w] && A[p][w] == 1)
//			{
//				PushQ(w);
//				C[w] = 0;
//			}
//	}
//}
////Duyet do thi theo chieu sau DFS
//int dfs[100], ndfs = 0;
//void DFS(int s)
//{
//	PushS(s);
//	dfs[ndfs] = s;
//	ndfs++;
//	C[s] = 0;
//	int v = -1, u = s;
//	while (isEmptyS()==0)
//	{
//		if (v == n)
//			PopS(u);
//		for(v=0;v<n;v++)
//			if (A[u][v] != 0 && C[v] == 1)
//			{
//				//	PushS(u);
//				PushS(v);
//				dfs[ndfs] = v;
//				ndfs++;
//				C[v] = 0;
//				u = v;
//				break;
//			}
//	}
//}
////Tim x tren do thi bang BFS
//void Search_by_BFS(int x, int v)
//{
//	int w, p;
//	PushQ(v);
//	C[v] = 0;
//	while (front != NULL)
//	{
//		PopQ(p);
//		if (x == p)
//		{
//			cout << "Tim thay x = " << x << endl;
//			return;
//		}
//		for(int w=0;w<n;w++)
//			if (C[w] && A[p][w] == 1)
//			{
//				PushQ(w);
//				C[w] = 0;
//			}
//	}
//}
//int main()
//{
//	int a[MAX];
//	int b[MAX];
//	int choice, x;
//	system("cls");
//	cout << " -------- BAI TAP 4, CHUONG 5, DO THI --------- " << endl;
//	cout << "1. Khoi tao MA TRAN KE rong" << endl;
//	cout << "2. Nhap MA TRAN KE tu file text" << endl;
//	cout << "3. Nhap MA TRAN KE" << endl;
//	cout << "4. Xuat MA TRAN KE" << endl;
//	cout << "5. Duyet do thi theo chieu rong BFS" << endl;
//	cout << "6. Duyet do thi theo chieu sau DFS" << endl;
//	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
//	cout << "8. Thoat" << endl;
//	do
//	{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			initG();
//			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
//			break;
//		case 2:
//			inputGraphFromText();
//			cout << "Ban vua nhap MA TRAN KE tu file:\n";
//			outputG();
//			break;
//		case 3:
//			inputG();
//			break;
//		case 4:
//			outputG();
//			break;
//		case 5:
//			initQ();
//			initC();
//			cout << "Vui long chon dinh xuat phat: ";
//			cin >> x;
//			nbfs = 0;
//			BFS(x);
//			cout << "Thu tu dinh sau khi duyet BFS: " << endl;
//			output(bfs, n);
//			break;
//		case 6:
//			initS();
//			initC();
//			cout << "Vui long chon dinh xuat phat: ";
//			cin >> x;
//			ndfs = 0;
//			DFS(x);
//			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
//			output(dfs, n);
//			break;
//		case 7:
//			cout << "Vui long nhap gia tri x can tim: ";
//			cin >> x;
//			Search_by_BFS(x, 0);
//			break;
//		case 8:
//			cout << "GOODBYE........!!!!" << endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 8);
//	system("pause");
//	return 0;
//}