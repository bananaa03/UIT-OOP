#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
protected:
	int manv;
	string hoten;
	int luong;
	int luongcoban;
public:
	virtual void NhapNV();
	virtual void XuatNV();
	virtual void Random();
	virtual void TinhLuong() = 0;
	int Get_Manv() { return this->manv; }
	int Get_Luong() { return this->luong; }
	virtual int Get_SoSP() { return -1; }
	bool TimNV(int manhanvien);
	NhanVien();
	~NhanVien();
};

void NhanVien::NhapNV()
{
	cout << "Nhap ma nhan vien: ";
	cin >> manv;
	cin.ignore();
	cout << "Nhap ten nhan vien: ";
	getline(cin, hoten);
}

void NhanVien::XuatNV()
{
	cout << manv << "  " << hoten << "  " << "Tong luong: " << luong;
}

void NhanVien::Random()
{
	manv = rand();
	hoten = rand();
}

bool NhanVien::TimNV(int manhanvien)
{
	if (manv == manhanvien)
		return true;
	return false;
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

class NhanVienSX : public NhanVien
{
	int sosanpham;
public:
	void NhapNV();
	void XuatNV();
	void Random();
	void TinhLuong();
	int Get_SoSP();
	NhanVienSX();
	~NhanVienSX();
};

void NhanVienSX::NhapNV()
{
	NhanVien::NhapNV();
	cout << "Nhap so san pham: ";
	cin >> sosanpham;
}

void NhanVienSX::XuatNV()
{
	NhanVien::XuatNV();
	cout << "  Luong co ban: " << luongcoban << endl;
}

void NhanVienSX::Random()
{
	NhanVien::Random();
	sosanpham = rand();
}

void NhanVienSX::TinhLuong()
{
	luong = luongcoban + sosanpham * 170000;
}

int NhanVienSX::Get_SoSP()
{
	return this->sosanpham;
}

NhanVienSX::NhanVienSX()
{
	luongcoban = 5300000;
}

NhanVienSX::~NhanVienSX()
{

}

class NhanVienVP : public NhanVien
{
	int songaylam;
public:
	void NhapNV();
	void XuatNV();
	void Random();
	void TinhLuong();
	NhanVienVP();
	~NhanVienVP();
};

void NhanVienVP::NhapNV()
{
	NhanVien::NhapNV();
	cout << "Nhap so ngay lam viec: ";
	cin >> songaylam;
}

void NhanVienVP::XuatNV()
{
	NhanVien::XuatNV();
	cout << "  Luong co ban: " << luongcoban << endl;
}

void NhanVienVP::Random()
{
	NhanVien::Random();
	songaylam = rand();
}

void NhanVienVP::TinhLuong()
{
	luong = luongcoban + songaylam * 220000;
}

NhanVienVP::NhanVienVP()
{
	luongcoban = 4500000;
}

NhanVienVP::~NhanVienVP()
{

}

void Menu()
{
	cout << "----------Menu----------\n";
	cout << "1. Nhap thong tin nhan vien.\n";
	cout << "2. Kiem thu danh sach nhan vien.\n";
	cout << "3. Xuat thong tin nhan vien\n";
	cout << "4. Tim nhan vien theo ma nhan vien.\n";
	cout << "5. Tim nhan vien co luong cao nhat.\n";
	cout << "6. Tim nhan vien co so san pham thap nhat.\n";
	cout << "0. Thoat khoi chuong trinh.\n";
}

void ChonLoaiNhanVien()
{
	cout << "1. Nhan vien san xuat.\n";
	cout << "0. Nhan vien van phong.\n";
}

int TimNhanVien(int manv, NhanVien* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].Get_Manv() == manv)
			return i;
	}
	return n;
}

int main()
{
	NhanVien *a[200];
	int n, option, index;
	bool chonnhanvien;
	int max = 0;
	int min;

	do
	{
		Menu();
		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option < 0 || option > 7);

		switch (option)
		{
		case 1:
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				ChonLoaiNhanVien();
				cout << "Chon loai nhan vien: ";
				cin >> chonnhanvien;
				switch (chonnhanvien)
				{
				case 1:
					a[i] = new NhanVienSX();
					a[i]->NhapNV();
					break;
				case 0:
					a[i] = new NhanVienVP();
					a[i]->NhapNV();
					break;
				}
			}
			break;
		case 2:
			n = 3;
			for (int i = 0; i < n; i++)
			{
				ChonLoaiNhanVien();
				chonnhanvien = rand();
				switch (chonnhanvien)
				{
				case 1:
					a[i] = new NhanVienSX();
					a[i]->Random();
					a[i]->TinhLuong();
					a[i]->XuatNV();
					cout << endl;
					break;
				case 0:
					a[i] = new NhanVienVP();
					a[i]->Random();
					a[i]->TinhLuong();
					a[i]->XuatNV();
					cout << endl;
					break;
				}
			}
			break;
		case 3:
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				ChonLoaiNhanVien();
				cout << "Chon loai nhan vien: ";
				cin >> chonnhanvien;
				switch (chonnhanvien)
				{
				case 1:
					a[i] = new NhanVienSX();
					a[i]->NhapNV();
					a[i]->TinhLuong();
					a[i]->XuatNV();
					break;
				case 0:
					a[i] = new NhanVienVP();
					a[i]->NhapNV();
					a[i]->TinhLuong();
					a[i]->XuatNV();
					break;
				}
			}
			break;
		case 4:
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				ChonLoaiNhanVien();
				cout << "Chon loai nhan vien: ";
				cin >> chonnhanvien;
				switch (chonnhanvien)
				{
				case 1:
					a[i] = new NhanVienSX();
					a[i]->NhapNV();
					break;
				case 0:
					a[i] = new NhanVienVP();
					a[i]->NhapNV();
					break;
				}
			}
			int manv;
			cout << "Nhap ma nhan vien can tim: ";
			cin >> manv;
			index = TimNhanVien(manv, *a, n);
			if (index < n)
				a[index]->XuatNV();
			else
				cout << "Khong co nhan vien can tim!\n";
			break;
		case 5:
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				ChonLoaiNhanVien();
				cout << "Chon loai nhan vien: ";
				cin >> chonnhanvien;
				switch (chonnhanvien)
				{
				case 1:
					a[i] = new NhanVienSX();
					a[i]->NhapNV();
					a[i]->TinhLuong();
					break;
				case 0:
					a[i] = new NhanVienVP();
					a[i]->NhapNV();
					a[i]->TinhLuong();
					break;
				}
			}
			for (int i = 1; i < n; i++)
				if (a[i]->Get_Luong() > a[max]->Get_Luong())
					max = i;
			cout << "Nhan vien co luong cao nhat: ";
			a[max]->XuatNV();
			break;
		case 6:
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				ChonLoaiNhanVien();
				cout << "Chon loai nhan vien: ";
				cin >> chonnhanvien;
				switch (chonnhanvien)
				{
				case 1:
					a[i] = new NhanVienSX();
					a[i]->NhapNV();
					a[i]->TinhLuong();
					break;
				case 0:
					a[i] = new NhanVienVP();
					a[i]->NhapNV();
					a[i]->TinhLuong();
					break;
				}
			}

			for (int i = 0; i < n; i++)
				if (a[i]->Get_SoSP() != -1)
				{
					min = i;
					for (int i = min + 1; i < n; i++)
						if (a[i]->Get_SoSP() < a[min]->Get_SoSP() && a[i]->Get_SoSP() != -1)
							min = i;
					break;
				}
			cout << "Nhan vien co so san pham thap nhat: ";
			a[min]->XuatNV();
			break;
		case 0:
			cout << "Ban da chon thoat khoi chuong trinh. Tam biet :)";
			break;
		}
	} while (option != 0);
}