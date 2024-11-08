#ifndef Employee_H
#define Employee_H
#include "NhanVien.h"
#include "QuanLy.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class QuanLy;
struct Node {
    NhanSu* data;
    Node* next;
    Node(NhanSu* ns) : data(ns), next(nullptr) {}
};

class LinkedList {
protected:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    Node* getHead() const {
    return head;
    }
    void add(NhanSu* ns) { //upload file
        Node* newNode = new Node(ns);
        newNode->next = head;
        head = newNode;
        NhanVien *em = dynamic_cast<NhanVien*>(ns);
        if(em){
            string maPhongBan = em->getBoPhanLamViec();
            Node* tmp = head;
            while(tmp){
                QuanLy* ql = dynamic_cast<QuanLy*>(tmp->data);
                if (ql && ql->getBoPhanLamViec() == maPhongBan) {
                    ql->update_nv(1);  
                    cout << "Số nhân viên quản lý hiện tại của " << ql->getMaNV() << ": " << ql->getSNV() << endl;
                    break;
                }
                tmp = tmp->next;
            }
        }
    }
    void addEmployee() {
        NhanVien* nhanVienMoi = new NhanVien();
        cin.ignore();
        cin >> *nhanVienMoi;
        add(nhanVienMoi);
        ofstream outfile("employee_info.txt", ios::app);
        if (outfile.is_open()) {
            outfile << nhanVienMoi->toString() << "\n";
            outfile.close();
            cout << "Đã thêm nhân viên vào file " << "employee_info.txt" << " thành công.\n";
        } else {
            cout << "Không thể mở file.\n";
        }
    }
    void deleteNode(const string& maNhanVien, QuanLy *manager) {
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        NhanVien* nv = dynamic_cast<NhanVien*>(current->data);
        if (nv && nv->getMaNV() == maNhanVien) {
            string maPhongBan = nv->getBoPhanLamViec();
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            if (manager->getBoPhanLamViec() == maPhongBan) {
                manager->update_nv(0);
                cout << "Đã xóa nhân viên với mã " << maNhanVien << endl;
                return;
            }
            else{
                cout << "Phòng ban " << manager->getBoPhanLamViec() << " không có nhân viên với mã " << maNhanVien << endl;
                return;
            }
        }
        prev = current;
        current = current->next;
    }
    cout << "Không tìm thấy nhân viên với mã " << maNhanVien << endl;
}
    NhanSu* login(const string& username, const string& password) const {
        ifstream infile("accounts.txt");
        string u, p, r;
        if (infile.is_open()) {
        while (infile >> u >> p >> r) {
            if (u == username && p == password) {
                Node* current = head; 
                while (current) {
                    NhanSu* user = current->data;
                    if (user->getMaNV() == username) {  
                        return user;
                    }
                    current = current->next;
                }
            }
        }
        infile.close();
    }
        return nullptr;     
    }
    void loadFromFile(const string& filename) {
        ifstream infile(filename);
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string ma, ten, gt, ns, sdt, dc, cm, cviec, hd;
            double hs;
            string extra1;
            ss >> ma >> ten >> gt >> ns >> sdt >> dc >> cm >> cviec >> hd >> hs;

            if (ma.find("employee") != string::npos) {
                ss >> extra1;
                NhanSu* nv = new NhanVien(ma, ten, gt, ns, sdt, dc, cm, cviec, hd, hs, "Employee", extra1, "", "");
                add(nv);
            } else if (ma.find("manager") != string::npos) {
                ss >> extra1;
                NhanSu* ql = new QuanLy(ma, ten, gt, ns, sdt, dc, cm, cviec, hd, hs, "Manager", extra1, 0, "", "");
                add(ql);
            }
        }
        infile.close();
    }

    void displayAll() const {
        Node* temp = head;
        cout << "================= DANH SÁCH NHÂN SỰ =================" << endl;
        while (temp) {
        cout << "----------------------------------------------------" << endl;
        string role = temp->data->getRole();
        if (role == "Manager") {
            QuanLy* ql = dynamic_cast<QuanLy*>(temp->data);
            if (ql) {
                ql->layThongTinCaNhan();
            } else {
                cout << "Lỗi: Không thể chuyển đối tượng sang QuanLy" << endl;
            }
        }
        else if(role == "Employee") {
            NhanVien* nv = dynamic_cast<NhanVien*>(temp->data);
            if (nv) {
                nv->layThongTinCaNhan();
            } else {
                cout << "Lỗi: Không thể chuyển đối tượng sang NhanVien" << endl;
            }
        }
        cout << "----------------------------------------------------" << endl;
        temp = temp->next;
    }
        cout << "=================== KẾT THÚC DANH SÁCH ===================" << endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
    }
};
void QuanLy::xemThongTinNhanVien(const LinkedList& list) const {
    cout << "Danh sách nhân viên trong phòng ban " << boPhanQuanLy << " do bạn quản lý:" << endl;
    Node* current = list.getHead(); 
    cout << "================= DANH SÁCH PHÒNG BAN =================" << endl;
    while (current) {
        NhanVien* nv = dynamic_cast<NhanVien*>(current->data);
        if (nv && nv->getBoPhanLamViec() == boPhanQuanLy) {
            cout << "----------------------------------------------------" << endl;
            nv->layThongTinCaNhan();
            cout << "----------------------------------------------------" << endl;
        }
        current = current->next;
    }
        cout << "=================== KẾT THÚC DANH SÁCH ===================" << endl;
}
#endif