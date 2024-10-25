﻿//Для чего нужна программа

/* 
Программа нужна для добавление машин на парковку и храния такаих данных как:
1.номер машины.
2.парковочное место.
3.время приезда-выезда.
4.общее время проведенное на парковке.
5.Историю посещений парковки.
*/

//Сколько и которых классов и других обьектов будет использовано в проекте.
/* 
Run class, для поддержания правильного написания main функции

Car class, в который будет входить Номер машины, парковочное место, время приезда либо выезда которые будет работать по специфике она на парковке тогда вьезд если нет выезд.
    Так же, общее время на парковке для подсчёта валюты которую должен заплатить водитель при ее выезде.
    Последним полем в классе будет поле(масив) историй вьездов выездов которые будут хранится в этом классе, то что будет хранить
    
Class HashTable класс таблица для хранения и поисков машин по их номерам.

Class command класс в котором будет использоватся функция для распределения последующиг шагов программы после ввода.
    Класс должен распределять и парсить информацию. 
    Примеры:    + HB1730AB - добавить машину в базу.
                - HB1730AB - выставить счёт за использование парковки и показать время использование парковки, так же не удалять дату предыдущих и текущих вьездов\выездов этой машины
                S HB1730AB - показать всю информацию о машине включая все вьезды и выезды.             
                Del HB1730AB - удалить всю дату об данной машине по запросу владельца, так же ввести подстверждение перед удалением.
                -help - Вывести список всех комманд с примерами для текущего пользователя.
                -list - Вывести список всех авто которые есть в базе.
                -Flash - Удалить все данные которые есть в базе.
                -Slost - Показать сколько осталось парковочных мест.
                Fee 10H - показать оплату сколько будет стоить пребывание на парковке за 10 часов.
                -//- Extra
                SCS(Special Car Spot) для грузовых машин нужно брать специльные места на парковке которые будут оплачится по повышеной цене
                + SCS HH7234AB - Добавить шину на специальное парковочное место.
                
               
*/

#include <iostream>
#include "MyCmd.h"
#include "iostream"
#include "Hashtable.h"
#include "Car.h"
using namespace std;

int main()
{   
    //cout << MyCmd::parse("+ ASD");
    
    Hashtable<Car *> hashtable;

    //cout << hashtable.hashfunc("AD1337AD") << endl;
    Car* a = new Car("AD1231AD",0,3);
    cout << hashtable.add(a->plate, a) << endl;
    cout << hashtable.add(a->plate, a) << endl;

    cout << hashtable.getN(1)->plate << endl;
    cout << hashtable.getN(2)->plate << endl;

 

}

