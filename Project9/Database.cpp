#include "Database.h"
#include <iostream>
#include <fstream>
#include <chrono>

Database::Database() {}

Database::~Database() {}

void Database::insertPlayer(const Player& player) {
    log_.logEntry(__FUNCTION__);

    // Check if the player ID already exists
    if (findPlayerByID(player.getID())) {
        std::cout << "Error: Player with the same ID already exists." << std::endl;
        log_.writeLog("Error: Player with the same ID already exists.");
        log_.logExit(__FUNCTION__);
        return;
    }

    players_.push_back(player);
    Timer t;
    t.TimerInsertion();
    std::cout << "Inserted player:" << std::endl;
    std::cout << "Name: " << player.getName().getString() << ", ID: " << player.getID()
        << ", Age: " << player.getAge() << ", Team: " << player.getTeam().getString() << std::endl;
    Timer t1;
    t1.TimerDatabase();
    std::ofstream print;
    print.open("Database.txt", std::ofstream::out | std::ofstream::app);
    print << "Name: " << player.getName().getString() << ", ID: " << std::to_string(player.getID())
        + ", Age: " << std::to_string(player.getAge()) + ", Team: " << player.getTeam().getString() << std::endl;

    log_.writeLog("Inserted player:");
    std::ofstream out;
    out.open("log.txt", std::ofstream::out | std::ofstream::app);
    out << "Name: " << player.getName().getString() << ", ID: " << std::to_string(player.getID())
        + ", Age: " << std::to_string(player.getAge()) + ", Team: " << player.getTeam().getString() << std::endl;

    log_.logExit(__FUNCTION__);
}

bool Database::findPlayerByID(int id) const {
    for (const Player& player : players_) {
        if (player.getID() == id) {
            return true;
        }
    }
    return false;
}

void Database::updatePlayer(int id, const Player& player) {
    log_.logEntry(__FUNCTION__);

    bool playerFound = false;

    for (Player& p : players_) {
        if (p.getID() == id) {
            p = player;
            playerFound = true;
            Timer t;
            t.TimerInsertion();
            std::cout << "Updated player:" << std::endl;
            std::cout << "Name: " << player.getName().getString() << ", ID: " << player.getID()
                << ", Age: " << player.getAge() << ", Team: " << player.getTeam().getString() << std::endl;
            Timer t1;
            t1.TimerDatabase();
            std::ofstream print;
            print.open("Database.txt", std::ofstream::out | std::ofstream::app);
            print << "Name: " << player.getName().getString() << ", ID: " << std::to_string(player.getID())
                + ", Age: " << std::to_string(player.getAge()) + ", Team: " << player.getTeam().getString() << std::endl;

            log_.writeLog("Updated player:");
            std::ofstream out;
            out.open("log.txt", std::ofstream::out | std::ofstream::app);
            out << "Name: " << player.getName().getString() << ", ID: " << std::to_string(player.getID())
                + ", Age: " << std::to_string(player.getAge()) + ", Team: " << player.getTeam().getString() << std::endl;
            break;
        }
    }

    if (!playerFound) {
        std::cout << "Error: Player with ID " << id << " not found." << std::endl;
        std::ofstream out;
        out.open("log.txt", std::ofstream::out | std::ofstream::app);
        out << "Error: Player with ID " + std::to_string(id) + " not found."<<std::endl;
    }

    log_.logExit(__FUNCTION__);
}

void Database::deletePlayer(int id) {
    log_.logEntry(__FUNCTION__);

    auto it = players_.begin();

    while (it != players_.end()) {
        if (it->getID() == id) {
            Timer t;
            t.TimerInsertion();
            std::cout << "Deleted player:" << std::endl;
            std::cout << "Name: " << it->getName().getString() << ", ID: " << it->getID()
                << ", Age: " << it->getAge() << ", Team: " << it->getTeam().getString() << std::endl;

            log_.writeLog("Deleted player:");
            std::ofstream out;
            out.open("log.txt", std::ofstream::out | std::ofstream::app);
            out << "Name: " << it->getName().getString() << ", ID: " << std::to_string(it->getID())
                + ", Age: " << std::to_string(it->getAge()) + ", Team: " << it->getTeam().getString() << std::endl;

            it = players_.erase(it);
            log_.logExit(__FUNCTION__);
            return;
        }
        else {
            ++it;
        }
    }
    std::ofstream out;
    out.open("log.txt", std::ofstream::out | std::ofstream::app);
    std::cout << "Error: Player with ID " << id << " not found." << std::endl;
    out << "Error: Player with ID " + std::to_string(id) + " not found."<<std::endl;
    log_.logExit(__FUNCTION__);
}

void Database::displayPlayers() {
    log_.logEntry(__FUNCTION__);

    if (players_.empty()) {
        std::cout << "Error: No players in the database." << std::endl;
        log_.writeLog("Error: No players in the database.");
        log_.logExit(__FUNCTION__);
        return;
    }

    Timer t;
    t.TimerInsertion();
    std::cout << "Displaying players:" << std::endl;
    log_.writeLog("Displaying players:");

    for (const Player& player : players_) {
        std::cout << "Name: " << player.getName().getString() << ", ID: " << player.getID()
            << ", Age: " << player.getAge() << ", Team: " << player.getTeam().getString() << std::endl;

        std::ofstream out;
        out.open("log.txt", std::ofstream::out | std::ofstream::app);
        out<<"Name: " <<player.getName().getString()<< ", ID: " << std::to_string(player.getID())
            + ", Age: " << std::to_string(player.getAge()) + ", Team: " << player.getTeam().getString()<<std::endl;
    }

    log_.logExit(__FUNCTION__);
}

void Database::setLoggedIn(bool loggedIn) {
    if (loggedIn)
        log_.logIn();
    else
        log_.logOut();
}
