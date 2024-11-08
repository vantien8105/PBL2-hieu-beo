#ifndef QUANLY_H
#define QUANLY_H
#include "Employee.h"
#include "Nhansu.h"
class LinkedList;
class QuanLy : public NhanSu {
protected:
    string boPhanQuanLy; 
    int soNhanVienQuanLy;
public:
    QuanLy();
    QuanLy(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec, string hd, double hs, string role, 
            string BPQL, int snv, string username, string password);
    void loadEmployeeInfo(string maNS);
    void taoCuocHop();
    void layThongTinCaNhan() const;
    int getSNV() const { return soNhanVienQuanLy; };
    void xemThongTinNhanVien(const LinkedList& list) const;
    double tinhLuong();    
    double tinhPhuCap();   
    double tinhThucLinh();
    void xetDuyetNghiPhep();
    void danhGiaNhanVien();
    void xetDuyetTangLuong();
    void Delete(const string& maNhanVien, const LinkedList& list) const;
    void update_nv(bool ok);
    string getUsername(){
        return username;
    }
    string getBoPhanLamViec() const override{ return boPhanQuanLy; }
    string getRole() const override { return "Manager"; }
    string getMaNV() const override { return maNhanSu; }
    friend ostream& operator<<(ostream& os, const QuanLy& ns);
    friend istream& operator>>(istream& is, QuanLy& ns);
};
QuanLy::QuanLy() : NhanSu("", "", "", "", "", "", "", "", "", 0, "Manager"), boPhanQuanLy(""), soNhanVienQuanLy(0) {}

QuanLy::QuanLy(string ma, string ten, string gt, string ns, string sdt, string dc, string cm, string cviec, string hd, double hs, string role,
            string BPQL, int snv, string username, string password)
            : NhanSu( ma, ten, gt, ns, sdt, dc, cm, cviec, hd, hs, role), boPhanQuanLy(BPQL), soNhanVienQuanLy(snv) {

}
ostream& operator<<(ostream& os, const QuanLy& ql) {
    os << static_cast<const NhanSu&>(ql);
    os << "Bộ phận quản lý " << ql.boPhanQuanLy << endl;
    os << "Số nhân viên quản lý: " << ql.soNhanVienQuanLy << endl;
    return os;
}
istream& operator>>(istream& is, QuanLy& ql) {
    is >> static_cast<NhanSu&>(ql);
    cout << "Nhập Bộ phận quản lý: ";
    is >> ql.boPhanQuanLy;
    cout << "Nhập nhân viên quản lý: ";
    is >> ql.soNhanVienQuanLy;
    return is;
}
void QuanLy::update_nv(bool ok) {
    if (ok) {
        ++soNhanVienQuanLy;
    } else {
        if (soNhanVienQuanLy > 0) {
            --soNhanVienQuanLy;
        }
    }
}
// void QuanLy::xemThongTinNhanVien(const LinkedList& list) const {  // Chỉnh const LinkedList&
//     cout << "Danh sách nhân viên trong phòng ban " << boPhanQuanLy << " do bạn quản lý:" << endl;
//     Node* current = list.getHead(); 
//     while (current) {
//         NhanVien* nv = dynamic_cast<NhanVien*>(current->data);
//         if (nv && nv->getBoPhanLamViec() == boPhanQuanLy) {
//             nv->layThongTinCaNhan();
//         }
//         current = current->next;
//     }
// }
void QuanLy::loadEmployeeInfo(string maNS) {
        ifstream infile("employee_info.txt");
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string maNhanSuFile;
            ss >> maNhanSuFile;
            if (maNhanSuFile == maNS) {
                maNhanSu = maNS;
                ss >> this->hoTen >> this->gioiTinh >> this->ngaySinh >> this->soDienThoai;
                ss >> this->diaChi;
                ss >> this->maChuyenMon;
                ss >> this->congViec;
                ss >> this->maHopDong;
                ss >> this->heSoLuong;
                ss >> this->boPhanQuanLy;
                ss >> this->soNhanVienQuanLy;
                break;
            }
        }
}
void QuanLy::taoCuocHop() {
    cout << "Nhap noi dung cuoc hop: ";
    string noiDung;
    cin.ignore();
    getline(cin, noiDung);
    cout << "Cuoc hop da duoc tao voi noi dung: " << noiDung << endl;
}
void QuanLy::xetDuyetNghiPhep() {
    cout << "Nhap ma nhan vien de xet duyet nghi phep: ";
    string maNhanVien;
    cin >> maNhanVien;
    cout << "Don xin nghi phep cua nhan vien " << maNhanVien << " da duoc xet duyet." << endl;
}
void QuanLy::danhGiaNhanVien() {
    cout << "Nhap ma nhan vien de danh gia: ";
    string maNhanVien;
    cin >> maNhanVien;
    cout << "Danh gia nhan vien " << maNhanVien << " la: Tot." << endl;
}
void QuanLy::xetDuyetTangLuong() {
    cout << "Nhap ma nhan vien de xet duyet tang luong: ";
    string maNhanVien;
    cin >> maNhanVien;
    cout << "De nghi tang luong cua nhan vien " << maNhanVien << " da duoc xet duyet." << endl;
}
void QuanLy::layThongTinCaNhan() const {
    cout << *this;
}
double QuanLy::tinhLuong(){
    return NhanSu::tinhLuong() + 5000.0;
}   
double QuanLy::tinhPhuCap(){
    return NhanSu::tinhPhuCap() + 1000.0;
} 
double QuanLy::tinhThucLinh(){
    return tinhLuong() + tinhPhuCap();
}
#endif
