#include <iostream>
#include <math.h>
using namespace std;

class ToaDo
{
private: 
	float x, y;
public:
	ToaDo();
	ToaDo(float, float);
	void Input();
	void Output();
	float GetX();
	float GetY();
	ToaDo Change(ToaDo);
	ToaDo MoveTo(ToaDo);
	ToaDo Distance(ToaDo);
	ToaDo Midpoint(ToaDo, ToaDo);
	void Delete(ToaDo);
	ToaDo Copy(ToaDo);
	~ToaDo() {};
};

ToaDo::ToaDo()
{
	x = 0;
	y = 0;
}

ToaDo::ToaDo(float hoanh, float tung)
{
	x = hoanh;
	y = tung;
}

void ToaDo::Input()
{
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}

void ToaDo::Output()
{
	cout << "(" << x << ";" << y << ")";
}

float ToaDo::GetX()
{
	cout << "Hoanh do la: ";
	return x;
}

float ToaDo::GetY()
{
	cout << "Tung do la: ";
	return y;
}

ToaDo ToaDo::Change(ToaDo a)
{
	Input();
	a.x = x;
	a.y = y;
	return a;
}

ToaDo ToaDo::MoveTo(ToaDo a)
{
	Input();
	a.x = x;
	a.y = y;
	return a;
}

ToaDo ToaDo::Distance(ToaDo b)
{
	double distance = sqrt(pow(b.x - x, 2) + pow(b.y - y, 2));
	cout << distance;
	return b;
}

ToaDo ToaDo::Midpoint(ToaDo a, ToaDo b)
{
	ToaDo i;
	i.x = (a.x + b.x) / 2;
	i.y = (a.y + b.y) / 2;
	return i;
}

void ToaDo::Delete(ToaDo a)
{
	a.~ToaDo();
}

ToaDo ToaDo::Copy(ToaDo a)
{
	
	cout << "Toa do diem b sao chep tu diem a: ";
	a.x = x;
	a.y = y;
	return a;
}

int main()
{
	ToaDo a, b, i;

	cout << "----------Menu----------\n";
	cout << "1. Nhap toa do mot diem\n";
	cout << "2. Xuat toa do mot diem\n";
	cout << "3. Lay tung do, hoanh do cua mot diem\n";
	cout << "4. Thay doi tung do, hoanh do cua mot diem\n";
	cout << "5. Di chuyen den toa do\n";
	cout << "6. Khoang cach giua hai diem\n";
	cout << "7. Tim toa do trung diem cua hai diem\n";
	cout << "8. Xoa toa do diem\n";
	cout << "9. Sao chep diem toa do\n";

	cout << "Nhap lua chon: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		cout << "Nhap toa do:\n";
		a.Input();
		break;
	case 2:
		cout << "Nhap toa do:\n";
		a.Input();

		cout << "Toa do da nhap: ";
		a.Output();
		break;
	case 3:
		cout << "Nhap toa do:\n";
		a.Input();

		cout << a.GetX();
		cout << endl;
		cout << a.GetY();
		break;
	case 4:
		cout << "Nhap toa do:\n";
		a.Input();

		cout << "Toa do ban dau: ";
		a.Output();

		cout << endl;

		cout << "Toa do sau khi thay doi: " << endl;
		b.Change(a);
		b.Output();
		break;
	case 5:
		cout << "Nhap toa do:\n";
		a.Input();

		cout << "Vi tri ban dau cua toa do: ";
		a.Output();

		cout << endl;

		cout << "Vi tri sau khi di chuyen: " << endl;
		b.MoveTo(a);
		b.Output();
		break;
	case 6:
		cout << "Nhap toa do diem thu nhat: " << endl;
		a.Input();
		cout << "Nhap toa do diem thu hai: " << endl;
		b.Input();

		cout << "Khoang cach giua hai diem vua nhap: ";
		a.Distance(b);
		break;
	case 7:
		cout << "Nhap toa do diem thu nhat: " << endl;
		a.Input();
		cout << "Nhap toa do diem thu hai: " << endl;
		b.Input();

		cout << "Toa do trung diem cua hai diem vua nhap: ";
		i.Midpoint(a, b).Output();
		break;
	case 8:
		cout << "Nhap toa do:\n";
		a.Input();

		cout << "Da xoa toa do diem!";
		a.Delete(a);
		break;
	case 9:
		a.Input();
		cout << "Toa do diem a: ";
		a.Output();

		cout << endl;

		b = a.Copy(a);
		b.Output();
		break;
	}
	return 0;
}
