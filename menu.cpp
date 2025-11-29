#include "menu.h"

void list_menu()
{
	cout << "====MENU CAY GIA PHA===\n";
	cout << "1. Them\n";
	cout << "2. Xoa\n";
	cout << "3. Tim kiem\n";
	cout << "4. Cap nhat\n";
	cout << "0. Thoat chuong trinh\n";
}

void list_them()
{
	cout << "\n===THEM FUCNTIONS===\n";
	cout << "1. Them vao dau danh sach\n";
	cout << "2. Them vao cuoi danh sach\n";
	cout << "3. Them vao vi tri bat ky\n";
}

void list_xoa()
{
	cout << "\n===XOA FUCNTIONS===\n";
	cout << "1. Xoa dau danh sach\n";
	cout << "2. Xoa truoc 1 nguoi\n";
	cout << "3. xoa vi tri bat ky\n";
}

void list_timkiem()
{
	cout << "\n===TIM KIEM FUCNTIONS===\n";
	cout << "1. In toan bo gia pha\n";
	cout << "2. Tim kiem thong tin mot nguoi\n";
}

void menu()
{
	GiaPha Giapha;
	createGiaPha(Giapha);

	Node* node;
	Node* node_find;
	bool flag = true;
	Person person;
	Person find_person;
	while (flag)
	{
		int n;
		int n2;
		list_menu();
		cout << "Lua chon thu: "; cin >> n;
		switch (n){

		case 1: // Da xong
			list_them();
			cout << "Lua chon thu: "; cin >> n2;
			person = createPerson();
			node = createNode(person);
			if (n2 == 1)
				//Them vao vi tri dau tien
				add_first_person(Giapha, node);
			else if (n2 == 2) 
				//Them vao vi tri cuoi cung
				add_last_person(Giapha, node);
			else if (n2 == 3)
			{
				cout << "Nhap ho ten nguoi dang sau: ";
				cin.ignore(10000, '\n');
				getline(cin, find_person.HoTen);
				node_find = Search_Hoten(Giapha, find_person);
				add_after_q(Giapha, node, node_find);
			}
			else
				cout << "Vui long nhap lai\n";
			break;


		case 2:
			list_xoa();
			cout << "Lua chon thu: "; cin >> n2;
			if (n2 == 1)
				if (remove_first(Giapha)) cout << "Xoa Thanh cong\n";
				else
					cout << "Xoa that bai\n";
			else if (n2 == 2)
			{
				cout << "Nhap ho ten nguoi muon xoa: ";
				cin.ignore(10000, '\n');
				getline(cin, find_person.HoTen);
				node_find = Search_Hoten(Giapha, find_person);
				add_after_q(Giapha, node, node_find);
				if (remove_first(Giapha)) cout << "Xoa Thanh cong\n";
				else
					cout << "Xoa that bai\n";
			}
			else
				cout << "Vui long nhap lai\n";
			break;


		case 3://Da xong
			list_timkiem();
			cout << "Lua chon thu: "; cin >> n2;
			if (n2 == 1)
				xuatGiaPha(Giapha);
			else if (n2 == 2)
			{
				cout << "Nhap ho ten nguoi can tim: ";
				cin.ignore(10000, '\n');
				getline(cin, find_person.HoTen);
				node_find = Search_Hoten(Giapha, find_person);
				xuatPerson(node_find->data);
			}
			else
				cout << "Vui long nhap lai\n";
			break;


		case 4:
			//Gom cac buoc sau: Tim kiem -> Xoa -> Them
			break;
		case 0:
			flag = false;
			cout << "\n===KET THUC CHUONG TRINH===\n";
			break;
		default:
			cout << "Vui long nhap lai\n";
		}
	}
}
