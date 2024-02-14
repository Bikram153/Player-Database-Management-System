#include<iostream>
#include "Log.h"
#include "String.h"
#include "Timer.h"

void Log::SetLogLevel(const Level level)
{
    m_LogLevel = level;
}

void Log::Warn(String& message)
{
    if (m_LogLevel >= Level::LevelWarning)
        std::cout << "[Warning]: " << message.getString() << std::endl;
}

void Log::Error(String& message)
{
    if (m_LogLevel >= Level::LevelError)
        std::cout << "[Error]: " << message.getString() << std::endl;
}

void Log::Info(String& message)
{
    if (m_LogLevel >= Level::LevelInfo)
        std::cout << "[Info]: " << message.getString() << std::endl;
}

Log::Log() {
    logFile_.open("log.txt", std::ofstream::out | std::ofstream::app);
    loggedIn_ = false; // Initially not logged in
}

Log::~Log() {
    logFile_.close();
}

void Log::writeLog(const String& message) {
    if (logFile_.is_open()) {
        logFile_ << message.m_Data << std::endl;
    }
}

void Log::logEntry(const String& function) {
    if (loggedIn_) {
        String s1{ "Entered function: " };
        String s2{ function };
        String s3 = s1 + s2;
        writeLog(s3);
    }
}

void Log::logExit(const String& function) {
    if (loggedIn_) {
        String s1{ "Exited function: " };
        String s2{ function };
        String s3 = s1 + s2;
        writeLog(s3);
    }
}


void Log::logIn() {
    Timer t;
    t.TimerInsertion();
    writeLog("Logged in successfully.");
    loggedIn_ = true;
}

void Log::logOut() {
    Timer t;
    t.TimerInsertion();
    writeLog("Logged out. Exiting.");
    loggedIn_ = false;
}



