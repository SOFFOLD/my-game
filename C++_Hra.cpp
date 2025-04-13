#include <iostream>
using namespace std;
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
    int Hp, zlato, mana, sila,classy;
    string inventory[5] , Mc;

    cout << "----------------Vitej v RPG hre--------------"<< endl;
    cout << "Vyber si class: "<< endl;
    cout << "Paladin = 1, assasin = 2, mag = 3, strelec = 4: "<< endl;
    do{
    cin >> classy;
    }while(classy <= 1 && classy >= 4);
    switch(classy){
        case 1:
            paladin();
            Hp = 10;
            sila = 6;
            mana = 10;
        break;
        case 2:
            assasin();
            Hp = 6;
            sila = 8;
            mana = 12;
        break;
        case 3:
            mag();
            Hp = 5;
            sila = 7;
            mana = 15;
        break;
        case 4:
            strelec();
            Hp = 7;
            sila = 6;
            mana = 8;
        break;
        default:
        cout << "Vyberte znovu";
    }
}
