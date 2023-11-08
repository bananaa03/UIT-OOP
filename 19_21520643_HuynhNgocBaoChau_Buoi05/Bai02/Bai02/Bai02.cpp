#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
protected:
	int manv;
	string hoten;
	int luongcoban;
	int luong;
	int loainhanvien;
public:
	virtual void Input();
	virtual void Output();
	virtual void tinhLuong() = 0;
	int getLuong();
	int getLoaiNV();
	NhanVien();
	~NhanVien();
};

void NhanVien::Input()
{
	cout << "Nhap ma nhan vien: ";
	cin >> manv;
	cout << "Nhap ho ten nhan vien: ";
	cin.ignore();
	getline(cin, hoten);
}

void NhanVien::Output()
{
	cout << manv << "  " << hoten << "  Tien luong: " << luong;
}

int NhanVien::getLuong()
{
	return this->luong;
}

int NhanVien::getLoaiNV()
{
	return this->loainhanvien;
}

NhanVien::NhanVien()
{
	manv = 0;
	hoten = "";
	luong = 0;
}

NhanVien::~NhanVien()
{

}

class LapTrinhVien : public NhanVien
{
	int sogiotangca;
public:
	void Input();
	void Output();
	void tinhLuong();
	LapTrinhVien();
	~LapTrinhVien();
};

void LapTrinhVien::Input()
{
	NhanVien::Input();
	cout << "Nhap so gio tang ca: ";
	cin >> sogiotangca;
}

void LapTrinhVien::Output()
{
	NhanVien::Output();
}

void LapTrinhVien::tinhLuong()
{
	luong = luongcoban + sogiotangca * 250000;
}

LapTrinhVien::LapTrinhVien()
{
	loainhanvien = 1;
	luongcoban = 1000000;
}

LapTrinhVien::~LapTrinhVien()
{

}

class PhanTichVien : public NhanVien
{
	int sogiotangca;
	int phucap;
public:
	void Input();
	void Output();
	void tinhLuong();
	PhanTichVien();
	~PhanTichVien();
};

void PhanTichVien::Input()
{
	NhanVien::Input();
	cout << "Nhap so gio tang ca: ";
	cin >> sogiotangca;
	cout << "Nhap phu cap: ";
	cin >> phucap;
}

void PhanTichVien::Output()
{
	NhanVien::Output();
}

void PhanTichVien::tinhLuong()
{
	luong = (luongcoban + sogiotangca * 250000) * 1.8;
}

PhanTichVien::PhanTichVien()
{
	loainhanvien = 2;
	luongcoban = 1200000;
}

PhanTichVien::~PhanTichVien()
{

}

class NhanVienKiem : public NhanVien
{
	int soloi;
public:
	void Input();
	void Output();
	void tinhLuong();
	NhanVienKiem();
	~NhanVienKiem();
};

void NhanVienKiem::Input()
{
	NhanVien::Input();
	cout << "Nhap so loi da sua: ";
	cin >> soloi;
}

void NhanVienKiem::Output()
{
	NhanVien::Output();
}

void NhanVienKiem::tinhLuong()
{
	luong = luongcoban + soloi * 85000;
}

NhanVienKiem::NhanVienKiem()
{
	loainhanvien = 3;
	luongcoban = 900000;
}

NhanVienKiem::~NhanVienKiem()
{

}

void ChonLoaiNhanVien()
{
	cout << "1. Lap trinh vien.\n2. Phan tich vien.\n3. Nhan vien kiem.\n";
}

int main()
{
	NhanVien *a[200];
	int n, loainhanvien;

	cout << "Nhap n: ";
	cin >> n;

	//Nhap danh sach nhan vien
	for (int i = 0; i < n; i++)
	{
		ChonLoaiNhanVien();
		cout << "Nhap loai nhan vien: ";
		cin >> loainhanvien;

		switch (loainhanvien)
		{
		case 1:
			a[i] = new LapTrinhVien();
			a[i]->Input();
			a[i]->tinhLuong();
			break;
		case 2:
			a[i] = new PhanTichVien();
			a[i]->Input();
			a[i]->tinhLuong();
			break;
		case 3:
			a[i] = new NhanVienKiem();
			a[i]->Input();
			a[i]->tinhLuong();
			break;
		}
	}

	//Xuat danh sach nhan vien
	cout << endl << "Danh sach nhan vien da nhap: \n";
	for (int i = 0; i < n; i++)
	{
		a[i]->Output();
		cout << endl;
	}
	cout << endl;

	//Xuat danh sach nhan vien luong thap hon muc trung binh
	int tongluong = 0;
	for (int i = 0; i < n; i++)
		tongluong += a[i]->getLuong();
	float trungbinh = tongluong / n;
	for(int i=0;i<n;i++)
		if (a[i]->getLuong() < trungbinh)
		{
			cout << "Nhan vien co luong thap hon muc trung binh: ";
			a[i]->Output();
			cout << endl;
		}
	cout << endl;

	//Nhan vien co luong cao nhat
	int max = 0;
	for (int i = 0; i < n; i++)
		if (a[i]->getLuong() > a[max]->getLuong())
			max = i;
	cout << "\nNhan vien co luong cao nhat: ";
	a[max]->Output();
	cout << endl;

	//Lap trinh vien co luong cao nhat
	int maxLTV = 0;
	for (int i = 0; i < n; i++)
		if (a[i]->getLoaiNV() == 1)
		{
			maxLTV = i;
			break;
		}
	for (int i = maxLTV + 1; i < n; i++)
		if (a[i]->getLuong() > a[maxLTV]->getLuong() && a[i]->getLoaiNV() == 1)
			maxLTV = i;
	cout << "Lap trinh vien co luong cao nhat: ";
	a[maxLTV]->Output();
	return 0;
}