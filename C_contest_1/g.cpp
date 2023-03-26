#include <stdlib.h>
#include <stdio.h>

struct Line
{
	int start;
	int finish;
};

void readLine  (struct Line * pa);          // читает отрезок
void printLine (struct Line a);             // печатает отрезок
int  lengthLine(struct Line a);             // длина отрезка
void moveLine  (struct Line * pa, int dx);  // двигает отрезок на dx

int main() {
    struct Line a;           // объявили переменную a типа struct Line
    int dx;
    readLine(&a);            // в функцию передается выражение типа struct Line *
    scanf("%d", &dx);        // в функцию передается выражение типа int *

    printf("%d\n", lengthLine(a));
	//printf("length = %d\n", lengthLine(a));
    //printLine(a);           // передаем a по значению
    moveLine(&a, dx);       // передаем a по адресу, dx по значению
    printLine(a);
    return 0;
}
void readLine(struct Line * pa) {
    // функция должна изменить значение переданного объекта,
    // поэтму объект в функцию передается по адресу
    scanf("%d%d", &(pa->start), &(pa->finish));
    // функция ничего не возвращает, так как прочитанные числа положила по адресам pa->start и pa->finish
	int buffer = 0;
	if( pa->start > pa->finish )
	{
		buffer = pa->start;
		pa->start = pa->finish;
		pa->finish = buffer;
	}
    // Измените функцию так, чтобы ВСЕГДА значение finish было больше или равно start
}
void printLine(struct Line a) {
    // функция НЕ должна изменить значение переданного объекта,
    // поэтму объект в функцию можно передать по значению
	printf("%d %d\n", a.start, a.finish);
    //printf("(%d, %d)\n", a.start, a.finish);
}
int lengthLine(struct Line a) {
    return a.finish - a.start;
}
void moveLine(struct Line * pa, int dx) {
    // функция должна изменить значение переданного объекта,
    // поэтму объект в функцию передается по адресу
    pa->start = pa->start + dx;
    pa->finish += dx;

    // функция ничего не возвращает
}
