#ifndef LOGICCORE_H
#define LOGICCORE_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <limits>
#include <map>

using namespace std;

// Cấu trúc thông tin lịch sử bãi xe
struct ThongTinLichSu { 
    string bs, loai, chuXe, ra; 
    double phi; 
};

// Các class xử lý ngoại lệ
class BaiXeException : public runtime_error {
public:
    explicit BaiXeException(const string& msg) : runtime_error(msg) {}
};

class BaiXeDayException : public BaiXeException {
public:
    BaiXeDayException() : BaiXeException("Hien tai bai xe da day cho, khong the nhan them!") {}
};

// Lớp Template bộ lưu trữ
template <typename T>
class BoLuuTru {
private:
    vector<T> danhSach;
public:
    void them(const T& item) { danhSach.push_back(item); }
    size_t size() const { return danhSach.size(); }
    const T& operator[](size_t index) const { return danhSach[index]; }
    bool empty() const { return danhSach.empty(); }
};

// Các hàm kiểm tra và định dạng bổ trợ
bool laBienSoHopLe(const string& s);
bool laTenHopLe(const string& s);
string nhapChuoi(const string& prompt, bool kieuTen);
int nhapSoNguyen(const string& prompt, int min_v, int max_v);
string formatThoiGian(time_t t);
bool laQuaNgay(time_t vao, time_t ra);

#endif // LOGICCORE_H
