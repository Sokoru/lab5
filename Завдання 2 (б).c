#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char input;
choice:
    printf("Запустити код? (y/n): ");
    scanf(" %c", &input);
    if (input == 'y')
    {
        goto method;
    }
    else if (input == 'n')
    {
        printf("Код зупинено.");
        return 0;
    }
    else
    {
        printf("Невірний вибір, введіть ще раз.\n");
        goto choice;
    }
method:
{
    char input;
    printf("a - на номер мінімального за модулем елемента масиву; b - на суму елементів масиву між першим та останнім додатними елементами. \n");
    printf("Яким методом будемо вирішувати завдання? Щоб повернутися - напишіть  r. (a/b/r): ");
    scanf(" %c", &input);
    if (input == 'a')
    {
        goto code_1;
    }
    else if (input == 'b')
    {
        goto code_2;
    }
    else if (input == 'r')
    {
        goto choice;
    }
    else
    {
        printf("Невірний вибір, введіть ще раз.\n");
        goto method;
    }
}

code_1:
{
    int n;
    printf("Задайте розмір масиву: ");
    scanf("%d", &n);

    int a[n];
    const int colCount = n, Low = -100, High = 100;
    srand(time(0));
    for (int i = 0; i < colCount; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
    for (int i = 0; i < colCount; i++)
    {
        printf("a[%d] = %d; ", i, a[i]);
    }

    int minIndex = 0;
    int minValue = abs(a[0]);
    for (int i = 1; i < n; i++)
    {
        int absValue = abs(a[i]);
        if (absValue < minValue)
        {
            minIndex = i;
            minValue = absValue;
        }
    }
    printf("\nНомер мінімального за модулем елемента масиву: %d;\n", minIndex);
    goto choice;
}

code_2: {
    int n;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    int a[n];
    const int colCount = n, Low = -100, High = 100;
    srand(time(0));
    for (int i = 0; i < colCount; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
    for (int i = 0; i < colCount; i++)
    {
        printf("a[%d] = %d; ", i, a[i]);
    }
    int firstPositiveIndex = -1;
    int lastPositiveIndex = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (firstPositiveIndex == -1)
            {
                firstPositiveIndex = i;
            }
            lastPositiveIndex = i;
        }
    }
    int sum = 0;
    if (firstPositiveIndex != -1 && lastPositiveIndex != -1 && firstPositiveIndex != lastPositiveIndex)
    {
        for (int i = firstPositiveIndex; i < lastPositiveIndex; i++)
        {
            sum += a[i];
        }
    }
    printf("Сума елементів масиву між першим та останнім додатними елементами: %d;\n", sum);
    goto choice;
}
}
