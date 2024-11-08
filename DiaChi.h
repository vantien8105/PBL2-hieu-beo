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
DiaChi::DiaChi(string duong, string qh) : tenDuong(duong), quanHuyen(qh) {}

ostream& operator<<(ostream& os, const DiaChi& dc) {
    os << "Ten duong: " << dc.tenDuong << endl;
    os << "Quan/Huyen: " << dc.quanHuyen << endl;
    return os;
}

istream& operator>>(istream& is, DiaChi& dc) {
    cout << "Nhap ten duong: ";
    getline(is, dc.tenDuong);
    cout << "Nhap quan/huyen: ";
    getline(is, dc.quanHuyen);
    return is;
}

void DiaChi::layThongTinDiaChi() const {
    cout << *this;
}

#endif
