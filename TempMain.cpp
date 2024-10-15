#include "NhanSu.h"

int main() {
    DiaChi diaChi("123 Nguyen Trai", "Quan 1");
    ChuyenMon chuyenMon("CN001", "CNTT", "DH Bach Khoa", "Ky Su");
    HopDong hopDong("HD001", "Hop Dong Lao Dong", "1 nam");
    NhanSu ns1("NS001", "Nguyen Van A", "Nam", "01/01/1990", "0912345678", diaChi, chuyenMon, "Lap trinh vien", hopDong, 3.5);
    cout << "Thong tin nhan su:\n" << ns1;
    cout << "Luong thuc linh: " << ns1.tinhThucLinh() << endl;
    NhanSu ns2;
    cin >> ns2;
    cout << "Thong tin nhan su vua nhap:\n" << ns2;
    return 0;
}
