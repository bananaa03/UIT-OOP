#include <iostream>
using namespace std;

typedef struct PhanSo
{
	int tu;
	int mau;
} PS;

PS Input(PS& p)
{
	cin >> p.tu >> p.mau;
	return p;
}

void Output(PS p)
{
	if (p.tu == p.mau) cout << p.tu / p.mau;
	else if (p.tu < 0 && p.mau < 0) cout << -1 * p.tu << "/" << -1 * p.mau;
	else if (p.tu > 0 && p.mau < 0) cout << -1 * p.tu << "/" << -1 * p.mau;
	else cout << p.tu << "/" << p.mau;
}

int UCLN(int a, int b) 
{
	if (a % b != 0)
		return UCLN(b, a % b);
	else
		return b;
}

void RutGonPS(PS &p)
{
	int c = UCLN(p.tu, p.mau);
	p.tu = p.tu / c;
	p.mau = p.mau / c;
}

int main()
{
	PS p;
	cout << "Nhap phan so: ";
	p = Input(p);

	cout << "Phan so sau khi rut gon: ";
	RutGonPS(p);
	Output(p);

	return 0;
}