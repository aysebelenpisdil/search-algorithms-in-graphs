#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define BEYAZ 0
#define GRI 1
#define SIYAH 2

typedef struct Dugum {
    int vertex;
    struct Dugum* sonraki;
} Dugum;

Dugum* liste[MAX];
int renk[MAX], ebeveyn[MAX];

void initGraf() {
    for(int i = 0; i < MAX; i++) {
        liste[i] = NULL;
        renk[i] = BEYAZ;
        ebeveyn[i] = -1;
    }
}

void kenarEkle(int u, int v) {
    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    yeni->vertex = v;
    yeni->sonraki = liste[u];
    liste[u] = yeni;
}

void DFSZiyaret(int u) {
    renk[u] = GRI;
    Dugum* p = liste[u];
    while(p) {
        int v = p->vertex;
        if(renk[v] == BEYAZ) {
            ebeveyn[v] = u;
            DFSZiyaret(v);
        }
        p = p->sonraki;
    }
    renk[u] = SIYAH;
}

void DFS(int basla) {
    for(int i = 0; i < MAX; i++) {
        renk[i] = BEYAZ;
        ebeveyn[i] = -1;
    }
    DFSZiyaret(basla);
}

int main() {
    initGraf();
    kenarEkle(0, 1);
    kenarEkle(0, 2);
    kenarEkle(1, 3);
    kenarEkle(2, 3);
    kenarEkle(2, 4);
    DFS(0);
    return 0;
}
