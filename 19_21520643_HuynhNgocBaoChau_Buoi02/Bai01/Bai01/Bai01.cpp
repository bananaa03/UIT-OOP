//Bai01

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class PhanSo
{
private:
	int tuso, mauso;
public:
	PhanSo();
	PhanSo(int, int);
	void NhapPS();
	void XuatPS();
	void RutGon();
	PhanSo CongPS(PhanSo);
	PhanSo TruPS(PhanSo);
	PhanSo NhanPS(PhanSo);
	PhanSo ChiaPS(PhanSo);
	void Random();
};

PhanSo::PhanSo()
{
	tuso = 0;
	mauso = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
	tuso = tu;
	mauso = mau;
}

void PhanSo::NhapPS()
{
	cout << endl;
	cout << "Nhap tu so: ";
	cin >> tuso;
	cout << "Nhap mau so: ";
	cin >> mauso;
}

void PhanSo::XuatPS()
{
	cout << tuso << "/" << mauso << endl;
}

void PhanSo::Random()
{
	srand(time(NULL));
	this->tuso = rand() % 5;
	this->mauso = rand() % 5 + 3;
}

int UCLN(int a, int b)
{
	if (a % b != 0)
		return UCLN(b, a % b);
	else
		return b;
}

void PhanSo::RutGon()
{
	int c = UCLN(tuso, mauso);
	tuso = tuso / c;
	mauso = mauso / c;
}

PhanSo PhanSo::CongPS(PhanSo p)
{
	PhanSo tong(tuso * p.mauso + p.tuso * mauso, mauso * p.mauso);
	tong.RutGon();
	return tong;
}

PhanSo PhanSo::TruPS(PhanSo p)
{
	PhanSo hieu(tuso * p.mauso - p.tuso * mauso, mauso * p.mauso);
	hieu.RutGon();
	return hieu;
}

PhanSo PhanSo::NhanPS(PhanSo p)
{
	PhanSo tich(tuso * p.tuso, mauso * p.mauso);
	tich.RutGon();
	return tich;
}

PhanSo PhanSo::ChiaPS(PhanSo p)
{
	PhanSo thuong(tuso * p.mauso, p.tuso * mauso);
	thuong.RutGon();
	return thuong;
}

int main()
{
	PhanSo p;
	PhanSo p1;
	PhanSo p2;

	cout << "----------Menu----------\n";
	cout << "1. Nhap phan so tu ban phim\n";
	cout << "2. Nhap phan so tu dong\n";
	cout << "3. Xuat phan so\n";
	cout << "4. Cong, tru, nhan, chia phan so\n";

	int option;
	do
	{
		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option > 4 || option < 0);

		switch (option)
		{
		case 1:
		{
			cout << "Nhap phan so: ";
			p.NhapPS();
			break;
		}
		case 2:
		{
			cout << "Phan so duoc nhap tu dong: ";
			p.Random();
			p.XuatPS();
			break;
		}
		case 3:
		{
			cout << "Nhap phan so: ";
			p.NhapPS();
			cout << "Phan so da nhap: ";
			p.XuatPS();
			break;
		}
		case 4:
		{
			cout << "Nhap phan so thu nhat: ";
			p1.NhapPS();
			cout << "Nhap phan so thu hai: ";
			p2.NhapPS();

			cout << "Tong 2 phan so: ";
			p1.CongPS(p2).XuatPS();

			cout << "Hieu 2 phan so: ";
			p1.TruPS(p2).XuatPS();

			cout << "Tich 2 phan so: ";
			p1.NhanPS(p2).XuatPS();

			cout << "Thuong 2 phan so: ";
			p1.ChiaPS(p2).XuatPS();

			break;
		}
		}
	} while (option < 4 && option>0);
	return 0;
}
