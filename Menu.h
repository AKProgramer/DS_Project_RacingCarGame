#include <iostream>
#include <ctime>
#include<iomanip>
#include <cstring>
#include<Windows.h>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
void screen1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    cout <<setw(29)<< BLUE << " _____                                                                            _____\n";
    cout <<setw(113)<< "(_____)--------------------------------------------------------------------------(_____)\n";
    cout <<setw(112)<< " |   |                                                                            |___|\n";
    cout <<setw(30)<< " |   |" << RED << "  _______  _______  _______  ______     _______  _______  _______  _______" << BLUE << "  |___|\n";
    cout <<setw(30)<< " |   |" << RED << " (  ____ )(  ___  )(  ___  )(  __  \\   (  ____ )(  ___  )(  ____ \\(  ____ \\" << BLUE << " |___|\n";
    cout <<setw(30)<< " |   |" << RED << " | (    )|| (   ) || (   ) || (  \\  )  | (    )|| (   ) || (    \\/| (    \\/" << BLUE << " |___|\n";
    cout <<setw(30)<< " |   |" << RED << " | (____)|| |   | || (___) || |   ) |  | (____)|| (___) || |      | (__" << BLUE << "     |___|\n";
    cout <<setw(30)<< " |   |" << RED << " |     __)| |   | ||  ___  || |   | |  |     __)|  ___  || | ____ |  __)" << BLUE << "    |___|\n";
    cout <<setw(30)<< " |   |" << RED << " | (\\(    | |   | || (   ) || |   ) |  | (\\ (   | (   ) || | \\_  )| (" << BLUE << "       |___|\n";
    cout <<setw(30)<< " |   |" << RED << " | ) \\\\__ | (___) || )   ( || (__/  )  | ) \\ \\__| )   ( || (___) || (____/\\" << BLUE << " |___| \n";
    cout <<setw(30)<< " |   |" << RED << " |/   \\__/(_______)|/     \\|(______/   |/   \\__/|/     \\|(_______)(_______/" << BLUE << " |___|\n";
    cout <<setw(112)<< " |___|                                                                            |___|\n";
    
    cout <<setw(115)<< "(_____)--------------------------------------------------------------------------(_____) \n\n" << RESET;

    cout <<setw(32)<< GREEN << "        __               _______ _________ _______  _______ _________   \n";
    cout<<setw(100) << "       /  \\             (  ____ \\\\__   __/(  ___  )(  ____ )\\__   __/   \n";
    cout<<setw(100) << "       \\/) )            | (    \\/   ) (   | (   ) || (    )|   ) (      \n";
    cout<<setw(100) << "         | |    _____   | (_____    | |   | (___) || (____)|   | |      \n";
    cout<<setw(100) << "         | |   (_____)  (_____  )   | |   |  ___  ||     __)   | |      \n";
    cout<<setw(100) << "         | |                  ) |   | |   | (   ) || (\\ (      | |      \n";
    cout<<setw(100) << "       __) (_           /\\____) |   | |   | )   ( || ) \\ \\__   | |      \n";
    cout<<setw(102) << "       \\____/           \\_______)   )_(   |/     \\||/   \\__/   )_(      \n\n\n" << RESET;

    cout <<setw(32)<< GREEN << "        _______             _______  _______  _                   \n";
    cout <<setw(94)<< "       / ___   )           (       )(  ____ \\( (    /||\\     /|   \n";
    cout <<setw(94)<< "       \\/   )  |           | () () || (    \\/|  \\  ( || )   ( |   \n";
    cout <<setw(94)<< "           /   )   _____   | || || || (__    |   \\ | || |   | |   \n";
    cout <<setw(94)<< "         _/   /   (_____)  | |(_)| ||  __)   | (\\ \\) || |   | |   \n";
    cout <<setw(94)<< "        /   _/             | |   | || (      | | \\   || |   | |   \n";
    cout <<setw(94)<< "       (   (__/\\           | )   ( || (____/\\| )  \\  || (___) |   \n";
    cout <<setw(96)<< "       \\_______/           |/     \\|(_______/|/    )_)(_______)   \n\n\n" << RESET;


    cout <<setw(28)<< GREEN << "                         _______          __________________   \n";
    cout <<setw(87)<< "                         (  ____ \\|\\     /|\\__   __/\\__   __/   \n";
    cout <<setw(87)<< "                         | (    \\/( \\   / )   ) (      ) (      \n";
    cout <<setw(87)<< "                        | (__     \\ (_) /    | |      | |      \n";
    cout <<setw(87)<< "                        |  __)     ) _ (     | |      | |      \n";
    cout <<setw(87)<< "                        | (       / ( ) \\    | |      | |      \n";
    cout <<setw(87)<< "                        | (____/\\( /   \\ )___) (___   | |      \n";
    cout <<setw(87)<< "                        (_______/|/     \\|\\_______/   )_(      \n" << RESET;
}
void screen2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "   __                _______  _______  _                 _______  _          \n";
    cout << "  /  \\              (       )(  ___  )( (    /||\\     /|(  ___  )( \\         \n";
    cout << "  \\/) )             | () () || (   ) ||  \\  ( || )   ( || (   ) || (         \n";
    cout << "    | |    _____    | || || || (___) ||   \\ | || |   | || (___) || |         \n";
    cout << "    | |   (_____)   | |(_)| ||  ___  || (\\ \\) || |   | ||  ___  || |         \n";
    cout << "    | |             | |   | || (   ) || | \\   || |   | || (   ) || |         \n";
    cout << "  __) (_            | )   ( || )   ( || )  \\  || (___) || )   ( || (____/\\   \n";
    cout << "  \\____/            |/     \\||/     \\||/    )_)(_______)|/     \\|(_______/   \n\n\n";


    cout << "   _______              _______          _________ _______    \n";
    cout << "  / ___   )            (  ___  )|\\     /|\\__   __/(  ___  )   \n";
    cout << "  \\/   )  |            | (   ) || )   ( |   ) (   | (   ) |   \n";
    cout << "      /   )   _____    | (___) || |   | |   | |   | |   | |   \n";
    cout << "    _/   /   (_____)   |  ___  || |   | |   | |   | |   | |   \n";
    cout << "   /   _/              | (   ) || |   | |   | |   | |   | |   \n";
    cout << "  (   (__/\\            | )   ( || (___) |   | |   | (___) |   \n";
    cout << "  \\_______/            |/     \\|(_______)   )_(   (_______)   \n\n\n";

   
    cout << "   _______             _______          __________________   \n";
    cout << "  (  __   )           (  ____ \\|\\     /|\\__   __/\\__   __/   \n";
    cout << "  | (  )  |           | (    \\/( \\   / )   ) (      ) (      \n";
    cout << "  | | /   |   _____   | (__     \\ (_) /    | |      | |      \n";
    cout << "  | (/ /) |  (_____)  |  __)     ) _ (     | |      | |      \n";
    cout << "  |   / | |           | (       / ( ) \\    | |      | |      \n";
    cout << "  |  (__) |           | (____/\\( /   \\ )___) (___   | |      \n";
    cout << "  (_______)           (_______/|/     \\|\\_______/   )_(      \n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
void screen3()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "   __               _______  _______  _        _______  _______  _________   _______  _______  _______  _______    \n";
    cout << "  /  \\             (  ____ \\(  ____ \\( \\      (  ____ \\(  ____ \\\\__   __/   (  ____ \\(  ___  )(  ____ )(  ____ \\     \n";
    cout << "  \\/) )            | (    \\/| (    \\/| (      | (    \\/| (    \\/   ) (      | (    \\/| (   ) || (    )|| (    \\/    \n";
    cout << "    | |    _____   | (_____ | (__    | |      | (__    | |         | |      | |      | (___) || (____)|| (_____    \n";
    cout << "    | |   (_____)  (_____  )|  __)   | |      |  __)   | |         | |      | |      |  ___  ||     __)(_____  )    \n";
    cout << "    | |                  ) || (      | |      | (      | |         | |      | |      | (   ) ||    (         ) |    \n";
    cout << "  __) (_           /\\____) || (____/\\| (____/\\| (____/\\| (____/\\   | |      | (____/\\| )   ( || ) \\ \\  /\\____) |    \n";
    cout << "  \\____/           \\_______)(_______/(_______/(_______/(_______/   )_(      (_______/|/     \\||/   \\__/\\_______)    \n\n\n";


    cout << "   _______             _        _______  _______  ______   _______  _______  ______   _______  _______  _______  ______   \n";
    cout << "  / ___   )           ( \\      (  ____ \\(  ___  )(  __  \\ (  ____ \\(  ____ )(  ___ \\ (  ___  )(  ___  )(  ____ )(  __  \\   \n";
    cout << "  \\/   )  |           | (      | (    \\/| (   ) || (  \\  )| (    \\/| (    )|| (   ) )| (   ) || (   ) || (    )|| (  \\  )   \n";
    cout << "      /   )   _____   | |      | (__    | (___) || |   ) || (__    | (____)|| (__/ / | |   | || (___) || (____)|| (   ) |   \n";
    cout << "    _/   /   (_____)  | |      |  __)   |  ___  || |   | ||  __)   |     __)|  __ (  | |   | ||  ___  ||     __)| |   | |   \n";
    cout << "   /   _/             | |      | (      | (   ) || |   ) || (      | (\\ (   | (  \\ \\ | |   | || (   ) || (\\ (   | |   ) |   \n";
    cout << "  (   (__/\\           | (____/\\| (____/\\| )   ( || (__/  )| (____/\\| ) \\ \\__| )___) )| (___) || )   ( || ) \\ \\__| |__/  )   \n";
    cout << "  \\_______/           (_______/(_______/|/     \\|(______/ (_______/|/   \\__/|/ \\___/ (_______)|/     \\||/   \\__/(______/   \n\n\n";


    cout << "   _______             _______          __________________   \n";
    cout << "  (  __   )           (  ____ \\|\\     /|\\__   __/\\__   __/   \n";
    cout << "  | (  )  |           | (    \\/( \\   / )   ) (      ) (      \n";
    cout << "  | | /   |   _____   | (__     \\ (_) /    | |      | |      \n";
    cout << "  | (/ /) |  (_____)  |  __)     ) _ (     | |      | |      \n";
    cout << "  |   / | |           | (       / ( ) \\    | |      | |      \n";
    cout << "  |  (__) |           | (____/\\( /   \\ )___) (___   | |      \n";
    cout << "  (_______)           (_______/|/     \\|\\_______/   )_(      \n\n\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void newGame()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "   __                _        _______             _______  _______  _______  _______          \n";
    cout << "  /  \\              ( (    /|(  ____ \\|\\     /|  (  ____ \\(  ___  )(       )(  ____ \\         \n";
    cout << "  \\/) )             |  \\  ( || (    \\/| )   ( |  | (    \\/| (   ) || () () || (    \\/         \n";
    cout << "    | |    _____    |   \\ | || (__    | | _ | |  | |      | (___) || || || || (__         \n";
    cout << "    | |   (_____)   | (\\ \\) ||  __)   | |( )| |  | | ____ |  ___  || |(_)| ||  __)            \n";
    cout << "    | |             | | \\   || (      | || || |  | | \\_  )| (   ) || |   | || (         \n";
    cout << "  __) (_            | )  \\  || (____/\\| () () |  | (___) || )   ( || )   ( || (____/\\   \n";
    cout << "  \\____/            |/    )_)(_______/(_______)  (_______)|/     \\||/     \\|(_______/   \n\n\n";

    cout << "   _______              _______  _______  _______           _______  _______    \n";
    cout << "  / ___   )            (  ____ )(  ____ \\(  ____ \\|\\     /|(       )(  ____ \\   \n";
    cout << "  \\/   )  |            | (    )|| (    \\/| (    \\/| )   ( || () () || (    \\/   \n";
    cout << "      /   )   _____    | (____)|| (__    | (_____ | |   | || || || || (__       \n";
    cout << "    _/   /   (_____)   |     __)|  __)   (_____  )| |   | || |(_)| ||  __)      \n";
    cout << "   /   _/              | (\\ (   | (            ) || |   | || |   | || (         \n";
    cout << "  (   (__/\\            | ) \\ \\__| (____/\\/\\____) || (___) || )   ( || (____/\\   \n";
    cout << "  \\_______/            |/   \\__/(_______/\\_______)(_______)|/     \\|(_______/   \n\n\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
