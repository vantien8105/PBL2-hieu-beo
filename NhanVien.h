#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "Nhansu.h"
#include <iostream>

class NhanVien : public NhanSu {
protected:
    string boPhanLamViec; //Ma bo phan
public:      
    NhanVien();
    NhanVien(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec, string hd, double hs, string bp, string td, string username, string password) 
    : NhanSu( ma ,  ten, gt , ns, sdt ,  dc, cm,  cviec, hd, hs), boPhanLamViec(bp){}
    void baoCaoTienDo();
    void layThongTinCaNhan();
    // bool login(string u, string p) override;
};

#endif
