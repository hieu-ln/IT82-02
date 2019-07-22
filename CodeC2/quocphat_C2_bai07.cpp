//bai 07_ chuong02
#include <iostream>
#define MAX 100
using namespace std;

int a[MAX];
int rear, font;

void init(int a[], int &rear, int &font)
{
	rear = -1;
	font = -1 ;
}

int isEmpty(int a[], int rear, int font)
{
	if(font == rear)
		return 1;
	else
		return 0;
}

int isFull(int a[], int rear, int font)
{
	if(rear - font == MAX - 1)
		return 1;
	return 0;
}

int push(int a[], int &rear, int &font, int x)
{
	if(rear - font == MAX -1)
		return 0;
	else
	{
		if(font == -1)
			font = 0;
		if(rear == MAX -1)
		{
			for(int i=font; i <= rear; i++)
				a[i - font] = a[i] ;
			rear = MAX - 1 - font ;
			font  = 0;
		}
	a[++rear] = x;
	return 1;
	}
	return 0;
}

int pop(int a[], int &rear, int &font, int &x)
{
	if(font == -1)
		return 0;
	else
	{
		x = a[font++];
		if(font > rear)
		{
			font = -1; 
			rear = -1;
		}
		return 1;
	}
}

void process_queue(int a[], int &rear, int &font)
{
	cout << "rear="<< rear<< "\t" << "font=" << font << endl;
	if(font <= rear && font != -1)
	{
		cout << "<--" ;
		for(int i = font; i <= rear; i++)
		{
			cout << a[i] << "  ";
		}
		cout << "<--" << endl;
	}
}

int main()
{
	int choice = 0, x, i ;
	system("cls");
	cout << "..............BAI TAP 07- CHUONG 02- QUEUE DAC \n" ;
	cout << "1.khoi tao QUEUE rong \n";
	cout << "2.kiem tra QUEUE rong \n";
	cout << "3.kiem tra QUEUE day \n" ;
	cout << "4.them 1 phan tu trong QUEUE \n";
	cout << "5.xoa 1 phan tu trong QUEUE \n";
	cout << "6. thoat \n" ;
	do{
		cout << "chon so de thuc hien: "; cin >> choice ;
		switch(choice)
		{
		case 1:
			init( a, rear, font);
			cout << "khoi tao QUEUE thanh cong! \n";
			break;
		case 2:
			if(isEmpty( a, rear, font) == 1)
				cout << "QUEUE rong! \n" ;
			else
				cout << "QUEUE ko rong \n " ;
			break;
		case 3:
			if(isFull( a, rear, font) == 1)
				cout << "QUEUE day! \n" ;
			else
				cout << "QUEUE chua day \n " ;
			break;
		case 4:
			cout << "nhap gia tri can them trong QUEUE: "; cin >> x;
			i = push(a, rear, font, x);
			cout << "QUEUE sau khi them la: \n";
			 process_queue(a, rear, font);
			 break;
		case 5:
			i = pop(a, rear, font, x);
			cout << "QUEUE sau khi xoa 1 ptu la: \n";
			 process_queue(a, rear, font);
			 break;
		case 6:
			cout << "GOODBYE! \N" ;
			break;
		default:
			break;
		}
	}while(choice!=6);
	system("pause");
	return 0;
}
