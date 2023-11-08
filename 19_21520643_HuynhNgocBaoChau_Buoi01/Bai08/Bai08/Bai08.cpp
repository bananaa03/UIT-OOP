#include <iostream>
using namespace std;

typedef struct PhanSo
{
	int tu;
	int mau;
} PS;

PS Input(PS& p)
{
	cout << "Nhap phan so: ";
	cin >> p.tu >> p.mau;
	return p;
}

void Output(PS p)
{
	if (p.mau == 1) cout << p.tu;
	else if (p.tu == p.mau) cout << p.tu / p.mau;
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

void QuyDongMau(PS &p1, PS &p2)
{
	int mau1 = p1.mau;
	p1.tu = p1.tu * p2.mau;
	p1.mau = p1.mau * p2.mau;
	p2.tu = p2.tu * mau1;
	p2.mau = p2.mau * mau1;
}

void SoSanh(PS p1, PS p2)
{
	int tu1 = p1.tu;
	int mau1 = p1.mau;
	int tu2 = p2.tu;
	int mau2 = p2.mau;

	QuyDongMau(p1, p2);

	if (p1.tu == p2.tu) cout << tu1 << "/" << mau1 << " = " << tu2 << "/" << mau2;
	else if (p1.tu > p2.tu) cout << tu1 << "/" << mau1 << " > " << tu2 << "/" << mau2;
	else cout << tu1 << "/" << mau1 << " < " << tu2 << "/" << mau2;
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
	p.tu = p1.tu * p2.mau;
	p.mau = p1.mau * p2.tu;
	RutGonPS(p);
	return p;
}

int main()
{
	PS p, p1, p2;
	int option;

	cout << "----------Menu----------\n";
	cout << "1. Nhap phan so\n";
	cout << "2. Xuat phan so\n";
	cout << "3. Rut gon phan so da nhap\n";
	cout << "4. So sanh hai phan so\n";
	cout << "5. Cong hai phan so\n";
	cout << "6. Tru hai phan so\n";
	cout << "7. Nhan hai phan so\n";
	cout << "8. Chia hai phan so\n";
	cout << "Nhap lua chon: "; 
	cin >> option;

	switch(option)
	{
		case 1:
		{
			Input(p);
			break;
		}
		case 2:
		{
			Input(p);
			Output(p);
			break;
		}
		case 3:
		{
			Input(p);
			RutGonPS(p);
			cout << "Phan so sau khi rut gon: " << p.tu << "/" << p.mau;
			break;
		}
		case 4:
		{
			Input(p1);
			Input(p2);
			SoSanh(p1, p2);
			break;
		}
		case 5:
		{
			Input(p1);
			Input(p2);
			PS tong = TongPS(p1, p2);
			cout << "Tong hai phan so: ";
			Output(tong);
			break;
		}
		case 6:
		{
			Input(p1);
			Input(p2);
			PS hieu = HieuPS(p1, p2);
			cout << "Hieu hai phan so: ";
			Output(hieu);
			break;
		}
		case 7:
		{
			Input(p1);
			Input(p2);
			PS tich = TichPS(p1, p2);
			cout << "Tich hai phan so: ";
			Output(tich);
			break;
		}
		case 8:
		{
			Input(p1);
			Input(p2);
			PS thuong = ThuongPS(p1, p2);
			cout << "Thuong hai phan so: ";
			Output(thuong);
			break;
		}
	}

	return 0;
}