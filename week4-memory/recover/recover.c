#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // Accept a single command-line argument

    // Open the memory card
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        {
            printf("Could not open file.\n");
            return 1;
        }
    unsigned char buffer[512]; // nasze okno do pisania pliku
    FILE *img = NULL;   // aktualny plik JPEG, czyli img to bedzie wskaznik do jPEGA ktorego aktualnie zapisuje. narazie jest pusty czyli null
    int count = 0;      // ile zdjęć znaleźliśmy
    char filename[10];   // "000.jpg", 8, bo musimy tez przewidzic byta na zakonczenie stringa (\0)

    while(fread(buffer, 1, 512, f) == 512) // w tym fread przepychamy kawalki pliku do bufora, nie musimy pisac &buffer, bo buffer sam w sobie jest juz pointerem do adresu pierwszego elementu arreya buffer
        { if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
                {

                    if (img != NULL) // czyli kiedy nasz plik image jest otwarty
                        {
                            fclose(img);
                        }
                    sprintf(filename, "%03i.jpg", count); // tworzy napis (string) z nazwą pliku i zapisuje go do tablicy filename
                    img = fopen(filename, "w");
                    count ++;
                }
             if(img != NULL)
                {
                    fwrite(buffer, 1, 512, img);
                }
        }

        if (img != NULL) // to jest do zamkniecia pliku ostatniego jpega z karty pamieci, bo wczesniejsze jpegi zamykalismy w ifie gdy rozpoczynal sie nowy jpeg, ale tutaj nie rozpoczyna si ekolejny, ale musimy jakos zamknac tez ostatni plik.
            {
                fclose(img);
            }

        fclose(f);


}
