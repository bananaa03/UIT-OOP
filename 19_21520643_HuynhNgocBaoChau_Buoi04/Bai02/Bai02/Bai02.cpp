#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

class Diem
{
public:
	double x;
	double y;
	Diem() {}
	Diem(double, double);
	void Input();
	void Output();
	double getX() { return x; }
	double getY() { return y; }
	double KhoangCach(Diem);
};

Diem::Diem(double hoanh, double tung)
{
	x = hoanh;
	y = tung;
}

void Diem::Input()
{
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}

void Diem::Output()
{
	cout << "(" << x << ";" << y << ")";
}

double Diem::KhoangCach(Diem a)
{
	return sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
}

class DuongTron: public Diem
{
private:
	double r;
public:
	DuongTron(double, double, double);
	void Input();
	void Output();
	double ChuVi();
	double DienTich();
	void VTTD(DuongTron);
};

DuongTron::DuongTron(double bk = 1, double hoanh = 0, double tung = 0) : Diem(hoanh, tung)
{
	r = bk;
}

void DuongTron::Input()
{
	cout << "Nhap ban kinh: ";
	cin >> r;
	cout << "Nhap hoanh do tam: ";
	cin >> x;
	cout << "Nhap tung do tam: ";
	cin >> y;
}

void DuongTron::Output()
{
	cout << "Duong tron tam: ";
	Diem::Output();
	cout << "\nBan kinh: " << r << endl;
}

double DuongTron::ChuVi()
{
	return 2 * PI * r;
}

double DuongTron::DienTich()
{
	return PI * r * r;
}

void DuongTron::VTTD(DuongTron c)
{
	if (Diem::KhoangCach(c) == (r + c.r) || Diem::KhoangCach(c) == abs(r - c.r))
		cout << "Hai duong tron tiep xuc nhau." << endl;
	else if (Diem::KhoangCach(c) > (r + c.r))
		cout << "Hai duong trong khong giao nhau." << endl;
	else if (Diem::KhoangCach(c) < (r + c.r))
		cout << "Hai duong tron cat nhau." << endl;
}

int main()
{
	DuongTron c, c1, c2;
	int option;
	do
	{
		cout << "----------Menu----------\n";
		cout << "1. Nhap thong tin duong tron.\n";
		cout << "2. Xuat thong tin duong tron.\n";
		cout << "3. Tinh chu vi duong tron.\n";
		cout << "4. Tinh dien tich duong tron.\n";
		cout << "5. Kiem tra moi quan he giua hai duong tron.\n";
		cout << "0. Thoat khoi chuong trinh.\n";
		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option > 5 || option < 0);

		switch (option)
		{
		case 1:
			cout << "Nhap duong tron:\n";
			c.Input();
			break;
		case 2:
			cout << "Nhap duong tron:\n";
			c.Input();
			cout << "Thong tin duong tron da nhap:\n";
			c.Output();
			cout << endl;
			break;
		case 3:
			cout << "Nhap duong tron:\n";
			c.Input();
			cout << "Chu vi: ";
			cout << c.ChuVi() << endl;
			break;
		case 4:
			cout << "Nhap duong tron:\n";
			c.Input();
			cout << "Dien tich: ";
			cout << c.DienTich() << endl;
			break;
		case 5:
			cout << "Nhap duong tron thu nhat:\n";
			c1.Input();
			cout << "Nhap duong tron thu hai:\n";
			c2.Input();
			cout << "Ket qua: ";
			c1.VTTD(c2);
			break;
		case 0:
			cout << "Ban da chon thoat khoi chuong trinh. Tam biet :)";
		}
	} while (option != 0);
}