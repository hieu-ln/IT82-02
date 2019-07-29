//BAI 1: QUAN LY DANH SACH DAC 100 PHAN TU KIEU SO NGUYEN 

#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;


//1.1 Khai bao cau truc danh sach
#define MAX 100
int a[MAX];
int n;
//Cau 1.2.0: Nhap danh sach tu dong 
void init (int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach da duoc nhap ngau nhien nhu sau: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}
//1.2 Viet thu tuc nhap danh sach
void Input (int a[], int &n)
{
	cout << " Nhap vao so luong phan tu cua DS :";
	cin >> n;
	for ( int i = 0; i<n ;i++)
	{
		cout <<" Nhap a["<<i<<"] = ";
		cin >>a[i];
	}
	cout << endl;
}

//1.3 Viet thu tuc xuat danh sach
void Output ( int a[], int n)
{
	for (int i = 0; i< n ; i++)
	{
		cout <<a[i]<<"  ";
	}
	cout << endl;
}

void CopyArray ( int a[], int b[], int n)
{
	for (int i = 0; i< n; i++)
		b[i] = a[i];
}
// HAM HOAN DOI 2 số nguyên 
void Swap ( int &a, int &b)
{
	int c;
	c= a;
	a= b;
	b= c;
}
//1.4 Viet thu tuc sx DS theo thu tu tang dan bang thuat toan Insertion Sort
void Insertion ( int a[], int n)
{
	int x,j;
	for ( int i = 1; i < n; i++)
	{
		x = a[i];
		j = i-1;
// di chuyển các pt có gtri > giá trĩ về sau một vị trí so vs vị trí ban đầu của nó.
		while ( j>= 0 && x < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=x;
	}
}

//1.5 Viet thu tuc sx DS theo thu tu tang dan bang thuat toan Selection Sort
void Selection ( int a[], int n)
{
	int min, i;
// di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp.
	for ( i= 0; i<n-1; i++)
	{// tìm phần tử nhỏ nhất trong mảng chưa sx
		min = i; 
		for ( int j = i+1; j< n; j++)
		{
			if ( a[j]< a[min])
				min = j;
		}
		Swap(a[min],a[i]);
	}
}
//1.6 Viet thu tuc sx DS theo thu tu tang dan bang thuat toan Interchange Sort
void Interchange ( int a[], int n)
{
	int  i,j;
	for ( i = 0; i< n ; i++)
	{
		for ( j = i+1; j< n ; j++)
		{
			if( a[j]< a[i] )
				Swap(a[i],a[j]);
		}
	}
}
//1.7 Viet thu tuc sx DS theo thu tu tang dan bang thuat toan Bubble Sort
void Bubble ( int a[], int n)
{
	int i,j;
	bool haveSwap = false;
	for ( i=0; i<n - 1;i++)
	{// i phần tử cuối cùng đã sắp xếp 
		haveSwap =false;
		for ( j = 0 ; j< n-1; j++)
		{
			if ( a[j] > a[j+1])
			{
				Swap (a[j],a[j+1]);
				haveSwap = true ;// kiểm tra lần lặp này có Swap không 
			}
		}
		// nếu không có Swap nào thực hiện => mảng đã sắp xếp , không cần lặp lại thêm  
		if ( haveSwap == false )
			break;
	}
}
//1.8 Viet thu tuc sx DS theo thu tu tang dan bang thuat toan Quick Sort
int partition ( int a[], int low, int high )
{
	int pivot = a[high];
	int left = low ;
	int right = high -1;
	while( true)
	{
		while (left <= right && a[left]< pivot ) 
			left++;
		while ( right >= left && a[right]> pivot )
			right--;
		if ( left >= right )
			break;
		Swap (a[left],a[high]);
		left++;
		right--;
	}
	Swap(a[left],a[high]);
	return left;
}

// hàm thực hiện giải thuật Quick Sort 
void Quick ( int a[], int low, int high )
{
	if( low < high )
	{
		/* pi là chỉ số nơi phần tử này đã đứng đúng vị trí 
		và là phần tử chia mảng làm 2 mảng con trái và phải */
		int pi = partition(a, low, high);
	// gọi đệ quy sắp xếp 2 mảng con trái và phải 
		Quick (a, low, pi - 1);
		Quick (a, pi+1, high);
	}
}
//1.9 Viet thu tuc sx DS theo thu tu tang dan bang thuat toan Heap Sort
void Heapify ( int a[], int n, int i)
{
	int largest = i;//  initialize largest as root 
	int l = 2*i+1; // left = 2*i+1
	int r = 2*i+2; // right = 2*i+2

	if ( l <n && a[l] > a[largest])
		largest = l;
	if ( r < n && a[r]> a[largest])
		largest = r;
	if ( largest != i)
	{
		Swap(a[i],a[largest]);
		Heapify (a,n,largest);
	}
}

// hàm Heap để chạy 
void heapSort ( int a[], int n)
{
	for ( int i=n/2 -1 ; i>= 0;i--)
		Heapify(a,n,i);
	for ( int i = n-1 ;i>= 0; i--)
	{
		Swap (a[0],a[i]);
		Heapify (a,i,0);
	}
}
//1.10 Viet thu tuc tim kiem mot phan tu trong danh sach co thu tu ( dung pp tim kiem tuan tu)
void SearchSequence ( int a[], int n , int x)
{
	int i = 0;
	while ( i<n && a[i] != x)
	{
		i++;
	}
	if( i== n)
	{
		cout << " Khong tim thay "<< endl;
	}
	else 
		cout << " Tim thay tai vi tri "<< i<< endl;
}
//1.11 Viet thu tuc tim kiem mot phan tu trong danh sach co thu tu ( dung pp tim kiem nhi phan)
int searchBinary ( int a[], int l, int r, int x)
{
	if( r>= l)
	{
		int mid = l+( r-l)/2;
		// tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn 
		if (a[mid] == x) // nếu a[mid] = x, trả về chỉ số và kết thúc
			return mid ;
		if ( a[mid]> x)
			return searchBinary(a,l, mid-1, x);
		return searchBinary(a, mid+1,r,x);
	}
	return -1;
}

int main ()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");

	cout <<"----- BAI TAP : CAC PHUONG PHAP SAP XEP THU TU DANH SAC DAC ----"<<endl;
	cout <<" 1.Khai bao  danh sach. "<< endl;
	cout <<" 2.Nhap mot danh sach. "<< endl;
	cout <<" 3.Xuat danh sach ."<< endl;
	cout <<" 4.Sap xep DS theo thu tu tang dan bang pp Insertion Sort ."<< endl;
	cout <<" 5.Sap xep DS theo thu tu tang dan bang pp Selection Sort ."<< endl;
	cout <<" 6.Sap xep DS theo thu tu tang dan bang pp Interchange Sort ."<< endl;
	cout <<" 7.Sap xep DS theo thu tu tang dan bang pp Quick Sort ."<< endl;
	cout <<" 8.Sap xep DS theo thu tu tang dan bang pp Bubble Sort ."<< endl;
	cout <<" 9.Sap xep DS theo thu tu tang dan bang pp Heap Sort ."<< endl;
	cout <<" 10.Tim kiem tuan tu mot phan tu trong danh sach co thu tu ."<< endl;
	cout <<" 11.Tim kiem nhi phan mot phan tu trong danh sach co thu tu ."<< endl;
	cout <<" 12.Thoat ! "<< endl;
	
	do 
	{
		cout<<" Vui long nhap thao tac can thuc hien ; ";
		cin >> choice ;
		switch(choice)
		{
		case 0:
			init (a,n);
			break;
		case 1:
			Input(a,n);
				break;

			case 2:
				cout << "Danh sach la: " << endl;
				Output(a,n);
				break;

			case 3:
				CopyArray(a,b,n);
				start = clock();
				Selection(b,n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Selection Sort la: " << endl;
					Output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Selection Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 4:
				CopyArray(a,b,n);
				start = clock();
				Insertion(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Intertion Sort la: " << endl;
					Output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Intertion Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 5:
				CopyArray(a,b,n);
				start = clock();
				Bubble (b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Bubble Sort la: " << endl;
					Output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Bubble Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;


			case 6:
				CopyArray(a,b,n);
				start = clock();
				Interchange(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Interchange Sort la: " << endl;
					Output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Interchange Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 7:
				CopyArray(a,b,n);
				start = clock();
				Quick (b, 0, n-1);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Quick Sort la: " << endl;
					Output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Quick Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 8:
				CopyArray(a,b,n);
				start = clock();
				heapSort(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "DS sau khi xap thu tu voi Heap Sort la: " << endl;
					Output(b,n);
				}
				if (duration > 0)
					cout << "Thoi gian Heap Sort: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 9:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				start = clock();
				 SearchSequence(a,n,x);
				if (i == -1)
					cout << "Khong tim thay x = " << x << " trong mang!" << endl;
				else
					cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (duration > 0)
					cout << "Thoi gian tiem kiem TUAN TU la: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 10:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				start = clock();
				i = searchBinary(b,0,n,x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (i == -1)
					cout << "Khong tim thay x = " << x << " trong mang!" << endl;
				else
					cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
				
				if (duration > 0)
					cout << "Thoi gian tiem kiem NHI PHAN la: " << duration * 1000000 << " Microseconds" << endl;
				break;

			case 11: 
				cout << "\nGoodbye!" <<endl;
				break;
			default:
				break;
		}
	}
	while ( choice != 11);
	system("pause");
	return 0;
}