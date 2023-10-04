#include <iostream>
#include <string>    // для работы с классом строк
#include <compare>   // для сравнения строк
#include <stdexcept> // для invalid_argument
#include "Resource/Resource.h"
#include "Handlers/Handlers.h"

namespace RNS {
    Resource::Resource(){
        name = std::string("Empty");
        price = 0.0;
        daily_consumption = 0.0;
        daily_production = 0.0;
    }

    Resource::Resource(std::string n, double np, double dc, double dp) : 
        name(n), price(np), daily_consumption(dc) , daily_production(dp) {};

    // добавление
    Resource &Resource::add(const Resource &r){
        setName(r.getName());
        setDP(this->daily_production  + r.getDP());
        setDC(this->daily_consumption + r.getDC());
        setPrice(std::min(this->price, r.getPrice()));
        return *this;
    }
    
    // вывод
    std::ostream & Resource::print(std::ostream &stream) const {
        stream << getName() << " | " << getDC() << " | " << getDP() << " | " << getPrice() << std::endl;
        return stream;
    }
    
    // сравнение (==)
    bool Resource::compare_equal(const Resource &r){
        double eps = 0.000001;
        if (getName().compare(r.getName()) == 0){
            if (std::abs(getDC() - r.getDC()) < eps){
                if (std::abs(getDP() - r.getDP()) < eps){
                    if (std::abs(getPrice() - r.getPrice()) < eps)
                        return true;
                }
            }
            return false;
        }
        else
            return false;
    }
    
    // сравнение (<)
    bool Resource::compare_less(const Resource &r){
        double eps = 0.00001;
        int name_comparison = getName().compare(r.getName());
        if (name_comparison == 0){  // ресурсы одинакового типа 
            double dc1 = getDC();
            double dc2 = r.getDC();
            if (std::abs(dc1 - dc2) < eps){
                double dp1 = getDP();
                double dp2 = r.getDP();
                if (std::abs(dp1 - dp2) < eps){
                    double price1 = getPrice();
                    double price2 = r.getPrice();
                    if (std::abs(price1 - price2) < eps)
                        return false;
                    else
                        return (price1 < price2) ? true : false;
                }
                else
                    return (dp1 < dp2) ? true : false;    
            }
            else
                return (dc1 < dc2) ? true : false;
        }
        else 
            return (name_comparison < 0) ? true : false;
    }

    // сеттеры (мутаторы), возвращают ссылку для создания цепных функций
    Resource &Resource::setName(std::string new_name){ 
        name = new_name; 
        return *this;
    }
    Resource &Resource::setDC(double dc){
        if (dc < 0.0)
            throw std::invalid_argument("invalid <daily consumption>! (must be >= 0)");
        daily_consumption = dc;
        return *this; 
    }
    Resource &Resource::setDP(double dp){
        if (dp < 0.0)
            throw std::invalid_argument("invalid <daily production>! (must be >= 0)");
        daily_production = dp;  
        return *this;    
    }
    Resource &Resource::setPrice(double pr){
        if (price < 0.0)
            throw std::invalid_argument("invalid <price>! (must be >= 0)");
        price = pr; 
        return *this;
    }
    // (*) увеличение оборота
    Resource &Resource::incTurnover(double multiplier){ 
        if (multiplier < 0.0)
            throw std::invalid_argument("invalid <multiplier>! (must be >= 0)");
        daily_consumption *= multiplier; 
        daily_production  *= multiplier;
        return *this;
    }

    // ======================== [ПЕРЕГРУЗКА ОПЕРАТОРОВ] ========================
    Resource &Resource::operator + (const Resource &r){
        add(r);
        return *this;
    }
    Resource &Resource::operator * (double multiplier){
        incTurnover(multiplier);
        return *this;
    }
    std::ostream &operator << (std::ostream &stream, const Resource &r){
        r.print(stream);
        return stream;
    }
    std::istream &operator >> (std::istream &stream, Resource &r){
        std::string str = Handler::getString(stream);
        if (stream.good()){
            if (str != "")
                r.setName(str);
            else
                stream.setstate(std::ios::failbit);
        }

        double dc = Handler::getDouble(stream, 0.0);
        if (stream.good()){
            if (dc)
                r.setDC(dc);
            else
                stream.setstate(std::ios::failbit);
        }

        double dp = Handler::getDouble(stream, 0.0);
        if (stream.good()){
            if (dp)
                r.setDP(dp);
            else
                stream.setstate(std::ios::failbit);
        }

        double price = Handler::getDouble(stream, 0.0);
        if (stream.good()){
            if (price)
                r.setPrice(price);           
            else
                stream.setstate(std::ios::failbit);
        }
        return stream;
    }
}