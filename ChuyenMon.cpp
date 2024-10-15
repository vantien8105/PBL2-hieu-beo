#include "ChuyenMon.h"

ChuyenMon::ChuyenMon(string ma, string ten, string uni, string bang) 
    : maChuyenNganh(ma), tenChuyenNganh(ten), university(uni), bangCap(bang) {}
ostream& operator<<(ostream& os, const ChuyenMon& cm) {
    os << "Ma chuyen nganh: " << cm.maChuyenNganh << endl;
    os << "Ten chuyen nganh: " << cm.tenChuyenNganh << endl;
    os << "Truong dai hoc: " << cm.university << endl;
    os << "Bang cap: " << cm.bangCap << endl;
    return os;
}
istream& operator>>(istream& is, ChuyenMon& cm) {
    cout << "Nhap ma chuyen nganh: ";
    is >> cm.maChuyenNganh;
    is.ignore();
    cout << "Nhap ten chuyen nganh: ";
    getline(is, cm.tenChuyenNganh);
    cout << "Nhap truong dai hoc: ";
    getline(is, cm.university);
    cout << "Nhap bang cap: ";
    getline(is, cm.bangCap);
    return is;
}
void ChuyenMon::inThongTinChuyenNganh() const {
    cout << *this;
}
