#include "workspace.h"

MoHinhBaiXe::MoHinhBaiXe(int sc) : SUC_CHUA(sc), doanhThu(0), tongXeDaVao(0) {}

MoHinhBaiXe::~MoHinhBaiXe() { 
    for (size_t i = 0; i < danhSach.size(); i++) delete danhSach[i]; 
}

void MoHinhBaiXe::xeVaoBai() {
    if (danhSach.size() >= SUC_CHUA) throw BaiXeDayException();
    
    cout << "\n========= CHON LOAI PHUONG TIEN VAO =========\n";
    cout << "1. Xe May So (3.000d)  |  2. Xe May Ga (4.000d)\n";
    cout << "3. Xe O To  (20.000d)  |  4. Xe Tai   (45.000d)\n";
    cout << "5. Xe Dap   (2.000d)\n";
    cout << "---------------------------------------------\n";
    int chon = nhapSoNguyen(" -> Moi ban chon loai xe: ", 1, 5);

    PhuongTien* x = NULL;
    switch(chon) {
        case 1: x = new XeSo(); break;
        case 2: x = new XeGa(); break;
        case 3: x = new OTo(); break;
        case 4: x = new XeTai(); break;
        default: x = new XeDap(); break;
    }

    x->nhap();

    for(size_t i = 0; i < danhSach.size(); i++) {
        if(danhSach[i]->getBienSo() == x->getBienSo()) {
            cout << "  [!] Loi: Bien so '" << x->getBienSo() << "' hien DANG CO trong bai xe!\n"; 
            delete x; 
            return;   
        }
    }

    danhSach.push_back(x);
    tongXeDaVao++;
    cout << "=> THONG BAO: Phuong tien da vao bai thanh cong!\n";
}

void MoHinhBaiXe::xeRaBai() {
    if (danhSach.empty()) { cout << "  [!] Thong bao: Bai xe hien dang trong!\n"; return; }
    
    string bs = nhapChuoi(" -> Nhap bien so xe can thanh toan: ", false);
    for(size_t i=0; i<bs.length(); i++) bs[i] = toupper(bs[i]);
    
    string ten = nhapChuoi(" -> Nhap ho ten chu xe de doi chieu: ", true);

    time_t gioRa = time(0);
    for (size_t i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getBienSo() == bs) {
            if (danhSach[i]->getChuXe() != ten) {
                cout << "  [!] Chon sai thong tin: Ho ten chu xe khong trung khop voi bien so '" << bs << "'!\n";
                return; 
            }

            double phi = danhSach[i]->tinhTien(gioRa);
            doanhThu += phi;
            
            ThongTinLichSu ls = {bs, danhSach[i]->getLoai(), danhSach[i]->getChuXe(), formatThoiGian(gioRa), phi};
            dsLichSu.them(ls); 

            cout << "\n********** HOA DON THANH TOAN **********\n";
            cout << " Bien so xe: " << bs << endl;
            cout << " Chu xe:     " << danhSach[i]->getChuXe() << endl;
            cout << " Loai xe:    " << danhSach[i]->getLoai() << endl;
            cout << " Thoi gian:  " << (laQuaNgay(danhSach[i]->getVao(), gioRa) ? "Gui qua dem (Gia x2)" : "Gui trong ngay") << endl;
            cout << " THANH TIEN: " << (long long)phi << " VND" << endl;
            cout << "****************************************\n";
            
            delete danhSach[i];
            danhSach.erase(danhSach.begin() + i);
            return;
        }
    }
    cout << "  [!] Khong tim thay bien so xe nay trong bai!\n";
}

void MoHinhBaiXe::hienThiTrangThai() const {
    cout << "\n================ DASHBOARD QUAN LY (" << danhSach.size() << "/" << SUC_CHUA << ") ================\n";
    if (danhSach.empty()) cout << "             (Hien tai bai xe dang trong)\n";
    else {
        cout << left << setw(6) << "STT" << setw(15) << "Bien So" << setw(18) << "Loai Xe" 
             << setw(25) << "Thoi Gian Vao" << "Chu Phuong Tien" << endl;
        cout << "----------------------------------------------------------------------\n";
        for (size_t i = 0; i < danhSach.size(); i++) {
            danhSach[i]->xuat(i + 1);
        }
    }
    cout << "======================================================================\n";
}

void MoHinhBaiXe::timKiemXe() const {
    string bs = nhapChuoi(" -> Nhap bien so xe can tim: ", false);
    for(size_t i=0; i<bs.length(); i++) bs[i] = toupper(bs[i]);
    
    vector<PhuongTien*>::const_iterator it = find_if(danhSach.begin(), danhSach.end(), BoTimKiemBienSo(bs));

    if (it != danhSach.end()) {
        cout << "\n[ KET QUA TIM KIEM ]:\n";
        (*it)->xuat(1);
    } else {
        cout << " Khong tim thay xe co bien so nay trong bai!\n";
    }
}

void MoHinhBaiXe::hienThiLichSu() const {
    cout << "\n============= LICH SU CAC XE DA RA BAI =============\n";
    if (dsLichSu.empty()) cout << " (Chua co lich su giao dịch)\n";
    for (size_t i = 0; i < dsLichSu.size(); i++)
        cout << i+1 << ". " << dsLichSu[i].bs << " | " << dsLichSu[i].loai 
             << " | Tien: " << (long long)dsLichSu[i].phi << " VND | Ra: " << dsLichSu[i].ra << endl;
}

void MoHinhBaiXe::thongKeDoanhThu() const {
    map<string, int> m;
    for (size_t i = 0; i < danhSach.size(); i++) m[danhSach[i]->getLoai()]++;
    cout << "\n============= THONG KE HOAT DONG =============\n";
    cout << " 1. So luong xe dang gui theo loai:\n";
    for (map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
        cout << "    + " << it->first << ": " << it->second << " xe\n";
    cout << " 2. Tong so luot xe da vao bai: " << tongXeDaVao << " luot xe\n";
    cout << " 3. TONG DOANH THU DAT DUOC:   " << (long long)doanhThu << " VND\n";
    cout << "==============================================\n";
}

void MoHinhBaiXe::xuatBaoCaoFile() const {
    ofstream f("BaoCao_Parking.csv"); 
    f << "\xEF\xBB\xBF"; // UTF-8 BOM để Excel không lỗi font tiếng Việt
    f << "sep=,\n"; 
    f << "BÁO CÁO THÔNG TIN TONG QUAN BAI XE\n";
    f << "TOng doanh thu (VND),Tong so luot xe da vao,So xe hien tai dang trong bai\n";
    f << (long long)doanhThu << "," << tongXeDaVao << "," << (int)danhSach.size() << "\n\n";
    
    f << "DANH SÁCH CHI TIET PHUONG TIEN ÐA XUAT BAI\n";
    f << "STT,Bien so xe,Chu phuong tien,Loai phuong tien,So tien thanh toán,Thoi gian ra bai\n"; 
    
    for (size_t i = 0; i < dsLichSu.size(); i++) {
        f << (i + 1) << ","
          << "\"" << dsLichSu[i].bs << "\","
          << "\"" << dsLichSu[i].chuXe << "\","
          << "\"" << dsLichSu[i].loai << "\","
          << (long long)dsLichSu[i].phi << " VND,"
          << "\"" << dsLichSu[i].ra << "\"\n";
    }
    f.close();
    cout << "=> Da xuat bao cao vao file 'BaoCao_Parking.csv' thanh cong!\n";
}
