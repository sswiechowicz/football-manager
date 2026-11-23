
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

class Game
{
private:
    double grass;
    double grassPerClick;

    bool isRunning;

public:
    Game();

    // Główna pętla gry
    void run();

    // Mechanika
    void clickBall();

    // Menu
    void showMenu();

    // Zapis i odczyt
    void saveGame();
    void loadGame();

    // Statystyki gracza
    class Statistics
    {
    public:
        int totalClicks = 0;
        int packsOpened = 0;
        int footballersCollected = 0;

        void showStatistics() const;
    };
};

#endif
