////BAI 4, CHUONG 6: TIM KIEM, DO THI, GIAI THUAT PRIM
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//using namespace std;
//
////Khai bao ma tran bang mang hai chieu
//#define MAX 20
//int a[MAX][MAX];
//int n; //so dinh cua do thi
//char vertex[MAX]; //ten dinh
//
//void InitGraph()
//{
//	n = 0;
//}
//
//void inputGraphFromText()
//{
//	string line;
//	ifstream myfile("mtts.txt");
//	if (myfile.is_open())
//	{
//		myfile >> n;
//		for (int i = 0; i < n; i++)
//			myfile >> vertex[i];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//				myfile >> a[i][j];
//		}
//	}
//}
//
////Nhap ma tran ke cua do thi
//void inputGraph()
//{
//	cout << "Nhap so dinh do thi n: ";
//	cin >> n;
//	cout << "Nhap ten dinh: ";
//	for (int i = 0; i < n; i++)
//		cin >> vertex[i];
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap vao dong thu " << i + 1 << ": ";
//		for (int j = 0; j < n; j++)
//			cin >> a[i][j];
//	}
//}
//
////Xuat ma tran ke cua do thi
//void outputGraph()
//{
//	cout << setw(5) << left;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << a[i][j] << setw(5) << left;
//		cout << endl;
//	}
//}
//
////Khai bao Tap E
//int E1[MAX];
//int E2[MAX];
//int wE[MAX];
//int nE = 0;  //so phan tu tap E
//
////Khai bao Tap T
//int T1[MAX];
//int T2[MAX];
//int wT[MAX];
//int nT = 0;  //so phan tu tap E
//
//int TonTai(int d, int D[], int nD)
//{
//	for (int i = 0; i < nD; i++)
//		if (D[i] == d)
//			return 1;
//	return 0;
//}
////Tao tap canh E
//void TaoE()
//{
//	for(int i=0;i<n;i++)
//		for(int j=0;j<n;j++)
//			if (a[i][j] != 0)
//			{
//				E1[nE] = i;
//				E2[nE] = j;
//				wE[nE] = a[i][j];
//				a[i][j] = 0;
//				a[j][i] = 0;
//				nE++;
//			}
//}
////Hoan vi
//void swap(int &a, int& b)
//{
//	int c;
//	c = a;
//	a = b;
//	b = c;
//}
////Sap Xep canh E
//void SapXepE()
//{
//	for(int i=0;i<nE-1;i++)
//		for(int j=i+1;j<nE;j++)
//			if (wE[i] > wE[j])
//			{
//				swap(wE[i], wE[j]);
//				swap(E1[i], E1[j]);
//				swap(E2[i], E2[j]);
//			}
//}
////Thuat toan Kruskal
//void Kruskal(int x)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
//			continue;
//		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
//			continue;
//		T1[nT] = E1[i];
//		T2[nT] = E2[i];
//		wT[nT] = wE[i];
//		nT++;
//		if (nT == n - 1)
//			break;
//	}
//}
//void output(bool VertexName)
//{
//	int tong = 0;
//	for (int i = 0; i < nT; i++)
//	{
//		if (VertexName)
//			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
//		else
//			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
//		tong += wT[i];
//	}
//	cout << "\n Tong = " << tong;
//}
//
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout << "----- Bai tap 4 - Chuong 6: TIM KIEM CAY KHUNG TOI THIEU, PRIM -----" << endl;
//	cout << "1. Khoi tao MA TRAN KE rong" << endl;
//	cout << "2. Nhap MA TRAN KE tu file text" << endl;
//	cout << "3. Nhap MA TRAN KE!" << endl;
//	cout << "4. Xuat MA TRAN KE" << endl;
//	cout << "5. Tim CAY KHUNG TOI TIEU bang Kruskal" << endl;
//	cout << "6. Thoat" << endl;
//
//	do
//	{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			InitGraph();
//			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
//			break;
//		case 2:
//			inputGraphFromText();
//			cout << "Ban vua nhap MA TRAN KE tu file: \n";
//			outputGraph();
//			break;
//		case 3:
//			inputGraph();
//			break;
//		case 4:
//			outputGraph();
//			break;
//		case 5:
//			TaoE();
//			SapXepE();
//			cout << "Vui long nhap dinh xuat phat: ";
//			cin >> x;
//			Kruskal(x);
//			cout << "Cay khung toi tieu voi Kruskal: " << endl;
//			output(true);
//			break;
//		case 6:
//			cout << "Goodbye!!!" << endl;
//			break;
//		}
//	} while (choice != 6);
//	system("pause");
//	return 0;
//}