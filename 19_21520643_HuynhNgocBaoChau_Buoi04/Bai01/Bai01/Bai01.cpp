#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class PhanSo
{
public:
	int tuso;
	int mauso;
	PhanSo(){}
	PhanSo(int, int);
	void Input();
	void Output();
	int getTu() { return tuso; }
	int getMau() { return mauso; }
	void RutGon();
};

PhanSo::PhanSo(int tu, int mau)
{
	tuso = tu;
	mauso = mau;
}

void PhanSo::Input()
{
	cout << "Nhap tu so: ";
	cin >> tuso;
	cout << "Nhap mau so: ";
	cin >> mauso;
}

void PhanSo::Output()
{
	cout << tuso << "/" << mauso;
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

class HonSo : public PhanSo
{
private:
	int nguyen;
public:
	HonSo(int, int, int);
	void Input();
	void Random();
	void Output();
	HonSo Chuyen(PhanSo);
	PhanSo Chuyen();
	HonSo Cong(HonSo);
	HonSo Tru(HonSo);
	PhanSo Nhan(HonSo);
	HonSo Chia(HonSo);
	void SoSanh(HonSo);
};

HonSo::HonSo(int a = 0, int b = 0, int c = 1) : PhanSo(b, c)
{
	nguyen = a;
}

void HonSo::Input()
{
	cout << "Nhap phan nguyen: ";
	cin >> nguyen;
	cout << "Nhap tu so: ";
	cin >> tuso;
	cout << "Nhap mau so: ";
	cin >> mauso;
}

void HonSo::Random()
{
	srand(time(NULL));
	this->nguyen = rand() % 6;
	this->tuso = rand() % 5;
	this->mauso = rand() % 5 + 3;
}

void HonSo::Output()
{
	cout << nguyen << "|" << tuso << "/" << mauso;
}

PhanSo HonSo::Chuyen()
{
	return PhanSo(mauso * nguyen + tuso, mauso);
}

HonSo HonSo::Chuyen(PhanSo p)
{
	if (p.getTu() < p.getMau())
		return HonSo(0, p.tuso, p.mauso);
	return HonSo(p.tuso / p.mauso, p.tuso % p.mauso, p.mauso);
}

HonSo HonSo::Cong(HonSo h)
{
	PhanSo cong(tuso * h.mauso + h.tuso * mauso, mauso * h.mauso);
	cong.RutGon();
	return HonSo(nguyen + h.nguyen, cong.tuso, cong.mauso);
}

HonSo HonSo::Tru(HonSo h)
{
	PhanSo tru(tuso * h.mauso - h.tuso * mauso, mauso * h.mauso);
	tru.RutGon();
	return HonSo(nguyen - h.nguyen, tru.tuso, tru.mauso);
}

void HonSo::SoSanh(HonSo h)
{
	h.Chuyen();
	if (tuso * h.mauso == mauso * h.tuso)
		cout << "2 hon so bang nhau.";
	if (tuso * h.mauso > mauso * h.tuso)
		cout << "Phan so thu nhat > Phan so thu hai.";
	else
		cout << "Phan so thu nhat < Phan so thu hai.";
}

int main()
{
	HonSo h1, h2, h;
	PhanSo p, p1, p2;
	int option;
	do
	{
		cout << "----------Menu----------\n";
		cout << "1. Nhap hon so.\n";
		cout << "2. Nhap hon so theo phuong phap tu dong.\n";
		cout << "3. Xuat hon so.\n";
		cout << "4. Chuyen doi phan so thanh hon so.\n";
		cout << "5. Chuyen doi hon so thanh phan so.\n";
		cout << "6. Cong, tru, nhan, chia hai hon so.\n";
		cout << "7. So sanh hai hon so.\n";
		cout << "0. Thoat khoi chuong trinh.\n";
		
		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option > 7 || option < 0);

		switch (option)
		{
		case 1:
			cout << "Nhap hon so:\n";
			h.Input();
			break;
		case 2:
			cout << "Ban da chon nhap tu dong hon so.\Hon so duoc nhap tu dong: ";
			h.Random();
			h.Output();
			cout << endl;
			break;
		case 3:
			cout << "Nhap hon so:\n";
			h.Input();
			cout << "Hon so da nhap: ";
			h.Output();
			cout << endl;
			break;
		case 4:
			cout << "Nhap phan so:\n";
			p.Input();
			cout << "Chuyen thanh hon so: ";
			h.Chuyen(p).Output();
			cout << endl;
			break;
		case 5:
			cout << "Nhap hon so:\n";
			h.Input();
			cout << "Chuyen thanh phan so: ";
			p = h.Chuyen();
			p.Output();
			cout << endl;
			break;
		case 7:
			cout << "Nhap hon so thu nhat:\n";
			h1.Input();
			h1.Chuyen();
			cout << "Nhap hon so thu hai:\n";
			h2.Input();
			cout << "Ket qua so sanh: ";
			h1.SoSanh(h2);
			break;
		case 6:
			cout << "Nhap hon so thu nhat:\n";
			h1.Input();
			cout << "Nhap hon so thu hai:\n";
			h2.Input();

			cout << "Cong: ";
			h1.Cong(h2).Output();
			
			cout << "\nTru: ";
			h1.Tru(h2).Output();
			cout << endl;
			break;
		case 0:
			cout << "Ban da chon thoat khoi chuong trinh. Tam biet :)";
			break;
		}
	} while (option != 0);
}