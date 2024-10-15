#ifndef HopDong_h
#define HopDong_h
#include <iostream>
using namespace std;
class HopDong {
protected:
    string maHopDong;
    string tenHopDong;
    string thoiHanHopDong;
public:
    HopDong(string ma = "", string ten = "", string thoiHan = "");
    void layThongTinHopDong() const;
    friend ostream& operator<<(ostream& os, const HopDong& hd);
    friend istream& operator>>(istream& is, HopDong& hd);
};
#endif
