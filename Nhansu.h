#ifndef NhanSu_h
#define NhanSu_h

#include <iostream>
#include <fstream>   
#include <sstream>   
#include "ChucVu.h"
#include "DiaChi.h"
#include "HopDong.h"
#include "ChuyenMon.h"
using namespace std;


class NhanSu {

protected:
    string maNhanSu;     
    string hoTen;        
    string gioiTinh;     
    string ngaySinh;    
    string soDienThoai;
    string diaChi;  
    string maChuyenMon; 
    string congViec;    
    string maHopDong;  
    string username;
    string password;
    string role;  
    double heSoLuong;
public:
    NhanSu(string ma = "", string ten = "", string gt = "", string ns = "", string sdt = "", 
        string dc = "" , string cm = "", string cviec = "", 
        string hd ="", double hs = 0.0, string role ="");
    virtual double tinhLuong();    
    virtual double tinhPhuCap();   
    virtual double tinhThucLinh();  
    virtual void layThongTinCaNhan();
    virtual void layLichLamViecVaHop();
    virtual string getMaNV() const = 0;
    virtual string getRole() const = 0;
    virtual string getBoPhanLamViec() const = 0;
    void setUsername(const string& username);
    void setRole(const string& role);
    virtual void printInfo();
    void loadEmployeeInfo(string maNS);
    friend ostream& operator<<(ostream& os, const NhanSu& ns);
    friend istream& operator>>(istream& is, NhanSu& ns);
    virtual ~NhanSu() {}
};


NhanSu::NhanSu(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec, string hd, double hs, string role)
    : maNhanSu(ma), hoTen(ten), gioiTinh(gt), ngaySinh(ns), soDienThoai(sdt), diaChi(dc), maChuyenMon(cm), congViec(cviec), maHopDong(hd), heSoLuong(hs) {}
double NhanSu::tinhLuong(){
    return heSoLuong * 3000.0;
}
double NhanSu::tinhPhuCap(){
    return 500.0;
}
double NhanSu::tinhThucLinh(){
    return tinhLuong() + tinhPhuCap();
}
void NhanSu::layThongTinCaNhan(){
    cout << *this; 
}
void NhanSu::layLichLamViecVaHop(){
    cout << "Lich lam viec va hop cua nhan vien " << hoTen << ":" << endl;
    cout << "Thoi gian hop: 9:00 AM, Ngay 1 thang 11 nam 2024" << endl;
    cout << "Cong viec: " << congViec << endl;
}
void NhanSu::setUsername(const string& username) {
    this->username = username;
}
void NhanSu::setRole(const string& role) {
    this->role = role;
}
void NhanSu::printInfo() {
        cout << "Mã nhân sự: " << maNhanSu << endl;
        cout << "Họ tên: " << hoTen << endl;
        cout << "Giới tính: " << gioiTinh << endl;
        cout << "Ngày sinh: " << ngaySinh << endl;
        cout << "Số điện thoại: " << soDienThoai << endl;
        cout << "Địa chỉ: " << diaChi << endl;
        cout << "Chuyên môn: " << maChuyenMon << endl;
        cout << "Công việc: " << congViec << endl;
        cout << "Hợp đồng: " << maHopDong << endl;
}
void NhanSu::loadEmployeeInfo(string maNS) {
        ifstream infile("employee_info.txt");
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string maNhanSuFile;
            ss >> maNhanSuFile;
            if (maNhanSuFile == maNS) {
                maNhanSu = maNS;
                ss >> this->hoTen >> this->gioiTinh >> this->ngaySinh >> this->soDienThoai;
                ss >> this->diaChi;
                ss >> this->maChuyenMon;
                ss >> this->congViec;
                ss >> this->maHopDong;
                ss >> this->heSoLuong;
                break;
            }
        }
}
ostream& operator<<(ostream& os, const NhanSu& ns) {
    os << "Mã nhân sự: " << ns.maNhanSu << endl;
    os << "Họ tên: " << ns.hoTen << endl;
    os << "Giới tính: " << ns.gioiTinh << endl;
    os << "Ngày sinh: " << ns.ngaySinh << endl;
    os << "Số điện thoại: " << ns.soDienThoai << endl;
    os << "Địa chỉ: " << ns.diaChi << endl;
    os << "Chuyên môn: " << ns.maChuyenMon << endl; 
    os << "Công việc: " << ns.congViec << endl;
    os << "Hợp đồng: " << ns.maHopDong << endl;  
    os << "Hệ số lương: " << ns.heSoLuong << endl;
    return os;
}
istream& operator>>(istream& is, NhanSu& ns) {
    cout << "Nhap ma nhan su: ";
    getline(is, ns.maNhanSu);
    cout << "Nhap ho ten: ";
    getline(is, ns.hoTen);
    cout << "Nhap gioi tinh: ";
    getline(is, ns.gioiTinh);
    cout << "Nhap ngay sinh: ";
    getline(is, ns.ngaySinh);
    cout << "Nhap so dien thoai: ";
    getline(is, ns.soDienThoai);
    cout << "Nhap dia chi: ";
    getline(is, ns.diaChi);
    cout << "Nhap chuyen mon: ";
    getline(is, ns.maChuyenMon);
    cout << "Nhap cong viec: ";
    getline(is, ns.congViec);
    cout << "Nhap hop dong: ";
    getline(is, ns.maHopDong);
    cout << "Nhap he so luong: ";
    is >> ns.heSoLuong;
    is.ignore();
    return is;
}


#endif
