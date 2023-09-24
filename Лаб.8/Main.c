#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // ����������� ���������� stadio.h
#include "Department.h" // ����������� ������������� ����� Department.h

#define TYPEADD 2 //�������� ��������� TYPEADD ������ 1

#if TYPEADD == 1 // ���������� ���������������� ��������� ��������� �������� ���������� 

int InputDeps(Department* dep) { // �������� �������, ������� �������� �� ���� ��������� �� ������ ��������, ��������� ��� �����������
	// � ���������� ���-�� �������� � �������

	strcpy(dep[0].depName, "����");
	dep[0].staff.qty = 1200000;
	strcpy(dep[0].staff.name, "����");
	dep[0].creationDate.year = 1879;
	dep[0].creationDate.month = 6;

	strcpy(dep[1].depName, "�������");
	dep[1].staff.qty = 1200000;
	strcpy(dep[1].staff.name, "������");
	dep[1].creationDate.year = 1995;
	dep[1].creationDate.month = 5;

	strcpy(dep[2].depName, "��������");
	dep[2].staff.qty = 450000;
	strcpy(dep[2].staff.name, "���-��");
	dep[2].creationDate.year = 1923;
	dep[2].creationDate.month = 3;

	strcpy(dep[3].depName, "�������");
	dep[3].staff.qty = 120000;
	strcpy(dep[3].staff.name, "�����");
	dep[3].creationDate.year = 2022;
	dep[3].creationDate.month = 2;

	strcpy(dep[4].depName, "��������");
	dep[4].staff.qty = 45700;
	strcpy(dep[4].staff.name, "������");
	dep[4].creationDate.year = 1979;
	dep[4].creationDate.month = 9;

	strcpy(dep[5].depName, "WG");
	dep[5].staff.qty = 20000;
	strcpy(dep[5].staff.name, "������");
	dep[5].creationDate.year = 2010;
	dep[5].creationDate.month = 8;

	strcpy(dep[6].depName, "Apple");
	dep[6].staff.qty = 99000;
	strcpy(dep[6].staff.name, "�����");
	dep[6].creationDate.year = 2002;
	dep[6].creationDate.month = 7;

	strcpy(dep[7].depName, "�������");
	dep[7].staff.qty = 600000;
	strcpy(dep[7].staff.name, "��������");
	dep[7].creationDate.year = 1961;
	dep[7].creationDate.month = 11;

	strcpy(dep[8].depName, "����");
	dep[8].staff.qty = 50000;
	strcpy(dep[8].staff.name, "�����");
	dep[8].creationDate.year = 1999;
	dep[8].creationDate.month = 1;

	strcpy(dep[9].depName, "�������");
	dep[9].staff.qty = 344444;
	strcpy(dep[9].staff.name, "�����");
	dep[9].creationDate.year = 1845;
	dep[9].creationDate.month = 2;

	strcpy(dep[10].depName, "���������");
	dep[10].staff.qty = 300000;
	strcpy(dep[10].staff.name, "����������");
	dep[10].creationDate.year = 2016;
	dep[10].creationDate.month = 12;

	strcpy(dep[11].depName, "�������");
	dep[11].staff.qty = 344444;
	strcpy(dep[11].staff.name, "������");
	dep[11].creationDate.year = 1995;
	dep[11].creationDate.month = 10;

	return 12; // ����� 12 �������� ���������, ������� ������������ ����� 12  
} 
	


#elif TYPEADD == 2 // ���������� �������� ��� �������� ���������� 

int InputDeps(Department* dep) { // �������� ������� ��� ���������� ������� �������� �������
	int len; // �������� ���������� len, ��� ����� ����� �������
	printf("������� ��������� ������� �� ������ 20: ");
	scanf("%d", &len); // ������ ���������� ������� 
	if (len > 20) { // �������� len > 20?
		printf("�� ����� ������������ �����, ����� �������, ����� ����� 20\n");
		len = 20; 
	}
	for (int i = 0; i < len; i++){ // �������� ����� ��� ���������� ������ �� ������ 
		printf("����������� ����� %d:\n", i+1);
		scanDepartment(&(dep[i])); // ����� ������� scanDepartment, ������� ����������� � ����� Department.c ���������� ����� ���������
		printf("\n"); // ������� �� ����� ������
	}
	return len; // ����������� ���������� �������
}



#endif


int main() { // ������ ������ �������� �������
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int length; // ���������� ��� ���������� ��������
	int year; // ���������� ��� ����
	int month; // ���������� ��� ������
	int k = 0; // �������� ���������� ����������� ��� ����������� ���-�� �������� � ���������� ���-��� �������
	int gooddep[20]; // �������� ������ ��� ����������� �������� � ���������� ������ �����������

	Department deps[20]; // �������� ������� ��������
	length = InputDeps(deps); // ����� ������� InputDeps, ������� ���������� ���-�� �������, � ��������� ������ ��������
	for (int i = 0; i < length; i++) { // �������� ����� for ��� ������ ��������� �������, �.�. ��������
		printf("/*****************/\n");
		printDepartment(deps[i]); // ������ ��������
	}
	printf("/**************************/\n"); 
	printf("������� ����� �������: ");
	scanf("%d", &month); // ���������� ������
	printf("������� ��� �������: ");
	scanf("%d", &year); // ���������� ����

	int qty = -32000; // ���������� ��� ��������� ���������� �����������
	int index = -1; // ���������� ��� ����������� �������� ������� ���������� ��������

	for (int i = 0; i < length; i++) { // �������� ����� ��� ������ ������ � ����� ������� ���-��� �����������
		if ((deps[i].creationDate.year > year) ||
			((deps[i].creationDate.year == year) && (deps[i].creationDate.month > month))) { // ���������� �������� 
			if (deps[i].staff.qty > qty) { // �������� �� ���������� ���-�� �����������
				qty = deps[i].staff.qty; // ������������ ���-�� ����������� ���������� qty
				index = i; // ����������� ������� ����������� ������

			}
		}
	}

	if (index == -1) { // �������� �� ������� ���������� �������
		printf("!!!!!!� ������ ������� ���� ������ � ����� �������� ������, ��� %d ����� � %d ���!!!!!!", month, year);
	}
	else {
		for (int i = 0; i < length; i++) {
			if ((deps[i].creationDate.year > year) ||
				((deps[i].creationDate.year == year) && (deps[i].creationDate.month > month))) { // ���������� �������� 
				if (deps[i].staff.qty == qty) { // �������� �� ���������� ���-�� �����������
					gooddep[k] = i; // ���������� ������� ��������� � ���������� ���-��� ����������� 
					k++; // �� ���� �������� �� ���-�� ����������� �� ���-�� ������� �������
				}
			}
		}
		if (k == 1) { // ��������� �������� �� ���-�� ��������� ������ �� ���-�� ����������� 
			printf("\n\n����� ������� ������� ��������:\n");
			printDepartment(deps[index]); // ���������� ����� ��� ������ ������� printDepartment, 
			//������� ����������� � ����  Department.c 
		}
		else { // �����
			printf("\n\n������ �������� �������� ��������:\n");
				for (int i = 0; i < k; i++) {
					int p = gooddep[i];
					printDepartment(deps[p]); // ������ �������� ��� ������ ������� printDepartment, 
					//������� ����������� � ���� Department.c 
				}
			}
		}
		printf("*******************");
		printf("Hello, world!!) git");
		printf("Hello, world!!) gitddddddd");
		//git remotec add origin https ://github.com/La3euka04/first_reposit.git
		//git remotec add origin https ://github.com/La3euka04/first_reposit.git
		//git remotec add origin https ://github.com/La3euka04/first_reposit.git
		//git remotec add origin https ://github.com/La3euka04/first_reposit.git
	return 0; // ��������� ������ ���������
}