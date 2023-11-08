#include <iostream>
using namespace std;

class Time
{
	int hour, minute, second;
public:
	Time(){}
	Time(int, int, int);
	void Input();
	void Output();
	Time Add(int);
	Time Cong2TG(Time);
	Time NextSecond();
	//Time HourToDay();
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::Input()
{
	cout << "Nhap gio: ";
	cin >> hour;
	cout << "Nhap phut: ";
	cin >> minute;
	cout << "Nhap giay: ";
	cin >> second;
}

void Time::Output()
{
	cout << hour << ":" << minute << ":" << second;
}

Time Time::Add(int n)
{
	if (hour == 23 && minute == 59 && second == 59)
	{
		hour = 0;
		minute = 0;
		second = second + n;
	}
	else if (minute == 59 && second == 59)
	{
		hour++;
		minute = 0;
		second = second + n;
	}
	else if (second == 59)
	{
		minute++;
		second = second + n;
	}
	second += n;
	return Time(hour, minute, second);
}

Time Time::Cong2TG(Time t)
{
	int gio, phut, giay;
	gio = hour + t.hour;
	phut = minute + t.minute;
	giay = second + t.second;
	if (giay >= 60)
	{
		giay %= 60;
		phut++;
	}
	if (phut >= 60)
	{
		phut %= 60;
		gio++;
	}
	if (gio >= 24)
	{
		if (gio == 24)
			gio = 0;
		else
		{
			gio %= 24;
			gio--;
		}
	}
	return Time(gio, phut, giay);
}

Time Time::NextSecond()
{
	if (hour == 23 && minute == 59 && second == 59) {
		hour = 0;
		minute = 0;
		second = 0;
	}
	if (minute == 59 && second == 59) {
		hour++;
		minute = 0;
		second = 0;
	}
	if (second == 59) {
		minute++;
		second = 0;
	}
	second++;
	return Time(hour, minute, second);
}

int main()
{
	Time t, t1, t2;
	int option, n;
	do
	{
		cout << "----------Menu----------\n";
		cout << "1. Nhap thoi gian.\n";
		cout << "2. Xuat thoi gian.\n";
		cout << "3. Cong mot so nguyen giay vao thoi gian.\n";
		cout << "4. Cong hai thoi gian.\n";
		cout << "5. ++ giay.\n";
		cout << "0. Thoat chuong trinh.\n";

		do
		{
			cout << "Nhap lua chon: ";
			cin >> option;
		} while (option < 0 || option > 5);
		switch (option)
		{
		case 1:
			cout << "Nhap thoi gian: \n";
			t.Input();
			break;
		case 2:
			cout << "Nhap thoi gian: \n";
			t.Input();
			cout << "Thoi gian da nhap: ";
			t.Output();
			break;
		case 3:
			cout << "Nhap thoi gian: \n";
			t.Input();
			cout << "Nhap mot so nguyen: ";
			cin >> n;
			cout << "Ket qua: ";
			t.Add(n).Output();
			break;
		case 4:
			cout << "Nhap thoi gian thu nhat: \n";
			t1.Input();
			cout << "Nhap thoi gian thu hai:\n";
			t2.Input();
			cout << "Ket qua cong 2 thoi gian: ";
			t1.Cong2TG(t2).Output();
			break;
		case 5:
			cout << "Nhap thoi gian: \n";
			t.Input();
			cout << "Ket qua sau khi tang 1 don vi: ";
			t.NextSecond().Output();
			break;
		case 0:
			cout << "Ban da chon thoat chuong trinh\nTam biet :)";
			break;
		}
		cout << "\n\n\n";
	} while (option != 0);
}