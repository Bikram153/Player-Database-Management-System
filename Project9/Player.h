#pragma once
#include <string>
#include "String.h"

class Player {
public:
    Player(const String& name, int id, int age, const String& team);

    String getName() const;
    int getID() const;
    int getAge() const;
    String getTeam() const;

private:
    String name_;
    int id_;
    int age_;
    String team_;
};

