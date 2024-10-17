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
    string diaChi;   //day cung vay   
    string maChuyenMon; //o day chi can ma chuyen mon roi truy xuat vao file co ma chuyen mon do la duoc 
    string congViec;    
    string maHopDong;  //day cung vay
    string username;
    string password;
    string role;  
    double heSoLuong;  

public:

    NhanSu(string ma = "", string ten = "", string gt = "", string ns = "", string sdt = "", 
        string dc = "" , string cm = "", string cviec = "", 
        string hd ="", double hs = 0.0); //string username, string password
    double tinhLuong() const;    
    double tinhPhuCap() const;   
    double tinhThucLinh() const;  
    void layThongTinCaNhan() const;
    void layLichLamViecVaHop() const;
    string getUsername();
    string getRole();
    void printInfo();
    void loadEmployeeInfo(string );

    // virtual bool login(string u, string p) = 0;
    friend ostream& operator<<(ostream& os, const NhanSu& ns);
    friend istream& operator>>(istream& is, NhanSu& ns);
};

#endif
