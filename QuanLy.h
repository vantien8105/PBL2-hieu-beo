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
    //Nên thừa kế constructor từ lớp Nhansu sẽ ok hơn. đỡ bị chê lặp code =))
    QuanLy(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec, string hd, double hs, 
            string BPQL, int snv, string username, string password)
            : NhanSu( ma,  ten,  gt,  ns,  sdt,  dc,  cm, cviec , hd,  hs), boPhanQuanLy(BPQL), soNhanVienQuanLy(snv) {};

    void taoCuocHop();
    void layThongTinCaNhan();
    // bool login(string u, string p) override;
};

#endif
