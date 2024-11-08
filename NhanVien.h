#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "Nhansu.h"
#include <iostream>
#include <fstream>
#include <string>
#include<iostream>
#include <sstream>
class NhanVien : public NhanSu {
protected:
    string boPhanLamViec;
public:      
    NhanVien();
    NhanVien(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec,
                string hd, double hs, string role, string bp, string username, string password);
    void loadEmployeeInfo(string maNS);
    void baoCaoTienDo();
    void layThongTinCaNhan();
    void xinNghiPhep();
    void deNghiTangLuong();
    string getMaNV() const override { return maNhanSu; }
    string getRole() const override { return "Employee"; }
    string getBoPhanLamViec() const override{ return boPhanLamViec; }
    string toString() const;
    friend ostream& operator<<(ostream& os, const NhanVien& ns);
    friend istream& operator>>(istream& is, NhanVien& ns);
};
NhanVien::NhanVien() : NhanSu("", "", "", "", "", "", "", "", "", 0, "Employee"), boPhanLamViec("") {}

NhanVien::NhanVien(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec,
                     string hd, double hs, string role, string bp, string username, string password) 
    :NhanSu(ma, ten, gt, ns, sdt, dc, cm, cviec, hd, hs, role), boPhanLamViec(bp){}

ostream& operator<<(ostream& os, const NhanVien& nv) {
    os << static_cast<const NhanSu&>(nv);
    os << "Bộ phận làm việc: " << nv.boPhanLamViec << endl;
    return os;
}

istream& operator>>(istream& is, NhanVien& nv) {
    is >> static_cast<NhanSu&>(nv);
    cout << "Nhập bộ phận làm việc: ";
    getline(is, nv.boPhanLamViec);
    return is;
}
string NhanVien::toString() const {
        stringstream ss;
        ss << maNhanSu << " "
           << hoTen << " "
           << gioiTinh << " "
           << ngaySinh << " "
           << soDienThoai << " "
           << diaChi << " "
           << maChuyenMon << " "
           << congViec << " "
           << maHopDong << " "
           << heSoLuong << " "
           << boPhanLamViec;
        return ss.str();
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
#endif
