#include "Nhansu.h"
#include "NhanVien.h"
#include "QuanLy.h"
#include <fstream>
#include <string>
#include<iostream>
#include <sstream>
#include <iomanip>
using namespace std;

NhanSu* checkLogin(string username, string password) {
    ifstream infile("accounts.txt");
    string u, p, r;
    if (infile.is_open()) {
        while (infile >> u >> p >> r) {
            if (u == username && p == password) {
                if (r == "Employee") {
                    NhanVien* NV = new NhanVien();
                    NV->loadEmployeeInfo(username);
                    NV->setUsername(username);
                    NV->setRole("Employee");
                    return NV;  
                } else if (r == "Manager") {
                    QuanLy* QL = new QuanLy(); 
                    QL->loadEmployeeInfo(username);
                    QL->setUsername(username);
                    QL->setRole("Manager");
                    return QL;  
                }
            }
        }
        infile.close();
    }
    return nullptr;
}

void saveAccountToFile(const string& username, const string& password, const string& role) {
    ofstream outfile("accounts.txt", ios::app);
    outfile << username << " " << password << " " << role << endl;
}
void employeeMenu(NhanVien* employee) {
    int choice;
    do {
        cout << "\n----- Menu Nhân Viên -----\n";
        cout << "1. Xem thông tin cá nhân\n";
        cout << "2. Báo cáo tiến độ\n";
        cout << "3. Xin nghỉ phép\n";
        cout << "4. Tính lương\n"; 
        cout << "5. Tính thực lĩnh\n"; 
        cout << "6. Đề nghị tăng lương\n"; 
        cout << "7. Đăng xuất\n";
        cout << "Lựa chọn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                employee->layThongTinCaNhan();
                break;
            case 2:
                employee->baoCaoTienDo();
                break;
            case 3:
                employee->xinNghiPhep();
                break;
            case 4:
                cout << fixed << setprecision(2);
                cout << "Luong cua ban la: " << employee->tinhLuong() << " VND\n";
                break;
            case 5:
                cout << fixed << setprecision(2);
                cout << "Thuc linh cua ban la: " << employee->tinhThucLinh() << " VND\n";
                break;
            case 6:
                employee->deNghiTangLuong(); 
                break;
            case 7:
                cout << "Đăng xuất thành công!\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ!\n";
        }
    } while (choice != 7);
}
void managerMenu(QuanLy* manager) {
    int choice;
    do {
        cout << "\n----- Menu Quản Lý -----\n";
        cout << "1. Xem thông tin cá nhân\n";
        cout << "2. Tạo cuộc họp\n";
        cout << "3. Xét duyệt nghỉ phép\n";
        cout << "4. Đánh giá nhân viên\n";
        cout << "5. Tính lương\n"; 
        cout << "6. Tính thực lĩnh\n"; 
        cout << "7. Xét duyệt tăng lương\n";  
        cout << "8. Đăng xuất\n";
        cout << "Lựa chọn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager->layThongTinCaNhan();
                break;
            case 2:
                manager->taoCuocHop();
                break;
            case 3:
                manager->xetDuyetNghiPhep();
                break;
            case 4:
                manager->danhGiaNhanVien();
                break;
            case 5:
                cout << fixed << setprecision(2);
                cout << "Luong cua ban la: " << manager->tinhLuong() << " VND\n";
                break;
            case 6:
                cout << fixed << setprecision(2);
                cout << "Thuc linh cua ban la: " << manager->tinhThucLinh() << " VND\n";
                break;
            case 7:
                manager->xetDuyetTangLuong(); 
                break;
            case 8:
                cout << "Đăng xuất thành công!\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ!\n";
        }
    } while (choice != 8);
}
int main() {
    int stop = 1;
    string username, password;
    while (stop) {
        cout << "Press Q to quit" << endl;
        cout << "Tên đăng nhập: ";
        cin >> username;
        if (username == "Q" || username == "q") break; // Thoát nếu người dùng bấm 'Q'
        cout << "Mật khẩu: ";
        cin >> password;

        NhanSu* user = checkLogin(username, password);
        if (user) {
            cout << "Đăng nhập thành công!" << endl;
            cout << "Chào mừng " << user->getUsername() << ", bạn là " << user->getRole() << "." << endl;
            if (NhanVien* employee = dynamic_cast<NhanVien*>(user)) {
                employeeMenu(employee);
            } else if (QuanLy* manager = dynamic_cast<QuanLy*>(user)) {
                managerMenu(manager);
            }
        } else {
            cout << "Tên đăng nhập hoặc mật khẩu không đúng!" << endl;
        }

        delete user; 
    }
    return 0;
}
