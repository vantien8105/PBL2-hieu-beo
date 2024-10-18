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
    string diaChi;  
    string maChuyenMon; 
    string congViec;    
    string maHopDong;  
    string username;
    string password;
    string role;  
    double heSoLuong;  

public:

    NhanSu(string ma = "", string ten = "", string gt = "", string ns = "", string sdt = "", 
        string dc = "" , string cm = "", string cviec = "", 
        string hd ="", double hs = 0.0, string role =""); //string username, string password
    double tinhLuong();    
    double tinhPhuCap();   
    double tinhThucLinh();  
    void layThongTinCaNhan();
    void layLichLamViecVaHop();
    string getUsername();
    string getRole();
    void setUsername(const string& username) {
    this->username = username;
    }
    void setRole(const string& role) {
    this->role = role;
    }
    void printInfo();
    void loadEmployeeInfo(string maNS);
    friend ostream& operator<<(ostream& os, const NhanSu& ns);
    friend istream& operator>>(istream& is, NhanSu& ns);
    virtual ~NhanSu() {}
};

#endif
