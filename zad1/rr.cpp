#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct proces
{
  int id;
  int czas;
  int czas_oczekiwania;
  int czas_zakonczenia;
};

const int KWANT = 20;

int
main (int argc, char ** argv)
{
  int liczba_testow, liczba_procesow, suma_oczekiwania;
  vector <proces> procesy;

  scanf("%d", &liczba_testow);
  for (int test = 0; test < liczba_testow; ++test) {
    suma_oczekiwania = 0;

    // tworzenie procesow
    scanf("%d", &liczba_procesow);
    printf("Test: %2d, procesow: %2d\n", test + 1, liczba_procesow);
    for (int i = 0; i < liczba_procesow; ++i) {
      proces p;
      p.id = i + 1;
      scanf("%d", &p.czas);
      p.czas_oczekiwania = p.czas_zakonczenia = 0;
      procesy.push_back(p);
    }

    for (int i = 0; i < procesy.size(); ++i)
      if (procesy[i].czas > KWANT) {
        procesy[i].czas -= KWANT;
        procesy.push_back(procesy[i]);
      }

    // obliczanie czasu
    procesy[0].czas_zakonczenia = procesy[0].czas;
    for (int i = 1; i < procesy.size(); ++i) {
      procesy[i].czas_oczekiwania = procesy[i-1].czas_oczekiwania + procesy[i-1].czas;
      procesy[i].czas_zakonczenia = procesy[i].czas_oczekiwania + procesy[i].czas;
    }

    // wyswietlanie wynikow
    for (int i = 0; i < procesy.size(); ++i) {
      suma_oczekiwania += procesy[i].czas_oczekiwania;
      printf("  id: %3d, czas: %3d, czas oczekiwania: %4d, czas obsluzenia: %4d\n",
          procesy[i].id, procesy[i].czas, procesy[i].czas_oczekiwania, procesy[i].czas_zakonczenia);
    }
    printf("Calkowity czas oczekiwania: %d\n", suma_oczekiwania);
    printf("Sredni czas oczekiwania: %.2lf\n\n", (double) suma_oczekiwania / (double) liczba_procesow);

    procesy.clear();

  }
  return 0;
}
