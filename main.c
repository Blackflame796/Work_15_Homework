#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define EMPLOYEES 10
#define MONTHS 12
#define MIN_SALARY 30000
#define MAX_SALARY 150000

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    
    int salaries[EMPLOYEES][MONTHS];
    double averages[MONTHS];
    
    puts("Зарплаты сотрудников за год\n");
    
    for (int i = 0; i < EMPLOYEES; i++) {
        for (int j = 0; j < MONTHS; j++) {
            salaries[i][j] = rand() % (MAX_SALARY - MIN_SALARY + 1) + MIN_SALARY;
        }
    }
    
    printf("№  |     Январь     |      Февраль   |       Март     |     Апрель     |      Май       |      Июнь      |\n");
    printf("---|----------------|----------------|----------------|----------------|----------------|----------------|\n");
    for (int i = 0; i < EMPLOYEES; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < 6; j++) {
            printf(" %9d руб. |", salaries[i][j]);
        }
        printf("\n");
    }
    
    printf("\n№  |      Июль      |     Август     |    Сентябрь    |     Октябрь    |     Ноябрь     |     Декабрь    |\n");
    printf("---|----------------|----------------|----------------|----------------|----------------|----------------|\n");
    for (int i = 0; i < EMPLOYEES; i++) {
        printf("%2d |", i + 1);
        for (int j = 6; j < MONTHS; j++) {
            printf(" %9d руб. |", salaries[i][j]);
        }
        printf("\n");
    }
    
    for (int month = 0; month < MONTHS; month++) {
        int sum = 0;
        for (int emp = 0; emp < EMPLOYEES; emp++) {
            sum += salaries[emp][month];
        }
        averages[month] = (double)sum / EMPLOYEES;
    }
    
    printf("\nСредняя зарплата по месяцам:\n\n");
    
    printf("%-16s| %s\n", "Месяц", "Средняя зарплата");
    printf("-----------|--------------------\n");
    
    printf("%-17s| %14.2f руб.\n", "Январь", averages[0]);
    printf("%-18s| %14.2f руб.\n", "Февраль", averages[1]);
    printf("%-15s| %14.2f руб.\n", "Март", averages[2]);
    printf("%-17s| %14.2f руб.\n", "Апрель", averages[3]);
    printf("%-14s| %14.2f руб.\n", "Май", averages[4]);
    printf("%-15s| %14.2f руб.\n", "Июнь", averages[5]);
    printf("%-15s| %14.2f руб.\n", "Июль", averages[6]);
    printf("%-17s| %14.2f руб.\n", "Август", averages[7]);
    printf("%-19s| %14.2f руб.\n", "Сентябрь", averages[8]);
    printf("%-18s| %14.2f руб.\n", "Октябрь", averages[9]);
    printf("%-17s| %14.2f руб.\n", "Ноябрь", averages[10]);
    printf("%-18s| %14.2f руб.\n", "Декабрь", averages[11]);
    
    return 0;
}