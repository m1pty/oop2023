#ifndef TDIALOG_DYNAMIC_H
#define TDIALOG_DYNAMIC_H
#include "TableDynamic/Table.h"

namespace dialogueT {
    /*!
        @brief Runs a user menu for Table interaction
        @param t A link to the table
    */
    void tableMenuD ( TNS::Table & );
    
    /*!
        @brief Allows to make an input of the Table 
        @param t A link to the table
    */
    void tableInputD ( TNS::Table & );
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tablePrintD ( TNS::Table & );
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableAddResD(TNS::Table &t);
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableGetResD(TNS::Table &t);
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableRenameResD(TNS::Table &t);
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableChangeResD(TNS::Table &t); // функция для взаимодействия с меню ресурса
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableGetProfitD(TNS::Table &t);
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableDelResNameD (TNS::Table &t);
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableDelResIndexD(TNS::Table &t);
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableCheckStateD (TNS::Table &t);
    
    /*!
        @brief 
        @param t A link to the table
    */
    void tableIncTurnoverD(TNS::Table &t);
}

#endif