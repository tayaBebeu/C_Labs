#include <stdio.h>
#include <iostream>
#include <cstring>
#include <ctype.h>

int slideStringList(char stringList[30][41], int count, int strIndex); //прототип функции
int searchString(const char stringList[30][41], int count, const char str[41]);

void testFirstFunction();
void testSecondFunction();

int main()
{
    char new_student[41];//фамилия студента
    printf_s("Enter the student's last name: ");
    gets(new_student);

    int n;//кол-во студентов - 1(последняя строка пустая) в массиве
    printf_s("Enter the number of students in the list: ");
    scanf_s("%d", &n);
    getchar();
    if ((n == 0) || (n < 0) || isdigit(n) == 0)
    {
        printf_s("\nno solution");
    } else
    {
        printf_s("\nEnter the last names of the students:\n");
        char students[30][41];//вводимый список студентов
        for (size_t k = 0; k < n; k++) //номер студента в списке
        {
            gets(students[k]);

        }

        for (int i = 0; i <= (n - 1); i++) //проверка на правильную сортировку
        {
            for (int j = 0; j < 41; j++)
            {
                if (students[i][j] > students[i + 1][j])
                {
                    printf_s("Invalid input data\n");
                    j = 41;
                    i = 30;
                }
                if (students[i][j] < students[i + 1][j])
                {
                    j = 41;
                }
            }
        }


        int pos = searchString(students, n, new_student);
        printf_s("%d", pos);

        slideStringList(students, 30, pos);

        for (int i = 0; i < 41; i++)
        {
            students[pos][i] = new_student[i];
        }
        for (int i = 0; i < 30; i++)
        {
            printf_s("%s\n", students[i]);
        }

        return 0;
    }
}

int searchString(const char stringList[30][41], int count, const char str[41])//1 функция
{
    int pos = 0; //позиция искомой фамилии
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < strlen(stringList[i]); j++)
        {
            char tmp = stringList[i][j];
            char tmp2 = str[j];
            if (tmp > tmp2)
            {
                pos = i;
            } else if (tmp < tmp2)
            {
                i++;
                j = -1;
            }
        }
    }
    return pos + 1;
}

int slideStringList(char stringList[30][41], int count, int strIndex)//2 функция
{
    for (int i = count - 1; i > strIndex; i--)
    {
        char tmp[41];
        for (int j = 0; j < 41; j++)
        {
            tmp[j] = stringList[i][j];
            stringList[i][j] = stringList[i - 1][j];
            stringList[i - 1][j] = tmp[j];
        }
    }
    return strIndex;
}/*

void testFirstFunction()//тест 1
{//входные данные
	const char stringList[30][41] = {
	{"Baker"},
	{"Brown"},
	{"Clark"},
	{"Clarke"},
	{"Cooper"},
	{"Davies"},
	{"Edwards"},
	{"Evans"},
	{"Green"},
	{"Hall"},
	{"Harris"},
	{"Hill"},
	{"Johnson"},
	{"Jones"},
	{"King"},
	{"Lewis"},
	{"Martin"},
	{"Roberts"},
	{"Robinson"},
	{"Smith"},
	{"Taylor"},
	{"Thomas"},
	{"Turner"},
	{"White"},
	{"Williams"},
	{"Wilson"},
	{"Wright "},
	{"Young"},
	{"Zet"},
	{""}
	};

	int count;
	const char str[41] = { "Cid" };
}

void testSecondFunction();*/