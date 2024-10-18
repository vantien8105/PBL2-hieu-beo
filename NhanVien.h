#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "Nhansu.h"
#include <iostream>

class NhanVien : public NhanSu {
protected:
    string boPhanLamViec;
public:      
    NhanVien();
    NhanVien(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec,
                string hd, double hs, string role, string bp, string td, string username, string password);
    void loadEmployeeInfo(string maNS);
    void baoCaoTienDo();
    void layThongTinCaNhan();
    void xinNghiPhep();
    void deNghiTangLuong();
    string getUsername(){
        return username;
    }
    string getRole(){
        return "Employee";
    }
    friend ostream& operator<<(ostream& os, const NhanVien& ns);
    friend istream& operator>>(istream& is, NhanVien& ns);
};

#endif
