////Bai 4_C6:Thuat Giai Prim
//#include<iostream>
//#include<stdio.h>
//#include<fstream>
//using namespace std;
//#define MAX 20
//int A[MAX][MAX], n;
//char vertex[MAX]; //Ten dinh
//void initG()
//{
//	n = 0;
//}
//void inputGraphFromText()
//{
//	string line;
//	ifstream file ("mtts.txt");
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
//
//void XoaViTriE(int i)
//{
//	for (int j = i; j < nE; j++)
//	{
//		E1[j] = E1[j + 1];
//		E2[j] = E2[j + 1];
//		wE[j] = wE[j + 1];
//	}
//	nE--;
//}
//
//void XoaCanhE(int u, int v)
//{
//	for (int i = 0; i < nE; i++)
//		if (E1[i] == u && E2[i] == v)
//		{
//			XoaViTriE(i);
//			break;
//		}
//}
//
//void prim(int s) // s là đỉnh bắt đầu
//{
//	int u = s, min, i, d1, d2;
//	while (nT < n - 1)
//	{
//		for (int v = 0; v < n; v++)
//			if (A[u][v] != 0)
//				if (TonTai(v, T2, nT) == 0)
//				{
//					E1[nE] = u;
//					E2[nE] = v;
//					wE[nE] = A[u][v];
//					nE++;
//				}
//		for (i = 0; i < nE; i++)
//			if (TonTai(E2[i], T2, nT) == 0)
//			{
//				min = wE[i];
//				d1 = E1[i];
//				d2 = E2[i];
//				break;
//			}
//		for (i = 0; i < nE; i++)
//			if (TonTai(E2[i], T2, nT) == 0)
//				if (min > wE[i])
//				{
//					min = wE[i];
//					d1 = E1[i];
//					d2 = E2[i];
//				}
//		T1[nT] = d1;
//		T2[nT] = d2;
//		wT[nT] = A[d1][d2];
//		A[d1][d2] = 0;
//		A[d2][d1] = 0;
//		nT++;
//		XoaCanhE(d1, d2);
//		u = d2;
//	}
//}
//
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
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout << "----- Bai tap 4 - Chuong 6: TIM KIEM CAY KHUNG TOI THIEU, PRIM -----" << endl;
//	cout << "1. Khoi Tao MA TRAN KE rong" << endl;
//	cout << "2. Nhap MA TRAN KE tu file text" << endl;
//	cout << "3. Nhap MA TRAN KE" << endl;
//	cout << "4. Xuat MA TRAN KE" << endl;
//	cout << "5. Tim Cay Khung Toi Tieu Bang Prim" << endl;
//	cout << "6. Thoat" << endl;
//
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
//			cout << "Ban vua nhap MA TRAN KE tu file: \n";
//			outputG();
//			break;
//		case 3:
//			inputG();
//			break;
//		case 4:
//			outputG();
//			break;
//		case 5:
//			cout << "Vui long nhap dinh xuat phat: ";
//			cin >> x;
//			prim(x);
//			cout << "Cay khung toi tieu voi PRIM: " << endl;
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