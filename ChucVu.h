#ifndef ChucVu_h
#define ChucVu_h
#include <iostream>
using namespace std;

class ChucVu {
protected:
    string maChucVu;
    string tenChucVu; 
    string quyenLoi;
    string quyenHan;  

public:
    ChucVu(string maCV = "", string tenCV = "", string quyenLoi = "", string quyenHan = "");
    void themChucVu();
    void xoaChucVu();
    void suaChucVu();
    friend ostream& operator<<(ostream& os, const ChucVu& cv);
    friend istream& operator>>(istream& is, ChucVu& cv);
};

#endif
