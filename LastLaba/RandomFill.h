#pragma once
#include "TData.h"
#include "StringConverter.h"
using namespace System;
using namespace System::Net;
using namespace System::IO;


TData* RandData() {
	//������� ��� ������ �� ������ http://randus.ru/api.php
	WebResponse^ response = WebRequest::Create("http://randus.ru/api.php")->GetResponse();
	//���������������� ����� ������
	StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
	//��������� ��������� ��������
	String^ s = reader->ReadToEnd();
	//��������� ������ ����
	/*
	{"lname":"��������","fname":"�����","patronymic":"��������� ",
	"gender":"w","date":"6 ���� 1963","postcode":"607430","city":"������",
	"street":"������������","house":59,"apartment":201,"phone":"8-928-372-86-85",
	"login":"VasyutinaMlada129","password":"kXbGbK2Z6TCA","color":"����������",
	"userpic":"http://randus.ru/avatars/w/myAvatar21.png"}
	*/
	//����� ������ ������ ������
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
			address +="�. "+ temp[1] + ", ";
		}
		if (ResArr[i]->Contains("street"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address += "��. " + temp[1] + ", ";
		}
		if (ResArr[i]->Contains("house"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address += "��� " + temp[1] + ", ";
		}
		if (ResArr[i]->Contains("apartment"))
		{
			array<String^>^ temp = ResArr[i]->Split(':');
			address += "�������� " + temp[1];
		}
	}
	address = address->Replace("\"", "");
	TData* g = new TData(ToSTDstring(name), ToSTDstring(faml), ToSTDstring(otch), ToSTDstring(address));
	return g;
}