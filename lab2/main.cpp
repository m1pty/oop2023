#include <iostream>
#include "Resource/Resource.h"
#include "Handlers/Handlers.h"
#include "RDialogue/RDialogue.h"

int main(){
    std::string s(" ");
    RNS::Resource resource{s, 0.0, 0.0, 0.0};
    RNS::Resource &link = resource;
    try {
        dialogR::menuD(link);
    }
    // ошибки выделения памяти
    catch (std::bad_alloc &ba){
        std::cout << "[ERROR]: Недостаточно памяти!" << std::endl;
        return 1;
    }
    // все runtime-ошибки
    catch (std::runtime_error &rt){
        std::cout << "[ERROR]: Runtime-error!" << std::endl;
        return 1;
    }
    // прочие исключения
    catch (std::exception &e) {
        std::cout << "[ERROR]: Ошибка типа: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}