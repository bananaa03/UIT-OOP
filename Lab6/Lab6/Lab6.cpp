#include <iostream>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

class NhanVien
{
protected:
	string HoTen;
	int MaNhanVien;
	int Luong;
	int LuongCB;
public:
	NhanVien();
	NhanVien(string ht, int ma, int l, int lcb);
	virtual void Nhap() = 0;
	void Xuat();
	int GetMNV() { return MaNhanVien; }
	int GetLuong() { return Luong; }
	string GetHoTen() { return HoTen; }
	void SetHoTen(string ht) { HoTen = ht; }
	void SetMNV(int ma) { MaNhanVien = ma; }
	virtual void SetLuong() {}
	virtual void TaoNgauNhien() {}
	virtual int GetLoai() = 0;
	virtual int GetSP() = 0;
};

NhanVien::NhanVien()
{
	HoTen = " ";
	MaNhanVien = 0;
	Luong = 0;
	LuongCB = 0;
}

NhanVien::NhanVien(string ht, int ma, int l, int lcb)
{
	HoTen = ht;
	MaNhanVien = ma;
	Luong = l;
	LuongCB = lcb;
}


void NhanVien::Xuat()
{
	cout << "Ho va ten nhan vien la: " << HoTen;
	cout << "\nMa nhan vien la: " << MaNhanVien;
	cout << "\nLuong cua nhan vien la: " << Luong;
	cout << "\nLuong co ban cua nhan vien la: " << LuongCB;
}

class NhanVienVanPhong :public NhanVien {
	int soNgayLamViec;
public:
	NhanVienVanPhong() :NhanVien()
	{
		soNgayLamViec = 0;
	}
	NhanVienVanPhong(string ht, int ma, int l, int lcb, int ngay) :NhanVien(ht, ma, l, lcb)
	{
		soNgayLamViec = ngay;
	}
	void Nhap();
	void SetLuong() { Luong = LuongCB + 220000 * soNgayLamViec; }
	void SetNgay(int ng) { soNgayLamViec = ng; }
	void TaoNgauNhien();
	int GetLoai() { return 1; }
	int GetSP() { return soNgayLamViec; }
};

void NhanVienVanPhong::Nhap()
{
	LuongCB = 4500000;
	cout << "Nhap ho va ten nhan vien: ";
	getline(cin, HoTen);
	cout << "Nhap ma nhan vien: ";
	cin >> MaNhanVien;
	cout << "Nhap so ngay lam viec: ";
	cin >> soNgayLamViec;
}

void NhanVienVanPhong::TaoNgauNhien()
{
	HoTen = "Hoang Thi Hong Gam";
	for (int i = 0; i < 17; i++) {
		HoTen[i] = rand() % 26 + 97;
	}
	MaNhanVien = rand();
	soNgayLamViec = rand() % 999 + 1;
	Luong = rand() % 10000000 + 1;
	LuongCB = rand() % 5000000 + 1;
}

class NhanVienSanXuat :public NhanVien {
	int soSanPham;
public:
	NhanVienSanXuat() :NhanVien()
	{
		soSanPham = 0;
	}
	NhanVienSanXuat(string ht, int ma, int l, int lcb, int sp) :NhanVien(ht, ma, l, lcb)
	{
		soSanPham = sp;
	}
	void Nhap();
	void SetLuong() { Luong = LuongCB + 170000 * soSanPham; }
	void SetSP(int sp) { soSanPham = sp; }
	int GetSP() { return soSanPham; }
	void TaoNgauNhien();
	int GetLoai() { return 2; }
};

void NhanVienSanXuat::Nhap()
{
	LuongCB = 4700000;
	cout << "Nhap ho va ten nhan vien: ";
	getline(cin, HoTen);
	cout << "Nhap ma nhan vien: ";
	cin >> MaNhanVien;
	cout << "Nhap so san pham: ";
	cin >> soSanPham;
}

void NhanVienSanXuat::TaoNgauNhien()
{
	HoTen = "Hoang Thi Hong Gam";
	for (int i = 0; i < 17; i++) {
		HoTen[i] = rand() % 26 + 97;
	}
	MaNhanVien = rand();
	soSanPham = rand() % 999 + 1;
	Luong = rand() % 10000000 + 1;
	LuongCB = rand() % 5000000 + 1;
}

NhanVien* MaxLuong(NhanVien* a[], int n)
{
	NhanVien* p = a[0];
	a[0]->SetLuong();
	int max = a[0]->GetLuong();
	for (int i = 1; i < n; i++) {
		a[i]->SetLuong();
		if (a[i]->GetLuong() > max) {
			max = a[i]->GetLuong();
			p = a[i];
		}
	}
	return p;
}

NhanVien* MinSP(NhanVien* a[], int n)
{
	NhanVien* p = a[0];
	int x = 0;
	for (int i = 0; i < n; i++)
		if (a[i]->GetLoai() == 2)
		{
			p = a[i];
			x = i;
			break;
		}
	for (int i = x + 1; i < n; i++) {
		if (a[i]->GetLoai() == 1)
			continue;
		if (p->GetSP() > a[i]->GetSP()) 
			p = a[i];
	}
	return p;
}

void Top10(NhanVien* a[], int n)
{
	NhanVien* c[200];
	int d = 0;
	cout << "Top 10 nhan vien co san pham nhieu nhat la: \n";
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		if (a[i]->GetLoai() == 2) {
			c[d] = a[i];
			d++;
		}
	}
	for (int i = 0; i < d; i++) {
		b[i] = c[i]->GetSP();
	}
	sort(b, b + d);
	for (int i = d - 1; i > d - 11; i--) {
		cout << "Nhan vien co san pham nhieu thu " << n - i << '\n';
		for (int j = 0; j < d; j++) {
			if (b[i] == c[j]->GetSP()) {
				c[j]->SetLuong();
				c[j]->Xuat();
				cout << '\n';
				break;
			}
		}
		cout << '\n';
	}
}

int main() {
	int n, l, key, x, y, ma;
	string ht;
	NhanVien* a[200];
	cout << "Nhap so luong nhan vien cua dai ly: ";
	cin >> n;
	cout << "Nhap thong tin cac nhan vien:\n";
	cout << "Nhap 1 neu la nhan vien van phong\n";
	cout << "Nhap 2 neu la nhan vien san xuat\n";
	for (int i = 0; i < n; i++) {
		cout << "Nhan vien thu " << i + 1;
		cout << "\nNhap loai nhan vien: ";
		cin >> l;
		cin.ignore();
		if (l == 1)
		{
			a[i] = new NhanVienVanPhong();
			a[i]->Nhap();
		}
		if (l == 2)
		{
			a[i] = new NhanVienSanXuat();
			a[i]->Nhap();
		}
		cout << '\n';
	}
	do
	{
		cout << "=================MENU================\n";
		cout << "1.Xuat cac nhan vien\n";
		cout << "2.Tinh va cap nhat tien luong cac loai nhan vien\n";
		cout << "3.Tim nhan vien theo ma nhan vien\n";
		cout << "4.Cap nhat thong tin nhan vien theo ma nhan vien\n";
		cout << "5.Tim nhan vien co luong cao nhat\n";
		cout << "6.Tim nhan vien co so san pham nhieu nhat\n";
		cout << "7.Tim top 10 nhan vien co so san pham nhieu nhat\n";
		cout << "8.Tao ngau nhien du lieu nhieu ngan vien\n";
		cout << "Moi chon menu: ";
		cin >> key;
		cout << '\n';
		switch (key) {
		case 1:
			for (int i = 0; i < n; i++) {
				cout << "Nhan vien thu " << i + 1 << ":\n";
				a[i]->SetLuong();
				a[i]->Xuat();
				cout << '\n' << '\n';
			}
			break;
		case 2:
			cout << "Tien luong cua nhan vien:\n";
			for (int i = 0; i < n; i++) {
				cout << "Nhan vien " << a[i]->GetHoTen() << ": ";
				a[i]->SetLuong();
				cout << a[i]->GetLuong() << '\n';
			}
			break;
		case 3:
			cout << "Nhap ma nhan vien can tim: ";
			cin >> x;
			for (int i = 0; i < n; i++) {
				if (a[i]->GetMNV() == x) {
					a[i]->SetLuong();
					a[i]->Xuat();
					break;
				}
			}
			break;
		case 4:
			cout << "Nhap ma nhan vien: ";
			cin >> x;
			y = rand() % 2;
			for (int i = 0; i < n; i++) {
				if (a[i]->GetMNV() == x) {
					if (y == 0) {
						cout << "Nhap ho ten can cap nhat cua nhan vien: ";
						getline(cin, ht);
						a[i]->SetHoTen(ht);
						a[i]->SetLuong();
						a[i]->Xuat();
					}
					if (y == 1) {
						cout << "Nhap ma nhan vien can cap nhat: ";
						cin >> ma;
						a[i]->SetMNV(ma);
						a[i]->SetLuong();
						a[i]->Xuat();
					}
					break;
				}
			}
			break;
		case 5:
			cout << "Nhan vien co luong cao nhat la: \n";
			MaxLuong(a, n)->SetLuong();
			MaxLuong(a, n)->Xuat();
			break;
		case 6:
			cout << "Nhan vien co so san pham thap nhat la:\n";
			MinSP(a, n)->SetLuong();
			MinSP(a, n)->Xuat();
			break;
		case 7:
			Top10(a, n);
			break;
		case 8:
			for (int i = 0; i < n; i++) {
				l = rand() % 2 + 1;
				if (l == 1)
				{
					a[i] = new NhanVienVanPhong();
					a[i]->TaoNgauNhien();
					a[i]->Xuat();
				}
				if (l == 2)
				{
					a[i] = new NhanVienSanXuat();
					a[i]->TaoNgauNhien();
					a[i]->Xuat();
				}
			}
			break;
		case 0:
			break;
		}
	} while (key != 0);
}
