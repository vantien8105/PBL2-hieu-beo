#include "Nhansu.h"
#include "NhanVien.h"
#include "QuanLy.h"
#include <fstream>
#include <string>
#include<iostream>
using namespace std;

NhanSu* checkLogin(string username, string password) {
    ifstream infile("accounts.txt");
    string u, p, r, ID;
    if (infile.is_open()) {
        while (infile >> u >> p >> r) {
            if (u == username && p == password) {

                if (r == "Employee") {
                    NhanVien NV;
                    NV.loadEmployeeInfo();

                    return &NV ;
                } else if (r == "Manager") {
                   QuanLy QL;
                   QL.loadEmployeeInfo();
                   return &QL;
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
int main() {
    saveAccountToFile("employee1", "123456", "Employee");
    saveAccountToFile("employee2", "abcdef", "Employee");
    string username, password;
    cout << "Tên đăng nhập: ";
    cin >> username;
    cout << "Mật khẩu: ";
    cin >> password;
    NhanSu* user = checkLogin(username, password);
    if (user) {
        cout << "Đăng nhập thành công!" << endl;
        cout << "Chào mừng " << user->getUsername() << ", bạn là " << user->getRole() << "." << endl;

        // Nếu là nhân viên, hiển thị thông tin nhân sự
        NhanVien* employee = static_cast<NhanVien*>(user);
        if (employee) {
            employee->printInfo();
        }
    } else {
        cout << "Tên đăng nhập hoặc mật khẩu không đúng!" << endl;
    }

    
    // DiaChi diaChi("123 Nguyen Trai", "Quan 1");
    // ChuyenMon chuyenMon("CN001", "CNTT", "DH Bach Khoa", "Ky Su");
    // HopDong hopDong("HD001", "Hop Dong Lao Dong", "1 nam");
    // NhanSu ns1("NS001", "Nguyen Van A", "Nam", "01/01/1990", "0912345678", diaChi, chuyenMon, "Lap trinh vien", hopDong, 3.5);
    // cout << "Thong tin nhan su:\n" << ns1;
    // cout << "Luong thuc linh: " << ns1.tinhThucLinh() << endl;
    // NhanSu ns2;
    // cin >> ns2;
    // cout << "Thong tin nhan su vua nhap:\n" << ns2;
    delete user;  // Giải phóng bộ nhớ
    return 0;
}
