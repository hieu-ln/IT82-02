//Chuong2_Bai1_Danh sach dac
//#include <iostream>
//#include <Windows.h>
//#include <iomanip>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int n;
//void input(int a[], int &n) //Thu tuc nhap danh sach
//{
//	cout<<"nhap so phan tu cua danh sach: ";
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//			cout<<"Nhap gia tri cua phan tu thu "<<i<<": ";
//			cin>>a[i];
//	}
//}
//void output(int a[],int n) //Thu tuc xuat danh sach
//{
//	for(int i=0;i<n;i++)
//	{
//		cout<<setw(3)<<a[i];
//	}
//	cout<<endl;
//}
//int Search(int a[],int n,int x) //Thu tuc tim phan tu
//{
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]==x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//void Insert_last(int a[],int &n,int x) //them cuoi
//{
//	if(n<MAX)
//	{
//		a[n]=x;
//		n++;
//	}
//}
//void Delete_last(int a[], int &n) //Thu tuc xoa cuoi
//{
//	if(n>0)
//		n--;
//}
//void Delete_i(int a[],int &n, int i) //Xoa phan tu tai i
//{
//	if(i>=0 && i<n)
//	{
//		for(int j=i;j<n-1;j++)
//			a[j]=a[j+1];
//		n--;
//	}
//}
//void Search_Delete(int a[],int &n, int x) //Tim va xoa
//{
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]==x)
//			Delete_i(a,n,i);
//	}
//}
//int main()
//{
//	int choice =0;
//	int x,i;
//	system("cls");
//	cout<<"Bai tap chuong 1\n";
//	cout<<"1.Nhap danh sach dac!\n";
//	cout<<"2.Xuat danh sach dac!\n";
//	cout<<"3.Tim mot phan tu trong danh sach!\n";
//	cout<<"4.Them phan tu vao cuoi danh sach!\n";
//	cout<<"5.Xoa phan tu o cuoi danh sach!\n";
//	cout<<"6.Xoa phan tu tai vi tri i!\n";
//	cout<<"7.Tim va xoa mot phan tu trong danh sach!\n";
//	cout<<"8.Thoat!\n";
//	do
//	{
//		cout<<"Vui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			input(a,n);
//			cout<<"Ban vua nhap danh sach thanh cong!\n";
//			break;
//		case 2:
//			cout<<"Danh sach vua nhap la:\n";
//			output(a,n);
//			break;
//		case 3:
//			cout<<"Vui long nhap x can tim: ";
//			cin>>x;
//			i=Search(a,n,x);
//			if(i==-1)
//				cout<<"Tim khong thay phan tu "<<x<<"\n";
//			else
//				cout<<"Tim thay tai vi tri i= "<<i<<endl;
//			break;
//		case 4:
//			cout<<"Vui long nhap x can them vao cuoi danh sach: ";
//			cin>>x;
//			Insert_last(a,n,x);
//			output(a,n);
//			break;
//		case 5:
//			cout<<"Danh sach da xoa phan tu cuoi:\n";
//			Delete_last(a,n);
//			output(a,n);
//			break;
//		case 6:
//			cout<<"Nhap vi tri i can xoa: ";
//			cin>>i;
//			Delete_i(a,n,i);
//			cout<<"Danh sach sau khi xoa:\n";
//			output(a,n);
//		case 7:
//			cout<<"Nhap gia tri can tim va xoa: ";
//			cin>>x;
//			Search_Delete(a,n,x);
//			cout<<"Danh sach sau khi da xoa phan tu x:\n";
//			output(a,n);
//			break;
//		case 8:
//			cout<<"Goodbye!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice!=8);
//	system("pause");
//	return 0;
//}
