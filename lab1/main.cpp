#include <bits/stdc++.h>
#include "matrix.h"

using namespace Matr;
using namespace Dialog;

int main(){
    Matrix matrix;
    try {
        matrix = Input();
        Permutating(matrix);
        Output(matrix);
    }
    // ошибки выделения памяти
    catch (std::bad_alloc &ba){
        std::cerr << "[ERROR]: Недостаточно памяти!" << std::endl;
        DelMatrix(matrix);
        return 1;
    }
    // все runtime-ошибки
    catch(std::runtime_error &rt){
        DelMatrix(matrix);
        return 1;
    }
    // прочие исключения
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
        DelMatrix(matrix);
        return 1;
    }
    return 0;
}