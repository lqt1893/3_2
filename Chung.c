#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int a[100][100], m, n;
void nh(int a[][100],int m,int n)
{
	int i, j;
	printf("(dong, cot <= 100) So dong, cot lan luot la: ");
	scanf("%d%d", &m, &n);
	if(m<=0||n<=0||m>100||n>100)
	{
		printf("Nhap lai: ");
		scanf("%d%d", &m, &n);
	}
	for(i=0; i<=m-1; i++)
		for(j=0; j<=n-1; j++)
		{
			printf("Nhap a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}	
}
void xu(int a[][100], int m, int n)
{
	int i, j;
	for(i=0; i<=m-1; i++)
	{
		for(j=0; j<=n-1; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
bool tk(int a[][100], int m, int n)
{
	int i, j;
	printf("Nhap phan tu can tim kiem: ");
	int t;
	scanf("%d", &t);
	for(i=0; i<=m-1; i++)
		for(j=0; j<=n-1; j++)
			if (a[i][j]==t)
				return 1;
	return 0;
}
bool nt(int a)//ktnt
{
	bool c=0;
	if (a==2||a==3)
	{
		c=1;
	}
	else
	{
		if (a>1)
		{
			int i;
			for(i=2; i<=sqrt(a); i++)
			{
				c=1;	
				if(a%i==0)
				{
					c=0;
					break;
				}
			}
		}
	}
	return c;
}
bool ktnt(int a[][100], int m, int n)//kiem tra nguyen to
{
	int i, j, d=0;
	for(i=0; i<=m-1; i++)
		for(j=0; j<=n-1; j++)
			if (nt(a[i][j])==0)
				return 0;
	return 1;
}
int tb(int a[][100], int m, int n)//toan bo
{
	int i, j, t=0;
	for (i=0; i<=m-1; i++)
		for (j=0; j<=n-1; j++)
			t+=a[i][j];
	printf("Tong toan ma tran la %d", t);
}
int dong(int a[][100], int m, int n)//dong
{
	int i, j, t=0;
	printf("Nhap dong can tinh tong: ");
	scanf("%d", &i);
	for(j=0; j<=n-1; j++)
		t+=a[i-1][j];
	printf("Tong dong %d la: %d", i, t);
}
int cot(int a[][100], int m, int n)//cot
{
	int i, j, t=0;
	printf("Nhap cot can tinh tong: ");
	scanf("%d", &j);
	for(i=0; i<=m-1; i++)
		t+=a[i][j-1];
	printf("Tong cot %d la: %d", j, t);
}
int dc(int a[][100], int m, int n)//duong cheo chinh
{
	int t=0;
	if(m==n)
	{
		while(m>=0&&n>=0)
		{
			t+=a[m-1][n-1];
			m--;
			n--;
		}
		printf("Tong duong cheo chinh la: %d", t);
	}
	else
		printf("So dong va cot khong bang nhau!");
}
int dp(int a[][100], int m, int n)//duong cheo phu
{
	int t=0, i=0;
	if(m==n)
	{
		while(m>=0&&i<=n-1)
		{
			t+=a[m-1][i];
			m--;
			i++;
		}
		printf("Tong duong cheo phu la: %d", t);
	}
	else
		printf("So dong va cot khong bang nhau!");
}
int tdc(int a[][100], int m, int n)//tren duong cheo chinh
{
	int t=0, i, j;
	if(m==n)
	{
		for (i=0; i<=m-1; i++)
			for (j=i+1; j<=n; j++)
				t+=a[i][j];
		printf("Tong tren duong cheo chinh la: %d", t);
	}
	else
		printf("So dong va cot khong bang nhau!");
}
int ddc(int a[][100], int m, int n)//duoi duong cheo chinh
{
	int t=0, i, j;
	if(m==n)
	{
		for (j=0; j<=n-1; j++)
			for (i=j+1; i<=m; i++)
				t+=a[i][j];
		printf("Tong duoi duong cheo chinh la: %d", t);
	}
	else
		printf("So dong va cot khong bang nhau!");
}
int tdp(int a[][100], int m, int n)//tren duong cheo phu
{
	int t=0, i, j;
	if(m==n)
	{
		for (i=0; i<=m-2; i++)
			for (j=0; j<=n-i-2; j++)
				t+=a[i][j];
		printf("Tong tren duong cheo phu la: %d", t);
	}
	else
		printf("So dong va cot khong bang nhau!");
}
int ddp(int a[][100], int m, int n)//duoi duong cheo phu
{
	int t=0, i, j;
	if(m==n)
	{
		for (i=1; i<=m-1; i++)
			for (j=n-1; j>=n-i; j--)
				t+=a[i][j];
		printf("Tong duoi duong cheo phu la: %d", t);
	}
	else
		printf("So dong va cot khong bang nhau!");
}
void to(int a[][100], int m, int n)
{
	int t;
	/*dong(a, m, n);
	cot(a, m, n);
	dc(a, m, n);
	dp(a, m, n);
	tdc(a, m, n);
	ddc(a, m, n);
	tdp(a, m, n);
	ddp(a, m, n);
	tb(a, m, n);*/
}
int ma(int a[][100],int m, int n)//max
{
	int t=a[0][0], i, j;
	for (i=0; i<=m-1; i++)
		for (j=0; j<=n-1; j++)
			if (t<a[i][j])
				t=a[i][j];
	return t;
}
bool ktdx(int a[][100],int m, int n)
{
	int i, j;
	if(m==n)
	{
		for (i=0; i<=m-1; i++)
			for (j=0; j<=n-1; j++)
				if (a[i][j]!=a[j][i])
					return 0;
		return 1;
	}
	else
		printf("So dong va cot khong bang nhau!\n");
}
int main()
{
	nh(a, m, n);
	xu(a, m, n);
	//printf("%d", tk(a, m,n));// tim kiem
	/*if (ktnt(a, m, n))//kt tinh chat
		printf("Day la ma tran toan nguyen to");
	else
		printf("Day khong phai la ma tran toan nguyen to");*/
	//to(a, m, n);//tong
	//printf("%d", ma(a, m, n));//tim max
	if (ktdx(a, m, n))//kiem tra doi xung
		printf("Ma tran doi xung");
	else
		printf("Ma tran khong doi xung");
}
