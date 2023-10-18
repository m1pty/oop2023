#ifndef RDIALOG_DYNAMIC_H
#define RDIALOG_DYNAMIC_H
#include "ResourceDynamic/Resource.h"

namespace dialogR {
    void menuD(RNS::Resource &r);        // главное меню интерфейса

    void inputD(RNS::Resource &r); // 
    void addD(RNS::Resource &r);         // 
    void printD(RNS::Resource &r);       // вывод 
    void compareD(RNS::Resource &r);     // 
    void incTurnoverD(RNS::Resource &r); // увеличение оборота
    void getProfitD(RNS::Resource &r);
    
    // сеттеры
    void setNameD(RNS::Resource &r);
    void setDCD(RNS::Resource &r);
    void setDPD(RNS::Resource &r);
    void setPriceD(RNS::Resource &r);
}
#endif