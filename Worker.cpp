#include "Worker.h"

#include <iostream>
#include <limits>

WORKER::WORKER()
{
    fullName = L"";
    position = L"";
    salary = 0.0;
    startYear = 0;
}

WORKER::WORKER(
    const std::wstring& fullName,
    const std::wstring& position,
    double salary,
    int startYear
)
{
    this->fullName = fullName;
    this->position = position;
    this->salary = salary;
    this->startYear = startYear;
}

void WORKER::input()
{
    std::wcout << L"Введите ФИО работника: ";
    std::getline(std::wcin, fullName);

    std::wcout << L"Введите должность: ";
    std::getline(std::wcin, position);

    std::wcout << L"Введите зарплату: ";
    while (!(std::wcin >> salary) || salary < 0)
    {
        std::wcout << L"Ошибка. Введите корректную зарплату: ";
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    }

    std::wcout << L"Введите год поступления на работу: ";
    while (!(std::wcin >> startYear) || startYear <= 0)
    {
        std::wcout << L"Ошибка. Введите корректный год: ";
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    }

    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
}

void WORKER::display(int currentYear) const
{
    std::wcout << L"ФИО: " << fullName << L'\n';
    std::wcout << L"Должность: " << position << L'\n';
    std::wcout << L"Зарплата: " << salary << L'\n';
    std::wcout << L"Год поступления: " << startYear << L'\n';
    std::wcout << L"Стаж: " << getExperience(currentYear) << L" лет\n";
}

int WORKER::getExperience(int currentYear) const
{
    return currentYear - startYear;
}

int WORKER::getStartYear() const
{
    return startYear;
}