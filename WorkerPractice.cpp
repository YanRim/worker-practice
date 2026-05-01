#include <iostream>
#include <list>
#include <limits>
#include <locale>

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

#include "Worker.h"

int main()
{
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif

    std::locale::global(std::locale(""));

    std::list<WORKER> workers;

    int currentYear;
    int count;

    std::wcout << L"Введите текущий год: ";
    while (!(std::wcin >> currentYear) || currentYear <= 0)
    {
        std::wcout << L"Ошибка. Введите корректный текущий год: ";
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    }

    std::wcout << L"Введите количество работников: ";
    while (!(std::wcin >> count) || count <= 0)
    {
        std::wcout << L"Ошибка. Введите корректное количество работников: ";
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    }

    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');

    for (int i = 0; i < count; ++i)
    {
        std::wcout << L"\nРаботник №" << i + 1 << L'\n';

        WORKER worker;
        worker.input();

        if (worker.getStartYear() > currentYear)
        {
            std::wcout << L"Ошибка: год поступления не может быть больше текущего года.\n";
            --i;
            continue;
        }

        workers.push_back(worker);
    }

    std::wcout << L"\nСписок всех работников:\n";

    int number = 1;
    for (const WORKER& worker : workers)
    {
        std::wcout << L"\nРаботник №" << number << L'\n';
        worker.display(currentYear);
        ++number;
    }

    int requiredExperience;

    std::wcout << L"\nВведите минимальный стаж для поиска: ";
    while (!(std::wcin >> requiredExperience) || requiredExperience < 0)
    {
        std::wcout << L"Ошибка. Введите корректный стаж: ";
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    }

    std::wcout << L"\nРаботники со стажем больше " << requiredExperience << L" лет:\n";

    bool found = false;
    number = 1;

    for (const WORKER& worker : workers)
    {
        if (worker.getExperience(currentYear) > requiredExperience)
        {
            std::wcout << L"\nРаботник №" << number << L'\n';
            worker.display(currentYear);
            found = true;
        }

        ++number;
    }

    if (!found)
    {
        std::wcout << L"Работники с таким стажем не найдены.\n";
    }

    return 0;
}