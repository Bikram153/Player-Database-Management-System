#include<fstream>
#include "Log.h"
#include "Date.h"
#include "String.h"
#include "Timer.h"
#include "Database.h"
#include<iostream>
int main()
{

    Timer t1;
    Log log{};
    {
        Timer t2;
        Date currentDate{};

        log.SetLogLevel(Log::Level::LevelError);

        currentDate.setDay(24);
        currentDate.setMonth(12);
        currentDate.setYear(2023);
        currentDate.Display();

        Date future_date = currentDate + 10;
        std::cout << "Future Date: ";
        future_date.Display();
        std::cout << "Date Class Duration: ";
        t2.stop();
    }
    {
        Timer t3;
        String str("Modern C++");
        StringFirst first("Bikram");
        StringLast last("Samanta");

        String string1("Hello, ");
        String string2("world!");
        String result = string1 + string2;
        const char* concatenated = result.getString();
        std::cout << "Concatenated String: " << concatenated << std::endl;

        std::cout << str.display() << std::endl;
        std::cout << first.display() << std::endl;
        std::cout << last.display() << std::endl;

        String info("Fine!");
        String warn("Carefull!");
        String error("Stop!");

        log.Info(info);
        log.Warn(warn);
        log.Error(error);
        std::cout << "String Class Duration: ";
        t3.stop();
    }


        Database database;

        auto loggedIn = false;
        String username = "user";
        String password = "password";

        while (true) {
            if (!loggedIn) {
                std::cout << "Enter username and password to log in." << std::endl;
                auto enteredUsername = String{};
                auto enteredPassword = String{};
                std::cout << "Username: ";
                std::cin >> enteredUsername;
                std::cout << "Password: ";
                std::cin >> enteredPassword;
                if (strcmp(enteredUsername.getString(), username.getString()) == 0 && strcmp(enteredPassword.getString(), password.getString()) == 0)
                {
                    loggedIn = true;
                    database.setLoggedIn(loggedIn);
                    
                    std::cout << "Logged in successfully." << std::endl;                
                }
                else {
                    std::cout << "Login failed. Try again." << std::endl;
                }
            }
            else {
                std::cout << "\t\t1 - Insert player \n";
                std::cout << "\t\t2 - Update player \n";
                std::cout << "\t\t3 - Delete player \n";
                std::cout << "\t\t4 - Display player \n";
                std::cout << "\t\t5 - Log Out \n";
                std::cout << "\t\tEnter your choice : ";

                auto choice = int{};
                std::cin >> choice;

                switch (choice) {
                case 1: {
                    int id, age;
                    String name, team;
                    std::cout << "Enter Player Name: ";
                    std::cin >> name;
                    std::cout << "Enter Player ID: ";
                    std::cin >> id;
                    std::cout << "Enter Player Age: ";
                    std::cin >> age;
                    std::cout << "Enter Player Team: " << std::endl;
                    std::cin >> team;
                    Player player(name, id, age, team);
                    database.insertPlayer(player);
                    break;

                }
                case 2: {
                    int playerId, age;
                    char name[150], team[150];
                    std::cout << "Enter Player ID to Update: ";
                    std::cin >> playerId;
                    std::cout << "Enter New Name: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.getline(name, 150);
                    std::cout << "Enter New Age: ";
                    std::cin >> age;
                    std::cout << "Enter Player Team: " << std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.getline(team, 150);
                    char* pname = name;
                    char* pteam = team;
                    Player updatedPlayer(pname, playerId, age, pteam);
                    database.updatePlayer(playerId, updatedPlayer);
                    break;

                }
                case 3: {
                    int playerId;
                    std::cout << "Enter Player ID to Delete: ";
                    std::cin >> playerId;
                    database.deletePlayer(playerId);
                    break;

                }
                case 4: {
                    database.displayPlayers();
                    break;

                }
                case 5: {
                    loggedIn = false;
                    database.setLoggedIn(loggedIn); // Call logOut() when logging out
                    std::cout << "Logged out successfully." << std::endl;
                    std::cout << "Do you want to continue (y/n)? ";
                    char continueChoice;
                    std::cin >> continueChoice;
                    if (continueChoice != 'y' && continueChoice != 'Y') {
                        std::cout << "Exiting the program." << std::endl;
                        std::cout << "Log Class Duration: ";
                        t1.stop();
                        return 0; // Exit the program
                    }
                    break;
                }
                default:
                    std::cout << "Invalid choice. Try again." << std::endl;
                }
            }
        }
        std::cout << "Log Class Duration: ";
        t1.stop();
        return 0;
    }

