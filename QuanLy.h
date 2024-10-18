#ifndef QUANLY_H
#define QUANLY_H

#include "Nhansu.h"
#include <iostream>

class QuanLy : public NhanSu {
protected:
    string boPhanQuanLy; // Ma bo phan
    int soNhanVienQuanLy;
public:
    QuanLy();
    QuanLy(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec, string hd, double hs, string role, 
            string BPQL, int snv, string username, string password);
    void loadEmployeeInfo(string maNS);
    void taoCuocHop();
    void layThongTinCaNhan();
    double tinhLuong();    
    double tinhPhuCap();   
    double tinhThucLinh();
    void xetDuyetNghiPhep();
    void danhGiaNhanVien();
    void xetDuyetTangLuong();
    string getUsername(){
        return username;
    }
    string getRole(){
    }
    friend ostream& operator<<(ostream& os, const QuanLy& ns);
    friend istream& operator>>(istream& is, QuanLy& ns);
};

#endif
