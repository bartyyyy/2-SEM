#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

void show(Stack* myStk)    //����� �����
{
	//Stack* e = ;    //����������� ��������� �� ������� �����
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

void function(Stack*& myStk) {
	Stack* reversedStack = nullptr;
	Stack* current = myStk;

	// �������������� ����
	while (current != nullptr) {
		Stack* next = current->next;
		current->next = reversedStack;
		reversedStack = current;
		current = next;
	}

	// ���� � ������� ������ ����� ������ 100
	Stack* prev = nullptr;
	current = reversedStack;
	while (current != nullptr) {
		if (current->data > 100) {
			if (prev == nullptr) { // ���� ������ ������� ������ 100
				reversedStack = current->next;
			}
			else {
				prev->next = current->next;
			}
			cout << "����� " << current->data << " �������" << endl;
			delete current;
			break;
		}
		prev = current;
		current = current->next;
	}

	// ��������������� �������� ������� �����
	myStk = nullptr;
	while (reversedStack != nullptr) {
		Stack* next = reversedStack->next;
		reversedStack->next = myStk;
		myStk = reversedStack;
		reversedStack = next;
	}

	if (current == nullptr) {
		cout << "� ����� ��� ����� ������ 100" << endl;
	}
}