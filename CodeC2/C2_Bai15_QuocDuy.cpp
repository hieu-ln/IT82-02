//#include<iostream>
//#include<windows.h>
//#include<stdlib.h>
//using namespace std;
//#define MAX 100
//int a[MAX], b[MAX];
//int n, m;
//void input(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "a[" << i << "] = ";
//		cin >> a[i];
//	}
//}
//void output(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//}
//void TapHop(int a[], int b[],int n ,int m)
//{
//	int found;
//	cout << "Cac phan tu thuoc TAP HOP cua hai DS la:\n";
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	for (int i = 0; i < m; i++)
//	{
//		found = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (b[i] == a[j])
//				found = 1;
//		}
//		if (found == 0)
//			cout << b[i] << " ";
//	}
//	cout << endl;
//}
//void TapGiao(int a[], int b[], int n, int m)
//{
//	int found;
//	cout << "Cac phan tu thuoc TAP GIAO cua hai DS la:\n";
//	for (int i = 0; i < n; i++)
//	{
//		found = 0;
//		for (int j = 0; j < m; j++)
//		{
//			if (a[i] == b[j])
//				found = 1;
//		}
//		if (found == 1)
//			cout << a[i] << " ";
//	}
//}
//void PhanBu(int a[], int b[], int n, int m)
//{
//	int found;
//	cout << "Phan bu cua DS A trong DS B:\n";
//	for (int i = 0; i < m; i++)
//	{
//		found = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (b[i]== a[j])
//				found = 1;
//		}
//		if (found == 0)
//			cout << b[i] << " ";
//	}
//	cout << endl;
//	cout << "Phan bu cua DS B trong DS A:\n";
//	for (int i = 0; i < n; i++)
//	{
//		found = 0;
//		for (int j = 0; j < m; j++)
//		{
//			if (a[i] == b[j])
//				found = 1;
//		}
//		if (found == 0)
//			cout << a[i] << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	system("cls");
//	int choice;
//	cout << "============= Bai 15, Chuong 2, Danh Sach Dac =============" << endl;
//	cout << "1. Nhap DS A\n";
//	cout << "2. Nhap DS B\n";
//	cout << "3. Xuat DS\n";
//	cout << "4. Tap Hop cua 2 DS\n";
//	cout << "5. Tap Giao cua 2 DS\n";
//	cout << "6. Phan bu cua 2 DS\n";
//	cout << "7. Thoat\n";
//	do
//	{
//		cout << "Vui Long nhap so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "Nhap so phan tu cua danh sach A: ";
//			cin >> n;
//			input(a, n);
//			break;
//		case 2:
//			cout << "Nhap so phan tu cua danh sach B: ";
//			cin >> m;
//			input(b, m);
//			break;
//		case 3:
//			cout << "Danh Sach A la: ";
//			output(a, n);
//			cout << "\nDanh Sach B la: ";
//			output(b, m);
//			cout << endl;
//			break;
//		case 4:
//			TapHop(a,b,n,m);
//			break;
//		case 5:
//			TapGiao(a, b, n, m);
//			cout << endl;
//			break;
//		case 6:
//			PhanBu(a, b, n, m);
//			break;
//		case 7:
//			cout << "GOODBYE......!\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 7);
//	system("pause");
//	return 0;
//}