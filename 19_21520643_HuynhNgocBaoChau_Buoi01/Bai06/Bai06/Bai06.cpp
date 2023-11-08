#include <iostream>
#include <string>
using namespace std;

typedef struct HocSinh
{
	string hoten;
	float toan;
	float van;
} HS;

void Input(HS& hs)
{
	cin.ignore();
	cout << "Nhap ten hoc sinh: ";
	getline(cin, hs.hoten);

	cout << "Nhap diem toan: ";
	cin >> hs.toan;

	cout << "Nhap diem van: ";
	cin >> hs.van;
}

float DiemTrungBinh(float a, float b)
{
	float dtb = (a + b) / 2;
	return dtb;
}

void Output(HS hs)
{
	cout << hs.hoten << endl;
}

void Min(HS a[], int n)
{
	float min = DiemTrungBinh(a[0].toan, a[0].van);
	for (int i = 0; i < n; i++)
	{
		if (min > DiemTrungBinh(a[i].toan, a[i].van)) min = DiemTrungBinh(a[i].toan, a[i].van);
	}

	for (int i = 0; i < n; i++)
		if (DiemTrungBinh(a[i].toan, a[i].van) == min)
		{
			cout << "Hoc sinh thap diem nhat la: ";
			Output(a[i]);
		}
}

void Max(HS a[], int n)
{
	float max = DiemTrungBinh(a[0].toan, a[0].van);
	for (int i = 0; i < n; i++)
	{
		if (max < DiemTrungBinh(a[i].toan, a[i].van)) max = DiemTrungBinh(a[i].toan, a[i].van);
	}

	for (int i = 0; i < n; i++)
		if (DiemTrungBinh(a[i].toan, a[i].van) == max)
		{
			cout << "Hoc sinh cao diem nhat la: ";
			Output(a[i]);
		}
}

int main()
{
	HS a[100]; int n;
	cout << "Nhap n: "; cin >> n;
	for (int i = 0; i < n; i++)
		Input(a[i]);

	Max(a, n);

	Min(a, n);

	return 0;
}