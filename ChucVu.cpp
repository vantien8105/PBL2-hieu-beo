#include "ChucVu.h"
ChucVu::ChucVu(string maCV, string tenCV, string quyenLoi, string quyenHan) 
    : maChucVu(maCV), tenChucVu(tenCV), quyenLoi(quyenLoi), quyenHan(quyenHan) {}
void ChucVu::themChucVu() {
    cout << "Them chuc vu moi.\n";
    cout << "Nhap ma chuc vu: ";
    cin >> maChucVu;
    cout << "Nhap ten chuc vu: ";
    cin.ignore();
    getline(cin, tenChucVu);
    cout << "Nhap quyen loi: ";
    getline(cin, quyenLoi);
    cout << "Nhap quyen han: ";
    getline(cin, quyenHan);
}
void ChucVu::xoaChucVu() {
    maChucVu = "";
    tenChucVu = "";
    quyenLoi = "";
    quyenHan = "";
    cout << "Chuc vu da duoc xoa.\n";
}
void ChucVu::suaChucVu() {
    cout << "Sua thong tin chuc vu.\n";
    cout << "Nhap ten chuc vu moi: ";
    cin.ignore();
    getline(cin, tenChucVu);
    cout << "Nhap quyen loi moi: ";
    getline(cin, quyenLoi);
    cout << "Nhap quyen han moi: ";
    getline(cin, quyenHan);
}
ostream& operator<<(ostream& os, const ChucVu& cv) {
    os << "Ma chuc vu: " << cv.maChucVu << endl;
    os << "Ten chuc vu: " << cv.tenChucVu << endl;
    os << "Quyen loi: " << cv.quyenLoi << endl;
    os << "Quyen han: " << cv.quyenHan << endl;
    return os;
}
istream& operator>>(istream& is, ChucVu& cv) {
    cout << "Nhap ma chuc vu: ";
    is >> cv.maChucVu;
    cout << "Nhap ten chuc vu: ";
    is.ignore(); 
    getline(is, cv.tenChucVu);
    cout << "Nhap quyen loi: ";
    getline(is, cv.quyenLoi);
    cout << "Nhap quyen han: ";
    getline(is, cv.quyenHan);
    return is;
}
