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
	cout << "2. Xoa mot nguoi\n";
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
	Node* node_new;
	bool flag = true;
	Person person;
	Person find_person;

	std::chrono::high_resolution_clock::time_point t_start, t_end;
	std::chrono::duration<double, std::milli> time_span;
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
			{
				t_start = std::chrono::high_resolution_clock::now();
				//Them vao vi tri dau tien
				add_first_person(Giapha, node);
			}
			else if (n2 == 2) 
			{
				//Them vao vi tri cuoi cung
				t_start = std::chrono::high_resolution_clock::now();
				add_last_person(Giapha, node);
			}
			else if (n2 == 3)
			{
				cout << "Nhap ho ten nguoi dang sau: ";
				cin.ignore(10000, '\n');
				getline(cin, find_person.HoTen);

				t_start = std::chrono::high_resolution_clock::now();
				node_find = Search_Hoten(Giapha, find_person);
				if (node_find == NULL)
					cout << "Khong tim ra ten nguoi dang sau\n";
				else
					add_after_q(Giapha, node, node_find);
			}
			else
				cout << "Vui long nhap lai\n";

			t_end = std::chrono::high_resolution_clock::now();
			time_span = t_end - t_start;
			cout << ">> Thoi gian thuc hien Case 1: " << time_span.count() << " ms\n";

			break;


		case 2: 
			list_xoa();
			cout << "Lua chon thu: "; cin >> n2;
			if (n2 == 1)
			{
				t_start = std::chrono::high_resolution_clock::now();
				if (remove_first(Giapha))
					cout << "Xoa Thanh cong\n";
				else
					cout << "Xoa that bai\n";
			}
			else if (n2 == 2)
			{
				cin.ignore(10000, '\n');
				cout << "Nhap ten can xoa: ";
				getline(cin, find_person.HoTen);
				
				t_start = std::chrono::high_resolution_clock::now();
				node_find = Search_Hoten(Giapha, find_person);
				string name = node_find->data.HoTen;
				if (remove_person(Giapha, node_find))
				{
					cout << "Da xoa " << name <<"\n";
				}
				else
				{
					cout << "Xoa that bai\n";
				}
			}
			else
				cout << "Vui long nhap lai\n";

			t_end = std::chrono::high_resolution_clock::now();
			time_span = t_end - t_start;
			cout << ">> Thoi gian thuc hien Case 2: " << time_span.count() << " ms\n";

			break;

				
		case 3://Da xong
			list_timkiem();
			cout << "Lua chon thu: "; cin >> n2;
			if (n2 == 1)
			{
				t_start = std::chrono::high_resolution_clock::now();
				xuatGiaPha(Giapha);
			}
			else if (n2 == 2)
			{
				cin.ignore(10000, '\n');
				cout << "Nhap ho ten nguoi can tim: ";
				getline(cin, find_person.HoTen);
				t_start = std::chrono::high_resolution_clock::now();
				node_find = Search_Hoten(Giapha, find_person);
				xuatPerson(node_find->data);
			}
			else
				cout << "Vui long nhap lai\n";

			t_end = std::chrono::high_resolution_clock::now();
			time_span = t_end - t_start;
			cout << ">> Thoi gian thuc hien Case 3: " << time_span.count() << " ms\n";

			break;


		case 4:
			//Gom cac buoc sau: Tim kiem -> Them -> Xoa
			person = createPerson();
			t_start = std::chrono::high_resolution_clock::now();
			node_new = createNode(person);
			node_find = Search_Hoten(Giapha, node_new->data);
			add_after_q(Giapha, node_new, node_find); //Luc nay them 1 ban ghi moi dang sau ban cu
			if (remove_person(Giapha, node_find)) //Xoa ban ghi cu
			{
				cout << "Da cap nhat\n";
			}
			else
				cout << "Tim khong ra ten de cap nhat\n";

			t_end = std::chrono::high_resolution_clock::now();
			time_span = t_end - t_start;
			cout << ">> Thoi gian thuc hien Case 4: " << time_span.count() << " ms\n";

			break;

		case 0:
			t_start = std::chrono::high_resolution_clock::now();
			flag = false;
			cout << "\n===KET THUC CHUONG TRINH===\n";
			destroy_giapha(Giapha);
			t_end = std::chrono::high_resolution_clock::now();
			time_span = t_end - t_start;
			cout << ">> Thoi gian xoa gia pha: " << time_span.count() << " ms\n";
			break;
		default:
			cout << "Vui long nhap lai\n";
		}
	}
}
