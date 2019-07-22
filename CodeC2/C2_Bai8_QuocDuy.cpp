//#include<iostream>
//#include<windows.h>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int sp;
//void init(int a[], int& sp) // Khoi tao stack rong
//{
//	sp = -1;
//}
//void Push(int a[], int& sp, int x) //Them 1 phan tu vao stack
//{
//	if (sp < MAX - 1)
//	{
//		a[++sp] = x;
//	}
//}
//void Pop(int a[], int& sp, int& x) //Lay 1 phan tu ra khoi stack
//{
//	if (sp != -1)
//	{
//		x = a[sp--];
//	}
//}
//int isEmpty(int a[], int sp) //KT stack rong
//{
//	if (sp == -1)
//		return 1;
//	return 0;
//}
//void Doi_co_so(int x, int i) // x la so he 10, i co so can chuyen
//{
//	int dec = x, r; // r la phan du cua phep chia x cho i
//	while (dec >= 1)
//	{
//		r = dec % i;
//		dec /= i;
//		Push(a, sp, r);
//	}
//}
//int main()
//{
//	int dec, i, x, choice, k;
//	cout << "======= Bai 8, Chuong 2, DOI He 10 sang He Bat Ky =======" << endl;
//	cout << "1. Doi He Co So 10 sang He Co So bat ki\n";
//	cout << "2. Thoat\n";
//	do
//	{
//		init(a,sp);
//		cout << "Vui Long nhap so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << " Nhap so He 10 can doi: ";
//			cin >> dec;
//			cout << " Nhap He Co So can doi: ";
//			cin >> i;
//			Doi_co_so(dec, i);
//			cout << "So " << dec << " trong he " << i << " la: ";
//			while (!isEmpty(a,sp))
//			{
//				Pop(a, sp, x);
//				cout << x;
//			}
//			cout << endl;
//			break;
//		case 2:
//			cout << " GOODBYE........!" << endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 2);
//	system("pause");
//	return 0;
//}
