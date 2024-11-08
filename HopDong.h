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

HopDong::HopDong(string ma, string ten, string thoiHan) : maHopDong(ma), tenHopDong(ten), thoiHanHopDong(thoiHan) {}
ostream& operator<<(ostream& os, const HopDong& hd) {
    os << "Ma hop dong: " << hd.maHopDong << endl;
    os << "Ten hop dong: " << hd.tenHopDong << endl;
    os << "Thoi han hop dong: " << hd.thoiHanHopDong << endl;
    return os;
}
istream& operator>>(istream& is, HopDong& hd) {
    cout << "Nhap ma hop dong: ";
    getline(is, hd.maHopDong);
    cout << "Nhap ten hop dong: ";
    getline(is, hd.tenHopDong);
    cout << "Nhap thoi han hop dong: ";
    getline(is, hd.thoiHanHopDong);
    return is;
}
void HopDong::layThongTinHopDong() const {
    cout << *this;
}
#endif
