#include "QuanLy.h"
#include <fstream>
#include <string>
#include<iostream>
#include <sstream>
using namespace std;
QuanLy::QuanLy() : NhanSu("", "", "", "", "", "", "", "", "", 0, "Manager"), boPhanQuanLy(""), soNhanVienQuanLy(0) {
}
QuanLy::QuanLy(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec, string hd, double hs, string role,
            string BPQL, int snv, string username, string password)
            : NhanSu( ma, ten, gt, ns, sdt, dc, cm, cviec, hd, hs, "Manager"), boPhanQuanLy(BPQL), soNhanVienQuanLy(snv) {

}
ostream& operator<<(ostream& os, const QuanLy& ql) {
    os << static_cast<const NhanSu&>(ql);
    os << "Bo phan quan ly: " << ql.boPhanQuanLy << endl;
    os << "So nhan vien quan ly: " << ql.soNhanVienQuanLy << endl;
    return os;
}
istream& operator>>(istream& is, QuanLy& ql) {
    is >> static_cast<NhanSu&>(ql);
    cout << "Nhap bo phan quan ly: ";
    is >> ql.boPhanQuanLy;
    cout << "Nhap so nhan vien quan ly: ";
    is >> ql.soNhanVienQuanLy;
    return is;
}
void QuanLy::loadEmployeeInfo(string maNS) {
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
                ss >> this->boPhanQuanLy;
                ss >> this->soNhanVienQuanLy;
                break;
            }
        }
}
void QuanLy::taoCuocHop() {
    cout << "Nhap noi dung cuoc hop: ";
    string noiDung;
    cin.ignore();
    getline(cin, noiDung);
    cout << "Cuoc hop da duoc tao voi noi dung: " << noiDung << endl;
}
void QuanLy::xetDuyetNghiPhep() {
    cout << "Nhap ma nhan vien de xet duyet nghi phep: ";
    string maNhanVien;
    cin >> maNhanVien;
    cout << "Don xin nghi phep cua nhan vien " << maNhanVien << " da duoc xet duyet." << endl;
}
void QuanLy::danhGiaNhanVien() {
    cout << "Nhap ma nhan vien de danh gia: ";
    string maNhanVien;
    cin >> maNhanVien;
    cout << "Danh gia nhan vien " << maNhanVien << " la: Tot." << endl;
}
void QuanLy::xetDuyetTangLuong() {
    cout << "Nhap ma nhan vien de xet duyet tang luong: ";
    string maNhanVien;
    cin >> maNhanVien;
    cout << "De nghi tang luong cua nhan vien " << maNhanVien << " da duoc xet duyet." << endl;
}
void QuanLy::layThongTinCaNhan(){
    cout << *this;
}
double QuanLy::tinhLuong(){
    return NhanSu::tinhLuong() + 5000.0;
}   
double QuanLy::tinhPhuCap(){
    return NhanSu::tinhPhuCap() + 1000.0;
} 
double QuanLy::tinhThucLinh(){
    return tinhLuong() + tinhPhuCap();
}
