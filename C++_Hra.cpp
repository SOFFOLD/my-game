#include <iostream>
#include <windows.h>
using namespace std;
void barva(int barva){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, barva);
}
void vesnice(int zlato, int zivoty , int mana, int sila, int maxHp, int maxmana){
    int a, b;
    cout << "Zde muzete:" << endl;
     do{
        cout << "(1)   Doplnovat si zivoty - 500 zlata" << endl;
        cout << "(2)   Vylepsit max zivoty - 500 zlata"<< endl;
        cout << "(3)   Vylepsit max manu - 500 zlata" << endl;
        cout << "(4)   Vylepsit damage/schopnosti - 500 zlata" << endl;
        cout << "(5)   Skip(jestli nemate zlato)"<<endl;
        cout << "Vase statistika: " << endl;
        cout << "   Zivoty: "<< zivoty<<"/"<<maxHp<<endl;
        cout << "   Mana: "<< mana<<"/"<<maxmana<<endl;
        cout << "   Sila: "<< sila <<endl;
        cout << "   Zlato: "<< zlato <<endl;
        cin >> a;
        switch (a){
            case 1:
                if(zlato >= 500){
                    if(zivoty == maxHp){
                        barva(4);
                        cout << "POZOR : Uz mate maximalne zivotu, vyberte si neco jineho"<< endl;
                        b = 1;
                        barva(7);
                    }else{
                        zivoty = maxHp;
                        zlato -= 500;
                        cout << "Mate ted :" << zivoty << "zivotu"<< endl;
                        barva(14);
                        cout << "Mate: "<< zlato << " zlata"<< endl;
                        barva(7);
                        cout << "Chcete si jeste neco vybrat? (0 = ne, 1 = ano): ";
                        do{
                        cin >> b;
                        }while(b > 1 || b <0);
                        cout << "--------------------------------------------" << endl;
                    }
                }else{
                    barva(4);
                    cout << "Nemate dostatek zlata"<< endl;
                    barva(7);
                    cout << "Vyberte si neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 2:
               if(zlato >= 500){
                    maxHp += 1;
                    zlato -= 500;
                    cout << "Vas maximalni pocet zivotu ted je: " << maxHp<< endl;
                    barva(14);
                    cout << "Mate: "<< zlato << " zlata"<< endl;
                    barva(7);
                    cout << "Chcete si jeste neco vybrat? (0 = ne, 1 = ano): " ;
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }else{
                    barva(4);
                    cout << "Nemate dostatek zlata"<< endl;
                    barva(7);
                    cout << "Vyberte si neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 3:
               if(zlato >= 500){
                    maxmana += 1;
                    zlato -= 500;
                    cout << "Vase maximalni pocet many ted je: " << maxmana << endl;
                    barva(14);
                    cout << "Mate: "<< zlato << " zlata"<< endl;
                    barva(7);
                    cout << "Chcete si jeste neco vybrat? (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }else{
                    barva(4);
                    cout << "Nemate dostatek zlata"<< endl;
                    barva(7);
                    cout << "Vyberte si neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 4:
               if(zlato >= 500){
                    sila += 1;
                    zlato -= 500;
                    cout << "Vas damage je ted: " << sila<< endl;
                    barva(14);
                    cout << "Mate: "<< zlato << " zlata"<< endl;
                    barva(7);
                    cout << "Chcete si jeste neco vybrat? (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }else{
                    barva(4);
                    cout << "Nemate dostatek zlata"<< endl;
                    barva(7);
                    cout << "Vyberte si neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 5:
                cout << "Jste si jisti? (0 = ne, 1 = ano): ";
                do{
                cin >> b;
                if(b==1){
                    b = 0;
                }else{
                    b = 1;
                }
                }while(b > 1 || b < 0);
            break;
        }
    }while(b != 0);
}
void paladin(){
    cout << "--------------------------------------------" << endl;
    cout << "Statistiky: " << endl;
    cout << "   Zivoty - 10/10" << endl;
    cout << "   Utok - 6"<< endl;
    cout << "   Mana - 10/10"<< endl;
    cout << "Schopnosti: " << endl;
    cout << "   Utok - Utok za 6 damage" << endl;
    cout << "   Bozsky vypad - 2 damage vsem nepratelum, mana - 4"<< endl;
    cout << "   Heal - +2 zivoty, mana - 2"<< endl;
}
void assasin(){
    cout << "--------------------------------------------" << endl;
    cout << "Statistiky: " << endl;
    cout << "   Zivoty - 6/6" << endl;
    cout << "   Utok - 8"<< endl;
    cout << "   Mana - 12/12"<< endl;
    cout << "Schopnosti: " << endl;
    cout << "   Utok - Utok za 8 damage" << endl;
    cout << "   Stinovy klon - vytvorite klona ktery zmizi po jednomu uderu po nem, mana - 4"<< endl;
    cout << "   Jedova dyka - dalsi utok ma 2x damage, mana - 3"<< endl;
}
void mag(){
    cout << "--------------------------------------------" << endl;
    cout << "Statistiky: " << endl;
    cout << "   Zivoty - 5/5" << endl;
    cout << "   Utok - 7"<< endl;
    cout << "   Mana - 15/15"<< endl;
    cout << "Schopnosti: " << endl;
    cout << "   Utok - Utok za 7 damage, mana - 1" << endl;
    cout << "   Ohniva koule - poslete ohnivou kouli na nepritele, mana - 5"<< endl;
    cout << "   Magicky vyboj - +2 zivoty, mana - 6"<< endl;
}
void strelec(){
    cout << "--------------------------------------------" << endl;
    cout << "Statistiky: " << endl;
    cout << "   Zivoty - 7/7" << endl;
    cout << "   Utok - 6"<< endl;
    cout << "   Mana - 8/8"<< endl;
    cout << "Schopnosti: " << endl;
    cout << "   Utok - Utok za 6 damage" << endl;
    cout << "   Prurazna strela - 6 damage vsem nepratelum, mana - 3"<< endl;
    cout << "   Ustupny vystrel - Vystreli a uskoci dozadu, mana - 2"<< endl;
}
int main(){
    int Hp = 1, zlato = 500, mana, maxmana, maxHp, sila,classy, y;
    string inventory[5] , Mc;
    if(Hp != 0){
    cout << "----------------Vitej v RPG hre----------------"<< endl;
    cout << "Vyber si class: "<< endl;
    do{
    cout << "Paladin = 1, assasin = 2, mag = 3, strelec = 4: "<< endl;
        do{
        cin >> classy;
        }while(classy < 1 || classy > 4);
        switch(classy){
            case 1:
                paladin();
                cout << "potvrdit? (0 = ne, 1 = ano): ";
                do{
                cin >> y;
                }while(y < 0 || y > 1);
                if(y == 0){
                    y = 0;
                    cout << "--------------------------------------------" << endl;
                }else{
                    cout << "Potvrzeni bylo uspesne, ted jste: PALADIN" << endl;
                    cout << "--------------------------------------------" << endl;
                    maxHp = 10;
                    Hp = 10;
                    sila = 6;
                    mana = 10;
                    maxmana = 10;
                }
            break;
            case 2:
                assasin();
                cout << "potvrdit? (0=ne, 1=ano): ";
                do{
                cin >> y;
                }while(y < 0 || y > 1);
                if(y == 0){
                    y = 0;
                    cout << "--------------------------------------------" << endl;
                }else{
                    cout << "Potvrzeni bylo uspesne, ted jste: ASSASIN" << endl;
                    cout << "--------------------------------------------" << endl;
                    Hp = 6;
                    maxHp = 6;
                    sila = 8;
                    mana = 12;
                    maxmana = 12;
                }
            break;
            case 3:
                mag();
                cout << "potvrdit? (0=ne, 1=ano): ";
                do{
                cin >> y;
                }while(y < 0 || y > 1);
                if(y == 0){
                    y = 0;
                    cout << "--------------------------------------------" << endl;
                }else{
                    cout << "Potvrzeni bylo uspesne, ted jste: MAG" << endl;
                    cout << "--------------------------------------------" << endl;
                    Hp = 5;
                    maxHp = 5;
                    sila = 7;
                    mana = 15;
                    maxmana = 15;
                }
            break;
            case 4:
                strelec();
                cout << "potvrdit? (0=ne, 1=ano): ";
                do{
                cin >> y;
                }while(y < 0 || y > 1);
                if(y == 0){
                    y = 0;
                    cout << "--------------------------------------------" << endl;
                }else{
                    cout << "Potvrzeni bylo uspesne, ted jste: STRELEC" << endl;
                    cout << "--------------------------------------------" << endl;
                    Hp = 7;
                    maxHp = 7;
                    sila = 6;
                    mana = 8;
                    maxmana = 8;
                }
            break;
        }
    }while(y == 0);

    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana);
    }else{
    return 0;
    }
}
