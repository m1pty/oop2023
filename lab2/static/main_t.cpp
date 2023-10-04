#include <iostream>
#include "Table/Table.h"
#include "Resource/Resource.h"
#include "Handlers/Handlers.h"
#include "RDialogue/RDialogue.h"
#include "TDialogue/TDialogue.h"

int main(){
    TNS::Table table{};
    TNS::Table &link = table;
    try {
        dialogueT::tableMenuD(link);
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