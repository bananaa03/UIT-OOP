#include <iostream>
using namespace std;

typedef struct PhanSo
{
	float tu;
	float mau;
} PS;


void Input(PS p[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout << "Nhap phan so thu " << i + 1 << endl;
		cin >> p[i].tu >> p[i].mau;
	}
}

void Output(PS *p, int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout << p[i].tu << "/" << p[i].mau << " ";
	}
}

void QuyDongMau(PS p1, PS p2)
{
	p1.tu = p1.tu * p2.mau;
	p1.mau = p1.mau * p2.mau;
	p2.tu = p2.tu * p1.mau;
	p2.mau = p2.mau * p1.mau;
}

PS Max(PS *p, int n)
{
	PS max = p[0];
	for (int i = 1; i < n; i++)
	{
		QuyDongMau(p[i], p[i+1]);
		if (p[i].tu > p[i+1].tu) max = p[i];
		else max = p[i+1];
	}
	return max;
}

void SapXepTangDan(PS p[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if ((p[i].tu / p[i].mau) > (p[j].tu / p[j].mau))
			{
				PS k = p[i];
				p[i] = p[j];
				p[j] = k;
			}
	Output(p, n);
}

void SapXepGiamDan(PS p[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if ((p[i].tu / p[i].mau) < (p[j].tu / p[j].mau))
			{
				PS k = p[i];
				p[i] = p[j];
				p[j] = k;
			}
	Output(p, n);
}

int main()
{
	PS p[100];
	int n;
	cout << "Nhap n: "; cin >> n;
	Input(p, n);

	PS max = Max(p, n);
	cout << "Phan so lon nhat trong day: ";
	cout << max.tu << "/" << max.mau;

	cout << endl;
	
	cout << "Day phan so sau khi sap sep tang dan: ";
	SapXepTangDan(p, n);
	
	cout << endl;

	cout << "Day phan so sau khi sap xep giam dan: ";
	SapXepGiamDan(p, n);

	return 0;
}