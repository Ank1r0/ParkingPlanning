﻿/*
Class command класс в котором будет использоватся функция для распределения последующиг шагов программы после ввода.
    Класс должен распределять и парсить информацию.
    Примеры:    + HB1730AB - добавить машину в базу.
                - HB1730AB - выставить счёт за использование парковки и показать время использование парковки, так же не удалять дату предыдущих и текущих вьездов\выездов этой машины
                S HB1730AB - показать всю информацию о машине включая все вьезды и выезды.
                Del HB1730AB - удалить всю дату об данной машине по запросу владельца, так же ввести подстверждение перед удалением.
                - help - Вывести список всех комманд с примерами для текущего пользователя.
                - list - Вывести список всех авто которые есть в базе.
                - clear - Удалить все данные которые есть в базе.
                - Slost - Показать сколько осталось парковочных мест.
                Fee 10H - показать оплату сколько будет стоить пребывание на парковке за 10 часов.
                -//- Extra
                SCS(Special Car Spot) для грузовых машин нужно брать специльные места на парковке которые будут оплачится по повышеной цене
                + SCS HH7234AB - Добавить шину на специальное парковочное место.
*/
#include "MyCmd.h"
#include "iostream"
#include "string"

using namespace std;



 string MyCmd::parse(std::string input)
{
    switch (input.at(0))
    {
    case '+':
       
        return "The car added to the parking.";

    case '-':
        return "The car removed from parking.";

    case 's':
        return "Car123.";

    case 'd':
        return "The car removed from the database.";

    case 'h':
        return "help";

    case 'l':
        return "list";

    case 'c':
        return "clear";

    case 'f':
        return "Fee 10$ for 10 days";
    default:
        break;
        return "";
    }
}


