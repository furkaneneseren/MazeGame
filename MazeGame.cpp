#include <iostream>
#include <string.h>     //Furkan Enes Eren 152120171099 Computer Programming Lab FINAL
#include <cstdlib>
#include <curses.h>     //windows için -> #include <conio.h> kullanılabilir. linuxda yazıldığı için bu kütüphane kullanılmıştır.
#include <time.h>       //Linux üzerinde çalıştırmak için dosyanın bulunduğu dizine gelerek terminale "gcc FurkanEnesEren_152120171099.cpp -lstdc++ -o myExec" ardından "./myExec" komutları yazılarak çıktılar görülebilir.
#include <fstream>      //Çıktılar dosya ile aynı dizinde "cikisYolu.txt" olarak yazılacaktır.

using namespace std;

const char GEN=20, YUK=10;                                  //labirent boyutları tanımı
const int left = 'a', right = 'd', up = 'w', down = 's';    //hareket tuşları tanımı
unsigned char oyuncu = {1};                                 //oyuncu tanımı
unsigned char hareket;                                      
bool oyunsonu = false;                                      //oyun bitirme kontrolü
int altinSayisi = 0;                                        //altın skoru

struct Dusman
{
    char imlec;                                             //dusman yapısı
    int x;
    int y;
};


struct Oyuncu
{
    char isaret;                                            //oyuncu yapısı
    int x;
    int y;
};

struct Altin
{
    char isaretAltin;                                       //altın yapısı
    int x;
    int y;
};



unsigned char labirent[YUK][GEN] = {
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1',' ',' ',' ',' ',' ',' ',' ','1','1',' ',' ',' ',' ',' ',' ','1','1',' ','1'},
{'1',' ','1',' ','1','1','1',' ',' ',' ',' ','1','1',' ','1',' ',' ',' ',' ','1'},
{'1',' ','1',' ','1',' ','1',' ','1',' ','1','1',' ',' ',' ','1',' ','1','1','1'},      //labirent
{'1',' ',' ',' ',' ',' ',' ',' ',' ',' ','1',' ',' ','1',' ','1',' ',' ',' ','1'},
{'1','1',' ','1',' ','1','1','1','1',' ','1',' ','1','1',' ',' ',' ','1',' ','1'},
{'1',' ',' ','1',' ',' ',' ',' ','1',' ','1',' ',' ',' ','1',' ','1','1',' ','1'},
{'1',' ','1','1','1',' ','1',' ',' ',' ','1','1','1',' ',' ',' ',' ','1',' ','1'},
{'1',' ',' ',' ',' ',' ','1',' ','1',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' '},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},};

int main() 
{
    srand (time(NULL));
    ofstream cikisYolu("cikisYolu.txt");                            //çıkış yolu dosyası
    cikisYolu << "X" << "   " << "Y" << endl;

    Oyuncu oyuncu;
    oyuncu.isaret = 'X';                                            //oyuncu tanımı
    oyuncu.x = 1;
    oyuncu.y = 1;

    Dusman dusman;
    dusman.imlec = '$';
    dusman.x = rand()%GEN;
    dusman.y = rand()%YUK;
    
    Dusman dusman2;
    dusman2.imlec = '$';
    dusman2.x = rand()%GEN;
    dusman2.y = rand()%YUK;
    
    Dusman dusman3;                                                 //dusman tanımları
    dusman3.imlec = '$';
    dusman3.x = rand()%GEN;
    dusman3.y = rand()%YUK;
    
    Dusman dusman4;
    dusman4.imlec = '$';
    dusman4.x = rand()%GEN;
    dusman4.y = rand()%YUK;
    
    Dusman dusman5;
    dusman5.imlec = '$';
    dusman5.x = rand()%GEN;
    dusman5.y = rand()%YUK;

    Altin altin;
    altin.isaretAltin = 'G';
    altin.x = rand()%GEN;
    altin.y = rand()%YUK;

    Altin altin2;
    altin2.isaretAltin = 'G';
    altin2.x = rand()%GEN;
    altin2.y = rand()%YUK;

    Altin altin3;
    altin3.isaretAltin = 'G';                                       //altın tanımları
    altin3.x = rand()%GEN;
    altin3.y = rand()%YUK;

    Altin altin4;
    altin4.isaretAltin = 'G';
    altin4.x = rand()%GEN;
    altin4.y = rand()%YUK;

    Altin altin5;
    altin5.isaretAltin = 'G';
    altin5.x = rand()%GEN;
    altin5.y = rand()%YUK;

    while(labirent[altin.y][altin.x] != ' '){
        altin.x = rand()%GEN;
        altin.y = rand()%YUK;
    }

    if(labirent[altin.y][altin.x] == ' '){
        labirent[altin.y][altin.x] = altin.isaretAltin;
    }

    while(labirent[altin2.y][altin2.x] != ' '){
        altin2.x = rand()%GEN;
        altin2.y = rand()%YUK;
    }

    if(labirent[altin2.y][altin2.x] == ' '){
        labirent[altin2.y][altin2.x] = altin2.isaretAltin;
    }

    while(labirent[altin3.y][altin3.x] != ' '){                         //rastgele altın yerleştirme
        altin3.x = rand()%GEN;
        altin3.y = rand()%YUK;
    }

    if(labirent[altin3.y][altin3.x] == ' '){
        labirent[altin3.y][altin3.x] = altin3.isaretAltin;
    }

    while(labirent[altin4.y][altin4.x] != ' '){
        altin4.x = rand()%GEN;
        altin4.y = rand()%YUK;
    }

    if(labirent[altin4.y][altin4.x] == ' '){
        labirent[altin4.y][altin4.x] = altin4.isaretAltin;
    }

    while(labirent[altin5.y][altin5.x] != ' '){
        altin5.x = rand()%GEN;
        altin5.y = rand()%YUK;
    }

    if(labirent[altin5.y][altin5.x] == ' '){
        labirent[altin5.y][altin5.x] = altin5.isaretAltin;
    }


    while(labirent[dusman.y][dusman.x] != ' '){
        dusman.x = rand()%GEN;
        dusman.y = rand()%YUK;
    }

    if(labirent[dusman.y][dusman.x] == ' '){
        labirent[dusman.y][dusman.x] = dusman.imlec;
    }
    
    while(labirent[dusman2.y][dusman2.x] != ' '){
        dusman2.x = rand()%GEN;
        dusman2.y = rand()%YUK;
    }

    if(labirent[dusman2.y][dusman2.x] == ' '){
        labirent[dusman2.y][dusman2.x] = dusman2.imlec;
    }
    
    while(labirent[dusman3.y][dusman3.x] != ' '){                       //rastgele düşman yerleştirme
        dusman3.x = rand()%GEN;
        dusman3.y = rand()%YUK;
    }

    if(labirent[dusman3.y][dusman3.x] == ' '){
        labirent[dusman3.y][dusman3.x] = dusman3.imlec;
    }

    while(labirent[dusman4.y][dusman4.x] != ' '){
        dusman4.x = rand()%GEN;
        dusman4.y = rand()%YUK;
    }

    if(labirent[dusman4.y][dusman4.x] == ' '){
        labirent[dusman4.y][dusman4.x] = dusman4.imlec;
    }

    while(labirent[dusman5.y][dusman5.x] != ' '){
        dusman5.x = rand()%GEN;
        dusman5.y = rand()%YUK;
    }

    if(labirent[dusman5.y][dusman5.x] == ' '){
        labirent[dusman5.y][dusman5.x] = dusman5.imlec;
    }

    while(hareket != 'q' && oyunsonu !=true)
    {

        if (labirent[oyuncu.y][oyuncu.x] == ' '){
            labirent[oyuncu.y][oyuncu.x] = oyuncu.isaret;                           //oyuncunun konuma hareketi
            cikisYolu << "" << oyuncu.x-1 << "   " << "" << oyuncu.y-1 << endl;     //konumu dosyaya yazma
        }

        else if (labirent[oyuncu.y][oyuncu.x] == '$'){
            labirent[oyuncu.y][oyuncu.x] = ' ';                                     //ekstra bir kontrol düşmana karşı
            oyuncu.y = 1;
            oyuncu.x = 1;
            cikisYolu << "" << oyuncu.x-1 << "   " << "" << oyuncu.y-1 << endl;
            labirent[oyuncu.y][oyuncu.x] = oyuncu.isaret;
        }

        for(int yuk=0; yuk<YUK; yuk++){
            cout << endl;
            for(int gen=0; gen<GEN; gen++){                                         //labirent yazdırma
                cout << labirent[yuk][gen];
            }
        }

        cout << "\nHareketi wasd ile sağlayabilirsiniz. Hareketinizi girdikten sonra enter'a basınız (ör. d (enter)): ";
        cin >> hareket;

        switch (hareket)
        {
            case 'a':
                if(labirent[oyuncu.y][oyuncu.x-1] != '1' && labirent[oyuncu.y][oyuncu.x-1] != '$' && labirent[oyuncu.y][oyuncu.x-1] != 'G'){
                    labirent[oyuncu.y][oyuncu.x] = ' ';             //önceki konumun boşluk olarak yazılması
                    oyuncu.x--;                                     //oyuncu hareketi
                }
                else if (labirent[oyuncu.y][oyuncu.x-1] == '$'){    //düşman kontrolü
                    labirent[oyuncu.y][oyuncu.x] = ' ';             
                    oyuncu.y = 1;
                    oyuncu.x = 1;
                    labirent[oyuncu.y][oyuncu.x] = oyuncu.isaret;   //oyuncunun labirentin başına atılması
                }
                else if (labirent[oyuncu.y][oyuncu.x-1] == 'G'){
                labirent[oyuncu.y][oyuncu.x] = ' ';
                labirent[oyuncu.y][oyuncu.x-1] = ' ';                           //altının yok edilmesi
                altinSayisi++;                                                  //altın toplarsa skor arttırımı
                oyuncu.x--;
                }
                break;
            case 'w':
                if(labirent[oyuncu.y-1][oyuncu.x] != '1' && labirent[oyuncu.y-1][oyuncu.x] != '$' && labirent[oyuncu.y-1][oyuncu.x] != 'G'){
                    labirent[oyuncu.y][oyuncu.x] = ' ';
                    oyuncu.y--;
                }
                else if (labirent[oyuncu.y-1][oyuncu.x] == '$'){
                    labirent[oyuncu.y][oyuncu.x] = ' ';
                    oyuncu.y = 1;
                    oyuncu.x = 1;
                    labirent[oyuncu.y][oyuncu.x] = oyuncu.isaret;
                }
                else if (labirent[oyuncu.y-1][oyuncu.x] == 'G'){
                labirent[oyuncu.y][oyuncu.x] = ' ';
                labirent[oyuncu.y-1][oyuncu.x] = ' ';
                altinSayisi++;
                oyuncu.y--;
                }
                break;
            case 's':
                if(labirent[oyuncu.y+1][oyuncu.x] != '1' && labirent[oyuncu.y+1][oyuncu.x] != '$' && labirent[oyuncu.y+1][oyuncu.x] != 'G'){
                    labirent[oyuncu.y][oyuncu.x] = ' ';
                    oyuncu.y++;
                }
                else if (labirent[oyuncu.y+1][oyuncu.x] == '$'){
                    labirent[oyuncu.y][oyuncu.x] = ' ';
                    oyuncu.y = 1;
                    oyuncu.x = 1;
                    labirent[oyuncu.y][oyuncu.x] = oyuncu.isaret;
                }
                else if (labirent[oyuncu.y+1][oyuncu.x] == 'G'){
                labirent[oyuncu.y][oyuncu.x] = ' ';
                labirent[oyuncu.y+1][oyuncu.x] = ' ';
                altinSayisi++;
                oyuncu.y++;
                }
                break;
            case 'd':
                if(labirent[oyuncu.y][oyuncu.x+1] != '1' && labirent[oyuncu.y][oyuncu.x+1] != '$' && labirent[oyuncu.y][oyuncu.x+1] != 'G'){
                    labirent[oyuncu.y][oyuncu.x] = ' ';
                    oyuncu.x++;
                }
                else if (labirent[oyuncu.y][oyuncu.x+1] == '$'){
                    labirent[oyuncu.y][oyuncu.x] = ' ';
                    oyuncu.y = 1;
                    oyuncu.x = 1;
                    labirent[oyuncu.y][oyuncu.x] = oyuncu.isaret;
                }
                else if (labirent[oyuncu.y][oyuncu.x+1] == 'G'){
                labirent[oyuncu.y][oyuncu.x] = ' ';
                labirent[oyuncu.y][oyuncu.x+1] = ' ';
                altinSayisi++;
                oyuncu.x++;
                }
                break;
            case 'q':
                exit (0);
                break;

        }
        
        if (oyuncu.y == YUK-2 && oyuncu.x == GEN-1){            //labirent sonu kontrolü
            cout << endl;
            cout << "oyun bitti";
            cout << endl;
            cout << "Altın: " << altinSayisi;
            system("PAUSE");
            oyunsonu = true;                                    //oyun sonlandırma
            cikisYolu.close();                                  //dosya kapatma
        }
    
    system("CLS");
        
    }

}

