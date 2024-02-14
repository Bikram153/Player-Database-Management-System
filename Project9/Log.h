#pragma once
#include "String.h"
#include<fstream>
class Log
{
public:
    enum class Level {
        LevelError = 0, LevelWarning, LevelInfo
    };
    void SetLogLevel(Level level);
    void Warn(String& message);
    void Error(String& message);
    void Info(String& message);

    Log();
    ~Log();

    void logIn();
    void logOut();

    void writeLog(const String& message);
    void logEntry(const String& function);
    void logExit(const String& function);
private:
    Level m_LogLevel = Level::LevelInfo;
    std::ofstream logFile_;
    bool loggedIn_;
};