// #include "Nhansu.h"
// #include "NhanVien.h"
// #include "QuanLy.h"
// #include <fstream>
// #include <string>
// #include<iostream>
// #include <sstream>
// #include <iomanip>
#include "Employee.h"
#include <limits>
using namespace std;
void employeeMenu(NhanVien* employee, LinkedList list) {
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
void managerMenu(QuanLy* manager, LinkedList list) {
    int choice;
    do {
        cout << "\n----- Menu Quản Lý -----\n";
        cout << "1. Xem thông tin cá nhân\n";
        cout << "2. Xem thông tin nhân viên trong phòng ban\n";
        cout << "3. Tạo cuộc họp\n";
        cout << "4. Xét duyệt nghỉ phép\n";
        cout << "5. Đánh giá nhân viên\n";
        cout << "6. Tính lương\n"; 
        cout << "7. Tính thực lĩnh\n"; 
        cout << "8. Xét duyệt tăng lương\n";
        cout << "9. Xóa nhân viên\n";
        cout << "10.Thêm nhân viên\n";
        cout << "0. Đăng xuất\n";
        cout << "Lựa chọn: ";
        cin >> choice;
        switch (choice) {
            case 1:
                manager->layThongTinCaNhan();
                break;
            case 2:
                manager->xemThongTinNhanVien(list);
                break;
            case 3:
                manager->taoCuocHop();
                break;
            case 4:
                manager->xetDuyetNghiPhep();
                break;
            case 5:
                manager->danhGiaNhanVien();
                break;
            case 6:
                cout << fixed << setprecision(2);
                cout << "Luong cua ban la: " << manager->tinhLuong() << " VND\n";
                break;
            case 7:
                cout << fixed << setprecision(2);
                cout << "Thuc linh cua ban la: " << manager->tinhThucLinh() << " VND\n";
                break;
            case 8:
                manager->xetDuyetTangLuong(); 
                break;
            case 9:{
                string mnv;
                cout << "Nhập mã nhân viên bạn muốn xóa: ";
                cin >> mnv;
                list.deleteNode(mnv, manager);
            }
                break;
            case 10:
                list.addEmployee();
                break;
            case 11:
                list.displayAll();
                break;
            case 0:
                cout << "Đăng xuất thành công!\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ!\n";
        }
    } while (choice != 0);
}
int main() {
    LinkedList list;
    list.loadFromFile("employee_info.txt");
    list.displayAll();
    int stop = 1;
    string username, password;
    while (stop) {
        cout << "Press Q to quit" << endl;
        cout << "Tên đăng nhập: ";
        cin >> username;
        if(username == "Q" || username == "q") break; 
        cout << "Mật khẩu: ";
        cin >> password;

        NhanSu* user = list.login(username, password);
        if(user){
            cout << "Đăng nhập thành công!" << endl;
            cout << "Chào mừng " << user->getMaNV() << ", bạn là " << user->getRole() << "." << endl;
            if (NhanVien* employee = dynamic_cast<NhanVien*>(user))
                employeeMenu(employee, list);
            else if (QuanLy* manager = dynamic_cast<QuanLy*>(user))
                managerMenu(manager, list);
            delete user;
        }
        else
            cout << "Tên đăng nhập hoặc mật khẩu không đúng!" << endl; 
    }
    return 0;
}
