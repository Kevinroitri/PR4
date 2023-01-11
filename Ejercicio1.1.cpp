// Ejercicio1.1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <MMSystem.h>


using namespace std;

//Atributos del Enemigo1
int enemyHP = 100;
int enemyDmg = 0;
string enemyName = "Sauron";
bool enemyIsAlive = true;
//Atributos del Enemigo2
int enemyHP2 = 100;
int enemyDmg2 = 0;
string enemyName2 = "Hanzo";
bool enemyIsAlive2 = true;
//Atributos del personaje
int heroHP = 150;
int heroDamage;
int heroEspadaDmg = 30;
int ataqueEspada = 2;
int heroMagicDmg = 20;
int heroPunoDmg = 10;
string heroName;
bool heroIsAlive = true;
int enemigo;
string ataque;

//Atributos del juego

void enemyAttackDmg(int& damage, string& eName) {
    damage = 1 + (rand() % 25);
    heroHP = heroHP - damage;
    Sleep(500);
    cout << "El enemigo " << eName << " te ha atacado con " << damage << " y te quedan: " << heroHP << " PX\n";

}
void chuseAttack() {
    
    Sleep(500);
    cout << "Elige tu abilidad de ataque con el enemigo: " << enemigo << " Atque magico [1] Ataque con espada [2] Ataque con punetazo [3] \n";
    cin >> ataque;
    Sleep(500);

    if (ataque == "1") {
        
        Sleep(500);
        cout << "has elegido el ataque: " << ataque << "\n";
        heroDamage = heroMagicDmg;
    }
    else if (ataque == "2") {
        Sleep(500);
        cout << "has elegido el ataque: " << ataque << "\n";

        if (ataqueEspada == 0) {
            
            Sleep(500);
            cout << "Ataque no disponible \n";
            
            Sleep(500);
            cout << "Elige tu abilidad de ataque con el enemigo: " << enemigo << " Atque magico [1] Ataque con punetazo [3] \n";
            cin >> ataque;
            if (ataque == "1") {
                Sleep(500);
                cout << "has elegido el ataque: " << ataque << "\n";
                heroDamage = heroMagicDmg;
            }
            else if (ataque == "3") {
                Sleep(500);
                cout << "has elegido el ataque: " << ataque << "\n";
                heroDamage = heroPunoDmg;
            }
        }
        else {

            heroDamage = heroEspadaDmg;
            ataqueEspada = ataqueEspada - 1;
        }
    }
    else if (ataque == "3") {
        Sleep(500);
        cout << "has elegido el ataque: " << ataque << "\n";
        heroDamage = heroPunoDmg;
    }
}
bool ataqueEnemy(string& eName, string& eName2, int& damage, int& damage2, int& eHP, int& eHP2) {

    if (eHP > 0) {
        Sleep(500);
        cout << "\t" << "Le metes un golpe de " << heroDamage << " de DMG!\n";
        eHP = eHP - heroDamage;
    }
    if (eHP <= 0) {
        Sleep(500);
        cout << "Te has cargado al enemigo " << eName << "\n";
        enemyIsAlive = false;
        PlaySound(TEXT("muerte.wav"), NULL, SND_RESOURCE | SND_ASYNC);
    }
    else if (enemigo == 1) {
        Sleep(500);
        cout << "El enemigo " << eName << " tiene: " << eHP << " PX\n";
    }
    else {
        Sleep(500);
        cout << "El enemigo " << eName2 << " tiene: " << eHP2 << " PX\n";
    }
    if (enemyIsAlive) {
        enemyAttackDmg(damage, eName);

    }
    if (enemyIsAlive2) {
        enemyAttackDmg(damage2, eName2);
        return false;
    }
}
void firstEnemy() {
        chuseAttack();
        ataqueEnemy(enemyName, enemyName2, enemyDmg, enemyDmg2, enemyHP, enemyHP2);
}
void secondEnemy() {  
        chuseAttack();       
        ataqueEnemy(enemyName, enemyName2, enemyDmg, enemyDmg2, enemyHP2, enemyHP);
}
void gameIntro() {

    cout << "los enemigos " << enemyName << " y " << enemyName2 << " han aparecido \n";
    Sleep(500);
    cout << "Como se llama el heroe? \n ";
    cin >> heroName;
    Sleep(500);
    cout << "El nombre del presonaje es " << heroName << "\n";
    Sleep(500);
    srand(time(NULL));

}
int OpcionCorrectaSimple(string& eName) {
    
    int enemigoselecionado = 0;
    int correctChoice = 0;
    while (correctChoice == 0) {
        Sleep(500);
        cout << "Escoje al enemigo que deseas atacar " << eName << " con el numero [2]: \n";
        cin >> enemigoselecionado;
        if (enemigoselecionado == 2) {
            correctChoice = 1;
        }
        else {
            Sleep(500);
            cout << "Escoje una opcion valdia\n";

        }
    }
    return enemigoselecionado;

}
int opcioCorrecta() {
    
    int enemigoselecionado = 0;
    int correctChoice = 0;
    if (enemyIsAlive == true && enemyIsAlive2 == true) {

        while (correctChoice == 0) {
            Sleep(500);
            cout << "Escoje al enemigo que deseas atacar " << enemyName << " con el numero [1] " << enemyName2 << " con el numero [2]: \n";
            cin >> enemigoselecionado;
            if (enemigoselecionado == 1) {
                correctChoice = 1;
            }
            else if (enemigoselecionado == 2) {
                correctChoice = 1;
            }
            else {
                Sleep(500);
                cout << "Escoje una opcion valdia\n";

            }
        }
    }
    else if (enemyIsAlive == true && enemyIsAlive2 == false) {

        OpcionCorrectaSimple(enemyName);

    }
    else if (enemyIsAlive == false && enemyIsAlive2 == true) {

        OpcionCorrectaSimple(enemyName2);
    }
    return enemigoselecionado;
}
void endGame() {
    
    if (heroHP <= 0) {
        Sleep(500);
        cout << "GAME OVER";
        PlaySound(TEXT("muerte.wav"), NULL, SND_RESOURCE | SND_ASYNC);
    }

    if (enemyHP <= 0 && enemyHP2 <= 0) {
        Sleep(500);
        cout << "HAS GANADO LA PARTIDA";
    }

}


int main() {
    
    gameIntro();

    while (heroHP > 0 && (enemyHP > 0 || enemyHP2 > 0)) {

        enemigo = opcioCorrecta();

        if ((enemigo == 1) && (enemyIsAlive = true)) {

            firstEnemy();

        }
        else if ((enemigo == 2) && (enemyIsAlive2 = true)) {

            secondEnemy();

        }
        endGame();
    }
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
