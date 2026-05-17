#include "workspace.h"

int main() {
    MoHinhBaiXe ql(50);
    int chon = -1;
    while (true) {
        try {
            ql.hienThiTrangThai();
            cout << "\n************* MENU QUAN LY BAI XE *************\n";
            cout << "* [1]. Cho phuong tien vao bai               *\n";
            cout << "* [2]. Thanh toan cho phuong tien ra         *\n";
            cout << "* [3]. Tim kiem phuong tien theo bien so     *\n";
            cout << "* [4]. Xem lich su giao dich                 *\n";
            cout << "* [5]. Thong ke doanh thu chi tiet           *\n";
            cout << "* [6]. Xuat bao cao ra file (.csv)           *\n"; 
            cout << "* [0]. Thoat chuong trinh                    *\n";
            cout << "***********************************************\n";
            
            chon = nhapSoNguyen(" -> Moi ban nhap lua chon: ", 0, 6);
            if (chon == 0) break;

            switch (chon) {
                case 1: ql.xeVaoBai(); break;
                case 2: ql.xeRaBai(); break;
                case 3: ql.timKiemXe(); break;
                case 4: ql.hienThiLichSu(); break;
                case 5: ql.thongKeDoanhThu(); break;
                case 6: ql.xuatBaoCaoFile(); break;
            }
        } catch (const exception& e) { 
            cout << "\n[LOI HE THONG]: " << e.what() << endl; 
        }
        
        cout << "\nNhan Enter de tiep tuc..."; cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    return 0;
}
