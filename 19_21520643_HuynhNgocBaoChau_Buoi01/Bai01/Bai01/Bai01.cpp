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

PS RutGonPS(PS p)
{
	p.tu = p.tu / UCLN(p.tu, p.mau);
	p.mau = p.mau / UCLN(p.tu, p.mau);
	return p;
}

void QuyDongMau(PS p1, PS p2)
{
	p1.tu = p1.tu * p2.mau;
	p1.mau = p1.mau * p2.mau;
	p2.tu = p2.tu * p1.mau;
	p2.mau = p2.mau * p1.mau;
}

PS Max(PS p1, PS p2)
{
	PS max;
	QuyDongMau(p1, p2);
	if (p1.tu > p2.tu) max = p1;
	else max = p2;
	return max;
}

int main()
{
	PS p1, p2;
	cout << "Nhap phan so thu nhat: ";
	p1 = Input(p1);
	cout << "Nhap phan so thu hai: ";
	p2 = Input(p2);

	PS max = Max(p1, p2);
	cout << "Phan so lon nhat la: ";
	Output(max);

	return 0;
}
