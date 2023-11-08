//Cho cấu trúc hỗ trợ quản lý thông tin khách hàng thân thiết của một siêu thị gồm : Mã khách hàng
//(MaKH); Họ, Tên khách hàng(HoTen); Ngày sinh(NgaySinh) có dạng ddmmyy; Năm(Nam) quản
//lý; Điểm(Diem) tích lũy đang có và tổng Doanh số(DoanhSo) mua hàng; Xếp hạng(Hang)
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>
#define MAX 100
using namespace std;
typedef struct Date
{
	int ngay;
	int thang;
	int nam;
}date;
typedef struct Khachhangthanthiet
{
	int makh;
	char hoten[150];
	date ngaysinh;
	double namql;
	int diem;
	double doanhso;
	int hang;
}khtt;
struct node
{
	khtt info;
	node* next;
};
struct list
{
	node* pHead;
	node* pTail;
};
void init(list& l)
{
	l.pHead = l.pTail = NULL;
}
void Nhap(khtt& khtt)
{
	rewind(stdin);
	cout << "\nNhap ma khach hang: "; cin >> khtt.makh;
	rewind(stdin);
	cout << "\nNhap ten khach hang: "; gets_s(khtt.hoten);
	rewind(stdin);
	cout << "\nNhap ngay sinh: "; cin >> khtt.ngaysinh.ngay;
	rewind(stdin);
	cout << "\nNhap thang sinh: "; cin >> khtt.ngaysinh.thang;
	rewind(stdin);
	cout << "\nNhap nam sinh: "; cin >> khtt.ngaysinh.nam;
	rewind(stdin);
	cout << "\nNhap nam quan li: "; cin >> khtt.namql;
	rewind(stdin);
	cout << "\nNhap diem: "; cin >> khtt.diem;
	rewind(stdin);
	cout << "\nNhap doanh so: "; cin >> khtt.doanhso;
}
node* makenode(khtt x)
{
	node* p = new node;
	if (p == NULL) return NULL;
	p->info.makh = x.makh;
	strcpy_s(p->info.hoten, x.hoten);
	p->info.ngaysinh.ngay = x.ngaysinh.ngay;
	p->info.ngaysinh.thang = x.ngaysinh.thang;
	p->info.ngaysinh.nam = x.ngaysinh.nam;
	p->info.namql = x.namql;
	p->info.diem = x.diem;
	p->info.doanhso = x.doanhso;
	p->next = NULL;
	return p;
}
void AddLast(list& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->next = p;
		l.pTail = p;
	}
};
void inputlist(list& l)
{
	int n;
	khtt x;
	cout << "\nNhap so luong khach hang: ";
	cin >> n;
	node* p;
	for (int i = 1; i <= n; i++)
	{
		cout << "\nNhap thong tin khach hang " << i;
		Nhap(x);
		p = makenode(x);
		AddLast(l, p);
	}
}
void Xuat(khtt khtt)
{
	cout << "\n  Ma khach hang: " << khtt.makh;
	cout << "\n  Ho ten: " << khtt.hoten;
	cout << "\n  Ngay sinh: " << khtt.ngaysinh.ngay << "/" << khtt.ngaysinh.thang << "/" << khtt.ngaysinh.nam;
	cout << "\n  Nam quan li: " << khtt.namql;
	cout << "\n  Diem:" << khtt.diem;
	cout << "\n  Doanh so: " << khtt.doanhso;
	if (khtt.doanhso >= 300)
		cout << "\n  Hang: Vang";
	else if (khtt.doanhso >= 100 && khtt.doanhso < 300)
		cout << "\n  Hang: Bac";
	else
		cout << "\n  Hang: Dong";

}
void outlist(list l)
{
	node* p;
	p = l.pHead;
	cout << "\nDanh sach khach hang" << endl;
	while (p != NULL)
	{
		Xuat(p->info);
		p = p->next;
	}
}
void interchange(list& l)
{
	for (node* p = l.pHead; p != l.pTail; p = p->next)
		for (node* q = p->next; q != NULL; q = q->next)
			if (p->info.makh > q->info.makh)
				swap(p->info, q->info);
}
void tim(list l)
{
	int x;
	node* p = l.pHead;
	cout << "\nNhap ma so can tim: ";
	cin >> x;
	while (p != NULL && p->info.makh != x)
		p = p->next;
	if (p == NULL) cout << "\nKhong tim thay san pham" << endl;
	else
	{
		cout << "\n Da tim duoc thong tin:" << endl;
		Xuat(p->info);
	}
}
void capnhat(list& l)
{
	node* p = l.pHead;
	if (p->info.makh == 100)
	{
		p->info.doanhso = p->info.doanhso + 50;
		p->info.diem = p->info.diem + 5;
	}
	else
		cout << "\nKhong co ma khach hang can cap nhat";
}
void AutoInput(list& l)
{
	khtt a[5];
	a[0] = { 100," Nguyen Van An", 13,05,85, 2018, 17, 124.8 };
	a[1] = { 101," Le Thi Binh", 23,07,90, 2019, 23, 238.6 };
	a[2] = { 102," Dinh La Ly",13,05,80, 2018, 55, 512.7 };
	a[3] = { 103," Tran Van An", 24,02,83, 2019, 3, 0 };
	a[4] = { 104," Le La", 12,9,91, 2019, 8, 87.2 };
	for (int i = 0; i < 5; i++)
	{
		node* q = makenode(a[i]);
		AddLast(l, q);
	}
	outlist(l);
}
int main()
{
	int key;
	khtt makh;
	khtt a[MAX];
	char MSMA[20];
	node* p = NULL;
	list l;
	init(l);
	while (true)
	{
		cout << "_______________________________-MENU_______________________________  \n";
		cout << "  1. Nhap thong tin khach hang.                                        \n";
		cout << "  2. Hien thi danh sach khach hang.                                    \n";
		cout << "  3. Sap xep InterchangeSort                                           \n";
		cout << "  4. Tim kiem thong tin khach hang.                                    \n";
		cout << "  5. Them 50 trieu vao doanh so cua khach hang co ma 100, tang diem +5 \n";
		cout << "  6. AutoInput                                                         \n";
		cout << "  0. Thoat                                                             \n";
		cout << "_______________________________________________________________________\n";
		cout << "Nhap tuy chon: ";
		cin >> key;
		switch (key)
		{

		case 1:
			cout << "\n1. Nhap thong tin khach hang";
			cout << endl;
			inputlist(l);
			cout << endl;
			break;
		case 2:
			cout << "\n2. Hien thi danh sach khach hang";
			cout << endl;
			outlist(l);
			cout << endl;
			break;
		case 3:
			cout << "\n3. Sap xep Interchange";
			cout << endl;
			interchange(l);
			outlist(l);
			cout << endl;
			break;
		case 4:
			cout << "\n4. Tim kiem thong tin khach hang ";
			cout << endl;
			tim(l);
			cout << endl;
			break;
		case 5:
			cout << "\n5. Cap nhat";
			cout << endl;
			capnhat(l);
			cout << endl;
			break;
		case 6:
			cout << "\n6.AutoInput";
			cout << endl;
			AutoInput(l);
			cout << endl;
			break;
		case 0:
			cout << "\nBan da chon thoat chuong trinh!\n";
			break;
		default:
			cout << "\nKhong co chuc nang nay!";
			cout << "\nHay chon chuc nang trong hop menu.";
			break;
		}

	}
}