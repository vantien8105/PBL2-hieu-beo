#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "NhanSu.h"
#include <iostream>

class NhanVien : public NhanSu {
protected:
    string boPhanLamViec; 
    string tienDo;
public:      
    NhanVien(string ma, string ten, string gt, string ns, string sdt, string dc, ChucVu cv, string cviec, string ct, double luong, string bp, string td);
        // : NhanSu(ma, ten, gt, ns, sdt, dc, cv, cviec, ct, luong), boPhanLamViec(bp), tienDo(td) {}
    void baoCaoTienDo();
    void layThongTinCaNhan();
};

#endif
