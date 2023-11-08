#include <iostream>
using namespace std;

class SoPhuc
{
private:
	double thuc;
	double ao;
public:
	SoPhuc();
	SoPhuc(double, double);
	void Input();
	void Output();
	SoPhuc Cong(SoPhuc);
	SoPhuc Tru(SoPhuc);
	SoPhuc Nhan(SoPhuc);
	SoPhuc Chia(SoPhuc);
};

SoPhuc::SoPhuc()
{
	thuc = 0;
	ao = 0;
}

SoPhuc::SoPhuc(double t, double a)
{
	thuc = t;
	ao = a;
}

void SoPhuc::Input()
{
	cout << "Nhap phan thuc: ";
	cin >> thuc;
	cout << "Nhap phan ao: ";
	cin >> ao;
}

void SoPhuc::Output()
{
	cout << "(" << thuc << "," << ao << ")";
}

SoPhuc SoPhuc::Cong(SoPhuc m)
{
	SoPhuc tong;
	tong.thuc = m.thuc + thuc;
	tong.ao = m.ao + ao;
	return tong;
}

SoPhuc SoPhuc::Tru(SoPhuc m)
{
	SoPhuc hieu;
	hieu.thuc = m.thuc - thuc;
	hieu.ao = m.ao - ao;
	return hieu;
}

SoPhuc SoPhuc::Nhan(SoPhuc m)
{
	SoPhuc tich;
	tich.thuc = m.thuc * thuc - m.ao * ao;
	tich.ao = m.thuc * ao + m.ao * thuc;
	return tich;
}

SoPhuc SoPhuc::Chia(SoPhuc m)
{
	SoPhuc thuong;
	thuong.thuc = (m.thuc * thuc + m.ao * ao) / (pow(thuc, 2) + pow(ao, 2));
	thuong.ao = (thuc * m.ao - m.thuc * ao) / (pow(thuc, 2) + pow(ao, 2));
	return thuong;
}

int main()
{
	SoPhuc m, n, cong, tru, nhan, chia;

	cout << "----------Menu----------\n";
	cout << "1. Nhap so phuc\n";
	cout << "2. Xuat so phuc\n";
	cout << "3. Cong, tru, nhan, chia hai so phuc\n";

	cout << "Nhap lua chon: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		cout << "Nhap so phuc:\n";
		m.Input();
		break;
	case 2:
		cout << "Nhap so phuc:\n";
		m.Input();

		cout << "So phuc vua nhap: ";
		m.Output();
		break;
	case 3:
		cout << "Nhap so phuc thu nhat:\n";
		m.Input();

		cout << "Nhap so phuc thu hai:\n";
		n.Input();

		cout << "A + B = ";
		m.Cong(n).Output();

		cout << endl;

		cout << "A - B = ";
		m.Tru(n).Output();

		cout << endl;

		cout << "A * B = ";
		m.Nhan(n).Output();

		cout << endl;

		cout << "A / B = ";
		m.Chia(n).Output();
		break;
	}
	return 0;
}
