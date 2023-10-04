#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <cstring>

namespace RNS {
    // класс ресурса
    class Resource {
    private:
        std::string name;             // имя
        double price;                 // цена (у.е/кг)
        double daily_consumption;     // потребление (кг/д)
        double daily_production;      // производство (кг/д)

    public:
        ~Resource() = default;
        // конструктор: default + создание экземпляра класса с инициализацией (все параметры / имя, цена
        // explicit = не конструктор с копированием (copy-initialization)
        Resource();
        Resource(std::string name, double price = 0.0, double dc = 0.0, double dp = 0.0);
        // геттеры (акксессоры)
        /*!
            @returns the link to name of this
            Returns the link to name of the instance
        */
        const std::string &getName() const { return name; }
        /*!
            @returns the daily consumption of this
            Returns the daily consumption of the instance
        */
        const double &getDC() const { return daily_consumption; }
        /*!
            @returns the daily production of this
            Returns the daily production of the instance
        */
        const double &getDP() const { return daily_production;  }
        /*!
            @returns the price of this
            Returns the price of the instance
        */
        const double &getPrice() const { return price; }

        // сеттеры (мутаторы), возвращают ссылку для создания цепных функций
        /*!
            @param new_name The new name of the Resource instance
            @returns The link to the instance
            Sets a new name for an instance
        */
        Resource &setName(std::string new_name);
        /*!
            @param new_dc The new daily consumption of the Resource instance
            @returns The link to the instance
            Sets a new daily consumption for an instance
        */
        Resource &setDC(double new_dc);
        /*!
            @param new_dp The new daily production of the Resource instance
            @returns The link to the instance
            Sets a new daily production for an instance
        */
        Resource &setDP(double new_dp); 
        /*!
            @param new_price The new price of the Resource instance
            @returns The link to the instance
            Sets a new price for an instance
        */
        Resource &setPrice(double new_price);
        // (*) увеличение оборота
        /*!
            @param multiplier (>= 0.0) The multiplier of increase
            @returns The link to the instance
            Increases daily consumption and production in <multiplier> times 
        */
        Resource &incTurnover(double multiplier);

        // методы вывода
        /*!
            @brief Prints a formatted instance
            @param stream The stream of output
            @returns The link to the stream
        */
        std::ostream & print(std::ostream &) const; // вывод

         /*!
            @brief Allows to input an instance
            @param stream The stream of input
            @returns The link to the stream
        */
        std::istream & input(std::istream &);

        // методы задания
        /*!
            @param r The link for a Resource instance
            @returns The new Resource instance
            Adds two (this, r) Resource instances with equal names by adding their dc's & dp's and setting the minimal price
        */
        Resource &add(const Resource &r); // (+) объединение двух одинаковых ресурсов    (через this)
        
        /*!
            @param r The link for a Resource instance
            @returns Boolean answer
            Checks if this and r Resources are equal
        */
        bool compare_equal(const Resource &r); // (==) сравнение двух ресурсов по имени (через this)

        /*!
            @param r The link for a Resource instance
            @returns Boolean answer
            Checks if r is less than this Resources are equal
        */
        bool compare_less (const Resource &r); // (<)  сравнение двух ресурсов по имени (через this)

        // вычисление ориентировочной прибыльности в неделю
        /*!
            @returns The weekly profit (double)
            Returns the weekly profit of "this" resource
        */
        double getProfit(){ return (daily_production - daily_consumption) * price * 7; }

        // операторы (первый операнд через this)
        Resource &operator + (const Resource &r);
        Resource &operator * (double multiplier);
        
        friend std::ostream &operator << (std::ostream &stream, const Resource &r);
        friend std::istream &operator >> (std::istream &stream, Resource &r);
    };
}
#endif