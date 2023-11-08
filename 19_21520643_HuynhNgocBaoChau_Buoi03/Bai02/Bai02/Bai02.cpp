#include <iostream>
#include <cmath>
using namespace std;

class ToaDo
{
public:
private:
	double x, y;
public:
	ToaDo(){}
	ToaDo(double hoanh, double tung);
	friend istream& operator>>(istream& i, ToaDo& A);
	friend ostream& operator<<(ostream& o, ToaDo A);
	//friend class TamGiac;
	double KhoangCach(ToaDo);
	//double ToO();
};
typedef ToaDo Diem;

ToaDo::ToaDo(double hoanh, double tung)
{
	x = hoanh;
	y = tung;
}

double ToaDo::KhoangCach(ToaDo B)
{
	return sqrt(pow(x - B.x, 2) + pow(y - B.y, 2));
}

istream& operator>>(istream& i, Diem& A)
{
	cout << "Nhap hoanh do: ";
	cin >> A.x;
	cout << "Nhap tung do: ";
	cin >> A.y;
	return i;
}

ostream& operator<<(ostream& o, Diem A)
{
	cout << "(" << A.x << "," << A.y << ")";
	return o;
}

class TamGiac
{
	Diem A, B, C;
public:
	TamGiac() {}
	TamGiac(double xA, double yA, double xB, double yB, double xC, double yC): A(), B(), C()
	{
		cout << "Da khoi tao tam giac: ";
		cout << A << "," << B << "," << C;
	}
	void Input();
	void Output();
	int Check();
	void XetLoai();
	double ChuVi();
	double DienTich();
	//Diem TamNgoaiTiep();
	//Diem TamNoiTiep();
};

void TamGiac::Input()
{
	cout << "Nhap thong tin tam giac:\n";
	cout << "Nhap dinh thu nhat:\n";
	cin >> A;
	cout << "Nhap dinh thu hai:\n";
	cin >> B;
	cout << "Nhap dinh thu ba:\n";
	cin >> C;
}

void TamGiac::Output()
{
	cout << "Tam giac(" << A << ", " << B << ", " << C << ")";
}

int TamGiac::Check()
{
	double AB = A.KhoangCach(B);
	double BC = B.KhoangCach(C);
	double AC = A.KhoangCach(C);
	if (AB + BC < AC || AB + AC < BC || BC + AC < AB)
		return 0;
	return 1;
}

void TamGiac::XetLoai()
{
	double AB = A.KhoangCach(B);
	double BC = B.KhoangCach(C);
	double AC = A.KhoangCach(C);

	if (AB == BC && BC == AC)
		cout << "Tam giac deu.";
	else if (AB == BC || BC == AC || AB == AC)
		cout << "Tam giac can.";
	else if (AB * AB == BC * BC + AC * AC || BC * BC == AB * AB + AC * AC || AC * AC == AB * AB + BC * BC)
		cout << "Tam giac vuong.";
	else
		cout << "Tam giac nhon.";
}

double TamGiac::ChuVi()
{
	double AB = A.KhoangCach(B);
	double BC = B.KhoangCach(C);
	double AC = A.KhoangCach(C);
	return AB + BC + AC;
}

double TamGiac::DienTich()
{
	double AB = A.KhoangCach(B);
	double BC = B.KhoangCach(C);
	double AC = A.KhoangCach(C);
	double p = ChuVi() / 2;
	return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}

int main()
{
	TamGiac ABC;
	Diem A, B, C;
	int option;
	do
	{
		cout << "----------Menu----------\n";
		cout << "1. Nhap tam giac.\n";
		cout << "2. Xuat thong tin tam giac.\n";
		cout << "3. Xet loai tam giac.\n";
		cout << "4. Tinh chu vi.\n";
		cout << "5. Tinh dien tich.\n";
		//cout << "6. Tim tam duong trong ngoai tiep tam giac.\n";
		//cout << "7. Tim tam duong tron noi tiep tam giac.\n";
		cout << "0. Thoat.\n";

		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option < 0 || option > 7);
		switch (option)
		{
		case 1:
			do
			{
				ABC.Input();
			} while (ABC.Check() == 0);
			break;
		case 2:
			do
			{
				ABC.Input();
			} while (ABC.Check() == 0);

			cout << "Tam giac da nhap la: ";
			ABC.Output();
			break;
		case 3:
			do
			{
				ABC.Input();
			} while (ABC.Check() == 0);

			cout << "Tam giac da nhap la: ";
			ABC.XetLoai();
			break;
		case 4:
			do
			{
				ABC.Input();
			} while (ABC.Check() == 0);

			cout << "Chu vi = ";
			cout << ABC.ChuVi();
			break;
		case 5:
			do
			{
				ABC.Input();
			} while (ABC.Check() == 0);

			cout << "Dien tich = ";
			cout << ABC.DienTich();
			break;
		case 0:
			cout << "Ban da chon thoat khoi chuong trinh.\nTam biet :)";
		}
		cout << "\n\n\n";
	} while (option != 0);
}