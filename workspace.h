#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "logicCore.h"
#include "logicgateitem.h"

class MoHinhBaiXe {
private:
    vector<PhuongTien*> danhSach;
    BoLuuTru<ThongTinLichSu> dsLichSu; 
    const int SUC_CHUA;
    double doanhThu;
    int tongXeDaVao;

public:
    MoHinhBaiXe(int sc);
    ~MoHinhBaiXe();

    void xeVaoBai();
    void xeRaBai();
    void hienThiTrangThai() const;
    void timKiemXe() const;
    void hienThiLichSu() const;
    void thongKeDoanhThu() const;
    void xuatBaoCaoFile() const;
};

#endif // WORKSPACE_H
