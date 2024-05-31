#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTELS 100
#define MAX_NAME 100
#define MAX_ADDRESS 100
#define MAX_PHONE 20

typedef struct {
    char name[MAX_NAME];
    int stars;
    char address[MAX_ADDRESS];
    char phone[MAX_PHONE];
    int rooms;
    int lux_rooms;
    int free_rooms;
} Hotel;

Hotel hotels[MAX_HOTELS];
int num_hotels = 0;

void add_hotel() {
    if (num_hotels < MAX_HOTELS) {
        printf("Введите наименование гостиницы: ");
        scanf("%s", hotels[num_hotels].name);

        printf("Введите количество звезд: ");
        scanf("%d", &hotels[num_hotels].stars);

        printf("Введите адрес гостиницы: ");
        scanf("%s", hotels[num_hotels].address);

        printf("Введите телефон гостиницы: ");
        scanf("%s", hotels[num_hotels].phone);

        printf("Введите количество номеров: ");
        scanf("%d", &hotels[num_hotels].rooms);

        printf("Введите количество номеров люкс: ");
        scanf("%d", &hotels[num_hotels].lux_rooms);

        printf("Введите количество свободных номеров: ");
        scanf("%d", &hotels[num_hotels].free_rooms);

        num_hotels++;
    } else {
        printf("Список гостиниц полон!\n");
    }
}

void delete_hotel() {
    char name[MAX_NAME];
    printf("Введите наименование гостиницы для удаления: ");
    scanf("%s", name);

    for (int i = 0; i < num_hotels; i++) {
        if (strcmp(hotels[i].name, name) == 0) {
            for (int j = i; j < num_hotels - 1; j++) {
                hotels[j] = hotels[j + 1];
            }
            num_hotels--;
            return;
        }
    }
    printf("Гостиница не найдена!\n");
}

void view_hotels() {
    for (int i = 0; i < num_hotels; i++) {
        printf("Наименование: %s, Звезды: %d, Адрес: %s, Телефон: %s, Номеров: %d, Люкс: %d, Свободных: %d\n",
               hotels[i].name, hotels[i].stars, hotels[i].address, hotels[i].phone, hotels[i].rooms, hotels[i].lux_rooms, hotels[i].free_rooms);
    }
}

void best_hotel() {
    int max_free_rooms = 0;
    int best_index = -1;
    for (int i = 0; i < num_hotels; i++) {
        if (hotels[i].free_rooms > max_free_rooms) {
            max_free_rooms = hotels[i].free_rooms;
            best_index = i;
        }
    }
    if (best_index!= -1) {
        printf("Лучшая гостиница: %s с %d свободными номерами\n", hotels[best_index].name, hotels[best_index].free_rooms);
    } else {
        printf("Гостиницы не найдены!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Меню:\n");
        printf("1. Добавить гостиницу\n");
        printf("2. Удалить гостиницу\n");
        printf("3. Просмотреть список гостиниц\n");
        printf("4. Найти лучшую гостиницу\n");
        printf("5. Выход\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_hotel();
                break;
            case 2:
                delete_hotel();
                break;
            case 3:
                view_hotels();
                break;
            case 4:
                best_hotel();
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}