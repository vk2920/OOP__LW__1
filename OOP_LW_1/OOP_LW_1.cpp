#define _CRT_SECURE_NO_WARNINGS

#define menu_items_count 19

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "Queue.h"

void list_item_data_print(list_item_data _data) {
    printf("Элемент: %s [%d]", _data.name, _data.protons_count);
}

int main()
{
    SetConsoleOutputCP(1251);
    const char* menu[menu_items_count] = {
        "Создать очередь",
        "Копировать очередь",
        "Добавить элемент в первую очередь",
        "Добавить элемент во вторую очередь",
        "Взять элемент из первой очереди",
        "Взять элемент из второй очереди",
        "Посмотреть элемент из первой очереди",
        "Посмотреть элемент из второй очереди",
        "Проверить первую очередь на одинаковые заряды",
        "Проверить вторую очередь на одинаковые заряды",
        "Просмотреть поля первого класса",
        "Просмотреть поля второго класса",
        "Изменить поле первого класса",
        "Изменить поле второго класса",
        "Очистить первую очередь",
        "Очистить вторую очередь",
        "Удалить первый класс",
        "Удалить второй класс",
        "Выйти из программы"
    };

    Queue* q1 = NULL, *q2 = NULL;

    short selected = 0;
    while ((selected = select_from_menu(menu, menu_items_count, menu_items_count-1)) != menu_items_count-1) {
        switch (selected) {
        case 0:  // Создать очередь
        {
            if (!q1) {
                q1 = new Queue();
                if (q1) printf("Очередь создана\n");
                else printf("Ошибка создания очереди\n");
            }
            else printf("Первая очередь уже существует, перед созданием новой первой очереди нужно удалить её\n");
            break;
        }
        case 1:  // Копировать очередь
        {
            if (!q2 && q1) {
                q2 = new Queue(*q1);
                if (q2) printf("Очередь скопирована");
                else printf("Ошибка создания второй очереди");
            }
            else printf("Очередь уже создана, нельзя добавить новую вторую очередь\n");
            break;
        }
        case 2:  // Добавить элемент в первую очередь
        {
            if (q1) {
                int pc1 = 0;
                char name1[30] = "";
                printf("Введите число протонов в ядре (заряд ядра): ");
                scanf("%d", &pc1);
                printf("Введите название элемента: ");
                scanf("%s", name1);
                if (q1->add_item(pc1, name1)) printf("Элемент добавлен в первую очередь\n");
                else printf("Ошибка добавления элемента\n");
            }
            break;
        }
        case 3:  // Добавить элемент во вторую очередь
        {
            if (q2) {
                int pc2 = 0;
                char name2[30] = "";
                printf("Введите число протонов в ядре (заряд ядра): ");
                scanf("%d", &pc2);
                printf("Введите название элемента: ");
                scanf("%s", name2);
                if (q2->add_item(pc2, name2)) printf("Элемент добавлен во вторую очередь\n");
                else printf("Ошибка добавления элемента\n");
            }
            break;
        }
        case 4:  // Взять элемент из первой очереди
        {
            if (q1) {
                list_item_data lid1 = q1->get_item(true);
                list_item_data_print(lid1);
            }
            break;
        }
        case 5:  // Взять элемент из второй очереди
        {
            if (q2) {
                list_item_data lid2 = q2->get_item(true);
                list_item_data_print(lid2);
            }
            break;
        }
        case 6:  // Посмотреть элемент из первой очереди
        {
            if (q1) {
                list_item_data lid1 = q1->get_item(false);
                list_item_data_print(lid1);
            }
            break;
        }
        case 7:  // Посмотреть элемент из второй очереди
        {
            if (q2) {
                list_item_data lid2 = q2->get_item(false);
                list_item_data_print(lid2);
            }
            break;
        }
        case 8:  // Проверить первую очередь на одинаковые заряды
        {
            if (q1) {
                if (q1->check_queue()) printf("Найдена как минимум одна пара в первой очереди\n");
                else printf("Нет ни одной пары повторов в первой очереди\n");
            }
            else printf("Нет первой очереди. Нечего проверять\n");
            break;
        }
        case 9:  // Проверить вторую очередь на одинаковые заряды
        {
            if (q2) {
                if (q2->check_queue()) printf("Найдена как минимум одна пара во второй очереди\n");
                else printf("Нет ни одной пары повторов во второй очереди\n");
            }
            else printf("Нет второй очереди. Нечего проверять\n");
            break;
        }
        case 10:  // Просмотреть поля первого класса
        {
            if (q1) q1->print_fields();
            break;
        }
        case 11:  // Просмотреть поля второго класса
        {
            if (q2) q2->print_fields();
            break;
        }
        case 12:  // Изменить поле первого класса
        {
            if (q1) {
                int d1 = 0;
                printf("Введите новое значение: ");
                scanf("%d", &d1);
                q1->set_editable_field(d1);
            }
            break;
        }
        case 13:  // Изменить поле второго класса
        {
            if (q2) {
                int d2 = 0;
                printf("Введите новое значение: ");
                scanf("%d", &d2);
                q2->set_editable_field(d2);
            }
            break;
        }
        case 14:  // Очистить первую очередь
        {
            if (q1) {
                if (q1->clear_items()) printf("Очередь первого класса очищена\n");
                else printf("Ошибка очистки очереди\n");
            }
            else printf("Нет первой очереди. Нечего очищать\n");
            break;
        }
        case 15:  // Очистить вторую очередь
        {
            if (q2) {
                if (q2->clear_items()) printf("Вторая очередь очищена успешно\n");
                else printf("Ошибка очистки второй очереди\n");
            }
            else printf("Нет второй очереди. Нечего очищать\n");
            break;
        }
        case 16:  // Удалить первый класс
        {
            if (q1) {
                delete q1;
                q1 = NULL;
                printf("Первый класс удалён\n");
            } 
            else printf("Нет первого класса. Нечего удалять\n");
            break;
        }
        case 17:  // Удалить второй класс
        {
            if (q2) {
                delete q2;
                q2 = NULL;
                printf("Второй класс удалён\n");
            }
            else printf("Нет второго класса. Нечего удалять\n");
            break;
        }
        }
        _getch();
    }
    return 0;
}
