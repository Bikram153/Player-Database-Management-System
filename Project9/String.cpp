#include "String.h"

String::String() {
    m_Size = 0;
    m_Data = nullptr;
}

String::String(const char* string) {
    m_Size = strlen(string);
    m_Data = new char[m_Size + 1];
    memcpy(m_Data, string, m_Size + 1);
}

String::String(const String& other) {
    m_Size = other.m_Size;
    m_Data = new char[m_Size + 1];
    memcpy(m_Data, other.m_Data, m_Size + 1);
}

String::String(String&& other) noexcept
    : m_Size(other.m_Size), m_Data(other.m_Data) {
    other.m_Size = 0;
    other.m_Data = nullptr;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] m_Data;
        m_Size = other.m_Size;
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, other.m_Data, m_Size + 1);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] m_Data;
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    return *this;
}

String::~String() {
    delete[] m_Data;
}

const char* String::getString() const {
    return m_Data;
}

const char* String::display() const {
    return m_Data;
}

String String::operator+(const String& other) const {
    int newSize = m_Size + other.m_Size;
    char* newData = new char[newSize + 1];

    memcpy(newData, m_Data, m_Size);
    memcpy(newData + m_Size, other.m_Data, other.m_Size + 1);
    newData[newSize] = '\0';
    String result(newData);
    delete[] newData;

    return result;
}

StringFirst::StringFirst(const char* value) : String(value) {}

const char* StringFirst::display() const {
    const char* prefix = "First: ";
    int prefixLength = strlen(prefix);
    int valueLength = strlen(m_Data);
    char* result = new char[prefixLength + valueLength + 1];

    memcpy(result, prefix, prefixLength);
    memcpy(result + prefixLength, m_Data, valueLength + 1);

    return result;
}

StringLast::StringLast(const char* value) : String(value) {}

const char* StringLast::display() const {
    const char* prefix = "Last: ";
    int prefixLength = strlen(prefix);
    int valueLength = strlen(m_Data);
    char* result = new char[prefixLength + valueLength + 1];

    memcpy(result, prefix, prefixLength);
    memcpy(result + prefixLength, m_Data, valueLength + 1);

    return result;
}

std::istream& operator>>(std::istream& is, String& str) {
    char buffer[1024];
    is >> buffer;
    str = String(buffer);
    return is;
}
