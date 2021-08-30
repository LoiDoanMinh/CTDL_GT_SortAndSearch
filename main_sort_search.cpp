#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;
void TaoMangNgauNhien(int* a, int n);
void PhatSinhMangTangDan(int* a, int n);
void Xuat(int* a, int n);
int Value_Max(int* a, int n);
int IndexMax(int* a, int n);
void AllIndexMax(int* a, int n);
int LinearSearch(int* a, int n, int k);
int LinearSearchImpr(int* a, int n, int k);
int TKNoiSuy(int A[], int n, int k);
void AllIndex_X(int* a, int n, int x);
int All_Index_TKNS(int* A, int n, int k);
void LietKeCap(int* a, int n);
void InterchangeSort(int* a, int n);
void SelectionSort(int* a, int n);
void menu(int* a, int n);
int main()
{
	int* a;
	int n, x;
	cout << "Nhap so phan tu n = ";
	cin >> n;
	a = new int[n];
	menu(a, n);
	
}
void TaoMangNgauNhien(int* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
}
void PhatSinhMangTangDan(int* a, int n)
{
	srand(time(NULL));
	a[0] = rand() % 11;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + rand() % 11;
	}
}
void Xuat(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
int Value_Max(int* a, int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int IndexMax(int* a, int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[max])
			max = i;
	}
	return max + 1;
}
void AllIndexMax(int* a, int n)
{
	int max = Value_Max(a, n);
	for (int i = 0; i < n; i++)
		if (a[i] == max)
			cout << i << " ";
}
int LinearSearch(int* a, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
			return i;
	}
	return -1;
}
int LinearSearchImpr(int* a, int n, int k)
{
	int* b;
	b = new int[n + 1];
	b[n] = k;
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	for (int i = 0; i <= n; i++)
	{
		if (b[i] == k)
			return i;
	}
}
int TKNoiSuy(int A[], int n, int k)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = l + (r - l) * (k - A[l]) / (A[r] - A[l]);
		if (k == A[m])
			return m;
		if (k < A[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}
void AllIndex_X(int* a, int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			cout << i << " ";
}
int All_Index_TKNS(int* A, int n, int k)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = l + (r - l) * (k - A[l]) / (A[r] - A[l]);
		if (k == A[m])
		{
			cout << m << " ";
			continue;
		}
		if (k < A[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}
void LietKeCap(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			cout << "(" << a[i] << "," << a[j] << ")";
		}
		cout << endl;
	}
}
void InterchangeSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void SelectionSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;

	}
}
void menu(int* a, int n)
{
	int luachon;
	while (1)
	{
		cout << "\n\n\t==========MENU==========";
		cout << "\n\t1.Tao Mang ngau nhien";
		cout << "\n\t2.Tao Mang ngau nhien tang dan";
		cout << "\n\t0.Thoat";
		cout << "\n\n\t==========END==========";
		cout << "\nNhap lua chon : ";
		cin >> luachon;
		if (luachon == 1)
		{
			TaoMangNgauNhien(a, n);
			int lc;
			while (1)
			{
				system("cls");
				cout << "\n\n\t==========MENU==========";
				cout << "\n\t1.Xuat";
				cout << "\n\t2.Tim gia tri lon nhat trong mang";
				cout << "\n\t3.Tim vi tri tai do co chua gia tri lon nhat cua mang ";
				cout << "\n\t4.Tim tat ca vi tri chua gia tri lon nhat";
				cout << "\n\t5.Tim vi tri co gia tri X(TKTT) va tinh TGTT";
				cout << "\n\t6.Tim vi tri co gia tri X(TKTTCT) va tinh TGTT";
				cout << "\n\t7.Tim tat ca vi tri co gia tri X";
				cout << "\n\t8.Liet ke tat ca cac cap gia tri trong mang ";
				cout << "\n\t9.Sap xep mang tang dan(interchange sort) va tinh TGTT";
				cout << "\n\t10.Sap xep mang tang dan(selection sort) va tinh TGTT";
				cout << "\n\t0.Thoat";
				cout << "\n\n\t==========END==========";
				cout << "\nNhap lua chon : ";
				cin >> lc;
				if (lc == 1)
				{
					Xuat(a, n);
					system("pause");
				}
				else if (lc == 2)
				{
					cout << "\nGia Tri lon nhat trong mang : " << Value_Max(a, n);
					system("pause");
				}
				else if (lc == 3)
				{
					cout << "\nVi tri chua gia tri max cua mang : " << IndexMax(a, n);
					system("pause");
				}
				else if (lc == 4)
				{
					cout << "\nTat ca vi tri co gia tri max trong mang : ";
					AllIndexMax(a, n);
					system("pause");
				}
				else if (lc == 5)
				{
					clock_t begin = clock();
					int x;
					cout << "\nNhap gia tri X : ";
					cin >> x;
					cout << "\nVi tri co gia tri X : " << LinearSearch(a, n, x);
					clock_t end = clock();
					cout << "\nTGTT: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
					system("pause");
				}
				else if (lc == 6)
				{
					clock_t begin = clock();
					int x;
					cout << "\nNhap gia tri X : ";
					cin >> x;
					cout << "\nVi tri co gia tri X : " << LinearSearchImpr(a, n, x);
					clock_t end = clock();
					cout << "\nTGTT: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
					system("pause");
				}
				else if (lc == 7)
				{
					int x;
					cout << "\nNhap gia tri X : ";
					cin >> x;
					cout << "\nTat ca vi tri co gia tri X : ";
					AllIndex_X(a, n, x);
					system("pause");
				}
				else if (lc == 8)
				{
					Xuat(a, n);
					cout << endl;
					LietKeCap(a, n);
					system("pause");
				}
				else if (lc == 9)
				{
					Xuat(a, n);
					clock_t begin = clock();
					InterchangeSort(a, n);
					cout << "\nMang sau khi SX tang dan : ";
					Xuat(a, n);
					clock_t end = clock();
					cout << "\nTGTT: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
					system("pause");
				}
				else if (lc == 10)
				{
					Xuat(a, n);
					clock_t begin = clock();
					SelectionSort(a, n);
					cout << "\nMang sau khi SX tang dan : ";
					Xuat(a, n);
					clock_t end = clock();
					cout << "\nTGTT: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
					system("pause");

				}

				else break;
			}
		}
		else if (luachon == 2)
		{
			PhatSinhMangTangDan(a, n);
			int lc;
			while (1)
			{
				system("cls");
				cout << "\n\n\t==========MENU==========";
				cout << "\n\t1.Tim vi tri co gia tri X(TKTT) va tinh TGTT";
				cout << "\n\t2.Tim tat ca vi tri co gia tri X(TKTT) va tinh TGTT";
				cout << "\n\t3.Tim vi tri co gia tri X(TKNS) va tinh TGTT";
				cout << "\n\t4.Tim tat ca vi tri co gia tri X(TKNS) va tinh TGTT";
				cout << "\n\n\t==========END==========";
				cout << "\nNhap lua chon : ";
				cin >> lc;
				if (lc == 1)
				{
					Xuat(a, n);
					clock_t begin = clock();
					int x;
					cout << "\nNhap gia tri X : ";
					cin >> x;
					cout << "\nVi tri co gia tri X : " << LinearSearch(a, n, x);
					clock_t end = clock();
					cout << "\nTGTT: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
					system("pause");
				}
				else if (lc == 2)
				{
					Xuat(a, n);
					int x;
					cout << "\nNhap gia tri X : ";
					cin >> x;
					cout << "\nTat ca vi tri co gia tri X : ";
					AllIndex_X(a, n, x);
					system("pause");
				}
				else if (lc == 3)
				{
					Xuat(a, n);
					clock_t begin = clock();
					int x;
					cout << "\nNhap gia tri X : ";
					cin >> x;
					cout << "\nVi tri co gia tri X : " << TKNoiSuy(a, n, x);
					clock_t end = clock();
					cout << "\nTGTT: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
					system("pause");
				}
				else if (lc == 4)
				{
					Xuat(a, n);
					clock_t begin = clock();
					int x;
					cout << "\nNhap gia tri X : ";
					cin >> x;
					cout << "\nTat ca Vi tri co gia tri X : ";
					All_Index_TKNS(a, n, x);
					clock_t end = clock();
					cout << "\nTGTT: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
					system("pause");
				}
				else break;
			}
		}
		else
			break;

	}
}