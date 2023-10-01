#include <bits/stdc++.h>
#include "matrix.h"
#include "handlers.h"

namespace Matr {

    Item* FillItem(int x, int y, double value){
        Item* item = new Item{x, y, value, nullptr};
        return item;
    }
    Matrix GetNewMatrix(int n, int m){
        List* list = new List{nullptr, nullptr};
        Matrix matrix{n, m, list};
        return matrix;
    }
    Matrix Input(){
        Matrix matrix;
        double number{0.0};
        try {
            int n{Handler::GetNumber<int>()};
            int m{Handler::GetNumber<int>()};

            std::cout << "[MSG]: Размер матрицы: " << n << " на " << m << std::endl;
            Matrix matrix = GetNewMatrix(n, m);
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    number = Handler::GetNumber<double>();
                    if ((number > 0.0) || (number < 0.0)){
                        Item* item = new Item{j, i, number, nullptr};
                        // вставка
                        if ((matrix.list)->first == nullptr){
                            (matrix.list)->first = item;
                            (matrix.list)->last  = item;
                        }
                        else {
                            (matrix.list)->last->next = item;
                            (matrix.list)->last = item;
                        }
                    }
                }
            }

        // любое исключение 
        } catch (...){ 
            DelMatrix(matrix);
            throw;
        }
        return matrix;
    }

    // очистка памяти под матрицу
    void DelMatrix(Matrix &matrix){
        Item *ptr = (matrix.list)->first, *collector = nullptr;
        while (ptr != nullptr){
            collector = ptr;
            ptr = ptr->next;
            delete collector;
        }
        (matrix.list)->first = nullptr; 
        (matrix.list)->last  = nullptr;
        delete matrix.list;
    }

    void Permutating(Matrix &matrix){
        int a;
    }

    // вывод матрицы
    void Output(Matrix &matrix){
        int counter{0};
        int coord_y{0}, coord_x{0};
        Item* current{(matrix.list)->first};
        while (counter <= matrix.m * matrix.n){
            coord_y = counter / matrix.n;
            coord_x = counter % matrix.m;
            
            if (coord_x == 0)
                std::cout << std::endl;

            // если остался ненулевой элемент
            if (current != nullptr){
                if ((current->y == coord_y) && (current->x == coord_x)){
                    std::cout << current->value;
                    current = current->next;
                }
                else {
                    std::cout << "0 ";
                }
            }
            else {
                std::cout << "0 ";
            }
            counter += 1;
        }
        current = nullptr;
    }
}