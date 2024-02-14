#include <iostream>
#include <vector>
#include "Player.h"
#include "Log.h"
#include "String.h"
#include <chrono>
#include "Timer.h"
class Database {
public:
    Database();
    ~Database();
    
    void insertPlayer(const Player& player);
    void updatePlayer(int id, const Player& player);
    void deletePlayer(int id);
    void displayPlayers();
    void setLoggedIn(bool loggedIn);
    bool findPlayerByID(int id) const;
private:
    Log log_;
    std::vector<Player> players_;
};


