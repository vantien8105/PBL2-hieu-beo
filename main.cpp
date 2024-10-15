#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanSu {
protected:
    string username;
    string password;
    string role;  // "NhanVien" hoặc "QuanLi"

public:
    NhanSu(string user, string pass, string r) : username(user), password(pass), role(r) {}

    string getUsername() { return username; }
    string getPassword() { return password; }
    string getRole() { return role; }

    virtual void xemLichHop() = 0;
    virtual void guiBaoCaoTienDo() {}
    virtual void xinNghiPhep() {}
    virtual void deNghiTangLuong() {}
    virtual void taoCuocHop() {}
    virtual void danhGiaTienDo() {}
    virtual void themNhanVienMoi() {}
    virtual void pheDuyetTangLuong() {}
};

// Class NhanVien kế thừa từ NhanSu
class NhanVien : public NhanSu {
public:
    NhanVien(string user, string pass) : NhanSu(user, pass, "NhanVien") {}

    void xemLichHop() override {
        cout << username << ": Xem lịch họp" << endl;
    }

    void guiBaoCaoTienDo() override {
        cout << username << ": Gửi báo cáo tiến độ" << endl;
    }

    void xinNghiPhep() override {
        cout << username << ": Gửi đề xuất xin nghỉ phép" << endl;
    }

    void deNghiTangLuong() override {
        cout << username << ": Gửi đề xuất tăng lương" << endl;
    }
};

// Class QuanLi kế thừa từ NhanSu
class QuanLi : public NhanSu {
private:
    vector<NhanVien*> danhSachNhanVien;

public:
    QuanLi(string user, string pass) : NhanSu(user, pass, "QuanLi") {}

    void xemLichHop() override {
        cout << username << ": Xem lịch họp quản lý" << endl;
    }

    void taoCuocHop() override {
        cout << username << ": Tạo cuộc họp cho nhân viên" << endl;
        for (NhanVien* nv : danhSachNhanVien) {
            cout << "Gửi thông báo cuộc họp cho " << nv->getUsername() << endl;
        }
    }

    void danhGiaTienDo() override {
        cout << username << ": Đánh giá tiến độ nhân viên" << endl;
    }

    void themNhanVienMoi(NhanVien* nv) {
        danhSachNhanVien.push_back(nv);
        cout << username << ": Thêm nhân viên mới: " << nv->getUsername() << endl;
    }

    void pheDuyetTangLuong() override {
        cout << username << ": Xem xét phê duyệt yêu cầu tăng lương" << endl;
    }
};

// Chức năng đăng nhập
NhanSu* login(vector<NhanSu*> &users, string username, string password) {
    for (NhanSu* user : users) {
        if (user->getUsername() == username && user->getPassword() == password) {
            return user;
        }
    }
    return nullptr;
}

int main() {
    // Tạo danh sách tài khoản
    vector<NhanSu*> users;
    QuanLi* ql1 = new QuanLi("admin", "admin123");
    users.push_back(ql1);
    NhanVien* nv1 = new NhanVien("nv1", "nv123");
    users.push_back(nv1);
    NhanVien* nv2 = new NhanVien("nv2", "nv123");
    users.push_back(nv2);

    ql1->themNhanVienMoi(nv1);  // Gán nhân viên cho quản lý
    ql1->themNhanVienMoi(nv2);  // Gán nhân viên cho quản lý

    string username, password;
    cout << "Dang nhap he thong:\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    // Kiểm tra đăng nhập
    NhanSu* currentUser = login(users, username, password);
    if (currentUser == nullptr) {
        cout << "Dang nhap that bai!" << endl;
        return 0;
    }

    cout << "Xin chao " << currentUser->getUsername() << " (" << currentUser->getRole() << ")" << endl;

    // Giao diện chức năng
    int choice;
    do {
        cout << "\nChon chuc nang:\n";
        if (currentUser->getRole() == "NhanVien") {
            cout << "1. Xem lich hop\n2. Gui bao cao tien do\n3. Xin nghi phep\n4. De nghi tang luong\n5. Thoat\n";
            cin >> choice;

            switch (choice) {
                case 1:
                    currentUser->xemLichHop();
                    break;
                case 2:
                    currentUser->guiBaoCaoTienDo();
                    break;
                case 3:
                    currentUser->xinNghiPhep();
                    break;
                case 4:
                    currentUser->deNghiTangLuong();
                    break;
                case 5:
                    cout << "Dang xuat..." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le." << endl;
                    break;
            }
        } else if (currentUser->getRole() == "QuanLi") {
            cout << "1. Xem lich hop\n2. Tao cuoc hop\n3. Danh gia tien do\n4. Them nhan vien moi\n5. Phe duyet tang luong\n6. Thoat\n";
            cin >> choice;

            switch (choice) {
                case 1:
                    currentUser->xemLichHop();
                    break;
                case 2:
                    currentUser->taoCuocHop();
                    break;
                case 3:
                    currentUser->danhGiaTienDo();
                    break;
                case 4: {
                    string newUser, newPass;
                    cout << "Nhap ten nhan vien moi: ";
                    cin >> newUser;
                    cout << "Nhap mat khau: ";
                    cin >> newPass;
                    NhanVien* newNv = new NhanVien(newUser, newPass);
                    ql1->themNhanVienMoi(newNv);
                    users.push_back(newNv);
                    break;
                }
                case 5:
                    currentUser->pheDuyetTangLuong();
                    break;
                case 6:
                    cout << "Dang xuat..." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le." << endl;
                    break;
            }
        }
    } while (choice != 5 && choice != 6);

    return 0;
}
