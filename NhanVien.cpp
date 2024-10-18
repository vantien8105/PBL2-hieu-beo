#include "NhanVien.h"
#include <fstream>
#include <string>
#include<iostream>
#include <sstream>
using namespace std;
NhanVien::NhanVien() : NhanSu("", "", "", "", "", "", "", "", "", 0, "Employee"), boPhanLamViec("") {
}
NhanVien::NhanVien(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec,
                     string hd, double hs, string role, string bp, string td, string username, string password) 
    : NhanSu(ma, ten, gt, ns, sdt, dc, cm, cviec, hd, hs, "Employee"), boPhanLamViec(bp){}
ostream& operator<<(ostream& os, const NhanVien& nv) {
    os << static_cast<const NhanSu&>(nv);
    os << "Bo phan lam viec: " << nv.boPhanLamViec << endl;
    return os;
}
istream& operator>>(istream& is, NhanVien& nv) {
    is >> static_cast<NhanSu&>(nv);
    cout << "Nhap bo phan lam viec: ";
    is >> nv.boPhanLamViec;
    return is;
}
void NhanVien::loadEmployeeInfo(string maNS) {
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
                ss >> this->boPhanLamViec;
                break;
            }
        }
}
void NhanVien::baoCaoTienDo() {
    cout << "Nhap bao cao tien do cong viec: ";
    string tienDo;
    cin.ignore();
    getline(cin, tienDo);
    cout << "Tien do da duoc ghi nhan: " << tienDo << endl;
}

void NhanVien::xinNghiPhep() {
    cout << "Nhap ngay ban muon nghi phep: ";
    string ngayNghi;
    cin.ignore();
    getline(cin, ngayNghi);
    cout << "Don xin nghi phep da duoc gui ngay: " << ngayNghi << endl;
}
void NhanVien::deNghiTangLuong() {
    cout << "Nhap ly do de nghi tang luong: ";
    string lyDo;
    cin.ignore();
    getline(cin, lyDo);
    cout << "De nghi tang luong cua ban da duoc gui voi noi dung: " << lyDo << endl;
}
void NhanVien::layThongTinCaNhan(){
    cout << *this;
}