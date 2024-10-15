#ifndef DiaChi_h
#define DiaChi_h
#include <iostream>
using namespace std;
class DiaChi {
protected:
    string tenDuong;   
    string quanHuyen;
public:
    DiaChi(string duong = "", string qh = "");
    void layThongTinDiaChi() const;
    friend ostream& operator<<(ostream& os, const DiaChi& dc);
    friend istream& operator>>(istream& is, DiaChi& dc);
};

#endif
