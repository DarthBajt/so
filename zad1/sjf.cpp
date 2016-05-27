#include <cstdio>
#include <algorithm>

using namespace std;

struct proces
{
  int id;
  int czas;
  int czas_oczekiwania;
  int czas_zakonczenia;
};

bool
compare (const proces & p1, const proces & p2)
{
  return p1.czas < p2.czas;
}

int
main (int argc, char ** argv)
{
  int liczba_testow, liczba_procesow, suma_oczekiwania;
  proces *p;


  scanf("%d", &liczba_testow);
  for (int test = 0; test < liczba_testow; ++test) {
    suma_oczekiwania = 0;

    // tworzenie procesow
    scanf("%d", &liczba_procesow);
    printf("Test: %2d, procesow: %2d\n", test + 1, liczba_procesow);
    p = new proces[liczba_procesow];
    for (int i = 0; i < liczba_procesow; ++i) {
      p[i].id = i + 1;
      scanf("%d", &p[i].czas);
      p[i].czas_oczekiwania = p[i].czas_zakonczenia = 0;
    }

    // sortowanie procesow po czasie
    sort(p, p + liczba_procesow, compare);

    // obliczanie czasu
    p[0].czas_zakonczenia = p[0].czas;
    for (int i = 1; i < liczba_procesow; ++i) {
      p[i].czas_oczekiwania = p[i-1].czas_oczekiwania + p[i-1].czas;
      p[i].czas_zakonczenia = p[i].czas_oczekiwania + p[i].czas;
    }

    // wyswietlanie wynikow
    for (int i = 0; i < liczba_procesow; ++i) {
      suma_oczekiwania += p[i].czas_oczekiwania;
      printf("  id: %3d, czas: %3d, czas oczekiwania: %4d, czas obsluzenia: %4d\n",
          p[i].id, p[i].czas, p[i].czas_oczekiwania, p[i].czas_zakonczenia);
    }
    printf("Calkowity czas oczekiwania: %d\n", suma_oczekiwania);
    printf("Sredni czas oczekiwania: %.2lf\n\n", (double) suma_oczekiwania / (double) liczba_procesow);

    delete [] p;
  }
  return 0;
}
