#include "logicCore.h"

bool laBienSoHopLe(const string& s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (!isalnum(s[i])) return false;  
    }
    return true;
}

bool laTenHopLe(const string& s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (!isalpha(s[i]) && !isspace(s[i])) return false;
    }
    return true;
}

string nhapChuoi(const string& prompt, bool kieuTen) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        size_t first = input.find_first_not_of(" \t");
        if (first == string::npos) {
            cout << "  [!] Thong bao: Khong duoc de trong thong tin!\n";
            continue;
        }
        size_t last = input.find_last_not_of(" \t");
        input = input.substr(first, last - first + 1);

        if (kieuTen) {
            if (input.length() > 50) {
                cout << "  [!] Thong bao: Ten khong duoc qua 50 ky tu!\n";
                continue;
            }
            if (!laTenHopLe(input)) {
                cout << "  [!] Thong bao: Ten chi duoc chua chu cai, khong chua so hay ky tu dac biet!\n";
                continue;
            }
        } else {
            if (input.length() > 10) {
                cout << "  [!] Thong bao: Toi da 10 ky tu. Vui long nhap lai!\n";
                continue;
            }
            if (!laBienSoHopLe(input)) {
                cout << "  [!] Thong bao: Bien so chi duoc chua chu va so, khong chua ky tu dac biet!\n";
                continue;
            }
        }
        return input;
    }
}

int nhapSoNguyen(const string& prompt, int min_v, int max_v) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        
        size_t first = input.find_first_not_of(" \t");
        if (first == string::npos) {
            cout << "  [!] Thong bao: Vui long chon so trong pham vi [" << min_v << "-" << max_v << "]\n";
            continue;
        }
        size_t last = input.find_last_not_of(" \t");
        string trimmed = input.substr(first, last - first + 1);
        
        bool laSoThuanTuy = true;
        for (size_t i = 0; i < trimmed.length(); i++) {
            if (!isdigit(trimmed[i])) {
                laSoThuanTuy = false;
                break;
            }
        }
        
        if (!laSoThuanTuy || trimmed.length() > 9) {
            cout << "  [!] Thong bao: Vui long chon so trong pham vi [" << min_v << "-" << max_v << "]\n";
            continue;
        }
        
        int val = 0;
        for (size_t i = 0; i < trimmed.length(); i++) {
            val = val * 10 + (trimmed[i] - '0');
        }
        
        if (val >= min_v && val <= max_v) {
            return val;
        }
        cout << "  [!] Thong bao: Vui long chon so trong pham vi [" << min_v << "-" << max_v << "]\n";
    }
}

string formatThoiGian(time_t t) {
    struct tm* timePtr = localtime(&t);
    char buf[32];
    strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M", timePtr);
    return string(buf);
}

bool laQuaNgay(time_t vao, time_t ra) {
    struct tm* tmVao = localtime(&vao);
    int d1 = tmVao->tm_mday, m1 = tmVao->tm_mon, y1 = tmVao->tm_year;
    struct tm* tmRa = localtime(&ra);
    return (tmRa->tm_mday != d1 || tmRa->tm_mon != m1 || tmRa->tm_year != y1);
}
