#ifndef LOGICGATEITEM_H
#define LOGICGATEITEM_H

#include "logicCore.h"

class PhuongTien {
protected:
    string bienSo, loaiXe, chuXe;
    time_t timestampVao;
public:
    virtual ~PhuongTien() {}
    virtual void nhap();
    virtual void xuat(int stt) const;
    virtual double tinhTien(time_t ra) const = 0;
    
    string getBienSo() const { return bienSo; }
    string getLoai() const { return loaiXe; }
    string getChuXe() const { return chuXe; }
    time_t getVao() const { return timestampVao; }
};

struct BoTimKiemBienSo {
    string bsCanTim;
    BoTimKiemBienSo(const string& target) : bsCanTim(target) {}
    bool operator()(const PhuongTien* x) const {
        return x->getBienSo() == bsCanTim;
    }
};

class XeSo : public PhuongTien {
public:
    XeSo() { loaiXe = "Xe May (So)"; }
    double tinhTien(time_t ra) const override;
};

class XeGa : public PhuongTien {
public:
    XeGa() { loaiXe = "Xe May (Ga)"; }
    double tinhTien(time_t ra) const override;
};

class OTo : public PhuongTien {
public:
    OTo() { loaiXe = "Xe O To"; }
    double tinhTien(time_t ra) const override;
};

class XeTai : public PhuongTien {
public:
    XeTai() { loaiXe = "Xe Tai"; }
    double tinhTien(time_t ra) const override;
};

class XeDap : public PhuongTien {
public:
    XeDap() { loaiXe = "Xe Dap"; }
    double tinhTien(time_t ra) const override;
};

#endif // LOGICGATEITEM_H
