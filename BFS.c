#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define BEYAZ 0
#define GRI 1
#define SARI 2

typedef struct Dugum {
    int vertex;
    struct Dugum *sonraki;
} Dugum;
Dugum *komsulukListesi[MAX_VERTICES];

typedef struct Kuyruk {
    int items[MAX_VERTICES];
    int front, rear;
} Kuyruk;

int renk[MAX_VERTICES], mesafe[MAX_VERTICES], ebeveyn[MAX_VERTICES];

void initGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) komsulukListesi[i] = NULL;
}

void kenarEkle(int u, int v) {
    Dugum *yeni = (Dugum*)malloc(sizeof(Dugum));
    yeni->vertex = v;
    yeni->sonraki = komsulukListesi[u];
    komsulukListesi[u] = yeni;
}

void initKuyruk(Kuyruk *q) { q->front = q->rear = 0; }
int kuyrukBos(Kuyruk *q) { return q->front == q->rear; }
void enqueue(Kuyruk *q, int deger) { q->items[q->rear++] = deger; }
int dequeue(Kuyruk *q) { return q->items[q->front++]; }

void bfs(int basla) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        renk[i] = BEYAZ;
        mesafe[i] = -1;
        ebeveyn[i] = -1;
    }
    renk[basla] = GRI;
    mesafe[basla] = 0;
    Kuyruk q; initKuyruk(&q);
    enqueue(&q, basla);
    while (!kuyrukBos(&q)) {
        int u = dequeue(&q);
        Dugum *temp = komsulukListesi[u];
        while (temp) {
            int v = temp->vertex;
            if (renk[v] == BEYAZ) {
                renk[v] = GRI;
                mesafe[v] = mesafe[u] + 1;
                ebeveyn[v] = u;
                enqueue(&q, v);
            }
            temp = temp->sonraki;
        }
        renk[u] = SARI;
    }
}

int main() {
    initGraph();
    kenarEkle(0, 1);
    kenarEkle(0, 2);
    kenarEkle(1, 3);
    kenarEkle(2, 3);
    kenarEkle(2, 4);
    bfs(0);
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (mesafe[i] != -1)
            printf("Vertex %d: distance=%d, parent=%d\n", i, mesafe[i], ebeveyn[i]);
    }
    return 0;
}
