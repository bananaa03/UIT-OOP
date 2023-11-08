#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class PhanSo
{
private:
	int tuso, mauso;
public:
	PhanSo() {}
	PhanSo(int, int);

	void Input();
	void Random();
	void Output();

	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
	PhanSo operator*(PhanSo);
	PhanSo operator/(PhanSo);
	PhanSo operator*(int);
	bool operator>(PhanSo);
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

void PhanSo::Random()
{
	srand(time(NULL));
	this->tuso = rand() % 5;
	this->mauso = rand() % 5 + 3;
}

void PhanSo::Output()
{
	cout << tuso << "/" << mauso;
}

PhanSo PhanSo::operator+(PhanSo p)
{
	return PhanSo(tuso * p.mauso + p.tuso * mauso, mauso * p.mauso);
}

PhanSo PhanSo::operator-(PhanSo p)
{
	return PhanSo(tuso * p.mauso - p.tuso * mauso, mauso * p.mauso);
}

PhanSo PhanSo::operator*(PhanSo p)
{
	return PhanSo(tuso * p.tuso, mauso * p.mauso);
}

PhanSo PhanSo::operator/(PhanSo p)
{
	return PhanSo(tuso * p.mauso, mauso * p.tuso);
}

PhanSo PhanSo::operator*(int n)
{
	return PhanSo(tuso * n, mauso);
}

bool PhanSo::operator>(PhanSo p)
{
	return tuso * p.mauso > p.tuso * mauso;
}

int main()
{
	PhanSo p, p1, p2;
	int n;
	int option;

	do
	{
		cout << "----------Menu----------\n";
		cout << "1. Nhap phan so.\n";
		cout << "2. Nhap phan so tu dong.\n";
		cout << "3. Xuat phan so.\n";
		cout << "4. Cong, tru, nhan, chia 2 phan so.\n";
		cout << "5. Nhan phan so với 1 so.\n";
		cout << "6. So sanh 2 phan so.\n";
		cout << "0. Thoat.\n";

		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option > 6 || option < 0);

		switch (option)
		{
		case 1:
			cout << "Nhap phan so: \n";
			p.Input();
			cout << endl;
			break;
		case 2:
			cout << "Phan so duoc nhap tu dong: ";
			p.Random();
			p.Output();
			cout << endl;
			break;
		case 3:
			cout << "Nhap phan so: \n";
			p.Input();

			cout << "Phan so da nhap: ";
			p.Output();
			cout << endl;
			break;
		case 4:
			cout << "Nhap phan so thu nhat: \n";
			p1.Input();
			cout << "Nhap phan so thu hai: \n";
			p2.Input();

			cout << "Cong: ";
			p1.operator+(p2).Output();

			cout << "\nTru: ";
			p1.operator-(p2).Output();

			cout << "\nNhan: ";
			p1.operator*(p2).Output();

			cout << "\nChia: ";
			p1.operator/(p2).Output();
			cout << endl;
			break;
		case 5:
			cout << "Nhap phan so:\n";
			p.Input();
			cout << "Nhap 1 so tu nhien: ";
			cin >> n;

			cout << "Ket qua: ";
			p.operator*(n).Output();
			cout << endl;
			break;
		case 6:
			cout << "Nhap phan so thu nhat: \n";
			p1.Input();
			cout << "Nhap phan so thu hai: \n";
			p2.Input();

			if (p1.operator>(p2)) 
				cout << "Phan so 1 > Phan so 2";
			else 
				cout << "Phan so 1 < Phan so 2";
			cout << endl;
			break;
		case 0:
			cout << "Ban da chon thoat khoi chuong trinh.\nTam biet :)";
			break;
		}
		cout << endl << endl << endl;
	} while (option != 0);
}
