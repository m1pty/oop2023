#ifndef TDIALOG_DYNAMIC_H
#define TDIALOG_DYNAMIC_H
#include "TableDynamic/Table.h"

namespace dialogueT {
    /*!
        @brief Runs a user menu for Table interaction
        @param t A link to the Table
    */
    void tableMenuD ( TNS::Table & );
    
    /*!
        @brief Allows to make an input of the Table
        @param t A link to the Table
    */
    void tableInputD ( TNS::Table & );
    
    /*!
        @brief Allows to print Table
        @param t A link to the Table
    */
    void tablePrintD ( TNS::Table & ) noexcept ;
    
    /*!
        @brief Allows to add a Resource to the Table
        @param t A link to the Table
    */
    void tableAddResD(TNS::Table &t);
    
    /*!
        @brief Allows to get a Table of Resources by name of Resource type
        @param t A link to the table
    */
    void tableGetResD(TNS::Table &t);
    
    /*!
        @brief Allows to rename type of Resource, contained in Table
        @param t A link to the Table
    */
    void tableRenameResD(TNS::Table &t);
    
    /*!
        @brief Allows to change the Resource in Table by it's own menu
        @param t A link to the table
    */
    void tableChangeResD(TNS::Table &t); // функция для взаимодействия с меню ресурса
    
    /*!
        @brief Allows to get the profit of all Resources in Table
        @param t A link to the Table
    */
    void tableGetProfitD(TNS::Table &t) noexcept;
    
    /*!
        @brief Allows to delete Table's Resources entries by name of Resource
        @param t A link to the Table
    */
    void tableDelResNameD (TNS::Table &t);
    
    /*!
        @brief Allows to delete Table's Resource entry by it's index
        @param t A link to the Table
    */
    void tableDelResIndexD(TNS::Table &t);
    
    /*!
        @brief Allows to increase turnover of all the Table's Resources
        @param t A link to the Table
    */
    void tableIncTurnoverD(TNS::Table &t);
}

#endif