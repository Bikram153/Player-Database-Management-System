#pragma once
#include <cstring>
#include <string>
#include <iostream>

class String {
protected:
    int m_Size;
public:
    char* m_Data;
    String();
    String(const char* string);
    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
    virtual ~String();
    const char* getString() const;
    virtual const char* display() const;
    String operator+(const String& other) const;
    friend std::istream& operator>>(std::istream& is, String& str);
};

class StringFirst : public String {
public:
    StringFirst(const char* value);
    const char* display() const override;
};

class StringLast : public String {
public:
    StringLast(const char* value);
    const char* display() const override;
};
