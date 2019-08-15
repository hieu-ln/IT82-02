//#include<iostream>
//#include<fstream>
//using namespace std;
// struct node 
// {
//	 int info;
//	 node* link;
// };
//node *rear;
//node *front;
//node *sp;
//#define max 100
// node *first[max];
// int n;
// char vertex[max];
// int c[max];
// int bfs[max], dfs[max];
// int nbfs=0, ndfs=0;   
// void initFitsr()
// {
//	 for (int i=0; i<n; i++)
//		 first[i]=NULL;
// }
// void insert(node *&f, int x)
// {
//	 node *p;
//	 p=new node;
//	 p->info=x;
//	 p->link =f;
//	 f=p;
// }
// void inputFromText()
// {
//	 int x;
//	 string line;
//	 ifstream myfile ("matranke1.txt");
//	 if (myfile.is_open())
//	 {
//		 myfile>>n;
//		 for(int i=0; i<n; i++)
//			 myfile>>vertex[i];
//		 for (int i=0; i<n; i++)
//		 {
//			 for (int j=0; j<n; j++)
//			 {
//				 myfile>>x;
//				 if (x==1)
//				 {
//					 insert(first[i], j);
//				 }
//			 }
//		 }
//	 }
//	 myfile.close();
// }
// void outPutList(node *f)
// {
//	 if (f!=NULL)
//	 {
//		 node*p=f;
//		 while(p!=NULL)
//		 {
//			cout<<p->info<<" ";
//			p=p->link;
//		 }
//	 }
// }
// void output()
// {
//	 if (n>0)
//		for(int i=0; i<n; i++)
//		{
//			cout<<endl<<"Danh sach thu "<<i+1<<":";
//			outPutList(first[i]);
//		}
//	 else
//		 cout<<"rong";
// }
//
// void inputByHand()
// {
//	 cout<<"Nhap so dinh: "; cin>>n;
//	 for (int i=0; i<n; i++)
//		 {
//			 cout<<"Nhap dong thu "<<i+1;
//			 for (int j=0; j<n; j++)
//				 cin>>a[i][j];
//		 }
// }
// void xuat(int n)
// {
//	 for (int i=0; i<n; i++)
//	 {
//		 for (int j=0; j<n; j++)
//		 {
//			 cout<<" "<<a[i][j];
//		 }
//		 cout<<endl;
//	 }
// }
// void initQueue()
// {
//	 node *rear=NULL;
//	 node *front =NULL;
// }
// void pushQ(int x)
// {
//	 node *p;
//	 p=new node;
//	 p->info=x;
//	 p->link=NULL;
//	 if (rear==NULL)
//		 front=p;
//	 else
//		 rear->link=p;
//	 rear=p;
// }
// int popQ(int &x)
// {
//	 if(front!=NULL)
//	 {
//		 node*p=front;
//		 x=p->info;
//		 front=front->link;
//		 if (front==NULL)
//			 rear=NULL;
//		 delete p;
//		 return 1;
//	 }
//	 return 0;
// }
// int isEmptyQ()
// {
//	 if (front == NULL)
//		 return 1;
//	 return 0;
// }
// int isEmptyS()
// {
//	 if (sp == NULL)
//		 return 1;
//	 return 0;
// }
// void initStack()
// {
//	 sp=NULL;
// }
// void pushS(int x)
// {
//	 node *p;
//	 p=new node;
//	 p->info=x;
//	 p->link=sp;
//	 sp=p;
// }
// int popS(int &x)
// {
//	 if(sp!=NULL)
//	 {
//		 node *p=sp;
//		 x=p->info;
//		 sp=p->link;
//		 delete p;
//		 return 1;
//	 }
//	 return 0;
// }
// void initC()
// {
//	 for (int i=0; i<n; i++)
//		 c[i]=1;
// }
// void BFS(int v)
// {
//	 initC();
//	 int p;
//	 pushQ(v);
//	 c[v]=0;
//	 while(front!=NULL)
//	 {
//		 popQ(p);
//		 bfs[nbfs]=p;
//		 nbfs++;
//		 node *p=first[v];
//		 while(p!=NULL)
//		 {
//			 if (c[p->info])
//			 {
//				 pushQ(v);
//				 c[v]=0;
//			 }
//		 }
//	 }
//	 for(int i=0; i<n; i++)
//	 {
//		 cout<<" "<<bfs[i];
//	 }
// }
// void DFS(int s)
// {
//	 initC();
//	 pushS(s);
//	 dfs[ndfs]=s;
//	 ndfs++;
//	 c[s]=0;
//	 int v=-1, u=s;
//	 while(!isEmptyS())
//	 {
//		 if (v==n)
//			 popS(u);
//		 for(v=0; v<n; v++)
//			 if(a[u][v]!=0 && c[v]==1)
//			 {
//				pushS(u);
//				pushS(v);
//				dfs[ndfs]=v;
//				ndfs++;
//				c[v]=0;
//				u=v;
//				break;
//			 }
//	 }
//	 for(int i=0; i<n; i++)
//	 {
//		 cout<<" "<<dfs[i];
//	 }
// }
// void searchBFS(int x, int v)
// {
//	 initC();
//	 int w, p;
//	 pushQ(v);
//	 c[v]=0;
//	 while(front!=NULL)
//	 {
//		 popQ(p);
//		 if (x==p)
//		 {
//			 cout<<x<<"ton tai";
//			 return;
//		 }
//		 for(w=0; w<n; w++)
//			 if (c[w] && a[p][w]==1)
//			 {
//				 pushQ(w);
//				 c[v]=0;
//			 }
//	 }
// }
// int main()
// {
//	 int so, x, dinh;
//	 cout<<"-----------Menu-----------";
//	 cout<<"\nNhap so 1 de nhap bang text";
//	 cout<<"\nNhap so 2 de nhap bang tay";
//	 cout<<"\nNhap so 3 de xuat ma tran";
//	 cout<<"\nNhap so 4 de duyet theo chieu rong";
//	 cout<<"\nNhap so 5 de duyet theo chieu sau";
//	 cout<<"\nNhap so 6 de kiem tim theo chieu rong";
//	 cout<<"\nNhap so khac de thoat";
//	 do {
//		 cout<<"\nNhap so: "; 
//		 cin>>so;
//		 switch (so)
//		 {
//			 case 1:
//				 {
//					 inputFromText();
//					 break;
//				 }
//			 case 2:
//				 {
//					 inputByHand();
//					 break;
//				 }
//   			 case 3:
//				 {
//					xuat(n);
//					break;
//				 }
//			 case 4:
//				 {
//					 cout<<"\n\tNhap dinh bat dau duyet "; cin>>dinh;
//					 BFS(dinh);
//					 break;
//				 }
//			 case 5:
//				 {
//					 cout<<"\n\tNhap dinh bat dau duyet "; cin>>dinh;
//					 DFS(dinh);
//					 break;
//				 }
//			 case 6:
//				 {
//					 cout<<"\n\tNhap dinh bat dau duyet "; cin>>dinh;
//					 cout<<"\n\tNhap so can tim: "; cin>>x;
//					 searchBFS(x, dinh);
//					 break;
//				 }
//			 default:
//				 {
//					 so=0;
//					 break;
//				 }
//		 }
//	 }while(so!=0);
//	 cout<<endl;
//	 system("pause");
//	 return 1;
// }