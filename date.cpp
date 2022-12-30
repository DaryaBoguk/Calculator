#include"functions.h"
const int nulll = 48;

void Date::difference() {
    std::string s, s1;
    std::cout << "enter the first date:\n";
    std::cin >> s;
    std::cout << "enter the second date:\n";
    std::cin >> s1;
    day = s[1] - nulll + (s[0] - nulll) * 10;
    day1 = s1[1] - nulll + (s1[0] - nulll) * 10;
    mes = s[4] - nulll + (s[3] - nulll) * 10;
    mes1 = s1[4] - nulll + (s1[3] - nulll) * 10;
    int i = s.size() - 1;
    int step = 1;
    int year = 0;
    while (s[i] != '.')
    {
        year = year + (s[i] - nulll) * step;
        step = step * 10; i--;
    }
    int i1 = s1.size() - 1;
    int step1 = 1;
    int year1 = 0;
    while (s1[i1] != '.')
    {
        year1 = year1 + (s1[i1] - nulll) * step1;
        step1 = step1 * 10; i1--;
    }
    int k;
    if (year * 365 + mes * 12 + day > year1 * 365 + mes1 * 12 + day1) {
        k = year;
        year = year1;
        year1 = k;
        k = mes;
        mes = mes1;
        mes1 = k;
        k = day;
        day = day1;
        day1 = k;

    }
    int ryear = 0, rmes = 0, rday = 0;
    mes = mes + year * 12;
    mes1 = mes1 + year1 * 12;
    ryear = mes1 / 12 - mes / 12;
    mes = mes % 12;
    mes1 = mes1 % 12;
    if (mes == 0) { mes += 12; }
    if (mes1 == 0) { mes1 += 12; ryear--; }
    while (mes != mes1)
    {
        rmes++;
        mes++;
        if (mes > 12)mes = mes - 12;
    }
    if (day1 >= day) rday = day1 - day;
    else {
        rmes--; mes--;
        if (mes == 0) mes = mes + 12;
        if (mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10 or mes == 12) rday = 31 - day + day1;
        else if (mes == 4 or mes == 6 or mes == 9 or mes == 11) rday = 30 - day + day1;
        else if (mes == 2 and year1 % 400 == 0) rday = 29 - day + day1;
        else if (mes == 2 and year1 % 100 == 0) rday = 28 - day + day1;
        else if (mes == 2 and year1 % 4 == 0) rday = 29 - day + day1;
        else rday = 28 - day + day1;
    }
    std::cout << ryear << " years " << rmes << " mounths " << rday << " days";
}
   

