#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

#define MAX_LOGS 1000
#define MAX_TEXT 128

string messages[3] = {
    "Вошел в систему",
    "Вышел из системы",
    "Ошибка входа в систему"
};

struct LogRecord {
    DWORD IDT = 0;
    int priority = 0;
    DWORD tick = 0;

    char message[MAX_TEXT];
};

struct LogBuffer {
    LogRecord records[MAX_LOGS];
    LONG index;
};



void Logger(LogRecord record, LogBuffer buffer) {
    srand(time(NULL));
    int id = rand() % 3;

    string mess = "[" + to_string(record.IDT) + ", " + to_string(record.priority)+ "] - " + messages[id] + " (" + to_string(record.tick) + "ms).";

    char d[MAX_TEXT];
    for (int i = 0; i < mess.size(); i++)
    {
        d[i] += mess[i];
    }

    buffer.records[buffer.index] = record;

    buffer.index++;
    cout << mess;
    int time = rand() % 100;
    Sleep(time < 10 ? 10 : time);


}
void Seeker(LogBuffer buffer) {
    int temp = 0;
    for (int i = buffer.index; i > buffer.index; i--)
    {
        temp++;
        if (temp == 5) {
            Sleep(100);
            temp = 0;
        }
        else {
            cout << buffer.records[i].message << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    LogRecord lr;
    LogBuffer buf;
    Logger(lr, buf);
}

