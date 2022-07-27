#include <iostream>
#include <fstream>
#include <clocale>
#include <sstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <time.h>

using namespace std;


class Item
{
private:

    string itemName = " ";
    string itemEffect = " ";
    double itemATK = 0;
    double itemWeaknessMultiplier = 0;

public:


    Item(string name, string effect, double atk, double mltplr)
    {
        itemName = name;
        itemEffect = effect;
        itemATK = atk;
        itemWeaknessMultiplier = mltplr;
    }

    void setItemName(string sName)
    {
        itemName = sName;
    }

    string getItemName()
    {
        return itemName;
    }

    void setItemEffect(string effect)
    {
        itemEffect = effect;
    }

    string getItemEffect()
    {
        return itemEffect;
    }

    void setItemAtk(double sItemATK)
    {
        itemATK = sItemATK;
    }

    double getItemAtk()
    {
        return itemATK;
    }

    void setItemWeakness(double sItemWkMltplr)
    {
        itemWeaknessMultiplier = sItemWkMltplr;
    }

    double getItemWeakness()
    {
        return itemWeaknessMultiplier;
    }

};

class Character
{
private:

    string nameNPC = " ";
    double atkNPC = 0;
    double hitPointNPC = 0;
    double critMultiplier = 0;
    double characterShield = 0;

public:

    vector <Item> items;
    vector <Character> npc;



    Character(string name, double atk, double hp, double crit, double shield)
    {
        nameNPC = name;
        atkNPC = atk;
        hitPointNPC = hp;
        critMultiplier = crit;
        characterShield = shield;
    }

    void setNPCName(string sName)
    {
        nameNPC = sName;
    }

    string getNPCName()
    {
        return nameNPC;
    }

    void setNPCAtk(double sAtk)
    {
        atkNPC = sAtk;
    }

    double getNPCAtk()
    {
        return atkNPC;
    }

    void setNPCHp(double hp)
    {
        hitPointNPC = hp;
    }

    double getNPCHp()
    {
        return hitPointNPC;
    }

    void setNPCCrit(double crit)
    {
        critMultiplier = crit;
    }

    double getNPCCrit()
    {
        return critMultiplier;
    }

    void setNPCShield(double shield)
    {
        characterShield = shield;
    }

    double getNPCShield()
    {
        return characterShield;
    }


};


class Monster
{
private:

    string nameMonster = " ";
    string monsterWeakness = " ";
    double atkMonster = 0;
    double hitPointMonster = 0;
    double critMultiplier = 0;

public:

    Monster(string name, string weakness, double atk, double hp, double critMltp)
    {
        nameMonster = name;
        monsterWeakness = weakness;
        atkMonster = atk;
        hitPointMonster = hp;
        critMultiplier = critMltp;
    }

    void setMonsterName(string name)
    {
        nameMonster = name;
    }

    string getMonsterName()
    {
        return nameMonster;
    }

    void setMonsterWeakness(string weakness)
    {
        monsterWeakness = weakness;
    }

    string getMonsterWeakness()
    {
        return monsterWeakness;
    }

    void setMonsterAtk(double atk)
    {
        atkMonster = atk;
    }

    double getMonsterAtk()
    {
        return atkMonster;
    }

    void setMonsterHP(double hp)
    {
        hitPointMonster = hp;
    }

    double getMonsterHP()
    {
        return hitPointMonster;
    }



    void setMonsterCrit(double crit)
    {
        critMultiplier = crit;
    }

    double getMonsterCrit()
    {
        return critMultiplier;
    }


};



double characterAttacks(double atk, double crit) //KARAKTER SALDIRI YAPTI�INDA ATK G�C�N� HESAPLAR
{

    srand(time(0));

    double crittedAtk;

    crit += (rand() % 20 + 1);

    crittedAtk = (atk * 0.67) + (crit * 0.33);

    return crittedAtk;

}

void characterHPsetter (Character * ch, double atk) //KARAKTER HASAR ALDI�INDA SA�LI�INI HESAPLAR
{
    double hp = ch->getNPCHp();
    ch->setNPCHp(hp-atk);

}

double blockedAttack(double atk, double shield) //KARAKTER BLOK YAPTI�INDA SA�LI�INI HESAPLAR
{
    double blockedAtk = 0;

    blockedAtk = (atk - (shield * 0.40));

    return blockedAtk;
}


//KARAKTER ENVATER�NDEN E�YA KULLANDI�INDA E�YANIN YARATI�IN ZAYIFLI�IYLA UYU�UP UYU�MADI�INI, UYU�UYORSA NE KADAR HASAR VERECE��N� HESAPLAR
double characterUsesItem(string monsterWeakness, string itemEffect, double atk, double weakness)
{

    double itemATK = (atk * 0.7) + (weakness * 2);


    if (monsterWeakness == itemEffect)
    {
        cout << "E�ya kullan�m� ba�ar�l�: " << itemATK << endl;

        return itemATK;
    }

    else
    {
        cout << "E�ya kullan�m� ba�ar�s�z" << endl;

        return 0;
    }

}

double shieldedHP (double hp, double shield) //KARAKTER�N KALKANI TARAFINDAN ENGELLENEN HASARI HESAPLAR
{
    double shieldedHP = 0;

    shieldedHP = (hp * 0.67) + (shield * 0.33);

    return shieldedHP;

}

double experienceCalculator(double atk, double crit) //�ATI�MA SONUNDA NE KADAR DENEY�M KAZANDI�INI HESAPLAR
{
    double exp = 0;

    exp = (atk + crit) * 0.2;

    return exp;
}

int escapeCalculator() //KARAKTER�N �ATI�MADAN KA�MA �HT�MAL�N� HESAPLAR
{

    srand(time(0));

    double escape = 0;

    int success;

    escape = (rand() % 100);

    if (escape > 50)
    {

        cout << "Ka�ma �ans�n�z: %" << escape << " Ka�may� ba�ard�n�z" << endl;

        success = 1;
    }

    if (escape <= 50)
    {
        cout << "Ka�ma �ans�n�z: %" << escape << " Ka�may� ba�aramad�n�zz" << endl;

        success = 0;
    }
    return success;
}

double monsterAttacks (double atk, double crit) //YARATIK SALDIRI YAPTI�INDA ATK G�C�N� HESAPLAR
{

    cout << "Yarat�k sald�rd�! \n" << endl;

    srand(time(0));

    double crittedAtk;

    crit += (rand() % 10 + 1);

    crittedAtk = (atk * 0.55) + (crit * 0.45);

    return crittedAtk;
}

void monsterHPsetter (Monster * mons, double atk) //YARATIK HASAR ALDI�INDA SA�LI�INI HESAPLAR
{
    double hp = mons->getMonsterHP();

    mons->setMonsterHP(hp-atk);



}

void createMonster(Character * ch, Monster * mons) //KARAKTER�N G�C�NE ORANLANMI� B�R �EK�LDE YARATIK OLU�TURUR
{
    double atk, hp, crit;

    atk = ch->getNPCAtk()*0.8;
    hp = ch->getNPCHp()*0.9;
    crit = ch->getNPCCrit()*0.8;

    mons->setMonsterAtk(atk);
    mons->setMonsterHP(hp);
    mons->setMonsterCrit(crit);

}

void characterLevelUP (Character * ch, double exp) //�ATI�MA SONRASI KARAKTER�N KAZANDI�I DENEY�M ORANINDA GEL��MES�N� SA�LAR
{
    double atk, hp, crit, shield;

    atk = ch->getNPCAtk() + exp;
    hp = ch->getNPCHp() + exp;
    crit = ch->getNPCCrit() + exp;
    shield = ch->getNPCShield() + exp;

    ch->setNPCAtk(atk);
    ch->setNPCHp(hp);
    ch->setNPCCrit(crit);
    ch->setNPCShield(shield);

    cout << "Karakteriniz g��lendi \n";
    cout << "ATK: " << ch->getNPCAtk() << endl;
    cout << "HP: " << ch->getNPCHp() << endl;
    cout << "Crit: " << ch->getNPCCrit() << endl;
    cout << "Shield: " <<  ch->getNPCShield() << endl;
}

void battle (Character * ch, Monster * mons, bool helper) //�ATI�MA S�M�LE EDER
{
    int escape;

    double hp, shield;

    hp = ch->getNPCHp();
    shield = ch->getNPCShield();

    while (escape == 0 && ch->getNPCHp() > 0 && mons->getMonsterHP() > 0)
    {
        cout << "Se�enekleriniz: \n\n" << endl;
        cout << "1. Sald�r� \n " << endl;
        cout << "2. E�ya kullanma \n " << endl;
        cout << "3. Savunma \n " <<  endl;
        cout << "4. Yard�m iste \n " <<  endl;
        cout << "5. Ka�ma \n " <<  endl;

        int battleChoice = 0;

        cin >> battleChoice;

        if (battleChoice == 1 )
        {

            monsterHPsetter( mons, characterAttacks( ch->getNPCAtk(),ch->getNPCCrit() ) );

            characterHPsetter ( ch , monsterAttacks(mons->getMonsterAtk(), mons->getMonsterCrit() ) );

            cout << "Sa�l�k: \n" << ch->getNPCHp() << endl;
            if (mons->getMonsterHP() <= 0)
            {
                cout << "Yarat�k �ld�r�ld�. \n\n";
            }
            else {
                cout << "Yarat���n sa�l���: \n" << mons->getMonsterHP() << endl;
            }


        }

        if (battleChoice == 2)
        {

            if (ch->items[0].getItemAtk() > 0)

            {
                cout << "Hangi e�yay� kullanmak istiyorsunuz? " << endl;

                for (int x = 0; x < ch->items.size(); x++)
                {
                    cout << x + 1 << ". " << ch->items[x].getItemName() << endl;
                }

                int itemNo;
                cin >> itemNo;
                itemNo -= 1;

                monsterHPsetter( mons, characterUsesItem( mons->getMonsterWeakness(), ch->items[itemNo].getItemEffect(), ch->items[itemNo].getItemAtk(), ch->items[itemNo].getItemWeakness()) );
                ch->items.erase(ch->items.begin() + itemNo);

                characterHPsetter ( ch , monsterAttacks(mons->getMonsterAtk(), mons->getMonsterCrit() ) );

                cout << "Sa�l�k: \n" << ch->getNPCHp() << endl;

                if (mons->getMonsterHP() <= 0)
                {
                    cout << "Yarat�k �ld�r�ld�. \n\n";
                }
                else
                {
                    cout << "Yarat���n sa�l���: \n" << mons->getMonsterHP() << endl;
                }
            }

            else

            {
                cout << "Kullanabilece�iniz bir e�yan�z yok. \n" << endl;
            }

        }

        if (battleChoice == 3)
        {

            characterHPsetter ( ch , blockedAttack ( monsterAttacks ( mons->getMonsterAtk() , mons->getMonsterCrit() ), ch->getNPCShield() ) );

            cout << "Kalkan�n hasar�n bir k�sm�n� engelledi " << endl;

            cout << "Sa�l�k: \n" << ch->getNPCHp() << endl;
            if (mons->getMonsterHP() <= 0)
            {
                cout << "Yarat�k �ld�r�ld�. \n\n";
            }
            else
            {
                cout << "Yarat���n sa�l���: \n" << mons->getMonsterHP() << endl;
            }

        }

        if ( battleChoice == 4 )
        {


            if( helper)
            {
                monsterHPsetter( mons, characterAttacks( ch->npc[0].getNPCAtk(),ch->npc[0].getNPCCrit() ) );

                characterHPsetter ( &ch->npc[0] , monsterAttacks(mons->getMonsterAtk(), mons->getMonsterCrit() ) );


                cout << "Yolda��n�n sa�l���: \n" << ch->npc[0].getNPCHp() << endl;
                if (mons->getMonsterHP() <= 0)
                {
                    cout << "Yarat�k �ld�r�ld�. \n\n";
                }
                else {
                    cout << "Yarat���n sa�l���: \n" << mons->getMonsterHP() << endl;
                }

            }

            else
            {
                cout << "�a��racak bir yolda��n�z yok.\n" << endl;
            }

        }



        if (battleChoice == 5)
        {

            escape = escapeCalculator();

        }

        if (mons->getMonsterHP() <= 0)
        {

            double xp = experienceCalculator(mons->getMonsterAtk(), mons->getMonsterCrit());
            cout << xp << "xp Deneyim kazand�n�z: " << endl;

            ch->setNPCHp(hp);
            ch->setNPCShield(shield);

            characterLevelUP(ch ,xp );
        }

        if (ch->getNPCHp() <= 0)
        {
            cout << "----------- OYUN B�TT� ----------- \n\n�LD�N�Z!" << endl;
        }


    }
}

void saveToFile(Character ch, int progress)
{

    string name;
    int  atk, hp, crit, shield;

    name = ch.getNPCName();
    atk = ch.getNPCAtk();
    hp = ch.getNPCHp();
    crit = ch.getNPCCrit();
    shield = ch.getNPCShield();

    ofstream savefile;

    savefile.open("userdata.txt", ios::out);

    if ( savefile.is_open() )
    {
        cout << "-----(Bu a�amaya kadarki ilerlemeniz kay�t edildi...)-----" << endl;

        savefile << name << "\n";
        savefile << progress << "\n";
        savefile << atk << "\n";
        savefile << hp << "\n";
        savefile << crit << "\n";
        savefile << shield << "\n";

        savefile.close();
    }

    else
    {
        cout << "error opening file" << endl;

    }

    savefile.close();


}


void openSaveFile ()
{
    ifstream savefile;

    string read, data[6];

    savefile.open("userdata.txt", ios::in);

    if (savefile.is_open() )
    {
        cout << "Dosyan�z a��ld�" << endl;

        getline (savefile, read);

        data[0] = read;


        for (int x = 1; x < 6; x++)
        {
            getline (savefile, read);

            data[x] = read;

        }

        cout << "Dosyan�zdan okunan bilgiler: " << endl;

        string info[6] {"�sim: ", "�lerleme: " , "ATK: " , "HP: " , "Crit: " , "Shield: "};

        for (int x = 0; x < 6; x++)
        {

            cout << info[x] << data[x] << endl;

        }
    }

    savefile.close();

}



void loadSaveFile (Character * ch, int * progress)
{

    ifstream savefile;

    string read, data[6];


    savefile.open("userdata.txt", ios::in);

    if (savefile.is_open() )
    {
        cout << "Dosyan�z a��ld�." << endl;

        getline (savefile, read);

        data[0] = read;


        for (int x = 1; x < 6; x++)
        {
            getline (savefile, read);

            data[x] = read;

        }

    }

    string name;
    int  atk, hp, crit, shield;

    name = data[0];
    *progress = stoi (data[1]);
    atk = stoi(data[2]);
    hp = stoi(data[3]);
    crit = stoi(data[4]);
    shield = stoi(data[5]);

    ch -> setNPCName( name );
    ch -> setNPCAtk( atk );
    ch -> setNPCHp( hp );
    ch -> setNPCCrit( crit );
    ch -> setNPCShield( shield) ;

    cout << "Kay�t y�klendi. " << endl;


    savefile.close();



}





int main()
{
    setlocale(LC_ALL, "Turkish");
    system("color 06");

    int save = 2;
    Character hero2("Paul", 10, 30, 8, 20);

    saveToFile(hero2, 2);

    //openSaveFile();

    loadSaveFile(&hero2, &save);





    Character hero("", 0, 0, 0, 0);

    int savepoint = 0;
    int menuChoice = 0;
    char loadChoice;

    cout << "\t\t---------------Oyuna ho� geldiniz---------------\n\n" << endl;

    cout << "\tSe�enekleriniz: " << endl;

    cout << "1- Yeni oyuna ba�la.\n" << endl;
    cout << "2- Kay�tl� oyunu y�kle\n" << endl;

    cin >> menuChoice;

    if (menuChoice == 1 )
    {
        cout << "Yeni oyun ba�lat�l�yor..." << endl;
    }

    if (menuChoice == 2)
    {
        openSaveFile();

        cout << "Kayd� y�klemek istiyor musunuz? (y/n)" << endl;

        cin >> loadChoice;

        if (loadChoice == 'n')
        {
            cout << "Kay�t y�klenmedi, yeni oyun ba�lat�l�yor..." << endl;
        }

        if (loadChoice == 'y')
        {
            loadSaveFile(&hero,&savepoint);
        }
    }

    
    
    
    if (loadChoice == 'n' || menuChoice == 1)

    {
        string cname;

        int weaponchoice, clanchoice;

        cout << "Karakterinizin ad�n� girin " << endl;
        cin >> cname;
        hero.setNPCName(cname);

        cout  << hero.getNPCName() <<
              " hangi klana aitsin? \n\n"
                      "1.Monar Klan� \n"
                      "2.Siyaki Klan� \n"
                      "3.Havsterd Klan� \n";
        cin >> clanchoice;
        if (clanchoice == 1)
        {
            cout << "Monar klan�n�n izbe bir k�y� olan Hujla ";
            hero.setNPCHp(40);
            hero.setNPCShield(20);
        }
        if (clanchoice == 2)
        {
            cout << "Siyaki klan�n�nizbe bir k�y� olan Merfive ";
            hero.setNPCHp(43);
            hero.setNPCShield(16);
        }
        if (clanchoice == 3)
        {
            cout << "Havster  klan�n�n izbe bir k�y� olan Yurlav ";
            hero.setNPCHp(38);
            hero.setNPCShield(22);
        }

        cout << " topraklar�n�n i�indesin.\n Sava� alan�nda ordunun, hangi b�l�m�nde g�revdeydin \n\n"
                "1. Ok�u 10 ATK - 8 Crit \n"
                "2. Piyade 12 ATK - 6 Crit\n";
        cin >> weaponchoice;

        if (weaponchoice == 1)
        {
            cout << "Ok�usu";
            hero.setNPCAtk(10);
            hero.setNPCCrit(8);

        }
        if (weaponchoice == 2)
        {
            cout << "Piyadesi";
            hero.setNPCAtk(12);
            hero.setNPCCrit(6);
        }
        cout <<
             " olarak girdi�in sava�ta bir olu�un alt�na s�k��t�n \n\n\n\n" << endl;


        for (int x = 0; x < 50; x++)
        {
            cout << "* ";
        }

        cout << "\n\n" << endl;
        cout << "Oluktan kurtulmak i�in: \n" << endl;

        cout << "1-) Olu�u �st�nden itmeyi dene. \n";
        cout << "2-) Kurtulmak i�in tahtalara tekme at \n";
        cout << "3-) ��ine yarayabilecek bir alet olup olmad���n� kontrol et \n";
        int troughchoice;

        cin >> troughchoice;




        if (troughchoice == 1)
        {
            cout << "Odunlar yerinden hi� k�p�rdamad� \n"
                    " Ard�ndan:\n";
            cout << "2-) Kurtulmak i�in tahtalara tekme at \n";
            cout << "3-) ��ine yarayabilecek bir alet olup olmad���n� kontrol et \n";
            int troughchoice;

            cin >> troughchoice;

            if (troughchoice == 2)
            {
                double hp = hero.getNPCHp();

                hero.setNPCHp(hp-10);

                cout << "Tekme atarken baca��n�z sakatland�  \n"
                        "Sa�l���n�z: " << hero.getNPCHp();

            }

        }

        if (troughchoice == 2)
        {
            double hp = hero.getNPCHp();

            hero.setNPCHp(hp-10);

            cout << "Tekme atarken baca��n�z sakatland�  \n"
                    "Sa�l���n�z: " << hero.getNPCHp();

        }

        if (troughchoice == 3 || troughchoice == 2)
        {

            cout << "\n\nSilah�n�n kabzas�n� ula�arak s�k��t��� yerde bir bo�luk olu�turdun ve kurtuldun \n" << endl;
            savepoint = 1;

            saveToFile(hero,savepoint);

        }

    }

    int plantChoice;

    if (savepoint == 1)
    {
        cout << "D��ar� ��kt���nda iki bitkiden birini elde etmek i�in gidece�in yola geldin \n";
        cout << "1- Juvani'yi se�ti\n"
                "2- Ukram'� se�ti\n" << endl;

        cin >> plantChoice;

        int soodehChoice1;
        int soodehChoice2;
        int soodehChoice3;

        if (plantChoice == 1)
        {
            cout << "Juvani�yi se�ip girdi�in ma�arada kar��na bir dev ��kt� \n" << endl;
            cout << "1- Sakince: 'Merhaba, ben " << hero.getNPCName() << "'\n"
                    "2- Hiddetle: 'Hey, sen! Elindeki Juvanileri hemen bana ver!' \n" << endl;

            cin >> soodehChoice1;

            if (soodehChoice1 == 1)
            {
                cout << "Dev k�s�k bir sesle: 'Ad�m Soodeh Manoja...Ne istiyorsun' dedi.  \n"
                        "\n\n"
                        "1- Sald�r�p bitkileri elinden al. \n"
                        "2- Bitkiye ihtiyac�n oldu�unu anlat. \n" << endl;

                cin >> soodehChoice2;

                if (soodehChoice2 == 1)
                {
                    cout << "Dev seni baca��ndan tutarak ma�aran�n tavan�na �arpt�. \n"
                            "Darbenin etkisiyle kemiklerinin k�r�ld���n� bile fark etmeyerek " << hero.getNPCName() << " bir daha g�zlerini a�mad�. "<< endl;
                    hero.setNPCHp(0);
                }

                if (soodehChoice2 == 2)
                {
                    cout << "Dev Soodeh'i ikna etmek i�in:  \n"
                            "1- Silah�nla �st�ne at�l \n"
                            "2- Kral'In m�hr�n� g�ster \n" << endl;

                    cin >> soodehChoice3;

                    if (soodehChoice3 == 1)
                    {
                        cout << "Dev seni baca��ndan tutarak ma�aran�n tavan�na �arpt�. \n"
                                "Darbenin etkisiyle kemiklerinin k�r�ld���n� bile fark etmeyerek " << hero.getNPCName() << " bir daha g�zlerini a�mad�. "<< endl;
                        hero.setNPCHp(0);
                    }

                    if (soodehChoice3 == 2)
                    {
                        cout << "Dev Soodeh ikna oldu ve sana bitkileri verdi. \n" << endl;
                        Item plant1("Juvani","Zehir",12,6);
                        hero.items.push_back(plant1);

                        savepoint == 2;

                        saveToFile(hero,savepoint);

                    }

                }

            }

            if (soodehChoice1 == 2)
            {
                cout << "Dev seni baca��ndan tutarak ma�aran�n tavan�na �arpt�. \n"
                        "Darbenin etkisiyle kemiklerinin k�r�ld���n� bile fark etmeyerek " << hero.getNPCName() << " bir daha g�zlerini a�mad�. "<< endl;
                hero.setNPCHp(0);
            }


        }
    }

    int ukramChoice1;
    int ukramChoice2;
    int ukramChoice3;


    if (plantChoice == 2)
    {
        cout << "Ukram Engerek Y�lan�n�n yuvas�nda veya a�a� tepelerinde bulunur. \n" << endl;
        cout << "1- A�a�lar� kontrol et. \n"
                "2- �n�ndeki yuvay� kontrol et." << endl;

        cin >> ukramChoice1;

        if (ukramChoice1 == 1)
        {
            cout << "A�ac�n en tepesine kadar t�rmand�n.\n"
                    " Ancak a�a�� inerken dengeni kaybederek kafa �st� yere �ak�ld�n  \n" << endl;
            hero.setNPCHp(0);

        }

        if (ukramChoice1== 2)
        {
            cout << "Yuvan�n dolu olmad���n� kontrol etmen gerekiyor.  \n"
                    "1- Elinle kontrol et \n"
                    "2- Silah�n�n ucunu yuvaya sokarak kontrol et \n" << endl;

            cin >> ukramChoice2;

            if (ukramChoice3 == 2)
            {
                cout << "Elini i�eri girer girmez bir �eyin seni �s�rd��� fark ettin. \n"
                        "Elini d��ar� �ekti�inde �oktan tamam� morarm��t�. " << hero.getNPCName() << " zehirin etkisiyle saniyeler i�erisinde tamamen fel� kald�. "<< endl;
                hero.setNPCHp(0);
            }

            if (ukramChoice2 == 2)
            {
                cout << "Silah�n� i�eri sokarken bir �eye de�di�ini fark ettin. \n"
                        "1- Geri �ekil. \n"
                        "2- Silah�nla y�lan� �ld�r. \n" << endl;
                cin >> ukramChoice3;

                if (ukramChoice3 == 1)
                {
                    cout << "Rahats�z olan y�lan ayaklar�n�n aras�ndan ge�erek uzakla�t�. \n"
                            "Art�k bo� olan yuvadan bitkiyi elde ettin. \n" << endl;
                    Item plant2("Ukram","Su",10,7);
                    hero.items.push_back(plant2);

                    savepoint = 3;

                    saveToFile(hero,savepoint);
                }

                if (ukramChoice3 == 2)
                {
                    cout << "S�r�nerek silah�na dolanan y�lan sana sald�r� f�rsat� vermedi. \n"
                         << hero.getNPCName() << " zehirin etkisiyle saniyeler i�erisinde tamamen fel� kald�. "<< endl;
                    hero.setNPCHp(0);
                }


            }

        }
    }



    if (hero.getNPCHp() == 0)
    {
        cout << "----------- OYUN B�TT� ----------- \n\n�LD�N�Z!" << endl;
    }

    for (int x = 0; x < 50; x++)
    {
        cout << "* ";
    }

    if ( savepoint == 3 )
    {
        Monster mons1("Hurkamus","Su",12,20,10);
        cout << "\n\n\nBitkiyi elde ettikten sonra Hurkamus isimli bir yarat�kla kar��la�t�n. \n"
                "Yarat�k sana f�rsat vermeden sald�r�ya ge�ti." << endl;


        battle (&hero, &mons1, false);

    }

    for (int x = 0; x < 50; x++)
    {
        cout << "* ";
    }

    if (hero.getNPCHp() > 0 )
    {
        cout << "\n\nSava�tan sonra yan�na gelen k�yl�lerden birisi sana kat�lmak istedi�ini s�yledi. \n"
                "Filoa ismindeki bu ki�i art�k sana yard�mc� olacak.\n\n" << endl;

        Character npc1("Filoa",8,40,5,20);
        hero.npc.push_back(npc1);

        savepoint = 4;

        saveToFile(hero,savepoint);

    }



    Monster mons2("Hurkamus","Su",12,20,10);
    battle (&hero, &mons2, true);




    return 0;
}
