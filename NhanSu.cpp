#include "NhanSu.h"

NhanSu::NhanSu(string ma, string ten, string gt, string ns, string sdt, DiaChi dc, ChuyenMon cm, string cviec, HopDong hd, double hs)
    : maNhanSu(ma), hoTen(ten), gioiTinh(gt), ngaySinh(ns), soDienThoai(sdt), diaChi(dc), chuyenMon(cm), congViec(cviec), hopDong(hd), heSoLuong(hs) {}
double NhanSu::tinhLuong() const{
    return heSoLuong * 3000000;
}
double NhanSu::tinhPhuCap() const{
    return 500000;
}
double NhanSu::tinhThucLinh() const{
    return tinhLuong() + tinhPhuCap();
}
void NhanSu::layThongTinCaNhan() const{
    cout << *this; 
}
void NhanSu::layLichLamViecVaHop() const{
    cout << "Lich lam viec va hop cua nhan vien " << hoTen << ":" << endl;
    cout << "Thoi gian hop: 9:00 AM, Ngay 1 thang 11 nam 2024" << endl;
    cout << "Cong viec: " << congViec << endl;
}
ostream& operator<<(ostream& os, const NhanSu& ns) {
    os << "Ma nhan su: " << ns.maNhanSu << endl;
    os << "Ho ten: " << ns.hoTen << endl;
    os << "Gioi tinh: " << ns.gioiTinh << endl;
    os << "Ngay sinh: " << ns.ngaySinh << endl;
    os << "So dien thoai: " << ns.soDienThoai << endl;
    os << "Dia chi: " << ns.diaChi << endl;
    os << "Chuyen mon: " << ns.chuyenMon << endl; 
    os << "Cong viec: " << ns.congViec << endl;
    os << "Hop dong: " << ns.hopDong << endl;  
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
    is >> ns.chuyenMon;
    cout << "Nhap cong viec: ";
    getline(is, ns.congViec);
    cout << "Nhap hop dong: " << endl;
    is >> ns.hopDong;
    cout << "Nhap he so luong: ";
    is >> ns.heSoLuong;
    is.ignore();
    return is;
}
