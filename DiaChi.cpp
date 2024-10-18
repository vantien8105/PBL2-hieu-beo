#include "DiaChi.h"

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
