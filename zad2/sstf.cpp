#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int
main (int argc, char ** argv)
{
  int rozmiar_dysku, przemieszczen, przemieszczenie, glowica, calkowita_droga = 0;
  scanf("%d", &rozmiar_dysku);
  scanf("%d", &glowica); // poczatkowe polozenie glowicy (losowe)
  scanf("%d", &przemieszczen);
  vector <int> przemieszczenia;
  for (int i = 0; i < przemieszczen; ++i) {
    scanf("%d", &przemieszczenie);
    przemieszczenia.push_back(przemieszczenie);
  }

  while (!przemieszczenia.empty()) {

    // szukanie najblizszej drogi od polozenia glowicy
    int min = abs(przemieszczenia[0] - glowica);
    int min_index = 0;
    for (int i = 1; i < przemieszczenia.size(); ++i)
      if (min > abs(przemieszczenia[i] - glowica)) {
        min = abs(przemieszczenia[i] - glowica);
        min_index = i;
      }

    glowica = przemieszczenia[min_index];
    calkowita_droga += min;
    przemieszczenia.erase(przemieszczenia.begin() + min_index);
  }

  printf("Rozmiar dysku: %d, przemieszczen: %d, suma przemieszczen: %d\n",
        rozmiar_dysku, przemieszczen, calkowita_droga);
  return 0;
}
