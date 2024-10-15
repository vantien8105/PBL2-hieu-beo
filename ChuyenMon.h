#ifndef ChuyenNganh_h
#define ChuyenNganh_h
#include <iostream>
using namespace std;
class ChuyenMon {
protected:
    string maChuyenNganh;
    string tenChuyenNganh;
    string university;
    string bangCap;
public:
    ChuyenMon(string ma = "", string ten = "", string uni = "", string bang = "");
    void inThongTinChuyenNganh() const;
    friend ostream& operator<<(ostream& os, const ChuyenMon& cm);
    friend istream& operator>>(istream& is, ChuyenMon& cm);
};
#endif