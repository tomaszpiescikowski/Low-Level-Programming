#include <stdio.h>
#include <conio.h>      //conio.h jako dodatkowa opcja potrzebna do funkcji getch() na koncu programu, niepotrzebna do dzialania

int main()
{   
    const int N = 50;             
    int tab[N][N] = {{0}};      //utworzenie tablicy dwuwymiarowej 50x50
    int i = 0, j = 0, count = 0, I, rozmiar;
    FILE * PLIKin = fopen("Dane.txt", "rt+");       //otwarcie pliku wejsciowego

    do{
    printf("Podaj rozmiar tablicy do wykorzystania: ");     //ad1. Program powinien zapytać użytkownika o aktualny rozmiar tablicy (mniejszy od 50).
    scanf("%d", &rozmiar);                                  //ad1. Tablica ma być statyczna zdefiniowana dla maksymalnej liczby danych, wykorzystywana jest jej część o rozmiarze podanym przez użytkownika.
    }while(rozmiar > 50 || rozmiar <= 0);   


    while(feof(PLIKin) == 0)    //program odczytuje dane do konca pliku
    {
        fscanf(PLIKin, "%d ", &tab[i][j++]);    //odczyt pojedynczej liczby calkowitej i przypisanie jej do tablicy (wierszami)
        count ++;       //zmienna do zliczania danych
        if(j == rozmiar)
         {  j = 0;      //gdy zapelni sie wiersz, zaczynamy uzupelnianie drugiego
            i++;    }       
    }

    printf("Wpisano %d liczb\n", count);        //dodatkowa informacja
  
    do{ printf("\nPodaj numer I: "); scanf("%d", &I); } while (I < 0 || I >= rozmiar);   //warunek jak w poleceniu
   
    FILE * PLIKout = fopen("Wynik.txt", "wt");      //utworzenie pliku wyjsciowego
    for(int j = I; j < rozmiar; j++)
    {
        for(int i = 0; i < rozmiar; i++)      //wypisanie elementow z kolejnych kolumn o numerach od I do N-1
        {   
            if(((i*rozmiar) + (j+1)) <= count) fprintf(PLIKout, "%d ", tab[i][j]);
            
        }
    }
    
   _fcloseall();        //zamkniecie wszystkich plikow
    
    printf("\nKoniec programu."); 
    printf("\nNacisnij dowolny klawisz...");       //dodatek do zatrzymania okna konsoli
    getch();        
    return 0;
}




