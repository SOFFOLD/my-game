#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int expm(){
    return rand() % 5 + 3;
    }

int expmi(){
    return rand() % 10 + 5;
    }

int ranc(){
    return rand() % 3 + 1;
    }

int ranz1(){
    return rand() % 6 + 2;
    }

int ranz2(){
    return rand() % 13 + 6;
    }

int ranm(){
    return rand() % 2 + 1;
    }

void stats(int zivoty, int sila, int mana, int maxmana, int maxzivoty, int zlato){
    cout << "Vase statistika: " << endl;
    cout << "   Zivoty: "<< zivoty<<"/"<<maxzivoty<<endl;
    cout << "   Mana: "<< mana<<"/"<<maxmana<<endl;
    cout << "   Sila: "<< sila <<endl;
    cout << "   Zlato: "<< zlato <<endl;
}
void barva(int barva){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, barva);
}
bool alldead(int M[], int b) {
    for (int a = 0; a < b; a++){
        if (M[a] > 0){
            return false;
        }
    }
    return true;
}

void boj(int &zlato, int &zivoty , int &mana, int &sila, int &maxHp, int &maxmana, string skill1, string skill2,string skill3, string skill4,int skil1, int skil2,bool skilll1,bool skilll2, string klass, int Msila, int M[], int b, int &p){
    int s, u = 1;
    bool jedovatadyka = false;
    do{
        u = 1;
        cout << "Vyberte utok: " << endl;
        cout << "1)    Obycejny utok: " << sila << " sily" << endl;
        if(skilll1 == true){
            cout << "2)    " << skill1 << skil1 << skill2 << endl;
        }else{
            cout << "2)    " << skill1 << endl;
        }
        if(skilll2 == true){
            cout << "3)    " << skill3 << skil2 << skill4 << endl;
        }else{
            cout << "2)    " << skill3 << endl;
        }
        cin >> s;
        while(s > 3 || s < 1) cin >> s;
        switch(s){
            case 1:
                for(int a = 0; a < b; a++){
                    if(klass == "assasin" && jedovatadyka == true){
                        int sila2 = sila;
                        sila2 *= 2;
                        jedovatadyka = false;
                        if(M[a] > 0){
                            M[a] -= sila2*2;
                            if(M[a] < 0){
                                M[a] = 0;
                                cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                                break;
                            }
                        }
                    }else if (klass == "mag") {
                        if (mana < 1) {
                            cout << "Nemate dostatek many: " << mana << endl;
                            u = 0;
                        } else {
                            if(M[a] > 0){
                                M[a] -= sila;
                                if(M[a] < 0){
                                    M[a] = 0;
                                    cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                                    break;
                                    mana -= 1;
                                }
                            }
                        }
                    }else{
                        if(M[a] > 0){
                            M[a] -= sila;
                            if(M[a] < 0){
                                M[a] = 0;
                                cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                                break;
                            }
                        }
                    }
                }
                break;
            case 2:
                if(klass == "paladin"){
                    if(mana >= 3){
                        for(int a = 0; a < b; a++){
                            M[a] -= 3;
                            if(M[a] < 0) M[a] = 0;
                            cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                        }
                        mana -= 2;
                    } else {
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                } else if(klass == "assasin"){
                    if(mana >= 5){
                        zivoty += Msila*b;
                        mana -= 5;
                    } else {
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                        }
                } else if(klass == "mag"){
                    if(mana >= 6){
                        for(int a = 0; a < b; a++){
                            if(M[a] > 0){
                                M[a] -= 9;
                                if(M[a] < 0) M[a] = 0;
                                cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                                break;
                            }
                        }
                        mana -= 6;
                    } else {
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                        }
                } else if(klass == "strelec"){
                    if(mana >= 4){
                        for(int a = 0; a < b; a++){
                            M[a] -= 6;
                            if(M[a] < 0) M[a] = 0;
                        }
                        mana -= 4;
                    } else {
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                }
                break;
            case 3:
                if(klass == "paladin"){
                    if(mana >= 6){
                        if(zivoty == maxHp){
                            cout << "Uz mate maximalne zivotu: " << zivoty << endl;
                            u = 0;
                        }else{
                            zivoty += b*2;
                            cout << "Ted mate: " << zivoty << " zivotu" << endl;
                            if(zivoty > maxHp) zivoty = maxHp;
                        }
                        mana -= 6;
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                } else if(klass == "assasin"){
                    if(mana >= 3){
                            jedovatadyka = true;
                            mana -= 3;
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                }else if(klass == "mag"){
                    if(mana >= 4){
                        if(zivoty == maxHp){
                            cout << "Uz mate maximalne zivotu" << endl;
                        }else{
                            zivoty += 5;
                            if(zivoty > maxHp) zivoty = maxHp;
                        }
                        mana -= 4;
                        cout << "Ted mate " << zivoty << " zivotu" << endl;
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                } else if(klass == "strelec"){
                    if(mana >= 3){
                        zivoty += Msila*b;
                        for(int a = 0; a < b; a++){
                            if(M[a] > 0){
                                M[a] -= sila;
                                if(M[a] < 0) M[a] = 0;
                            }
                        }
                        for(int a = 0; a < b; a++){
                            cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                            mana -= 3;
                        }
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                }
                break;
        }
        cout << "--------------------------------------------" << endl;
        if (alldead(M,b)){
            p = 1;
            cout << "Zabili jste " << b << " monstrum" << endl;
        }
    }while(u != 1);
}

void monstrum(int &zlato, int &zivoty, int &mana, int sila, int &maxHp, int &maxmana, string skill1, string skill2,string skill3, string skill4,int skil1, int skil2,bool skilll1,bool skilll2, string klass, int M[], int b, int &p, int &expi, int &exp, int &level){
    int Msila = 1;
    for(int a = 0; a < 3 ; a++){
        M[a] = 0;
    }
    for(int a = 0; a < b ; a++){
        M[a] = 5;
    }
    do {
        boj(zlato,zivoty,mana,sila,maxHp,maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,Msila,M,b,p);
        if(p == 0){
            cout << "Monstrum na tahu" << endl;
            for(int a = 0; a < b; a++) if(M[a] > 0){
                cout << "-" << Msila << " zivotu od monstrum" << endl;
                zivoty -= Msila;
            }
        }else{
            break;
        }
    } while(!alldead(M,b) && zivoty > 0);
    if (zivoty <= 0){
        cout << "--------------PROHRALI JSTE--------------"<<endl;
    }else if(alldead(M,b)){
        cout << "--------V tomto setkani jste vyhrali--------" << endl;
        for(int a = 0; a < b; a++){
            if(ranm() == 1){
                int z = ranz1();
                zlato += z;
                barva(14);
                cout << "Dostali jste + " << z << " zlata"<< endl;
                barva(7);
                expi += expm();
            }
        }
        if(expi >= exp) {
            expi -= exp;
            level++;
            expi -= exp;
            zivoty = maxHp;
            mana = maxmana;
            barva(1);
            cout << "Novy level: " << (level-1) << " => " << level << endl;
            barva(7);
            int r = ranc();
            if (r == 1) {
                sila += 1;
                cout << "Ted mate " << sila << " sily" << endl;
            }
            else if (r == 2) {
                maxHp += 1;
                cout << "Ted mate " << maxHp << " maximalnich zivotu" << endl;
            }
            else {
                maxmana += 1;
                cout << "Ted mate " << maxmana << " maximalni many" << endl;
            }
        }
    }
}


void miniboss(int &zlato, int &zivoty, int &mana, int sila, int &maxHp, int &maxmana, string skill1, string skill2,string skill3, string skill4,int skil1, int skil2,bool skilll1,bool skilll2, string klass, int MB[], int b, int &p, int &expi, int &exp, int &level){
    int MBsila = 2;
    MB[0] = 15;
    do {
        boj(zlato,zivoty,mana,sila,maxHp,maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,MBsila,MB,b,p);
        if(p == 0){
            cout << "Mini boss na tahu" << endl;
            if(MB[0] > 0) cout << "-" << MBsila << " zivotu od mini bosse" << endl;
            zivoty -= MBsila;
        } else break;
    } while(p != 1 && zivoty > 0);
    if (zivoty <= 0){
        cout << "--------------PROHRALI JSTE--------------" << endl;
    }else{
        cout << "--------V tomto setkani jste vyhrali--------" << endl;
        int z = ranz2();
        zlato += z;
        barva(14); cout << "Dostali jste + " << z << " zlata" << endl; barva(7);
        expi += expmi();
        if(expi >= exp) {
            expi -= exp;
            level++;
            expi -= exp;
            zivoty = maxHp;
            mana = maxmana;
            cout << "Novy level: " << (level-1) << " => " << level << endl;
            int r = ranc();
            if (r == 1) {
                sila += 1;
                cout << "Ted mate " << sila << " sily" << endl;
            }
            else if (r == 2) {
                maxHp += 1;
                cout << "Ted mate " << maxHp << " maximalnich zivotu" << endl;
            }
            else {
                maxmana += 1;
                cout << "Ted mate " << maxmana << " maximalni many" << endl;
            }
        }
    }
}

void Geargrind(int &zlato ,int &zivoty ,int &mana,int sila ,int &maxHp ,int &maxmana ,string skill1 ,string skill2 ,string skill3, string skill4,int skil1, int skil2,bool skilll1,bool skilll2,string klass,int B[],int b,int &p){
    int Bsila = 3, k;
    B[0] = 50;
    do{
        boj(zlato,zivoty,mana,sila,maxHp,maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,Bsila,B,b,p);
        if(p == 0){
           cout << "Geargrind na tahu" << endl;
        if(ranc() == 1){
            cout << "Geargrind je na hranici roztrzeni, ale utoci jako nikdy predtim!" << endl;
            Bsila *= 2;
            k = 1;
        }
            for(int a = 0; a < b;a++){
                if(B[a] > 0){
                    cout << "-" << Bsila << " zivotu od Geargrindu" << endl;
                }
            }
            zivoty -= Bsila;
        }else{
            break;
        }
        if(k == 1){
            Bsila /= 2;
            k = 0;
        }
        srand(time(0));
        Bsila += 3;
    }while(!alldead(B,b) && zivoty > 0);
    if (zivoty <= 0){
            cout << "--------------PROHRALI JSTE--------------"<<endl;
        }else if(alldead(B,b)){
            cout << "--------Zabili jste hlavniho bosse, konec hry--------" << endl;
        }
}


void vesnice(int &zlato, int &zivoty , int &mana, int &sila, int &maxHp, int &maxmana, int skil1, int skil2,bool skilll1,bool skilll2){
    int a, b = 0, v,t;
    cout << "Zde muzete:" << endl;
     do{
        cout << "(1)   Doplnit si zivoty - 4 zlata" << endl;
        cout << "(2)   Vylepsit max zivoty - 7 zlata"<< endl;
        cout << "(3)   Doplnit si manu - 4 zlata" << endl;
        cout << "(4)   Vylepsit max manu - 7 zlata" << endl;
        cout << "(5)   Vylepsit damage/schopnosti - 9 zlata" << endl;
        cout << "(6)   Skip"<<endl;
        stats(zivoty,sila,mana,maxmana,maxHp,zlato);
        cin >> a;
        switch (a){
            case 1:
                if(zlato >= 4){
                    if(zivoty == maxHp){
                        barva(4);
                        cout << "POZOR : Uz mate maximalne zivotu, vyberte si neco jineho"<< endl;
                        b = 1;
                        barva(7);
                        cout << "--------------------------------------------" << endl;
                    }else{
                        zivoty = maxHp;
                        zlato -= 4;
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
                    cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b < 0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 2:
               if(zlato >= 7){
                    maxHp += 1;
                    zivoty = maxHp;
                    zlato -= 7;
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
                    cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 3:
                if(zlato >= 4){
                    if(mana == maxmana){
                        barva(4);
                        cout << "POZOR : Uz mate maximalne many, vyberte si neco jineho"<< endl;
                        b = 1;
                        barva(7);
                        cout << "--------------------------------------------" << endl;
                    }else{
                        mana = maxmana;
                        zlato -= 4;
                        cout << "Mate ted :" << mana << "many"<< endl;
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
                    cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b < 0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 4:
               if(zlato >= 7){
                    maxmana += 1;
                    mana = maxmana;
                    zlato -= 7;
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
                    cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                    do{
                    cin >> b;
                    }while(b > 1 || b <0);
                    cout << "--------------------------------------------" << endl;
                }
            break;
            case 5:
                cout << "Co si chcete vylepsit(damage - 1, schopnost - 2): ";
                cin >> v;
                if(v == 1){
                    if(zlato >= 9){
                        sila += 1;
                        zlato -= 9;
                        cout << "Vas damage je ted: " << sila<< endl;
                        barva(14);
                        cout << "Mate: "<< zlato << " zlata"<< endl;
                        barva(7);
                        cout << "Chcete si jeste neco vybrat? (0 = ne, 1 = ano): ";
                        do{
                            cin >> b;
                        }while(b > 1 || b < 0);
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
                }else{
                    cout << "Jaky skill si chcete vylepsit(prvni - 1, druhy - 2): ";
                    cin >> t;
                    if(t == 1){
                        if(skilll1 == true){
                            if(zlato >= 9){
                                skil1 += 1;
                                zlato -= 9;
                                cout << "Upgrade prvniho skilu o 1" << endl;
                                barva(14);
                                cout << "Mate: "<< zlato << " zlata"<< endl;
                                barva(7);
                                cout << "Chcete si jeste neco vybrat? (0 = ne, 1 = ano): ";
                                do{
                                    cin >> b;
                                }while(b > 1 || b < 0);
                                cout << "--------------------------------------------" << endl;
                            }else{
                                barva(4);
                                cout << "Nemate dostatek zlata"<< endl;
                                barva(7);
                                cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                                do{
                                    cin >> b;
                                }while(b > 1 || b <0);
                                cout << "--------------------------------------------" << endl;
                            }
                        }else{
                            cout << "Tuto schopnost nemuzete vylepsit" << endl;
                            cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                            do{
                                cin >> b;
                            }while(b > 1 || b <0);
                            cout << "--------------------------------------------" << endl;
                        }

                    }else if(t == 2){
                        if(skilll2 == true){
                            if(zlato >= 9){
                                skil2 += 1;
                                zlato -= 9;
                                cout << "Upgrade druheho skilu o 1" << endl;
                                barva(14);
                                cout << "Mate: "<< zlato << " zlata"<< endl;
                                barva(7);
                                cout << "Chcete si jeste neco vybrat? (0 = ne, 1 = ano): ";
                                do{
                                    cin >> b;
                                }while(b > 1 || b < 0);
                                cout << "--------------------------------------------" << endl;
                            }else{
                                barva(4);
                                cout << "Nemate dostatek zlata"<< endl;
                                barva(7);
                                cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                                do{
                                    cin >> b;
                                }while(b > 1 || b <0);
                                cout << "--------------------------------------------" << endl;
                            }
                        }else{
                            cout << "Tuto schopnost nemuzete vylepsit" << endl;
                            cout << "Chcete si vybrat neco jineho (0 = ne, 1 = ano): ";
                            do{
                                cin >> b;
                            }while(b > 1 || b <0);
                            cout << "--------------------------------------------" << endl;
                        }
                    }
                }
            break;
            case 6:
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
    cout << "   Bozsky vypad - 2 damage vsem nepratelum, mana - 3"<< endl;
    cout << "   Bozi pozehnani - Heal - +3 zivoty za kazdeho monstra, mana - 6"<< endl;
}
void assasin(){
    cout << "--------------------------------------------" << endl;
    cout << "Statistiky: " << endl;
    cout << "   Zivoty - 6/6" << endl;
    cout << "   Utok - 8"<< endl;
    cout << "   Mana - 12/12"<< endl;
    cout << "Schopnosti: " << endl;
    cout << "   Utok - Utok za 8 damage" << endl;
    cout << "   Stinovy klon - vytvorite klona ktery zmizi po jednomu uderu po nem, mana - 5"<< endl;
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
    cout << "   Ohniva koule - poslete ohnivou kouli na nepritele, mana - 6"<< endl;
    cout << "   Magicky vyboj - +5 zivoty, mana - 4"<< endl;
}
void strelec(){
    cout << "--------------------------------------------" << endl;
    cout << "Statistiky: " << endl;
    cout << "   Zivoty - 7/7" << endl;
    cout << "   Utok - 6"<< endl;
    cout << "   Mana - 8/8"<< endl;
    cout << "Schopnosti: " << endl;
    cout << "   Utok - Utok za 6 damage" << endl;
    cout << "   Prurazna strela - 6 damage vsem nepratelum, mana - 4"<< endl;
    cout << "   Ustupny vystrel - Vystreli a uskoci dozadu, mana - 3"<< endl;
}
int main(){
    srand(time(0));
    int Hp = 1, zlato = 8, mana, maxmana, maxHp, sila, classy, y, b=1, M[3],p=0,MB[1],B[1],exp = 20, n = 2, expi, level = 1, skil1, skil2;
    string skill1,skill2,skill3,skill4,klass;
    bool skilll1 = true,skilll2 = true;
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
                    skill1 = "Bozsky vypad - ";
                    skill2 = " damage vsem nepratelum, mana - 3";
                    skil1 = 2;
                    skill3 = "Bozi pozehnani - Heal - ";
                    skill4 = " zivoty za kazdeho monstra, mana - 6";
                    skil2 = 3;
                    klass = "paladin";
                }
            break;
            case 2:
                assasin();
                cout << "potvrdit? (0 - ne, 1 - ano): ";
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
                    skill1 = "Stinovy klon - vytvorite klona ktery zmizi po jednomu uderu po nem, mana - 5";
                    skilll1 = false;
                    skill3 = "Jedova dyka - dalsi utok ma 2x damage, mana - 3";
                    skilll2 = false;
                    klass = "assasin";
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
                    skill1 = "Ohniva koule - poslete ohnivou kouli na nepritele, ";
                    skill2 = " damage, mana - 6";
                    skil1 = 9;
                    skill3 = "Magicky vyboj - + ";
                    skill4 = " zivoty, mana - 4";
                    skil2 = 5;
                    klass = "mag";
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
                    skill1 = "Prurazna strela - ";
                    skill2 = " damage vsem nepratelum, mana - 4";
                    skill3 = "Ustupny vystrel - Vystreli a uskoci dozadu, mana - 3";
                    skilll2 = false;
                    klass = "strelec";
                }
            break;
        }
    }while(y == 0);

    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana,skil1,skil2,skilll1,skilll2);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "--------------------------------------------" << endl;
    cout << "Potkali jste monstrum" << endl;
    b = 1;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste monstrum" << endl;
    b = 1;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste mini Bosse" << endl;
    b = 1;
    p = 0;
    miniboss(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,MB,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana,skil1,skil2,skilll1,skilll2);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "--------------------------------------------" << endl;
    cout << "Potkali jste monstrum" << endl;
    b = 1;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste mini Bosse" << endl;
    b = 1;
    p = 0;
    miniboss(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,MB,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana,skil1,skil2,skilll1,skilll2);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 3 monstra" << endl;
    b = 3;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,M,b,p,expi,exp,level);
    if(Hp <= 0){
        return 0;
    }
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana,skil1,skil2,skilll1,skilll2);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste hlavniho bosse" << endl;
    b = 3;
    p = 0;
    Geargrind(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,skill3,skill4,skil1,skil2,skilll1,skilll2,klass,B,b,p);
    if(Hp <= 0){
        return 0;
    }
}
