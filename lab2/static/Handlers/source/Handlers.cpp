#include <iostream>
#include <limits>
#include <cstring>
#include <cerrno>
#include <sstream>

#include "Handlers/Handlers.h"

namespace Handler {
    // функция ввода числа с плавющей запятой с проверками
    double getDouble(std::istream &stream, double min, double max){
        double number;
        while (true){
            stream >> number;
            if (stream.eof())
                throw std::runtime_error("[ERROR]: Обнаружен конец файла");

            else if (stream.bad()) // невосстановимая ошибка
                throw std::runtime_error(std::string("[ERROR]: Невосстановимая шибка типа: ") + std::strerror(errno));
            
            else if (stream.fail()){ // восстановимая ошибка (откат до стабильного состояния)
                stream.clear();
                stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Вы сделали что-то неверно, повторите ввод!" << std::endl << PROMPT;
            }
            else {
                if ((max >= number) && (number >= min))
                    return number;
                
                // число корректно в рамках запрашиваемого типа, но не входит в заданный диапазон
                stream.clear();
                stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Введённое число не попадает в диапазон, повторите ввод!" << std::endl << PROMPT;
            }
        }
    }

    // функция ввода целого числа с проверками
    int getInt(std::istream &stream, int min, int max){
        int number;
        while (true){
            stream >> number;
            if (stream.eof())
                throw std::runtime_error("[ERROR]: Обнаружен конец файла");

            else if (stream.bad()) // невосстановимая ошибка
                throw std::runtime_error(std::string("[ERROR]: Невосстановимая шибка типа: ") + std::strerror(errno));
            
            else if (stream.fail()){ // восстановимая ошибка (откат до стабильного состояния)
                stream.clear();
                stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Вы сделали что-то неверно, повторите ввод!" << std::endl << PROMPT;
            }
            else {
                if ((max >= number) && (number >= min))
                    return number;
                
                // число корректно в рамках запрашиваемого типа, но не входит в заданный диапазон
                stream.clear();
                stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Введённое число не попадает в диапазон, повторите ввод!" << std::endl << PROMPT;
            }
        }
    }

    // функция ввода строки с проверками
    std::string getString(std::istream &stream){
        std::string label;
        while (true)
        {
            std::getline(stream, label);
            std::cout << "[SYSTEM]: Got input of '" << label << "'\n";
            
            if (stream.eof())
                throw std::runtime_error("[ERROR]: Обнаружен конец файла");

            else if (stream.bad()) // невосстановимая ошибка
                throw std::runtime_error(std::string("[ERROR]: Невосстановимая шибка типа: ") + strerror(errno));
            
            else if (stream.fail()) // восстановимая ошибка (откат до стабильного состояния)
            { 
                stream.clear();
                stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Вы сделали что-то неверно, повторите ввод!" << std::endl << PROMPT;
            }
            
            else if (label.compare("") == 0)
            {
                std::cout << "[WARNING]: Вы ввели пустую строку, повторите ввод!" << std::endl << PROMPT;
            }
            
            else 
            {
                std::cout << "[SYSTEM]: Ввод успешен!\n";
                return label;
            }
        }
    }

    int countIntLength(int link){
        int answer = 1;
        while (std::abs(link) >= 10){
            ++answer;
            link /= 10;
        }
        return answer;
    }

    
}