#include <iostream>
using namespace std;
#define PI 3.14

class Circle
{
private:
	double r;
	double x, y;
public:
	Circle();
	Circle(double, double, double);
	void Input();
	void Output();
	double ChuVi();
	double DienTich();
	void ZoomIn();
	void ZoomOut();
	void Intersect(Circle, Circle);
};

Circle::Circle()
{
	r = 1;
	x = 0;
	y = 0;
}

Circle::Circle(double bankinh, double hoanhdo, double tungdo)
{
	r = bankinh;
	x = hoanhdo;
	y = tungdo;
}

void Circle::Input()
{
	cout << "Nhap ban kinh: ";
	cin >> r;
	cout << "Nhap hoanh do tam: ";
	cin >> x;
	cout << "Nhap tung do tam: ";
	cin >> y;
}

void Circle::Output()
{
	cout << "[(" << x << ";" << y << ");" << r << "]";
}

double Circle::ChuVi()
{
	return 2 * PI * r;
}

double Circle::DienTich()
{
	return PI * r * r;
}

void Circle::ZoomIn()
{
	cout << "Nhap ti le phan tram can thay doi: ";
	double tile;
	cin >> tile;

	r = r + r * tile;
	cout << "Duong tron sau khi phong to: ";
	Output();
}

void Circle::ZoomOut()
{
	cout << "Nhap ti le phan tram can thay doi: ";
	double tile;
	cin >> tile;

	r = r - r * tile;
	cout << "Duong tron sau khi thu nho: ";
	Output();
}

void Circle::Intersect(Circle a, Circle b)
{
	double distance = sqrt(pow(b.x - x, 2) + pow(b.y - y, 2));
	if (distance < r + b.r)
		cout << "2 duong tron giao nhau";
	else
		cout << "2 duong tron khong giao nhau";
}

int main()
{
	Circle a, b;

	cout << "----------Menu----------\n";
	cout << "1. Nhap duong tron.\n";
	cout << "2. Xuat thong tin duong tron.\n";
	cout << "3. Tinh chu vi duong tron.\n";
	cout << "4. Tinh dien tich duong tron.\n";
	cout << "5. Phong to duong tron theo phan tram.\n";
	cout << "6. Thu nho duong tron theo phan tram.\n";
	cout << "7. Kiem tra 2 duong tron co giao nhau hay khong.\n";

	cout << "Nhap lua chon: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		cout << "Nhap duong tron:\n";
		a.Input();
		break;
	case 2:
		cout << "Nhap duong tron:\n";
		a.Input();

		cout << "Thong tin duong tron da nhap: ";
		a.Output();
		break;
	case 3:
		cout << "Nhap duong tron:\n";
		a.Input();

		cout << "Chu vi = ";
		cout << a.ChuVi();
		break;
	case 4:
		cout << "Nhap duong tron:\n";
		a.Input();

		cout << "Dien tich = ";
		cout << a.DienTich();
		break;
	case 5:
		cout << "Nhap duong tron:\n";
		a.Input();

		cout << "Phong to duong tron: ";
		a.ZoomIn();
		break;
	case 6:
		cout << "Nhap duong tron:\n";
		a.Input();

		cout << "Thu nho duong tron: ";
		a.ZoomOut();
		break;
	case 7:
		cout << "Nhap duong tron thu nhat:\n";
		a.Input();

		cout << "Nhap duong trong thu hai:\n";
		b.Input();

		a.Intersect(a, b);
		break;
	}
	return 0;
}