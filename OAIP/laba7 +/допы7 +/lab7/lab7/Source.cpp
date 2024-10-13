#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

void show(Stack* myStk)    //����� �����
{
	int a;
	if (myStk == NULL)
		cout << "���� ����!" << endl;
	while (myStk != NULL)
	{
		a = myStk->data;          //������ �������� � ���������� a
		cout << a << " ";
		myStk = myStk->next;
	}
	cout << endl;
}

void push(int x, Stack*& myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� data 
	e->next = myStk;         //������� ������� �� ��������� ������� 
	myStk = e;               //����� ������� �� ������� ������
}

void toFile(Stack*& myStk) //������ � ����
{
	Stack* e = myStk;
	ofstream frm("file.txt");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (e)
	{
		frm << e->data << " ";
		e = e->next;
	}
	frm.close();
	cout << "���� ������� � ���� file.txt\n";
}

void fromFile(Stack*& myStk)          //���������� �� �����
{
	Stack* first = nullptr;
	ifstream frm("file.txt");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	int number;
	while (frm >> number)
	{
		push(number, first);
		cout << " " << number;
	}
	cout << endl;
	frm.close();
	myStk = first;
	cout << "\n������ ������ �� ����� file.txt\n";
}

int clear(Stack*& myStk)  //����� ����� � ��������
{
	if (myStk == NULL)
	{
		cout << "���� ����!" << endl;
		return 0;
	}
	else
	{
		while (myStk != NULL) {
			Stack* e = myStk;        //�-���������� ��� �������� ������ ��������
			int x = myStk->data;    //������ �������� �� ���� data � �����. x 
			if (myStk)
				myStk = myStk->next;   //������� �������
			cout << x << " ";
			delete e;
		}

	}
		
	cout << endl;
}

int function(Stack*& myStk) {
	int min, max;
	cout << "������� ������ ������ ��� ���������: ";
	cin >> min;
	cout << "������� ������� ������ ��� ���������: ";
	cin >> max;
	int k = 0;

	if (myStk == NULL)
	{
		cout << "���� ����!" << endl;
		return 0;
	}
	else
	{
		while (myStk != NULL) {
			Stack* e = myStk;        //�-���������� ��� �������� ������ ��������
			
			int x = myStk->data;    //������ �������� �� ���� data � �����. x 
			if (myStk) {
				if (x >= min && x <= max) {
					cout << "����� � �����, ������� � �������� ���������: " << x << endl;
					k++;
				}
				myStk = myStk->next;   //������� �������
			}
				
			delete e;
		}
		if (k == 0) {
			cout << "� ����� ��� �����, ������� � �������� ���������" << endl;
		}
	}

	cout << endl;
}