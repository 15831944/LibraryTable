#pragma once
#include "TData.h"
#include "StringConverter.h"
using namespace System;
using namespace System::Net;
using namespace System::IO;


TData* RandData() {
	//создать веб запрос по адресу http://randus.ru/api.php
	WebResponse^ response = WebRequest::Create("http://randus.ru/api.php")->GetResponse();
	//инициализировать поток чтения
	StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
	//прочитать полностью страницу
	String^ s = reader->ReadToEnd();
	//обработка строки типа
	/*
	{"lname":"Васютина","fname":"Млада","patronymic":"Романовна ",
	"gender":"w","date":"6 июля 1963","postcode":"607430","city":"Троицк",
	"street":"Бартеневская","house":59,"apartment":201,"phone":"8-928-372-86-85",
	"login":"VasyutinaMlada129","password":"kXbGbK2Z6TCA","color":"Фиолетовый",
	"userpic":"http://randus.ru/avatars/w/myAvatar21.png"}
	*/
	//берем только нужные данные
	array<String^>^ ResArr = s->Split(',');
	String^ name, ^faml, ^otch, ^address;
	for (int i = 0; i < ResArr->Length; i++)
	{
		if (ResArr[i]->Contains("fname"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			name = temp[1];
			name = name->Replace("\"", "");
		}
		if (ResArr[i]->Contains("patronymic"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			otch = temp[1];
			otch = otch->Replace("\"", "");
		}
		if (ResArr[i]->Contains("lname"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			faml = temp[1];
			faml = faml->Replace("\"", "");
		}
		if (ResArr[i]->Contains("postcode"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address += temp[1] + ", ";
		}
		if (ResArr[i]->Contains("city"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address +="г. "+ temp[1] + ", ";
		}
		if (ResArr[i]->Contains("street"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address += "ул. " + temp[1] + ", ";
		}
		if (ResArr[i]->Contains("house"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address += "дом " + temp[1] + ", ";
		}
		if (ResArr[i]->Contains("apartment"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address += "квартира " + temp[1];
		}
	}
	address = address->Replace("\"", "");
	TData* g = new TData(ToSTDstring(name), ToSTDstring(faml), ToSTDstring(otch), ToSTDstring(address));
	return g;
}