#include <iostream>
#include <string>
using namespace std;
#define MAX 300

class NhanVien
{
private:
	int manhanvien;
	string hoten;
	int sosanpham;
	int luong;
public:
	NhanVien() {};
	NhanVien(int, string, int, int);
	void Input();
	void Output();
	void Random();
	void FindID();
	void Update();
	int TinhLuong();
	void FindMax();
	void FindMin();
	void Find10Max();
};

NhanVien::NhanVien(int ID, string name, int number, int salary)
{
	manhanvien = ID;
	hoten = name;
	number = sosanpham;
	luong = salary;
}

void NhanVien::Input()
{
	cout << "Nhap thong tin nhan vien:\n";
	cout << "Nhap ma nhan vien: ";
	cin >> manhanvien;
	cin.ignore();
	cout << "Nhap ho ten nhan vien: ";
	getline(cin, hoten);
	cout << "Nhap so san pham da lam: ";
	cin >> sosanpham;
}

void NhanVien::Output()
{
	cout << "Thong tin cua nhan vien:\n";
	cout << "Ma nhan vien: " << manhanvien;
	cout << "\nHo ten nhan vien: " << hoten;
	cout << "\nSo san pham da lam: " << sosanpham;
	cout << "\nLuong: " << luong;
}

void NhanVien::Random()
{
	
}

