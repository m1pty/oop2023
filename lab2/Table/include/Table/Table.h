#ifndef TABLE_H
#define TABLE_H
#include "Resource/Resource.h"

namespace TNS {
    enum class Fullness{full, partly_full, empty};
    // класс таблицы
    class ResourceTable {
    private:
        static const int msize = 10;
        RNS::Resource table_vector[msize];
        int csize = 0;

    public:
        Fullness is_full();
        // -создание экземпляров класса с инициализацией заданным количеством ресурсов из массива ресурсов;
        // -(+=) добавление нового ресурса в таблицу;
        // -([]) получение ресурса по его наименованию (при помощи двоичного поиска; 
        // возврат по ссылке);
        // -проверка состояния таблицы (пустая, частично заполнена или полная);
        // -удаление ресурса с заданным наименованием из таблицы;
        // -вычисление общей прибыльности по всем ресурсам;
        // -(*) увеличение оборота всех ресурсов в заданное число раз;
        // -переименование заданного ресурса (передаются старое и новое наименования).

        void add(const RNS::Resource &r);   // добавление ресурса в таблицу
        int searchByName(std::string name); // поиск по имени
        RNS::Resource &getByName(std::string name); // после успешного поиска - изъятие по ссылке
        std::string checkFullness();

    };
}

#endif