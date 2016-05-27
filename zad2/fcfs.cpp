#include <cstdio>
#include <cstdlib>

using namespace std;

int
main (int argc, char ** argv)
{
  int rozmiar_dysku, przemieszczen, przemieszczenie, glowica, calkowita_droga = 0;
  scanf("%d", &rozmiar_dysku);
  scanf("%d", &glowica); // poczatkowe polozenie glowicy (losowe)
  scanf("%d", &przemieszczen);
  for (int i = 0; i < przemieszczen; ++i) {
    scanf("%d", &przemieszczenie);
    calkowita_droga += abs(przemieszczenie - glowica);
    glowica = przemieszczenie;
  }
  printf("Rozmiar dysku: %d, przemieszczen: %d, suma przemieszczen: %d\n",
        rozmiar_dysku, przemieszczen, calkowita_droga);
  return 0;
}
