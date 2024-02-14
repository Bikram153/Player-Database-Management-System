#include "Player.h"

Player::Player(const String& name, int id, int age, const String& team)
    : name_(name), id_(id), age_(age), team_(team) {}

String Player::getName() const {
    return name_;
}

int Player::getID() const {
    return id_;
}

int Player::getAge() const {
    return age_;
}

String Player::getTeam() const {
    return team_;
}
