#include <iostream>
using namespace std;

typedef struct DayMonthYear
{
	int day;
	int month;
	int year;
} Date;

void Input(Date &date)
{
	cout << "Nhap ngay thang nam: ";
	cin >> date.day >> date.month >> date.year;
}

void Output(Date date)
{
	cout << date.day << "/" << date.month << "/" << date.year;
}

bool KiemTraNamNhuan(Date date)
{
	if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0)
		return 1;
	return 0;
}

int SoNgayTrongThang(Date date)
{
	switch (date.month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		return 31;
		break;
	}
	case 4: case 6: case 9: case 11:
	{
		return 30;
		break;
	}
	case 2:
	{
		if (KiemTraNamNhuan(date) == 1)
			return 29;
		return 28;
		break;
	}
	}
}

bool KiemTraHopLe(Date date)
{
	if (date.day < 0 || date.day > 31 || date.month < 0 || date.month > 12 || date.year < 0)
		return 0;
	return 1;
}

Date NgayHomSau(Date &tomorrow, Date date)
{
	if (date.month != 12 && date.day == SoNgayTrongThang(date))
	{
		tomorrow.day = 1;
		tomorrow.month = date.month + 1;
		tomorrow.year = date.year;
	}

	else if (date.month == 12 && date.day == SoNgayTrongThang(date))
	{
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = date.year + 1;
	}

	else if (date.month == 2)
	{
		if (KiemTraNamNhuan(date) == 1)
		{
			tomorrow.day = 1;
			tomorrow.month = date.month + 1;
			tomorrow.year = date.year;
		}
		if (KiemTraNamNhuan(date) == 0)
		{
			tomorrow.day = 1;
			tomorrow.month = date.month + 1;
			tomorrow.year = date.year;
		}
	}

	else
	{
		tomorrow.day = date.day + 1;
		tomorrow.month = date.month;
		tomorrow.year = date.year;
	}
	return tomorrow;
}

int main()
{
	Date date, tomorrow;
	Input(date);

	if (KiemTraHopLe(date) == 1)
	{
		cout << "Ngay tiep theo la: ";
		NgayHomSau(tomorrow, date);
		Output(tomorrow);
	}

	else cout << "Ngay thang nam da nhap khong hop le.";

	return 0;
}