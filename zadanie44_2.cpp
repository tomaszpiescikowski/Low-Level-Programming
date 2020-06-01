#include <stdio.h>      //standardowy input/output i inne 
#include <conio.h>      //dodatek potrzebny do funkcji getch(), aby zatrzymac okno konsoli

struct Dane_pomiarowe{      //definiowanie struktury danych
    int numer_serii;        
    double dana_1;
    double dana_2;
    double dana_3;
    double wynik;
};

void opcja_R(int &liczba_struktur, Dane_pomiarowe *Dane);
void opcja_S(int &liczba_struktur, Dane_pomiarowe *Dane);     //definiowanie funkcji z referencja do liczby struktur oraz wskaznikiem do tablicy struktur jako argumenty
void opcja_T(int &liczba_struktur, Dane_pomiarowe *Dane); 


int main()      //funkcja glowna programu
{   
    void(*tab_wsk[3])(int &, Dane_pomiarowe *) = {opcja_R, opcja_S, opcja_T};      //definiowanie tablicy wskaznikow funkcji

    int liczba_struktur = 0;        //definiowanie zmiennych potrzebnych do instrukcji wyboru 
    char choice;

    Dane_pomiarowe Dane[100] = {0, 0.0, 0.0, 0.0, 0.0};     //deklaracja tablicy struktur

    printf("R | Wczytanie ciagu struktur z pliku wejsciowego\n");
    printf("S | Przetwarzanie tablicy struktur\n");
    printf("T | Zapisanie liczby struktur\n");
    printf("Q | Koniec programu\n");
    

    printf("\nCo ma zrobic program?: ");
    choice = getchar() - 82;
    while(choice != -1)
    {   
        if(choice >= 0 && choice <= 2) tab_wsk[choice](liczba_struktur, Dane);
        fflush(stdin);
        printf("\nCo ma zrobic program?: ");
        choice = getchar() - 82;
    }

    // printf("\nCo ma zrobic program?: ");
    // choice = getchar() - 82;
    // while(choice >= 0 && choice <= 2)
    // {
    //     tab_wsk[choice](liczba_struktur, Dane);      //wersja bez Q
    //     fflush(stdin);
    //     printf("\nCo ma zrobic program?: ");
    //     choice = getchar() - 82;
    // }

	printf("\n\n\n\n\nKoniec programu.");
    printf("\nNacisnij dowolny klawisz...");       //dodatek do zatrzymania okna konsoli
    getch();        
    return 0;
}

void opcja_R(int &liczba_struktur, Dane_pomiarowe *Dane)
{
    char nazwa_pliku[256] = "struct.txt";       //zmienna do przechowania sciezki pliku zrodlowego
    
    for(int q = 0; q < 100; q++)        //zerowanie struktury na wypadek wczesniejszej edycji
    {
        Dane[q].numer_serii = 0;
        Dane[q].dana_1 = 0.0;
        Dane[q].dana_2 = 0.0;
        Dane[q].dana_3 = 0.0;
        Dane[q].wynik = 0.0;
    }      

    do{ printf("Podaj liczbe struktur do wczytania: "); scanf("%d", &liczba_struktur); }
    while(liczba_struktur > 100 || liczba_struktur < 0);        //liczba struktur nie moze byc wieksza od 100

    printf("Podaj nazwe pliku: "); scanf("%s", nazwa_pliku);

    FILE * PLIK = fopen(nazwa_pliku, "rt+");        //otworzenie pliku do odczytu danych
    
    for(int i = 0; i < liczba_struktur; i++) 
        fscanf(PLIK, "%d %lf %lf %lf %lf ", &Dane[i].numer_serii, &Dane[i].dana_1, &Dane[i].dana_2, &Dane[i].dana_3, &Dane[i].wynik);

    fclose(PLIK);       //wczytanie danych z pliku do struktury a nastepnie zamkniecie pliku

    printf("\n\nLiczba struktur: %d", liczba_struktur);        //pogladowe wyswietlenie danych struktury
    for(int j = 0; j < liczba_struktur; j++){
        printf("\n\nNumer serii: %d\n", Dane[j].numer_serii);
        printf("Dana 1: %lf\n", Dane[j].dana_1);
        printf("Dana 2: %lf\n", Dane[j].dana_2);
        printf("Dana 3: %lf\n", Dane[j].dana_3);
        printf("Wynik: %lf\n", Dane[j].wynik);
    }
}

void opcja_S(int &liczba_struktur, Dane_pomiarowe *Dane)
{
    bool sposob;
    printf("\nWybierz sposob przetwarzania danych:\n0 - rezultatem jest suma trzech danych\n1 - rezultatem jest trzecia dana\n");
    printf("\nSposob przetwarzania danych: "); scanf("%d", &sposob);
    
    for(int i = 0; i < liczba_struktur; i++) Dane[i].wynik = 0.0;       //zerowanie ewentualnie wczesniej przetworzonych danych

    if(sposob == 0)
        for(int i = 0; i < liczba_struktur; i++)        //wynik jako suma trzech danych
        {
            Dane[i].wynik += Dane[i].dana_1;
            Dane[i].wynik += Dane[i].dana_2;
            Dane[i].wynik += Dane[i].dana_3;
        }
    else 
        for(int i = 0; i < liczba_struktur; i++) Dane[i].wynik = Dane[i].dana_3;        //wynik jako trzecia dana
    
    printf("\n\nLiczba struktur przetworzonych: %d", liczba_struktur);     //pogladowe wypisanie danych struktury
    for(int j = 0; j < liczba_struktur; j++){
        printf("\n\nNumer serii: %d\n", Dane[j].numer_serii);
        printf("Dana 1: %lf\n", Dane[j].dana_1);
        printf("Dana 2: %lf\n", Dane[j].dana_2);
        printf("Dana 3: %lf\n", Dane[j].dana_3);
        printf("Wynik: %lf\n", Dane[j].wynik);
    }
}

void opcja_T(int &liczba_struktur, Dane_pomiarowe *Dane)
{
    char nazwa[256] = "out.txt";
    printf("\nWpisz nazwe pliku wyjsciowego: "); scanf("%s", nazwa);     //zapytanie o nazwe pliku wyjsciowego 

    FILE * OUT = fopen(nazwa, "wt");        //utworzenie nowego pliku do zapisu

    for(int i = 0; i < liczba_struktur; i++)
        fprintf(OUT, "%d %lf %lf %lf %lf\n", Dane[i].numer_serii, Dane[i].dana_1, Dane[i].dana_2, Dane[i].dana_3, Dane[i].wynik);

    fprintf(OUT, "Liczba struktur: %d", liczba_struktur);       //zapis danych struktur po spacji i podanie ich liczby w ostatniej linii
    fclose(OUT);
}

