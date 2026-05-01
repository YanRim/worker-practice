#ifndef WORKER_H
#define WORKER_H

#include <string>

class WORKER
{
private:
    std::wstring fullName;
    std::wstring position;
    double salary;
    int startYear;

public:
    WORKER();

    WORKER(
        const std::wstring& fullName,
        const std::wstring& position,
        double salary,
        int startYear
    );

    void input();
    void display(int currentYear) const;

    int getExperience(int currentYear) const;
    int getStartYear() const;
};

#endif