#include <iostream>
#include <math.h>
using namespace std;

class Triangles
{
private:
	double a, b, c;
public:
	Triangles();
	Triangles(double, double, double);
	void Input();
	void Output();
	void LoaiTamGiac();
	double ChuVi();
	double DienTich();
};

Triangles::Triangles()
{
	a = 1;
	b = 1;
	c = 1;
}

Triangles::Triangles(double canh1, double canh2, double canh3)
{
	a = canh1;
	b = canh2;
	c = canh3;
}

void Triangles::Input()
{
	cout << "Nhap do dai canh thu nhat: ";
	cin >> a;
	cout << "Nhap do dai canh thu hai: ";
	cin >> b;
	cout << "Nhap do dai canh thu ba: ";
	cin >> c;
}

void Triangles::Output()
{
	if (a + b <= c || a + c <= b || b + c <= a)
		cout << "Khong phai ba canh cua mot tam giac.";
	else
		cout << "Tam giac co do dai ba canh: (" << a << "," << b << "," << c << ")";
}

void Triangles::LoaiTamGiac()
{
	if (a + b <= c || a + c <= b || b + c <= a)
		cout << "Khong phai ba canh cua mot tam giac.";
	else
	{
		if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
			cout << "tam giac vuong";
		else if (a == b && b == c)
			cout << "tam giac deu";
		else if (a == b || a == c || b == c)
			cout << "tam giac can";
		else if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b)
			cout << "tam giac tu";
		else
			cout << "tam giac nhon";
	}
}

double Triangles::ChuVi()
{
	return a + b + c;
}

double Triangles::DienTich()
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
	Triangles abc;

	cout << "----------Menu----------\n";
	cout << "1. Nhap tam giac.\n";
	cout << "2. Xuat thong tin tam giac.\n";
	cout << "3. Xet loai tam giac.\n";
	cout << "4. Tinh chu vi tam giac.\n";
	cout << "5. Tinh dien tich tam giac.\n";

	cout << "Nhap lua chon: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		cout << "Nhap ba canh tam giac:\n";
		abc.Input();
		break;
	case 2:
		cout << "Nhap ba canh tam giac:\n";
		abc.Input();
		
		cout << "Thong tin tam giac da nhap: ";
		abc.Output();
		break;
	case 3:
		cout << "Nhap ba canh tam giac:\n";
		abc.Input();

		cout << "Loai tam giac tu ba canh da nhap: ";
		abc.LoaiTamGiac();
		break;
	case 4:
		cout << "Nhap ba canh tam giac:\n";
		abc.Input();

		cout << "Chu vi = ";
		cout << abc.ChuVi();
		break;
	case 5:
		cout << "Nhap ba canh tam giac:\n";
		abc.Input();

		cout << "Dien tich: ";
		cout << abc.DienTich();
		break;
	}
	return 0;
}