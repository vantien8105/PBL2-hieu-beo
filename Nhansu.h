#ifndef NhanSu_h
#define NhanSu_h
#include <iostream>
#include "ChucVu.h"
#include "DiaChi.h"
#include "HopDong.h"
#include "ChuyenMon.h"
using namespace std;

class NhanSu {
protected:
    string maNhanSu;     
    string hoTen;        
    string gioiTinh;     
    string ngaySinh;    
    string soDienThoai;
    DiaChi diaChi;     
    ChuyenMon chuyenMon; 
    string congViec;    
    HopDong hopDong;    
    double heSoLuong;  

public:
    NhanSu(string ma = "", string ten = "", string gt = "", string ns = "", string sdt = "", 
        DiaChi dc = DiaChi(), ChuyenMon cm = ChuyenMon(), string cviec = "", 
        HopDong hd = HopDong(), double hs = 0.0); 
    double tinhLuong() const;    
    double tinhPhuCap() const;   
    double tinhThucLinh() const;  
    void layThongTinCaNhan() const;
    void layLichLamViecVaHop() const;
    friend ostream& operator<<(ostream& os, const NhanSu& ns);
    friend istream& operator>>(istream& is, NhanSu& ns);
};

#endif
