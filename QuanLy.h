#ifndef QUANLY_H
#define QUANLY_H

#include "NhanSu.h"
#include <iostream>

class QuanLy : public NhanSu {
protected:
    string boPhanQuanLy; 
    int soNhanVienQuanLy;
    QuanLy(string ma, string ten, string gt, string ns, string sdt, string dc, string cv, string cviec, string ct, double luong, string bp, int snv);
    //:NhanSu(string ma, string ten, string gt, string ns, string sdt, string dc, ChucVu cv, string cviec, string ct, double luong), boPhanQuanLy(bp), soNhanVienQuanLy(snv);
    void taoCuocHop();
    void layThongTinCaNhan();
};

#endif
