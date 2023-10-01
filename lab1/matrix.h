#ifndef MATRIX_H
#define MATRIX_H

namespace Matr {
    struct Item {
        int x, y;
        double value;
        Item* next;
    };

    struct List {
        Item* first;
        Item*  last;
    };

    struct Matrix {
        int n, m;
        List* list;
    };

    Item* FillItem(int x, int y, double value); // заполнение элемента
    Matrix GetNewMatrix(int n, int m);          //  [ ] выделение памяти под пустую матрицу
    Matrix Input();                             //  [ ] ввод матрицы
    void DelMatrix   ( Matrix& );               //  [ ] очищение памяти под матрицу
    void Permutating ( Matrix& );               //  [ ] задание, перестановка местами max и min
    void Output      ( Matrix& );               //  [?] вывод матрицы
}

namespace Dialog {
    void Menu();
    void NewMatrix();
}

#endif