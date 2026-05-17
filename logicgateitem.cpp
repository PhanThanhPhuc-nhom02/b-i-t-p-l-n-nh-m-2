#include "logicgateitem.h"

void PhuongTien::nhap() {
    bienSo = nhapChuoi("  + Nhap bien so xe (Viet lien): ", false);
    for(size_t i = 0; i < bienSo.length(); i++) bienSo[i] = toupper(bienSo[i]);
    chuXe = nhapChuoi("  + Nhap ho ten chu xe: ", true);
    timestampVao = time(0);
}

void PhuongTien::xuat(int stt) const {
    cout << left << setw(6) << stt << setw(15) << bienSo << setw(18) << loaiXe 
         << setw(25) << formatThoiGian(timestampVao) << chuXe << endl;
}

double XeSo::tinhTien(time_t ra) const { 
    return laQuaNgay(timestampVao, ra) ? 6000 : 3000; 
}

double XeGa::tinhTien(time_t ra) const { 
    return laQuaNgay(timestampVao, ra) ? 8000 : 4000; 
}

double OTo::tinhTien(time_t ra) const { 
    return laQuaNgay(timestampVao, ra) ? 20000 : 20000; 
}

double XeTai::tinhTien(time_t ra) const { 
    return laQuaNgay(timestampVao, ra) ? 90000 : 45000; 
}

double XeDap::tinhTien(time_t ra) const { 
    return laQuaNgay(timestampVao, ra) ? 4000 : 2000; 
}
