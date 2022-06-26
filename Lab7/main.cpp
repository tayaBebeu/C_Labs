#include <stdio.h>
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;


int slideStringList(char stringList[30][41], int count, int strIndex); //прототип функции
int searchString(const char stringList[30][41], int count, const char str[41]);

void testFirstFunction();

void testSecondFunction();

int main()
{
    char new_student[41];//фамилия студента
    printf("Enter the student's last name: "); //Ввод имени студента
    //cout << "Enter the student's last name: " << endl;

    gets(new_student);

    int n;//кол-во студентов - 1(последняя строка пустая) в массиве
    printf("Enter the number of students in the list up to 30: ");
    scanf_s("%d", &n);

    if ((n == 0) || (n < 2) || (n > 30)) //проверка на: список не равен 0, отрицательному числу и букве
    {
        printf_s("\nno solution");
    }
    else
    {
        char students[n][41];//вводимый список студентов

        printf_s("\nEnter the last names of the students:\n");
//        getchar();
        for (int k = 0; k < n - 1; k++) //номер студента в списке
        {
            scanf("%s", students[k]);
//            gets(students[k]); //cчитываем фамилии
        }

        int i = 0;
        if (n > 2)
        {
            int compareStrings = (strcmp(students[i], students[i + 1])); //Сравнить две строки
            if (compareStrings > 0) //если функция strcmp возвращает число > 0, значит первая строка больше второй
            {                       //если число < 0 - первая строка меньше второй
                                    //если число == 0 - строки эквивалентны
                printf_s("Invalid input data\n");
            }
                int pos = searchString(students, n, new_student);
                printf_s("The desired position: %d", pos);

                slideStringList(students, 30, pos);

                for (int i = 0; i < 41; i++)
                {
                    students[pos][i] = new_student[i];
                }
                for (int i = 0; i < 30; i++)
                {
                    printf_s("%s\n", students[i]);
                }
            //return 0;
        }
    }
}


int searchString(const char stringList[30][41], int count, const char str[41])//1 функция
{
    int pos = 0; //искомая позиция введенной фамилии
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < strlen(stringList[i]); j++)
        {
            char tmp = stringList[i][j];
            char tmp2 = str[j];
            if (tmp > tmp2)
            {
                pos = i;
            }
            else if (tmp < tmp2)
            {
                i++;
                j = -1;
            }
        }
    }
    if (pos == count)
    {
        return -1;
    }
    else
    {
        return pos + 1;
    }
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