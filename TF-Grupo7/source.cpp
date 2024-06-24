#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
using namespace System;
int width = 100, height = 38;
int puntj = 100, vida = 100;
bool flag = 1;

string maze[27] = {
        ",-----------------------------.----------------------------------.",
        "|                             |                                  |",
        "|      . .     ,---------     |     ------------------------.    |",
        "|     _|@|_    |              |                             |    |",
        "|    |     '---'--------------'    ,-------------------.    |    |",
        "|    |                             |                   |    |    |",
        "|    :--------------.--------------'----     ,---------:    |    |",
        "|    |  #           |                        |         |    | #  |",
        "|    :---------     |    .    ,---------.    |    .    |    `----:",
        "|    |              |    |    | #       |    |    |    |         |",
        "|    |     ---------'    |    :----     |    |    |    |    .    |",
        "|    |                   |    |         |    |    |    |    |    |",
        "|    `-------------------'    |     ----'    |    |    |    |    |",
        "|                             |              |    |    |    |    |",
        ":--------------.---------.    :--------------'    |    :----'    |",
        "|              |         |    |         @         |    | $       |",
        "|    .    .    |    .    |    |    ,--------------:    `----     |",
        "|    |    |    |    |    |    |    |              |              |",
        "|    |    |    '    |    |  __|    |     ---------'---------.    |",
        "|    |    |         |  $ |@|__     |                        |    |",
        "|    |    `---------'----'    |    |    ,---------.    .    |    |",
        "|    |                        |    |    |         |    |    |    |",
        "|    :---------.--------------:    |    |    .    |    |    |    |",
        "|    |         |              |    |    | $  |    |    |    |    |",
        "|    '    .    `---------     |    |    `----'    |    `----'    |",
        "|         |                   |    |              |              |",
        "`---------'-------------------'__&_`--------------'--------------'"
};

string maze2[31] = {
        "+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+",
        "|        |        |                        @                   |",
        "+  +--+  +  +--+--+  +--+--+--+--+--+--+--+--+--+  +--+--+--+  +",
        "|     |     |        |     |     |              |     |        |",
        "+--+  +  +--+  +--+--+  +  +  +  +  +--+--+--+  +--+  +  +--+--+",
        "|     |  |  @  |        |     |  |        |  |  | $   |     |  |",
        "+  +--+  +  +--+  +--+--+--+--+--+--+  +--+--+  +--+--+--+  +--+",
        "|  | #   |  |  |  |              |  |  |  @  |        |  |     |",
        "+  +--+--+  +--+  +  +--+--+--+  +  +  +  +  +--+  +  +--+--+  +",
        "|        |  |     |     |     |  |  |     |     |  |           |",
        "+  +--+  +  +  +--+--+  +--+  +  +--+--+--+--+  +  +--+--+--+--+",
        "|  |     |  |      $ |     |  |       $      |  |           |  |",
        "+  +  +--+  +--+--+--+--+  +  +--+--+--+--+  +  +--+  +--+  +--+",
        "|  |  |                    |              |  |     |  |  |     |",
        "+  +  +  +--+--+--+--+--+--+--+  +--+--+  +- +--+  +  +  +--+  +",
        "|  |        |     |                    |  |     |  |     |     |",
        "+  +--+--+  +  +  +  +--+  +--+--+  +--+--+  +  +  +--+  +  +--+",
        "|  |        |  |  |     |      $ |  |        |  |  |# |  |     |",
        "+  +  +--+--+  +  +--+  +  +--+--+--+  +--+--+--+  +  +  +--+  +",
        "|  |  |        |     |  |     |     |           |  |     |  |  |",
        "+  +  +  +--+--+--+--+  +--+  +  +--+--+--+--+  +  +--+--+--+  +",
        "|  |                       | #|     |  |  |     |  @     |  |  |",
        "+  +  +--+--+--+--+--+--+--+--+--+  +--+--+  +--+--+--+  +--+  +",
        "|  |   @    |     |  |        |  |  |  |              |  |     |",
        "+--+--+--+  +  +  +  +  +--+  +--+  +--+  +--+  +--+--+  +  +--+",
        "-           |  |  |  |  |  |        |  |  |     |     |       &-",
        "+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+",
        "                                                                ",
        "                                                                ",
        "                                                                ",
        "                                                                "
};

string maze3[27] = {
    ":--:--:--:--:--:--:--:--:--:--:--:--:--:--:--:",  
    "|              |                             |",  
    ":  :--:--:--:  :--:--:--:--:  :--:--:  :--:  :",  
    "|           |                 |        | #   |",  
    ":  :--:--:  :--:--:--:--:  :--:--:--:--:--:--:",  
    "|  |     |  |           |  |        @        |",  
    ":  :  :  :  :  :  :--:  :  :  :--:--:--:--:  :",  
    "|  |  |$ |  |  |  | #   |  |  |  |        |  |",  
    ":  :  :--:  :  :--:--:--:  :  :  :--:  :  :  :",  
    "|  |     |  |              |           |  |  |",  
    ":  :--:  :  :--:--:--:--:--:  :--:--:--:--:  :",  
    "| @   |  |            @       |              |",  
    ":--:  :  :--:--:--:--:--:--:--:  :--:--:--:  :",  
    "|  |  |                    |  @  |     | $|  |",  
    ":  :  :--:  :--:--:--:--:  :  :--:  :  :  :  :",  
    "|  |  |     |     |$    |  |  |     |     |  |",  
    ":  :  :  :--:--:  :--:  :  :  :  :--:--:--:  :",  
    "|     |  |              |  |  |              |",  
    ":--:  :  :  :--:--:--:  :  :  :  :--:--:--:--:",  
    "|$ |  |  |  |  | &   |  |  |  |  |           |",  
    ":  :  :  :  :  :--:  :  :  :  :  :  :--:--:  :",  
    "|  |  |  |  |        |  |  |  |  |  |     |  |",  
    ":  :  :  :  :  :--:--:  :  :  :  :  :  :  :  :",  
    "|  |  |  |  |        @  |  |  |  |  | #|  |  |",  
    ":  :  :  :  :--:--:--:--:  :  :  :  :--:  :  :",  
    "|     @  |                 |  |           |  |",  
    ":__:--:++:--:--:--:--:--:--:II:--:--:--:--:--:"  
     
};

void gotoxy(int x, int y) {
    Console::SetCursorPosition(x, y);
}
void changeColor(int x) {
    if (x == 1)Console::ForegroundColor = ConsoleColor::Cyan;
    if (x == 2)Console::ForegroundColor = ConsoleColor::Blue;
    if (x == 3)Console::ForegroundColor = ConsoleColor::Magenta;
    if (x == 4)Console::ForegroundColor = ConsoleColor::Red;
    if (x == 5)Console::ForegroundColor = ConsoleColor::Green;
    if (x == 6)Console::ForegroundColor = ConsoleColor::Yellow;
    if (x == 7)Console::ForegroundColor = ConsoleColor::Gray;
    if (x == 8)Console::ForegroundColor = ConsoleColor::DarkGreen;
    if (x == 9)Console::ForegroundColor = ConsoleColor::DarkRed;
    if (x == 10)Console::ForegroundColor = ConsoleColor::White;
    if (x == 11)Console::ForegroundColor = ConsoleColor::DarkCyan;
    if (x == 12)Console::ForegroundColor = ConsoleColor::DarkYellow;
}
void drawMaze() {
    for (int i = 0; i < 27; ++i) {
        gotoxy(5, 3+i);
        for (int j = 0; j < 66; ++j) {
            if (maze[i][j] == '@')changeColor(9);
            if (maze[i][j] == '$')changeColor(11);
            if (maze[i][j] == '&')changeColor(8);
            if (maze[i][j] == '#')changeColor(12);
            cout << maze[i][j];
            changeColor(10);
        }
    }
}
void drawMaze2() {
    for (int i = 0; i < 31; ++i) {
        gotoxy(5, 3 + i);
        for (int j = 0; j < 64; ++j) {
            if (maze2[i][j] == '@')changeColor(9);
            if (maze2[i][j] == '$')changeColor(11);
            if (maze2[i][j] == '&')changeColor(8);
            if (maze2[i][j] == '#')changeColor(12);
            cout << maze2[i][j];
            changeColor(10);
        }
    }
}
void drawMaze3() {
    for (int i = 0; i < 27; ++i) {
        gotoxy(5, 3 + i);
        for (int j = 0; j < 47; ++j) {
            if (maze3[i][j] == '@')changeColor(9);
            if (maze3[i][j] == '$')changeColor(11);
            if (maze3[i][j] == '&')changeColor(8);
            if (maze3[i][j] == '#')changeColor(12);
            cout << maze3[i][j];
            changeColor(10);
        }
    }
}
void printLine(int n, int a) {
    for (int i = 0; i < n; i++) {
        cout << (char)a;
    }
}
void printMarco() {
    gotoxy(0, 0);
    char cr = 219;
    for (int i = 0; i < width; i++)cout << cr;
    cout << endl;
    for (int i = 0; i < height - 2; i++) {
        for (int i = 0; i < width; i++)i == 0 || i == width - 1 ? cout << cr : cout << " ";
        cout << endl;
    }
    for (int i = 0; i < width; i++)cout << cr;
}
char displayMainMenu() {
    system("cls");
    printMarco();
    gotoxy(5, 3);   cout << "                                                                                 " << endl;
    gotoxy(5, 4);   cout << "                                /$$       /$$      /$$                            " << endl;
    gotoxy(5, 5);   cout << "                               | $$      | $$$    /$$$                            " << endl;
    gotoxy(5, 6);   cout << "                               | $$      | $$$$  /$$$$                            " << endl;
    gotoxy(5, 7);   cout << "                               | $$      | $$ $$/$$ $$                            " << endl;
    gotoxy(5, 8);   cout << "                               | $$      | $$  $$$| $$                            " << endl;
    gotoxy(5, 9);   cout << "                               | $$      | $$\\  $ | $$                            " << endl;
    gotoxy(5, 10);  cout << "                               | $$$$$$$$| $$ \\/  | $$                            " << endl;
    gotoxy(5, 11);  cout << "                               |________/|__/     |__/                            " << endl;
    gotoxy(5, 12);  cout << "                                                                                  " << endl;
    gotoxy(5, 13);  cout << "                                  1.- Nuevo Juego                                 " << endl;
    gotoxy(5, 14);  cout << "                                  2.- Intruciones                                    " << endl;
    gotoxy(5, 15);  cout << "                                  3.- Creditos                                       " << endl;
    gotoxy(5, 16);  cout << "                                  0.- Salir                                          " << endl;
    gotoxy(10, 17); cout << "                                                                                     " << endl;
    gotoxy(10, 18); cout << "                                                                                     " << endl;
    gotoxy(10, 19); cout << "                                                                                     " << endl;
    gotoxy(10, 20); cout << "                                             `. ___                                  " << endl;
    gotoxy(10, 21); cout << "                                            __,' __`.                _..----....____ " << endl;
    gotoxy(10, 22); cout << "                                __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'" << endl;
    gotoxy(10, 23); cout << "                          _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'    " << endl;
    gotoxy(10, 24); cout << "                        ,'________________                          \\`-._`-','       " << endl;
    gotoxy(10, 25); cout << "                         `._              ```````````------...___   '-.._'-:         " << endl;
    gotoxy(10, 26); cout << "                            ```--.._      ,.                     ````--...__\\-.      " << endl;
    gotoxy(10, 27); cout << "                                    `.--. `-`                       ____    |  |`    " << endl;
    gotoxy(10, 28); cout << "                                      `. `.                       ,'`````.  ;  ;`    " << endl;
    gotoxy(10, 29); cout << "                                        `._`.        __________   `.      \\'__/`   " << endl;
    gotoxy(10, 30); cout << "                                           `-:._____/______/___/____`.     \\  `    " << endl;
    gotoxy(10, 31); cout << "                                                       |       `._    `.    \\      " << endl;
    gotoxy(10, 32); cout << "                                                       `._________`-.   `.   `.___ " << endl;
    gotoxy(10, 33); cout << "                                                                          `------'`" << endl;
    gotoxy(39, 17); cout << "Seleccione una opcion: "; char op; cin >> op;
    return op;
}
void displayInstructions() {
    system("cls");
    printMarco();
    gotoxy(17, 10); cout << "Bienvenido a LaberintosMatamaticos! Tu misión es pasar el laberinto con vida";
    gotoxy(17, 12); cout << "INSTRUCCIONES                                                          ";
    gotoxy(19, 13); cout << " *Control : Usa W, A, S, D para moverte.                        ";
    gotoxy(19, 14); cout << " *Objetivo : Pasar los 3 niveles con vida.                  ";
    gotoxy(19, 15); cout << " *Rescate : .  ";
    gotoxy(19, 16); cout << " *Salida: En cada laberinto tienes que llegar a la salida representada por &.";
    gotoxy(19, 17); cout << " *Tutores: Los tutores representados por $ te daran consejos.";
    gotoxy(19, 18); cout << " *Elixir de Euler: Estan representados por # y te recuperan 50 de vida";
    gotoxy(19, 19); cout << " *Peligros :                                                           ";
    gotoxy(19, 20); cout << "   -Los enemigos.                                                      ";
    gotoxy(19, 21); cout << "   -Tienes 100 puntos de vida y score si alguno llega a 0 o menos pierdes  ";
    gotoxy(19, 22); cout << "   -Al chocar con un enemigo te hara una pregunta";
    gotoxy(19, 23); cout << "   -Si no respondes bien pierdes vida y score";
    gotoxy(17, 24); cout << "Buena suerte!";
    gotoxy(5, 32); system("pause");
}
void displayGameOver() {
    printMarco();
    gotoxy(12, 9); cout << "                   /$$     /$$   /$$$$$$   /$$   /$$ ";
    gotoxy(12, 10); cout << "                  |  $$   /$$/  /$$__  $$ | $$  | $$  ";
    gotoxy(12, 11); cout << "                   \\  $$ /$$/  | $$  \\ $$ | $$  | $$";
    gotoxy(12, 12); cout << "                    \\  $$$$/   | $$  | $$ | $$  | $$";
    gotoxy(12, 13); cout << "                     \\  $$/    | $$  | $$ | $$  | $$";
    gotoxy(12, 14); cout << "                      | $$     | $$  | $$ | $$  | $$";
    gotoxy(12, 15); cout << "                      | $$     |  $$$$$$/ |  $$$$$$/ ";
    gotoxy(12, 16); cout << "                      |__/      \\______/   \\______/";
    gotoxy(12, 17); cout << " /$$         /$$$$$$     /$$$$$$    /$$$$$$$$  /$$              /$$$";
    gotoxy(12, 18); cout << "| $$        /$$__  $$   /$$__  $$  | $$_____/ | $$            /$$_/ ";
    gotoxy(12, 19); cout << "| $$       | $$  \\ $$  | $$  \\__/  | $$       | $$       /$$ /$$/ ";
    gotoxy(12, 20); cout << "| $$       | $$  | $$  |  $$$$$$   | $$$$$    | $$      |__/| $$ ";
    gotoxy(12, 21); cout << "| $$       | $$  | $$   \\____  $$  | $$__/    |__/          | $$  ";
    gotoxy(12, 22); cout << "| $$       | $$  | $$   /$$  \\ $$  | $$                 /$$|  $$ ";
    gotoxy(12, 23); cout << "| $$$$$$$$ |  $$$$$$/  |  $$$$$$/  | $$$$$$$$  /$$      |__/ \\  $$$ ";
    gotoxy(12, 24); cout << "|________/  \\______/    \\______/   |________/ |__/            \\___/ ";
    gotoxy(4, 36); system("pause");

}
void displayVictory() {
    printMarco();
    gotoxy(6, 9); cout << "      /$$     /$$   /$$$$$$    /$$  /$$     / $$      /$$   /$$$$$$   /$$   /$$          ";
    gotoxy(6, 10); cout << "     |  $$   /$$/  /$$ __ $$  | $$  |$$     | $$  /$ | $$  |_ $$_/   | $$$ | $$          ";
    gotoxy(6, 11); cout << "      \\  $$ /$$/  | $$   \\$$  | $$  |$$     | $$ /$$$| $$   | $$     | $$$$| $$         ";
    gotoxy(6, 12); cout << "       \\  $$$$/   | $$   |$$  | $$  |$$     | $$/$$ $$ $$   | $$     | $$ $$ $$         ";
    gotoxy(6, 13); cout << "        \\  $$/    | $$   |$$  | $$  |$$     | $$$$ _  $$$$  | $$     | $$  $$$$         ";
    gotoxy(6, 14); cout << "         | $$     | $$   |$$  | $$  |$$     | $$$ / \\  $$$  | $$     | $$\\  $$$        ";
    gotoxy(6, 15); cout << "         | $$     | $$$$$$/   | $$$$$$/     | $$ /   \\  $$  /$$$$$$  | $$ \\  $$        ";
    gotoxy(6, 16); cout << "         |__/      \\______ /  \\______/      |__ /     \\__/ |______/  |__/  \\__/      ";
    gotoxy(6, 17); cout << "    /$$$$$$    /$$$$$$     /$$$$$$   /$$$$$$$       /$$$$$    /$$$$$$    /$$$$$$$   /$$  ";
    gotoxy(6, 18); cout << "   /$$__  $$  / $$__ $$   / $$__ $$  |$$__  $$     |__   $$  / $$__  $$ | $$__  $$ | $$  ";
    gotoxy(6, 19); cout << "  | $$  \\__/  | $$  \\$$   | $$  \\$$  | $$ \\ $$         | $$  | $$  \\$$  | $$  \\ $$ | $$  ";
    gotoxy(6, 20); cout << "  | $$ /$$$$  | $$  |$$   | $$  |$$  | $$ | $$         | $$  | $$  |$$  | $$$$$$$  | $$  ";
    gotoxy(6, 21); cout << "  | $$|_  $$  | $$  |$$   | $$  |$$  | $$ | $$    /$$  | $$  | $$  |$$  | $$__  $$ |__/  ";
    gotoxy(6, 22); cout << "  | $$  \\ $$  | $$  |$$   | $$  |$$  | $$ | $$   | $$  | $$  | $$  |$$  | $$  \\ $$       ";
    gotoxy(6, 23); cout << "  |  $$$$$$/  |  $$$$$$/  |  $$$$$$/ | $$$$$$$/  | $$$$$$/   |  $$$$$$/ | $$$$$$$/ /$$   ";
    gotoxy(6, 24); cout << "   \\______/    \\______/    \\______/  |_______/   \\______/     \\______/  |_______/ |__/   ";
    gotoxy(6, 26); cout << "Felicitaciones! ganaste y con un puntaje de: " << puntj;
    gotoxy(6, 27);
    system("pause");
}
void displayStats() {
    gotoxy(75, 4); printLine(19, 219);
    gotoxy(75, 9); printLine(19, 219);
    for (int i = 0; i < 4; i++) {
        gotoxy(75,5+i); cout << (char)219;
        gotoxy(93,5+i); cout << (char)219;
    }
    gotoxy(79, 6); cout << "Puntaje: " << puntj;
    gotoxy(79, 7); cout << "vida: " << vida;
    changeColor(9); gotoxy(75, 11); cout << "@ = Enemigos ";
    changeColor(11); gotoxy(75, 12); cout << "$ = Tutores ";
    changeColor(8); gotoxy(75, 13); cout << "& = Salida ";
    changeColor(12); gotoxy(75, 14); cout << "# = Curaciones ";
}
void displayCredits(){
    system("cls");
    printMarco();
    gotoxy(8,5); cout << "  /$$$$$$   /$$$$$$$   /$$$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$$  /$$$$$$    /$$$$$$";
    gotoxy(8,6); cout << " /$$__  $$ | $$__  $$ | $$_____/ | $$__  $$ |_  $$_/ |__  $$__/ /$$__  $$  /$$__  $$";
    gotoxy(8,7); cout << "| $$  \\__/ | $$  \\ $$ | $$       | $$  \\ $$   | $$      | $$   | $$  \\ $$ | $$  \\__/";
    gotoxy(8,8); cout << "| $$       | $$$$$$$/ | $$$$$    | $$  | $$   | $$      | $$   | $$  | $$ |  $$$$$$";
    gotoxy(8,9); cout << "| $$       | $$__  $$ | $$__/    | $$  | $$   | $$      | $$   | $$  | $$  \\____  $$";
    gotoxy(8,10); cout << "| $$    $$ | $$  \\ $$ | $$       | $$  | $$   | $$      | $$   | $$  | $$  /$$  \\ $$";
    gotoxy(8,11); cout << "|  $$$$$$/ | $$  | $$ | $$$$$$$$ | $$$$$$$/  /$$$$$$    | $$   |  $$$$$$/ |  $$$$$$/";
    gotoxy(8,12); cout << " \\______/  |__/  |__/ |________/ |_______/  |______/    |__/    \\______/   \\______/ ";
    gotoxy(8,16); cout << "                           ==========INTEGRANTES==========";
    gotoxy(8,18); cout << "                              GABRIEL MENDOZA PALACIOS";
    gotoxy(8,20); cout << "                              LEONARDO LAZARTE DAMIAN";
    gotoxy(8,24); cout << "                           ==========DOCENTE========== ";
    gotoxy(8,26); cout << "                              LUIS CANAVAL SANCHEZ";
    gotoxy(8,28); cout << "             _   _   ____     ____          ____     ___    ____    _  _";
    gotoxy(8,29); cout << "            | | | | |  _ \\  / ___|         |___ \\   / _ \\  | ___ \\ | || |";
    gotoxy(8,30); cout << "            | | | | | |_)| | |      _____    __) | | | | |   __) | | || |_";
    gotoxy(8,31); cout << "            | |_| | | __/  | |___  |_____|  / __/  | |_| |  / __/  |__   _|";
    gotoxy(8,32); cout << "             \\___/  |_|     \\____|         |_____|  \\___/  |_____|    |_| ";
    gotoxy(5, 35); system("pause");
}
void challengeS1_1(int number) {
    system("cls");
    changeColor(8); printMarco();
    gotoxy(3, 3); cout << "                             /$$$$$$$  /$$$$$$$$ /$$$$$$$$  /$$$$$$                    ";
    gotoxy(3, 4); cout << "                            | $$__  $$| $$_____/|__  $$__/ /$$__  $$                     ";
    gotoxy(3, 5); cout << "                            | $$  \\ $$| $$         | $$   | $$  \\ $$                   ";
    gotoxy(3, 6); cout << "                            | $$$$$$$/| $$$$$      | $$   | $$  | $$                     ";
    gotoxy(3, 7); cout << "                            | $$__  $$| $$__/      | $$   | $$  | $$                     ";
    gotoxy(3, 8); cout << "                            | $$  \\ $$| $$         | $$   | $$  | $$                    ";
    gotoxy(3, 9); cout << "                            | $$  | $$| $$$$$$$$   | $$   |  $$$$$$/                     ";
    gotoxy(3, 10); cout << "                            |__/  |__/|________/   |__/    \\______/                    ";
    gotoxy(3, 11); cout << "                                                                                      ";
    gotoxy(3, 12); cout << "                                                                                        "; changeColor(5);
    gotoxy(3, 13); cout << "      _       _                                                                         "; 
    gotoxy(3, 14); cout << "     (_\\     /_)                                                                       ";
    gotoxy(3, 15); cout << "       ))   ((                                                                          ";
    gotoxy(3, 16); cout << "     .'''''''''.                                                                        ";
    gotoxy(3, 17); cout << " /^\\/  _.   _.  \\/^\\                                                                 ";
    gotoxy(3, 18); cout << " \\(   /__\\ /__\\   )/                                                                 ";
    gotoxy(3, 19); cout << "  \\,  \\o_/_\\o_/  ,/                                                                  ";
    gotoxy(3, 20); cout << "    \\    (_)    /                                                                      ";
    gotoxy(3, 21); cout << "     `-.'==='.-'                                                                        ";
    gotoxy(3, 22); cout << "      __) - (__                                                                         "; changeColor(10);
    gotoxy(3, 23); cout << "     /  `~~~`  \\                                                     ____            ___";
    gotoxy(3, 24); cout << "    /  /     \\  \\                                          |        | ___\\          /~~~|";
    gotoxy(3, 25); cout << "    \\ :       ; /                                         _:_______|/'(..)`\\_______/  | |";
    gotoxy(3, 26); cout << "     \\|==(*)==|/                                         <_|``````  \\__~~__/       ___|_|";
    gotoxy(3, 27); cout << "      :       :                                            :\\_____(=========,(*),--\\__|_/";
    gotoxy(3, 28); cout << "       \\  |  /                                             |       \\       /---'       ";
    gotoxy(3, 29); cout << "     ___)=|=(___                                                    | (*) /            ";
    gotoxy(3, 30); cout << "    {____/ \\____}                                                   |____/             ";
    changeColor(12);
    gotoxy(3, 31); printLine(95, 203);
    gotoxy(3, 32); printLine(95, 219);
    gotoxy(3, 33); printLine(95, 219);
    gotoxy(3, 34); printLine(95, 219); 
    changeColor(10); gotoxy(39, 17);
    int sol;
    if (number == 1) {
        cout << "2 + 4: "; cin >> sol;
    }
    if (number == 2) {
        cout << "3 + 7 + 8: "; cin >> sol;
    }
    if (number == 3) {
        cout << "12 + 13 + 3: "; cin >> sol;
    }

    if ((sol == 6 && number==1) || (sol == 18 && number == 2) || (sol==28 && number==3)) {
        gotoxy(39, 18);cout << "Correcto! ganaste 30 puntos";
        puntj += 50;
        gotoxy(39, 19); system("pause");
        system("cls");
        printMarco();
        drawMaze();
        changeColor(8);displayStats();changeColor(10);
    }
    else {
        gotoxy(39, 18); cout << "Incorrecto :( perdiste 30 puntos y 20 puntos de vida";
        puntj -= 30;
        vida -= 30;
        gotoxy(39, 19); system("pause");
        system("cls");
        printMarco();
        drawMaze();
        changeColor(8);displayStats();changeColor(10);

    }
    if (vida <= 0 || puntj<0) { flag = 0; }
}
void challengeS2_1(int number) {
    system("cls");
    changeColor(8); printMarco();
    gotoxy(3, 3); cout << "                             /$$$$$$$  /$$$$$$$$ /$$$$$$$$  /$$$$$$                    ";
    gotoxy(3, 4); cout << "                            | $$__  $$| $$_____/|__  $$__/ /$$__  $$                     ";
    gotoxy(3, 5); cout << "                            | $$  \\ $$| $$         | $$   | $$  \\ $$                   ";
    gotoxy(3, 6); cout << "                            | $$$$$$$/| $$$$$      | $$   | $$  | $$                     ";
    gotoxy(3, 7); cout << "                            | $$__  $$| $$__/      | $$   | $$  | $$                     ";
    gotoxy(3, 8); cout << "                            | $$  \\ $$| $$         | $$   | $$  | $$                    ";
    gotoxy(3, 9); cout << "                            | $$  | $$| $$$$$$$$   | $$   |  $$$$$$/                     ";
    gotoxy(3, 10); cout << "                            |__/  |__/|________/   |__/    \\______/                    ";
    gotoxy(3, 11); cout << "                                                                                      ";
    gotoxy(3, 12); cout << "                                                                                        "; changeColor(5);
    gotoxy(3, 13); cout << "      _       _                                                                         ";
    gotoxy(3, 14); cout << "     (_\\     /_)                                                                       ";
    gotoxy(3, 15); cout << "       ))   ((                                                                          ";
    gotoxy(3, 16); cout << "     .'''''''''.                                                                        ";
    gotoxy(3, 17); cout << " /^\\/  _.   _.  \\/^\\                                                                 ";
    gotoxy(3, 18); cout << " \\(   /__\\ /__\\   )/                                                                 ";
    gotoxy(3, 19); cout << "  \\,  \\o_/_\\o_/  ,/                                                                  ";
    gotoxy(3, 20); cout << "    \\    (_)    /                                                                      ";
    gotoxy(3, 21); cout << "     `-.'==='.-'                                                                        ";
    gotoxy(3, 22); cout << "      __) - (__                                                                         "; changeColor(10);
    gotoxy(3, 23); cout << "     /  `~~~`  \\                                                     ____            ___";
    gotoxy(3, 24); cout << "    /  /     \\  \\                                          |        | ___\\          /~~~|";
    gotoxy(3, 25); cout << "    \\ :       ; /                                         _:_______|/'(..)`\\_______/  | |";
    gotoxy(3, 26); cout << "     \\|==(*)==|/                                         <_|``````  \\__~~__/       ___|_|";
    gotoxy(3, 27); cout << "      :       :                                            :\\_____(=========,(*),--\\__|_/";
    gotoxy(3, 28); cout << "       \\  |  /                                             |       \\       /---'       ";
    gotoxy(3, 29); cout << "     ___)=|=(___                                                    | (*) /            ";
    gotoxy(3, 30); cout << "    {____/ \\____}                                                   |____/             ";
    changeColor(12);
    gotoxy(3, 31); printLine(95, 203);
    gotoxy(3, 32); printLine(95, 219);
    gotoxy(3, 33); printLine(95, 219);
    gotoxy(3, 34); printLine(95, 219);
    changeColor(10); gotoxy(39, 17);
    double sol;
    if (number == 1) {
        cout << "3.1 + 4.5: "; cin >> sol;
    }
    if (number == 2) {
        cout << "3.2 + 7.7 + 2.6 "; cin >> sol;
    }
    if (number == 3) {
        cout << "12.12 + 17.45: "; cin >> sol;
    }
    if (number == 4) {
        cout << "14.56 + 15.34 + 2.23: "; cin >> sol;
    }
    if (number == 5) {
        cout << "103.455 + 12.545: "; cin >> sol;
    }

    if ((sol == 7.6 && number == 1) || (sol == 13.5 && number == 2) || (sol == 29.57 && number == 3) || (sol==32.13 && number==4) || (sol==116 && number==5)) {
        gotoxy(39, 18); cout << "Correcto! ganaste 30 puntos";
        puntj += 50;
        gotoxy(39, 19); system("pause");
        system("cls");
        printMarco();
        drawMaze2();
        changeColor(8);displayStats();changeColor(10);
    }
    else {
        gotoxy(39, 18); cout << "Incorrecto :( perdiste 30 puntos y 20 puntos de vida";
        puntj -= 30;
        vida -= 30;
        gotoxy(39, 19); system("pause");
        system("cls");
        printMarco();
        drawMaze2();
        changeColor(8);displayStats();changeColor(10);

    }
    if (vida <= 0 || puntj<0) { flag = 0; }
}
void challengeS3_1(int number) {
    system("cls");
    changeColor(8); printMarco();
    gotoxy(3, 3); cout << "                             /$$$$$$$  /$$$$$$$$ /$$$$$$$$  /$$$$$$                    ";
    gotoxy(3, 4); cout << "                            | $$__  $$| $$_____/|__  $$__/ /$$__  $$                     ";
    gotoxy(3, 5); cout << "                            | $$  \\ $$| $$         | $$   | $$  \\ $$                   ";
    gotoxy(3, 6); cout << "                            | $$$$$$$/| $$$$$      | $$   | $$  | $$                     ";
    gotoxy(3, 7); cout << "                            | $$__  $$| $$__/      | $$   | $$  | $$                     ";
    gotoxy(3, 8); cout << "                            | $$  \\ $$| $$         | $$   | $$  | $$                    ";
    gotoxy(3, 9); cout << "                            | $$  | $$| $$$$$$$$   | $$   |  $$$$$$/                     ";
    gotoxy(3, 10); cout << "                            |__/  |__/|________/   |__/    \\______/                    ";
    gotoxy(3, 11); cout << "                                                                                      ";
    gotoxy(3, 12); cout << "                                                                                        "; changeColor(5);
    gotoxy(3, 13); cout << "      _       _                                                                         ";
    gotoxy(3, 14); cout << "     (_\\     /_)                                                                       ";
    gotoxy(3, 15); cout << "       ))   ((                                                                          ";
    gotoxy(3, 16); cout << "     .'''''''''.                                                                        ";
    gotoxy(3, 17); cout << " /^\\/  _.   _.  \\/^\\                                                                 ";
    gotoxy(3, 18); cout << " \\(   /__\\ /__\\   )/                                                                 ";
    gotoxy(3, 19); cout << "  \\,  \\o_/_\\o_/  ,/                                                                  ";
    gotoxy(3, 20); cout << "    \\    (_)    /                                                                      ";
    gotoxy(3, 21); cout << "     `-.'==='.-'                                                                        ";
    gotoxy(3, 22); cout << "      __) - (__                                                                         "; changeColor(10);
    gotoxy(3, 23); cout << "     /  `~~~`  \\                                                     ____            ___";
    gotoxy(3, 24); cout << "    /  /     \\  \\                                          |        | ___\\          /~~~|";
    gotoxy(3, 25); cout << "    \\ :       ; /                                         _:_______|/'(..)`\\_______/  | |";
    gotoxy(3, 26); cout << "     \\|==(*)==|/                                         <_|``````  \\__~~__/       ___|_|";
    gotoxy(3, 27); cout << "      :       :                                            :\\_____(=========,(*),--\\__|_/";
    gotoxy(3, 28); cout << "       \\  |  /                                             |       \\       /---'       ";
    gotoxy(3, 29); cout << "     ___)=|=(___                                                    | (*) /            ";
    gotoxy(3, 30); cout << "    {____/ \\____}                                                   |____/             ";
    changeColor(12);
    gotoxy(3, 31); printLine(95, 203);
    gotoxy(3, 32); printLine(95, 219);
    gotoxy(3, 33); printLine(95, 219);
    gotoxy(3, 34); printLine(95, 219);
    changeColor(10); gotoxy(39, 17);
    double sol;
    if (number == 1) {
        cout << "3.5 + 2 * 1.5: "; cin >> sol;
    }
    if (number == 2) {
        cout << "(7.8 - 3.2) * 4: "; cin >> sol;
    }
    if (number == 3) {
        cout << "6 / 2.5 + 7: "; cin >> sol;
    }
    if (number == 4) {
        cout << "(5 + 2.1) * (3 - 1.5): "; cin >> sol;
    }
    if (number == 5) {
        cout << "10.5 - (4 + 2.2) * 3: "; cin >> sol;
    }
    if (number == 6) {
        cout << "(3.3 + 5) * 2 - 4.8 / 2: "; cin >> sol;
    }
    if ((sol == 6.5 && number == 1) || (sol == 18.4 && number == 2) || (sol == 9.4 && number == 3) ) {
        gotoxy(39, 18); cout << "Correcto! ganaste 30 puntos";
        puntj += 50;
        gotoxy(39, 19); system("pause");
        system("cls");
        printMarco();
        drawMaze3();
        changeColor(8);displayStats();changeColor(10);
    }
    else if ((sol == 10.65 && number == 4) || (sol == -8.1 && number == 5) || (sol == 14.2 && number == 6)) {
        gotoxy(39, 18); cout << "Correcto! ganaste 30 puntos";
        puntj += 50;
        gotoxy(39, 19); system("pause");
        system("cls");
        printMarco();
        drawMaze3();
        changeColor(8); displayStats(); changeColor(10);
    }
    else {
        gotoxy(39, 18); cout << "Incorrecto :( perdiste 30 puntos y 20 puntos de vida";
        puntj -= 30;
        vida -= 30;
        gotoxy(39, 19); system("pause");
        system("cls");
        printMarco();
        drawMaze3();
        changeColor(8);displayStats();changeColor(10);

    }
    if (vida <= 0 || puntj < 0) { flag = 0; }
}
void tutors(int number) {
    system("cls");
    printMarco();
    printMarco();
    gotoxy(3, 3);  cout << "                             /$$   /$$ /$$$$$$$$ /$$       /$$$$$$$                     ";
    gotoxy(3, 4);  cout << "                            | $$  | $$| $$_____/| $$      | $$__  $$                    ";
    gotoxy(3, 5);  cout << "                            | $$  | $$| $$      | $$      | $$  \\ $$                    ";
    gotoxy(3, 6);  cout << "                            | $$$$$$$$| $$$$$   | $$      | $$$$$$$/                    ";
    gotoxy(3, 7);  cout << "                            | $$__  $$| $$__/   | $$      | $$____/                     ";
    gotoxy(3, 8);  cout << "                            | $$  | $$| $$      | $$      | $$                          ";
    gotoxy(3, 9);  cout << "                            | $$  | $$| $$$$$$$$| $$$$$$$$| $$                          ";
    gotoxy(3, 10); cout << "                            |__/  |__/|________/|________/|__/                          ";
    gotoxy(3, 11); cout << "                                                                                        ";
    gotoxy(3, 12); cout << "                                                                                        "; 
    gotoxy(3, 13); cout << "                                                                                        ";
    gotoxy(3, 14); cout << "                                                                                        ";
    gotoxy(3, 15); cout << "        _..._                                                                           ";
    gotoxy(3, 16); cout << "      .'     '.      _                                                                  ";
    gotoxy(3, 17); cout << "     /    .----\\   _/ \\                                                               ";
    gotoxy(3, 18); cout << "   .-|   /:.   |  |   |                                                                 ";
    gotoxy(3, 19); cout << "   |  \\  |:.   /.-'-./                                                                 ";
    gotoxy(3, 20); cout << "   | .-'-;:__.'    =/                                                                   ";
    gotoxy(3, 21); cout << "   .'=  *=|     _.='                                                                    ";
    gotoxy(3, 22); cout << "  /   _.  |    ;                                                                        "; 
    gotoxy(3, 23); cout << " ;-.-'|    \\   |                                                      ____            ___";
    gotoxy(3, 24); cout << "/   | \\    _\\  _\\                                           |        | ___\\          /~~~|";
    gotoxy(3, 25); cout << "\\__/'._;.  ==' ==\\                                         _:_______|/'(..)`\\_______/  | |";
    gotoxy(3, 26); cout << "         \\    \\   |                                       <_|``````  \\__~~__/       ___|_|";
    gotoxy(3, 27); cout << "         /    /   /                                         :\\_____(=========,(*),--\\__|_/";
    gotoxy(3, 28); cout << "         /-._/-._/                                          |       \\       /---'       ";
    gotoxy(3, 29); cout << "         \\   `\\  \\                                                   | (*) /            ";
    gotoxy(3, 30); cout << "          `-._/._/                                                   |____/             ";
       
    changeColor(12);
    gotoxy(3, 31); printLine(95, 203);
    gotoxy(3, 32); printLine(95, 219);
    gotoxy(3, 33); printLine(95, 219);
    gotoxy(3, 34); printLine(95, 219);
    changeColor(10); gotoxy(32, 17);

    if (number == 1) {
        cout << "Recuerda que puedes usar los dedos para sumas pequeñas."; 
    }
    if (number == 2) {
        cout << "Para sumar 9, añade 10 y resta 1."; 
    }
    if (number == 3) {
        cout << "Cuando sumes números grandes, empieza por las unidades."; 
    }
    if (number == 4) {
        cout << "Alinea los puntos decimales antes de sumar.";
    }
    if (number == 5) {
        cout << "Agrega ceros para igualar las longitudes de los decimales.";
    }
    if (number == 6) {
        cout << "Suma de derecha a izquierda como en la suma de enteros.";
    }
    if (number == 7) {
        cout << "Revisa tu punto decimal en el resultado final.";
    }
    if (number == 8) {
        cout << "Multiplicación y división se resuelven de izquierda a derecha.";
    }
    if (number == 9) {
        cout << "Sigue el orden de operaciones: paréntesis primero.";
    }
    if (number == 10) {
        cout << "Simplifica expresiones complejas paso a paso.";
    }
    if (number == 11) {
        cout << "Revisa cada paso para evitar errores.";
    }
    gotoxy(32, 19); system("pause");
    system("cls");
    printMarco();
    if(number>0 && number<4)drawMaze();
    if (number>=4 && number<8)drawMaze2();
    if (number >= 8 && number < 12)drawMaze3();
    changeColor(8);displayStats();changeColor(10);
}


void level1() {
    printMarco();
    int x = 22, y = 26; 

    drawMaze();
    changeColor(8);displayStats();changeColor(10);
    gotoxy(x, y);
    cout << "X";

    int cc=0;
    int cc2 = 0;
    while (true) {
        if (_kbhit()) {
            char ch = _getch();

            gotoxy(x, y);
            cout << " ";

            int newX = x-5;
            int newY = y-3;

            if (ch == 'w' || ch == 'W') {
                newY--;
            }
            else if (ch == 's' || ch == 'S') {
                newY++;
            }
            else if (ch == 'a' || ch == 'A') {
                newX--;
            }
            else if (ch == 'd' || ch == 'D') {
                newX++;
            }
            if (maze[newY][newX] == '&')break;
            if (maze[newY][newX] == '#') {
                x = newX + 5;
                y = newY + 3;
                vida += 50;
                maze[newY][newX] = ' ';
                system("cls");
                printMarco();
                drawMaze();
                changeColor(8); displayStats(); changeColor(10);
            }
            if (maze[newY][newX] == '$') {
                x = newX + 5;
                y = newY + 3;
                cc2++;
                maze[newY][newX] = ' ';
                tutors(cc2);
            }
            if (maze[newY][newX] == ' ' || maze[newY][newX] == '@') {
                x = newX+5;
                y = newY+3;
                if (maze[newY][newX] == '@') {
                    cc++;
                    maze[newY][newX] = ' ';
                    challengeS1_1(cc);
                }
            }
            
            gotoxy(x, y);
            cout << "X";
        }
        if (vida <= 0 || puntj<0)break;
    }
}
void level2() {
    printMarco();
    int x = 12, y = 28;

    drawMaze2();
    changeColor(8);displayStats();changeColor(10);;
    gotoxy(x, y);
    cout << "X";

    int cc = 0;
    int cc2 = 3;
    while (true) {
        if (_kbhit()) {
            char ch = _getch();

            gotoxy(x, y);
            cout << " ";

            int newX = x - 5;
            int newY = y - 3;

            if (ch == 'w' || ch == 'W') {
                newY--;
            }
            else if (ch == 's' || ch == 'S') {
                newY++;
            }
            else if (ch == 'a' || ch == 'A') {
                newX--;
            }
            else if (ch == 'd' || ch == 'D') {
                newX++;
            }
            if (maze2[newY][newX] == '&')break;
            if (maze2[newY][newX] == '#') {
                x = newX + 5;
                y = newY + 3;
                vida += 50;
                maze2[newY][newX] = ' ';
                system("cls");
                printMarco();
                drawMaze2();
                changeColor(8); displayStats(); changeColor(10);
            }
            if (maze2[newY][newX] == '$') {
                x = newX + 5;
                y = newY + 3;
                cc2++;
                maze2[newY][newX] = ' ';
                tutors(cc2);
            }
            if (maze2[newY][newX] == ' ' || maze2[newY][newX] == '@') {
                x = newX + 5;
                y = newY + 3;
                if (maze2[newY][newX] == '@') {
                    cc++;
                    maze2[newY][newX] = ' ';
                    challengeS2_1(cc);
                }
            }

            gotoxy(x, y);
            cout << "X";
        }
        if (vida <= 0 || puntj<0)break;
    }

}
void level3() {
    printMarco();
    int x = 33, y = 28;

    drawMaze3();
    changeColor(8);displayStats();changeColor(10);;
    gotoxy(x, y);
    cout << "X";

    int cc = 0;
    int cc2 = 7;
    while (true) {
        if (_kbhit()) {
            char ch = _getch();

            gotoxy(x, y);
            cout << " ";

            int newX = x - 5;
            int newY = y - 3;

            if (ch == 'w' || ch == 'W') {
                newY--;
            }
            else if (ch == 's' || ch == 'S') {
                newY++;
            }
            else if (ch == 'a' || ch == 'A') {
                newX--;
            }
            else if (ch == 'd' || ch == 'D') {
                newX++;
            }
            if (maze3[newY][newX] == '&')break;
            if (maze3[newY][newX] == '#') {
                x = newX + 5;
                y = newY + 3;
                vida += 50;
                maze3[newY][newX] = ' ';
                system("cls");
                printMarco();
                drawMaze3();
                changeColor(8); displayStats(); changeColor(10);
            }
            if (maze3[newY][newX] == '$') {
                x = newX + 5;
                y = newY + 3;
                cc2++;
                maze3[newY][newX] = ' ';
                tutors(cc2);
            }
            if (maze3[newY][newX] == ' ' || maze3[newY][newX] == '@') {
                x = newX + 5;
                y = newY + 3;
                if (maze3[newY][newX] == '@') {
                    cc++;
                    maze3[newY][newX] = ' ';
                    challengeS3_1(cc);
                }
            }

            gotoxy(x, y);
            cout << "X";
        }
        if (vida <= 0 || puntj < 0)break;
    }

}

void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = width - 1;
    windowSize.Bottom = height - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

int main() {
    setConsoleSize(width, height);
    while (true) {
        char opcion = displayMainMenu();
        if (opcion == '1') {
            displayInstructions();
            if (flag)level1();
            if (flag)level2();
            if (flag)level3();
            if (flag)displayVictory();
            if (!flag)displayGameOver();
        }
        if (opcion == '2') {
            displayInstructions();
        }
        if (opcion == '3') {
            displayCredits();
        }
        if (opcion == '0')return 0;
    }
    
    system("pause");
    
    return 0;

}