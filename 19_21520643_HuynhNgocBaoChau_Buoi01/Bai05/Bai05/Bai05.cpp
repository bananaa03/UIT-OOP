#include <iostream>
#include <string>
using namespace std;

typedef struct HocSinh
{
	string hoten;
	float toan;
	float van;
} HS;

void Input(HS &hs)
{
	cout << "Nhap ho ten: ";
	getline(cin, hs.hoten);

	cout << "Nhap diem toan: ";
	cin >> hs.toan;

	cout << "Nhap diem van: ";
	cin >> hs.van;
}

int main()
{
	HS hs;
	Input(hs);

    double diemtrungbinh = (hs.toan + hs.van) / 2;
	cout << "Diem trung binh la: " << diemtrungbinh;

	return 0;
}

