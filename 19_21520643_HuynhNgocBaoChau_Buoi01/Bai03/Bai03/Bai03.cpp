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

void RutGonPS(PS& p)
{
	int c = UCLN(p.tu, p.mau);
	p.tu = p.tu / c;
	p.mau = p.mau / c;
}

PS TongPS(PS p1, PS p2)
{
	PS p;
	p.tu = p1.tu * p2.mau + p2.tu * p1.mau;
	p.mau = p1.mau * p2.mau;
	RutGonPS(p);
	return p;
}

PS HieuPS(PS p1, PS p2)
{
	PS p;
	p.tu = p1.tu * p2.mau - p2.tu * p1.mau;
	p.mau = p1.mau * p2.mau;
	RutGonPS(p);
	return p;
}

PS TichPS(PS p1, PS p2)
{
	PS p;
	p.tu = p1.tu * p2.tu;
	p.mau = p1.mau * p2.mau;
	RutGonPS(p);
	return p;
}

PS ThuongPS(PS p1, PS p2)
{
	PS p;
	p.tu = p1.tu* p2.mau;
	p.mau = p1.mau * p2.tu;
	RutGonPS(p);
	return p;
}

int main()
{
	PS p1, p2, tong, hieu, tich, thuong;
	cout << "Nhap phan so thu nhat: ";
	p1 = Input(p1);
	cout << "Nhap phan so thu hai: ";
	p2 = Input(p2);

	tong = TongPS(p1, p2);

	hieu = HieuPS(p1, p2);

	tich = TichPS(p1, p2);

	thuong = ThuongPS(p1, p2);

	cout << "Tong 2 phan so la: " << tong.tu << "/" << tong.mau << endl;
	cout << "Hieu 2 phan so la: " << hieu.tu << "/" << hieu.mau << endl;
	cout << "Tich 2 phan so la: " << tich.tu << "/" << tich.mau << endl;
	cout << "Thuong 2 phan so la: " << thuong.tu << "/" << thuong.mau << endl;
	return 0;
}