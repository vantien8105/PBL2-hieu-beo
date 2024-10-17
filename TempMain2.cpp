#include "Nhansu.h"
#include "NhanVien.h"
#include "QuanLy.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

NhanSu* checkLogin(string username, string password) {
    ifstream infile("accounts.txt");
    string u, p, r;
    if (infile.is_open()) {
        while (infile >> u >> p >> r) {
            if (u == username && p == password) {
                if (r == "Employee") {
                    NhanVien* NV = new NhanVien();  // Cấp phát bộ nhớ động
                    NV->loadEmployeeInfo(username);
                    return NV;  // Trả về con trỏ đến đối tượng động
                } else if (r == "Manager") {
                    QuanLy* QL = new QuanLy();  // Cấp phát bộ nhớ động
                    QL->loadEmployeeInfo(username);
                    return QL;  // Trả về con trỏ đến đối tượng động
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
        if (NhanVien* employee = static_cast<NhanVien*>(user)) {
            employee->printInfo();
        }
        // Nếu là quản lý, có thể thêm logic hiển thị cho quản lý ở đây
    } else {
        cout << "Tên đăng nhập hoặc mật khẩu không đúng!" << endl;
    }

    delete user;  // Giải phóng bộ nhớ cho đối tượng đã được cấp phát động
    return 0;
}
