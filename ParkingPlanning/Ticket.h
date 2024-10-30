﻿/*
Car class, в который будет входить Номер машины, парковочное место, время приезда либо выезда которые будет работать по специфике она на парковке тогда вьезд если нет выезд.
	Так же, общее время на парковке для подсчёта валюты которую должен заплатить водитель при ее выезде.
	Последним полем в классе будет поле(масив) историй вьездов выездов которые будут хранится в этом классе, то что будет хранить
*/
#pragma once
#include <string>

using namespace std;
class Ticket
{
public:
	string plate;
	unsigned int IOtime;
	string spot;
	int overalltime;

	Ticket();
	Ticket(string _plate, unsigned int _IOtime, string _spot);
};
