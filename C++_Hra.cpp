#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int expm(){
    srand(time(0));
    int expim = rand() % 5 + 3;
    return expim;
}
int ranc() {
    srand(time(0));
    int randc = rand() % 3 + 1;
    return randc;
}
int ranz1(){
    int randz1 = rand() % 9 + 3;
    return randz1;
}
int ranz2(){
    int randz2 = rand() % 11 + 5;
    return randz2;
}
int ranm(){
    srand(time(0));
    int randm = rand() % 2 + 1;
    return randm;
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
    for (int a = 0; a < b; a++) {
        if (M[a] > 0) return false;
    }
    return true;
}

void boj(int &zlato, int &zivoty , int &mana, int &sila, int &maxHp, int &maxmana, string skill1, string skill2,string klass,int Msila,int M[],int b,int &p){
    int s,u = 1;
    do{
        u = 1;
        cout << "Vyberte utok: " << endl;
        cout << "1)    Obycejny utok: " << sila << " sily" << endl;
        cout << "2)    " << skill1 << endl;
        cout << "3)    " << skill2 << endl;
        cin >> s;
        while(s > 3 || s < 1){
            cin >> s;
        }
        switch(s){
            case 1:
                for(int a = 0;a < b; a++){
                    if(M[a] > 0){
                        M[a] -= sila;
                        if(M[a] < 0){
                            M[a] = 0;
                        }
                        cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                        break;
                    }
                }


            break;
            case 2:
                if(klass == "paladin"){
                    if(mana >= 2){
                        for(int a = 0; a < b; a++){
                            M[a] -= 2;
                            if(M[a] < 0){
                                M[a] = 0;
                            }
                                cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                        }
                        mana -= 2;
                        }else{
                            cout << "Nemate dostatek many: " << mana << endl;
                            u = 0;
                        }

                }else if(klass == "assasin"){
                    if(mana >= 4){
                        zivoty += Msila*b;
                        mana -= 4;
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                }else if(klass == "mag"){
                    if(mana >= 5){
                        for(int a = 0;a < b; a++){
                            if(M[a] > 0){
                                M[a] -= 9;
                                if(M[a] < 0){
                                    M[a] = 0;
                                }
                                cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                                break;
                            }
                        }
                        mana -= 5;
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                }else if(klass == "strelec"){
                    if(mana >= 3){
                        for(int a = 0; a < b; a++){
                            M[a] -= 6;
                            if(M[a] < 0){
                                M[a] = 0;
                            }
                        }
                        mana -= 3;
                        }else{
                            cout << "Nemate dostatek many: " << mana << endl;
                            u = 0;
                        }
                }
            break;
            case 3:
                if(klass == "paladin"){
                    if(mana >= 4){
                        if(zivoty == maxHp){
                            cout << "Uz mate maximalne zivotu: " << zivoty << endl;
                            u = 0;
                            }else{
                                zivoty = zivoty + b*2;
                                cout << "Ted mate: " << zivoty << " zivotu" << endl;
                                if(zivoty > maxHp){
                                    zivoty = maxHp;
                                }
                            }
                            mana -= 2;
                        }else{
                            cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;

                    }
                }else if(klass == "assasin"){
                    if(mana >= 4){
                        for(int a = 0;a < b; a++){
                            if(M[a] > 0){
                                M[a] -= 2*sila;
                                if(M[a] < 0){
                                    M[a] = 0;
                                }
                                for(int a = 0;a < b;a++){
                                    cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                                }
                            }
                        }
                        mana -= 4;
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }

                }else if(klass == "mag"){
                    if(mana >= 6){
                        if(zivoty == maxHp){
                            cout << "Uz mate maximalne zivotu" << endl;
                        }else{
                            if(zivoty > maxHp){
                                zivoty = maxHp;
                            }else{
                                zivoty += 2;
                            }
                        }
                        mana -= 6;
                    }else{
                        cout << "Nemate dostatek many: " << mana << endl;
                        u = 0;
                    }
                    cout << "Ted mate" << zivoty << " zivotu" << endl;

                }else if(klass == "strelec"){
                    if(mana >= 2){
                        zivoty += Msila*b;
                        for(int a = 0;a < b; a++){
                            if(M[a] >   0){
                                M[a] -= sila;
                                if(M[a] < 0){
                                    M[a] = 0;
                                }
                                for(int a = 0;a < b;a++){
                                    cout << "Monstrum " << a+1 << " ma: " << M[a] << " zivotu" << endl;
                                }
                            }
                        }
                        mana -= 2;
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
void monstrum(int &zlato ,int &zivoty ,int &mana,int sila ,int &maxHp ,int &maxmana ,string skill1 ,string skill2 ,string klass,int M[],int b,int &p,int &expi,int exp[]){
    int Msila = 2;
    for(int a = 0;a < 3 ; a++){
        M[a] = 0;
    }
    for(int a = 0;a < b ; a++){
        M[a] = 5;
    }
    do{
        boj(zlato,zivoty,mana,sila,maxHp,maxmana,skill1,skill2,klass,Msila,M,b,p);
        if(p == 0){
           cout << "Monstrum na tahu" << endl;
            for(int a = 0; a < b;a++){
                if(M[a] > 0){
                    cout << "-" << Msila << " zivotu od monstrum" << endl;
                }
            }
            zivoty -= b*Msila;
        }else{
            break;
        }

    }while(!alldead(M,b) && zivoty > 0);
    if (zivoty <= 0){
            cout << "--------------PROHRALI JSTE--------------"<<endl;
        }else if(alldead(M,b)){
            cout << "--------V tomto setkani jste vyhrali--------" << endl;
            for(int a; a <= b; a++){
                if(ranm() == 1){
                    zlato += ranz1();
                    barva(14);
                    cout << "Dostali jste + " << ranz2 << " zlata"<< endl;
                    barva(7);
                    srand(time(0));
                }
            }
            for(int a; a <= b; a++){
                for(int a = 0; a < 8 ; a++){
                    if(exp[a] >= 0)
                    exp[a] += expm();
                }
            }
        }
}

void miniboss(int &zlato ,int &zivoty ,int &mana,int sila ,int &maxHp ,int &maxmana ,string skill1 ,string skill2 ,string klass,int MB[],int b,int &p,int &expi,int exp[]){
    int MBsila = 4;
    MB[0] = 15;
    do{
        boj(zlato,zivoty,mana,sila,maxHp,maxmana,skill1,skill2,klass,MBsila,MB,b,p);
        if(p == 0){
           cout << "Mini boss na tahu" << endl;
                if(MB[0] > 0){
                    cout << "-" << MBsila << " zivotu od mini bosse" << endl;
                }
            zivoty -= MBsila;
        }else{
            break;
        }
    }while(p != 1 && zivoty > 0);
    if (zivoty <= 0){
            cout << "--------------PROHRALI JSTE--------------";
        }else{
            cout << "--------V tomto setkani jste vyhrali--------" << endl;
            zlato += ranz2();
            barva(14);
            cout << "Dostali jste + " << ranz2 << " zlata" << endl;
            barva(7);
            srand(time(0));
        }
}

void Geargrind(int &zlato ,int &zivoty ,int &mana,int sila ,int &maxHp ,int &maxmana ,string skill1 ,string skill2 ,string klass,int B[],int b,int &p){
    int Bsila = 3, k;
    B[0] = 100;
    do{
        boj(zlato,zivoty,mana,sila,maxHp,maxmana,skill1,skill2,klass,Bsila,B,b,p);
        if(p == 0){
           cout << "Geargrind na tahu" << endl;
        if(ranc() == 1){
            cout << "Geargrind je na hranici roztrzeni, ale utoci jako nikdy predtim!";
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
        Bsila += 3;
    }while(!alldead(B,b) && zivoty > 0);
    if (zivoty <= 0){
            cout << "--------------PROHRALI JSTE--------------"<<endl;
        }else if(alldead(B,b)){
            cout << "--------Zabili jste hlavniho bosse, konec hry--------" << endl;
        }
}


void vesnice(int &zlato, int &zivoty , int &mana, int &sila, int &maxHp, int &maxmana){
    int a, b = 0;
    cout << "Zde muzete:" << endl;
     do{
        cout << "(1)   Doplnovat si zivoty - 500 zlata" << endl;
        cout << "(2)   Vylepsit max zivoty - 500 zlata"<< endl;
        cout << "(3)   Vylepsit max manu - 500 zlata" << endl;
        cout << "(4)   Vylepsit damage/schopnosti - 500 zlata" << endl;
        cout << "(5)   Skip(jestli nemate zlato)"<<endl;
        stats(zivoty,sila,mana,maxmana,maxHp,zlato);
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
                    }while(b > 1 || b < 0);
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
    cout << "   Bozsky vypad - 2 damage vsem nepratelum, mana - 2"<< endl;
    cout << "   Bozi pozehnani - Heal - +3 zivoty za kazdeho monstra, mana - 4"<< endl;
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
    cout << "   Jedova dyka - dalsi utok ma 2x damage, mana - 4"<< endl;
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
    int Hp = 1, zlato = 500, mana, maxmana, maxHp, sila,classy, y,b=1, M[3],p=0,MB[1],B[1],exp[8],n = 2 ,expi;
    string inventory[5] ,skill1,skill2,klass;
    for(int a = 0; a < expi; a++){
        exp[a] = 10 + n;
        n += 12;
    }
    if(Hp > 0){
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
                    skill1 = "Bozsky vypad - 2 damage vsem nepratelum, mana - 2";
                    skill2 = "Bozi pozehnani - Heal - +3 zivoty za kazdeho monstra, mana - 4";
                    klass = "paladin";
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
                    skill1 = "Stinovy klon - vytvorite klona ktery zmizi po jednomu uderu po nem, mana - 4";
                    skill2 = "Jedova dyka - dalsi utok ma 2x damage, mana - 3";
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
                    skill1 = "Ohniva koule - poslete ohnivou kouli na nepritele, 9 damage, mana - 5";
                    skill2 = "Magicky vyboj - +2 zivoty, mana - 6";
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
                    skill1 = "Prurazna strela - 6 damage vsem nepratelum, mana - 3";
                    skill2 = "Ustupny vystrel - Vystreli a uskoci dozadu, mana - 2";
                    klass = "strelec";
                }
            break;
        }
    }while(y == 0);

    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "--------------------------------------------" << endl;
    cout << "Potkali jste monstrum" << endl;
    b = 1;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste monstrum" << endl;
    b = 1;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste mini Bosse" << endl;
    b = 1;
    p = 0;
    miniboss(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,MB,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "--------------------------------------------" << endl;
    cout << "Potkali jste monstrum" << endl;
    b = 1;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste mini Bosse" << endl;
    b = 1;
    p = 0;
    miniboss(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,MB,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 2 monstra" << endl;
    b = 2;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste 3 monstra" << endl;
    b = 3;
    p = 0;
    monstrum(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,M,b,p,expi,exp);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Prisli jste do vesnice" << endl;
    vesnice(zlato, Hp, mana, sila, maxHp, maxmana);
    stats(Hp,sila,mana,maxmana,maxHp,zlato);
    cout << "Potkali jste hlavniho bosse" << endl;
    b = 3;
    p = 0;
    Geargrind(zlato, Hp, mana, sila, maxHp, maxmana,skill1,skill2,klass,B,b,p);
    }else if(Hp <= 0){
    cout << "--------------PROHRALI JSTE--------------";
    return 0;
    }
}
