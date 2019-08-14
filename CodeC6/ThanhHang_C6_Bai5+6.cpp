// BAI 5 _ CHUONG 6_ GIAI THUAT KRUSAL

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// khai bao ma tran trong mang 2 chieu 
#define MAX 20
int a[MAX][MAX];
int n;
char ver[MAX];

void InitGraph ()
{
	n = 0;
}

 void InputGraphFromText()
 {
	 string line;
	 ifstream myfile ("MTTS1.txt");
	 if (myfile.is_open())
	 {
		 myfile>> n;
		 for ( int i = 0; i< n; i++)
			 myfile >> ver[i];
		 for ( int i = 0; i< n; i++)
		 {
			 for ( int j = 0; j< n; j++)
				 myfile >> a[i][j];
		 }
	 }
 }

 // nhap ma tran ke cua do thi 
 void InputGraph()
 {
	 cout <<" Nhap so dinh cua do thi :";
	 cin >> n;
	 for ( int i = 0; i < n; i++)
	 {
		 cout << " Nhap ten dinh :";
		 cin >> ver[i];
		 cout << " Nhap vao dong thu "<< i+1 <<" : ";
		 for ( int j = 0; j< n;j++)
			 cin >> a[i][j];
	 }
 }

 // xuat ma tran ke cua do thi 
 void OutputGraph ()
 {
	 cout << setw(6) << left;
	 for ( int i = 0; i< n; i++)
	 {
		 for ( int j = 0; j< n; j++)
			 cout << a[i][j] << setw(6)<< left;
		 cout<< endl;
	 }
 }

 // khai bao tap E
 int E1[MAX];
 int E2[MAX];
 int wE[MAX];
 int nE = 0;

 // khai bao tap T
 int T1[MAX];
 int T2[MAX];
 int wT[MAX];
 int nT = 0;

 void TaoE ()
 {
	 for ( int i = 0; i< n ;i++)
	 {
		 for ( int j = 0;j< n; j++)
			 if ( a[i][j] != 0)
			 {
				 E1[nE] = i;
				 E2[nE] = j;
				 wE[nE] = a[i][j];
				 a[i][j] = 0;
				 nE++;
			 }
	 }
 }

 int TonTai ( int E, int T[], int nT)
 {
	 for ( int i = 0; i< nT ; i++)
		 if ( E == T[i])
			 return 1;
	 return 0;
 }

void SapxepE()
{
	for ( int i = 0; i<( nE-1); i++)
	{
		 for ( int j = 0; j<nE ; j++)
			 if ( wE[i]> wE[j])
			 {
				 swap(wE[i], wE[j]);
				 swap(E1[i], E1[j]);
				 swap(E2[i], E2[j]);
			 }
	}
}
void Krusal()
{
	for ( int i = 0; i< nE ; i++)
	{
		if ( TonTai(E1[i], T1, nT)==1 && (TonTai(E2[i],T2,nT))==1)
			continue;
		if ( TonTai(E1[i], T2, nT)==1 && (TonTai(E2[i],T1,nT))==1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if ( nT == ( n-1))
			break;
	}
}

void output ( bool verName)
{
	int tong = 0;
	for ( int i = 0; i< nT; i++)
	{
		if ( verName)
			cout <<endl<<"("<<ver[T1[i]]<<" , "<< ver[T2[i]]<<") = "<<wT[i];
		else
			cout << endl<<"("<<T1[i]<<") = "<< wT[i];
		tong += wT[i];
	}
	cout <<"\n  Tong = "<< tong ;
}

int main ()
{
	int choice, x, i;
	system ("cls");
	cout << " ----- BAI 5_CHUONG 6_ TIM KIEM CAY NHI PHAN TOI TIEU_KRUSAL----"<<endl;
	cout << " 1. Khoi tao MA TRAN KE rong."<<endl;
	cout << " 2. Nhap MA TRAN KE tu file ."<< endl;
	cout << " 3. Nhap MA TRAN KE . "<< endl;
	cout << " 4. Xuat MA TRAN KE ."<< endl;
	cout << " 5. Tim CAY KHUNG TOI TIEU bang KRUSAL ."<< endl;
	cout << " 6. Thoat ."<< endl;
	do 
	{
		 cout << " Vui long chon thao tac thuc hien : ";
		 cin >> choice ;
		 switch ( choice)
		 {
		 case 1:
			 InitGraph ();
			 cout << " Ban vua khoi tao thanh cong MA TRAN KE rong."<< endl;
			 break;
		 case 2:
			 InputGraphFromText();
			 cout << " Ban vua nhap MA TRAN KE tu file ."<< endl;
			 break;
		 case 3:
			 InputGraph();
			 break;
		 case 4:
			 OutputGraph();
			 cout << " MA TRAN KE cua do thi la :"<< endl;
			 break;
		 case 5:
			 TaoE();
			 SapxepE();
			 Krusal();
			 cout << " Cay khung toi tieu voi KRUSAL :"<< endl;
			 output(true);
			 break;
		 case 6:
			 cout << "----- GOODBYE----. "<< endl;
			 break;
		 default:
			 break;
		 }
	}
	while ( choice != 6);
	system ("pause");
	return 0;

}