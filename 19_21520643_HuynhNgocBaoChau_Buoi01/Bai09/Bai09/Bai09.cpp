#include <iostream>
#include <string>
#define MAX 200
using namespace std;

struct SinhVien
{
	int mssv;
	string hoten;
	float diemtrungbinh;
};

typedef struct SinhVien SV;

void Input(SV &sv)
{
	cout << "Nhap ma so sinh vien: ";
	cin >> sv.mssv;
	cin.ignore();
	cout << "Nhap ho ten sinh vien: ";
	getline(cin, sv.hoten);
	cout << "Nhap diem trung binh: ";
	cin >> sv.diemtrungbinh;
}

void InputRandom(SV a[])
{
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		a[i].mssv = 0 - rand();
		a[i].hoten= 0 - rand();
		a[i].diemtrungbinh = 0 - rand();
		cout << "MSSV: " << a[i].mssv << endl;
		cout << "Ho va ten: " << a[i].hoten << endl;
		cout << "Diem trung binh: " << a[i].diemtrungbinh << endl;
		cout << endl;
	}
}

void Output(SV sv)
{
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Ho va ten: " << sv.hoten << endl;
	cout << "Diem trung binh: " << sv.diemtrungbinh << endl;
}

float FindMax(SV a[], int n)
{
	float max = a[0].diemtrungbinh;
	for (int i = 0; i < n; i++)
		if (a[i].diemtrungbinh > max) max = a[i].diemtrungbinh;
	return max;
}

void OutputMax(SV a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i].diemtrungbinh == FindMax(a, n))
		{
			Output(a[i]);
		}
}

void XepLoaiHocLuc(SV sv)
{
	if (sv.diemtrungbinh < 3.5) cout << "Sinh vien co mssv " << sv.mssv << " xep loai : Kem" << endl;
	else if (sv.diemtrungbinh >= 3.5 && sv.diemtrungbinh < 5.0) cout << "Sinh vien co mssv " << sv.mssv << " xep loai : Yeu" << endl;
	else if (sv.diemtrungbinh >= 5.0 && sv.diemtrungbinh < 7.0) cout << "Sinh vien co mssv " << sv.mssv << " xep loai : Trung binh" << endl;
	else if (sv.diemtrungbinh >= 7.0 && sv.diemtrungbinh < 8.0) cout << "Sinh vien co mssv " << sv.mssv << " xep loai : Kha" << endl;
	else if (sv.diemtrungbinh >= 8.0 && sv.diemtrungbinh < 9.0) cout << "Sinh vien co mssv " << sv.mssv << " xep loai : Gioi" << endl;
	else if (sv.diemtrungbinh >= 9.0 && sv.diemtrungbinh <= 10) cout << "Sinh vien co mssv " << sv.mssv << " xep loai : Xuat sac" << endl;
}

void FindID(SV a[], int n)
{
	int choice;
	cout << "Nhap ma so sinh vien can tim: ";
	cin >> choice;

	for (int i = 0; i < n; i++)
		if (a[i].mssv == choice) Output(a[i]);
}

void FindAvg(SV a[], int n)
{
	float choice;
	cout << "Nhap diem trung binh can tim: ";
	cin >> choice;

	for (int i = 0; i < n; i++)
		if (a[i].diemtrungbinh == choice) Output(a[i]);
}

void Find10Max(SV a[], int n)
{
	//Sap xep diem trung binh theo thu tu tang dan
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].diemtrungbinh > a[j].diemtrungbinh)
			{
				SV k = a[i];
				a[i] = a[j];
				a[j] = k;
			}

	//Xuat ra 10 sinh vien co diem trung binh cao nhat
	for (int i = 0; i < 9; i++)
	{
		Output(a[i]);
	}
}

void Find10Min(SV a[], int n)
{
	//Sap xep diem trung binh theo thu tu giam dan
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].diemtrungbinh < a[j].diemtrungbinh)
			{
				SV k = a[i];
				a[i] = a[j];
				a[j] = k;
			}

	//Xuat ra 10 sinh vien co diem trung binh thap nhat
	for (int i = 0; i < 9; i++)
	{
		Output(a[i]);
	}
}

int main()
{
	SV a[MAX];
	int n;

	cout << "----------Menu---------\n";
	cout << "1. Nhap thu cong n sinh vien.\n";
	cout << "2. Khoi tao ngau nhien cac sinh vien.\n";
	cout << "3. Xuat thong tin sinh vien ra man hinh\n";
	cout << "4. Xuat thong tin sinh vien co diem trung binh cao nhat\n";
	cout << "5. Xep loai hoc luc sinh vien.\n";
	cout << "6. Tim sinh vien theo ma so.\n";
	cout << "7. Tim cac sinh vien co diem trung binh cho truoc.\n";
	cout << "8. Tra ve 10 sinh vien co diem trung binh cao nhat.\n";
	cout << "9. Tra ve 10 sinh vien co diem trung binh thap nhat\n";
	cout << "Nhap lua chon: ";
	int option;
	cin >> option;

	switch (option)
	{
		case 1:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				Input(a[i]);
			break;
		}
		case 2:
		{
			InputRandom(a);
			break;
		}
		case 3:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				Input(a[i]);
				cout << endl;
				Output(a[i]);
			}
			break;
		}
		case 4:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				Input(a[i]);

			cout << endl;

			OutputMax(a, n);
			break;
		}
		case 5:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				Input(a[i]);

			cout << endl;

			for (int i = 0; i < n; i++)
				XepLoaiHocLuc(a[i]);
			break;
		}
		case 6:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				Input(a[i]);

			cout << endl;

			FindID(a, n);

			break;
		}
		case 7:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				Input(a[i]);

			cout << endl;

			FindAvg(a, n);
			break;
		}
		case 8:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				Input(a[i]);

			cout << endl;

			Find10Max(a, n);
			break;
		}
		case 9:
		{
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				Input(a[i]);

			cout << endl;

			Find10Min(a, n);
			break;
		}
	}
	return 0;
}

