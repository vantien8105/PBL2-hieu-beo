#include "Nhansu.h"
#include <fstream>
#include <string>
#include<iostream>
#include <sstream>

using namespace std;

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
string NhanSu::getUsername() {
    return username;
}

string NhanSu::getRole() {
    return role;
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
    os << "Ma nhan su: " << ns.maNhanSu << endl;
    os << "Ho ten: " << ns.hoTen << endl;
    os << "Gioi tinh: " << ns.gioiTinh << endl;
    os << "Ngay sinh: " << ns.ngaySinh << endl;
    os << "So dien thoai: " << ns.soDienThoai << endl;
    os << "Dia chi: " << ns.diaChi << endl;
    os << "Chuyen mon: " << ns.maChuyenMon << endl; 
    os << "Cong viec: " << ns.congViec << endl;
    os << "Hop dong: " << ns.maHopDong << endl;  
    os << "He so luong: " << ns.heSoLuong << endl;
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
    cout << "Nhap dia chi: " << endl;
    is >> ns.diaChi;
    cout << "Nhap chuyen mon: " << endl;
    is >> ns.maChuyenMon;
    cout << "Nhap cong viec: ";
    getline(is, ns.congViec);
    cout << "Nhap hop dong: " << endl;
    is >> ns.maHopDong;
    cout << "Nhap he so luong: ";
    is >> ns.heSoLuong;
    is.ignore();
    return is;
}

