#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
	int manv;
	string hoten;
	float luong;
public:
	bool chucvu;
	NhanVien(){}
	NhanVien(int, string, float, bool);
	void Input();
	void Random();
	void Output();
	NhanVien FindID(NhanVien a[], int n, int);
	void Update(NhanVien a[], int n, int);
	NhanVien FindMax(NhanVien a[], int n);
	NhanVien FindMin(NhanVien a[], int n);
	void Find10Max(NhanVien a[], int n);
};

NhanVien::NhanVien(int id, string name, float salary, bool cv)
{
	manv = id;
	hoten = name;
	luong = salary;
	chucvu = cv;
}

void NhanVien::Input()
{
	cout << "Nhap ma nhan vien: ";
	cin >> manv;
	cout << "Nhap ho ten nhan vien: ";
	cin.ignore();
	getline(cin, hoten);
	cout << "Nhap chuc vu: ";
	cin >> chucvu;
}

void NhanVien::Random()
{
	srand(time(NULL));
	manv = rand();
	hoten = rand();
	luong = rand();
	chucvu = rand();
}

void NhanVien::Output()
{
	cout << "Ma nhan vien: " << manv;
	cout << "\nHo ten nhan vien: " << hoten;
	if (chucvu == 0)
	{
		cout << "\nChuc vu: Nhan vien van phong";
	}
	else
		cout << "\nChuc vu: Nhan vien san xuat";
}

NhanVien NhanVien::FindID(NhanVien a[], int n, int option)
{
	cout << "Nhap ma nhan vien can tim: ";
	cin >> option;
	for (int i = 0; i < n; i++)
		if (a[i].manv == option)
			return a[i];
}

void NhanVien::Update(NhanVien a[], int n, int option)
{
	cout << "Nhap ma nhan vien can cap nhat ten: ";
	cin >> option;
	for (int i = 0; i < n; i++)
		if (a[i].manv == option)
		{
			cout << "Nhap lai ten nhan vien: ";
			getline(cin, hoten);
		}
}

NhanVien NhanVien::FindMax(NhanVien a[], int n)
{
	int i;
	float max = a[0].luong;
	for (i = 0; i < n; i++)
		if (a[i].luong > max) max = a[i].luong;
	return a[i];
}

NhanVien NhanVien::FindMin(NhanVien a[], int n)
{
	int i;
	float min = a[0].luong;
	for (i = 0; i < n; i++)
		if (a[i].luong < min) min = a[i].luong;
	return a[i];
}

void NhanVien::Find10Max(NhanVien a[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].luong > a[j].luong) {
				float temp = a[i].luong;
				a[i].luong = a[j].luong;
				a[j].luong = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		a[i].Output();
		cout << endl;
	}
}

class NVVP : public NhanVien
{
	int songaylam;
public:
	NVVP(int, int, string, float, bool);
	float tinhLuong();
};

NVVP::NVVP(int date = 0, int id = 0, string name = "", float salary = 0, bool cv = 0) : NhanVien(id, name, salary, cv)
{
	songaylam = date;
}

float NVVP::tinhLuong()
{
	return 4500000 + songaylam * 220000;
}

class NVSX :public NhanVien
{
	int sosanpham;
public:
	NVSX(int, int, string, float, bool);
	float tinhLuong();
};

NVSX::NVSX(int product, int id, string name, float salary, bool cv = 0) : NhanVien(id, name, salary, cv)
{
	sosanpham = product;
}

float NVSX::tinhLuong()
{
	return 5300000 + sosanpham * 170000;
}

int main()
{
	NhanVien a[200];
	int option, n;
	do
	{
		cout << "----------Menu----------\n";
		cout << "1. Nhap danh sach nhan vien.\n";
		cout << "2. Tao danh sach nhan vien ngau nhien.\n";
		cout << "3. Xuat thong tin cac nhan vien.\n";
		cout << "4. Cap nhat luong cho nhan vien.\n";
		cout << "5. Tim nhan vien theo ma nhan vien.\n";
		cout << "6. Cap nhat lai ten nhan vien theo ma nhan vien.\n";
		cout << "7. Tim nhan vien co luong cao nhat.\n";
		cout << "8. Tim nhan vien co luong thap nhat.\n";
		cout << "9. Tim top 10 nhan vien co luong cao nhat.\n";
		cout << "0. Thoat chuong trinh.\n";
		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option > 9 || option < 0);

		switch (option)
		{
		case 1:
			cout << "Nhap danh sach cac nhan vien:\nNhap so luong nhan vien: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap nhan vien thu " << i + 1 << endl;
				a[i].Input();
			}
			break;
		case 2:
			cout << "Danh sach cac nhan vien duoc nhap tu dong:\nNhap so luong nhan vien: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				a[i].Random(); 
				a[i].Output();
				cout << endl;
			}
			break;
		case 3:
			cout << "Nhap danh sach cac nhan vien:\nNhap so luong nhan vien: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap nhan vien thu " << i + 1 << endl;
				a[i].Input();
			}
			for (int i = 0; i < n; i++)
			{
				a[i].Output();
				cout << endl;
			}
			break;
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0:
			cout << "Ban da chon thoat khoi chuong trinh. Tam biet :)";
		}
	} while (option != 0);
}