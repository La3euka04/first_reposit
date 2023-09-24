#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // Подключение библиотеки stadio.h
#include "Department.h" // Подключение заголовочного файла Department.h

#define TYPEADD 2 //Создание константы TYPEADD равной 1

#if TYPEADD == 1 // Выполнение препроцессорного условного оператора условной компеляции 

int InputDeps(Department* dep) { // Создание функции, которая получает на вход указатель на массив структур, заполняет его структурами
	// и возвращает кол-во структур в массиве

	strcpy(dep[0].depName, "Сбер");
	dep[0].staff.qty = 1200000;
	strcpy(dep[0].staff.name, "Греф");
	dep[0].creationDate.year = 1879;
	dep[0].creationDate.month = 6;

	strcpy(dep[1].depName, "Газпром");
	dep[1].staff.qty = 1200000;
	strcpy(dep[1].staff.name, "Миллер");
	dep[1].creationDate.year = 1995;
	dep[1].creationDate.month = 5;

	strcpy(dep[2].depName, "Аэрофлот");
	dep[2].staff.qty = 450000;
	strcpy(dep[2].staff.name, "Гос-во");
	dep[2].creationDate.year = 1923;
	dep[2].creationDate.month = 3;

	strcpy(dep[3].depName, "Теремок");
	dep[3].staff.qty = 120000;
	strcpy(dep[3].staff.name, "Говор");
	dep[3].creationDate.year = 2022;
	dep[3].creationDate.month = 2;

	strcpy(dep[4].depName, "Листопад");
	dep[4].staff.qty = 45700;
	strcpy(dep[4].staff.name, "Иванов");
	dep[4].creationDate.year = 1979;
	dep[4].creationDate.month = 9;

	strcpy(dep[5].depName, "WG");
	dep[5].staff.qty = 20000;
	strcpy(dep[5].staff.name, "Кислый");
	dep[5].creationDate.year = 2010;
	dep[5].creationDate.month = 8;

	strcpy(dep[6].depName, "Apple");
	dep[6].staff.qty = 99000;
	strcpy(dep[6].staff.name, "Джобс");
	dep[6].creationDate.year = 2002;
	dep[6].creationDate.month = 7;

	strcpy(dep[7].depName, "Читинка");
	dep[7].staff.qty = 600000;
	strcpy(dep[7].staff.name, "Стрелков");
	dep[7].creationDate.year = 1961;
	dep[7].creationDate.month = 11;

	strcpy(dep[8].depName, "Лада");
	dep[8].staff.qty = 50000;
	strcpy(dep[8].staff.name, "Гуров");
	dep[8].creationDate.year = 1999;
	dep[8].creationDate.month = 1;

	strcpy(dep[9].depName, "Вишенка");
	dep[9].staff.qty = 344444;
	strcpy(dep[9].staff.name, "Шарин");
	dep[9].creationDate.year = 1845;
	dep[9].creationDate.month = 2;

	strcpy(dep[10].depName, "Гастроном");
	dep[10].staff.qty = 300000;
	strcpy(dep[10].staff.name, "Кристенсон");
	dep[10].creationDate.year = 2016;
	dep[10].creationDate.month = 12;

	strcpy(dep[11].depName, "Овощной");
	dep[11].staff.qty = 344444;
	strcpy(dep[11].staff.name, "Панков");
	dep[11].creationDate.year = 1995;
	dep[11].creationDate.month = 10;

	return 12; // Всего 12 структур заполнено, поэтому возвращается число 12  
} 
	


#elif TYPEADD == 2 // Выполнение проверки для условной компеляции 

int InputDeps(Department* dep) { // Создание функции для заполнения массива структур вручную
	int len; // Создание переменной len, для длины длины массива
	printf("Введите количство отделов не больше 20: ");
	scanf("%d", &len); // Ввести количество отделов 
	if (len > 20) { // Проверка len > 20?
		printf("ВЫ ВВЕЛИ НЕПРАВИЛЬНУЮ ДЛИНУ, БУДЕМ СЧИТАТЬ, ДЛИНА РАВНА 20\n");
		len = 20; 
	}
	for (int i = 0; i < len; i++){ // Создание цикла для заполнения данных об отделе 
		printf("Департамент номер %d:\n", i+1);
		scanDepartment(&(dep[i])); // Вызов функции scanDepartment, которая обьясняется в файле Department.c заполнения одной структуры
		printf("\n"); // Перейти на новую строку
	}
	return len; // Возвращение количества отделов
}



#endif


int main() { // Начало работы основной функции
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int length; // Переменная для количества структур
	int year; // Переменная для года
	int month; // Переменная для месяца
	int k = 0; // Создание переменной необходимой для запоминания кол-ва структур с одинаковым кол-вом человек
	int gooddep[20]; // Создание масива для запоминания индексов с одинаковым числом сотрудников

	Department deps[20]; // Создание массива структур
	length = InputDeps(deps); // Вызов функции InputDeps, которая возвращает кол-во отделов, и заполняет массив структур
	for (int i = 0; i < length; i++) { // Создание цикла for для вывода элементов массива, т.е. структур
		printf("/*****************/\n");
		printDepartment(deps[i]); // Печать стуктуры
	}
	printf("/**************************/\n"); 
	printf("Введите месяц содания: ");
	scanf("%d", &month); // Считывание месяца
	printf("Введите год содания: ");
	scanf("%d", &year); // Считывание года

	int qty = -32000; // Переменная для сравнения количества сотрудников
	int index = -1; // Переменная для последующей проверки наличия подходящих структур

	for (int i = 0; i < length; i++) { // Создание цикла для поиска отдела с самым большим кол-вом сотрудников
		if ((deps[i].creationDate.year > year) ||
			((deps[i].creationDate.year == year) && (deps[i].creationDate.month > month))) { // Выполнение проверки 
			if (deps[i].staff.qty > qty) { // Проверки на наибольшее кол-во сотрудников
				qty = deps[i].staff.qty; // Присваивание кол-ва сотрудников переменной qty
				index = i; // Запоминание индекса наибольшего отдела

			}
		}
	}

	if (index == -1) { // Проверка на наличие подходящих отделов
		printf("!!!!!!В списке отделов нету отдела с датой создания больше, чем %d месяц и %d год!!!!!!", month, year);
	}
	else {
		for (int i = 0; i < length; i++) {
			if ((deps[i].creationDate.year > year) ||
				((deps[i].creationDate.year == year) && (deps[i].creationDate.month > month))) { // Выполнение проверки 
				if (deps[i].staff.qty == qty) { // Проверки на одинаковое кол-во сотрудников
					gooddep[k] = i; // Сохранение индекса стркутуры с одинкаовым кол-вом сотрудников 
					k++; // По сути отвечает за кол-во совпадающих по кол-ву человек отделов
				}
			}
		}
		if (k == 1) { // Выпонение проверки на кол-во одинковых отделв по кол-ву сотрудников 
			printf("\n\nСамым большим отделом является:\n");
			printDepartment(deps[index]); // Напечатать отдел при помощи функции printDepartment, 
			//которая обьясняется в файе  Department.c 
		}
		else { // Иначе
			printf("\n\nСамыми большими отделами являются:\n");
				for (int i = 0; i < k; i++) {
					int p = gooddep[i];
					printDepartment(deps[p]); // Печать структур при помощи функции printDepartment, 
					//которая обьясняется в файе Department.c 
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
	return 0; // Окончание работы программы
}