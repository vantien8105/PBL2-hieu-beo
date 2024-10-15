#ifndef PhongBan_h
#define PhongBan_h
#include <iostream>
using namespace std;
class PhongBan {
protected:
    string maPhongBan;
    string tenPhongBan;
    int soLuongThanhVien;
    string diaChi;
public:
    PhongBan(string ma, string ten, int soLuong, string dc);
    void layThongTinPhongBan();
    void dieuChinhThongTin();
};
#endif