#include <iostream>
#include <limits>
#include <cstring>
#include <cerrno>

#include "Handlers/Handlers.h"


namespace Handler {
    // функция ввода числа с плавющей запятой с проверками
    double getDouble(double min, double max){
        double number;
        while (true){
            std::cin >> number;
            if (std::cin.eof())
                throw std::runtime_error("[ERROR]: Обнаружен конец файла");

            else if (std::cin.bad()) // невосстановимая ошибка
                throw std::runtime_error(std::string("[ERROR]: Невосстановимая шибка типа: ") + std::strerror(errno));
            
            else if (std::cin.fail()){ // восстановимая ошибка (откат до стабильного состояния)
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Вы сделали что-то неверно, повторите ввод!" << std::endl << PROMPT;
            }
            else {
                if ((max >= number) && (number >= min))
                    return number;
                
                // число корректно в рамках запрашиваемого типа, но не входит в заданный диапазон
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Введённое число не попадает в диапазон, повторите ввод!" << std::endl << PROMPT;
            }
        }
    }

    // функция ввода целого числа с проверками
    int getInt(int min, int max){
        int number;
        while (true){
            std::cin >> number;
            if (std::cin.eof())
                throw std::runtime_error("[ERROR]: Обнаружен конец файла");

            else if (std::cin.bad()) // невосстановимая ошибка
                throw std::runtime_error(std::string("[ERROR]: Невосстановимая шибка типа: ") + std::strerror(errno));
            
            else if (std::cin.fail()){ // восстановимая ошибка (откат до стабильного состояния)
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Вы сделали что-то неверно, повторите ввод!" << std::endl << PROMPT;
            }
            else {
                if ((max >= number) && (number >= min))
                    return number;
                
                // число корректно в рамках запрашиваемого типа, но не входит в заданный диапазон
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Введённое число не попадает в диапазон, повторите ввод!" << std::endl << PROMPT;
            }
        }
    }

    // функция ввода строки с проверками
    std::string getString(){
        std::string label;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, label, '\n');
        if (std::cin.eof())
            throw std::runtime_error("[ERROR]: Обнаружен конец файла");

        else if (std::cin.bad()) // невосстановимая ошибка
            throw std::runtime_error(std::string("[ERROR]: Невосстановимая шибка типа: ") + strerror(errno));
            
        else if (std::cin.fail()){ // восстановимая ошибка (откат до стабильного состояния)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[WARNING]: Вы сделали что-то неверно, повторите ввод!" << std::endl << PROMPT;
        }
        return label;
    }
}