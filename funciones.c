#include "constants.h"

int cuentaVecinos(int matriz[WIDTH][HEIGHT], int i, int j) {
    int f, c, cont = 0;
    for (f = i - 1; f <= i + 1; f++) {
        for (c = j - 1; c <= j + 1; c++) {
            if (f >= 0 && f < WIDTH && c >= 0 && c < HEIGHT) {
                if (!(f == i && c == j)) {
                    if (matriz[f][c] == 1 || matriz[f][c] == 2) {
                        cont++;
                    }
                }
            }
        }
    }
    return cont;
}

void calculaSiguiente(int matriz[WIDTH][HEIGHT]) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            int cont = cuentaVecinos(matriz, i, j);
            if (matriz[i][j] == 0 && cont == 3)
                matriz[i][j] = 3;
            if (matriz[i][j] == 1 && (cont < 2 || cont > 3))
                matriz[i][j] = 2;

        }
    }
    return;
}

void aplicaSiguiente(int matriz[WIDTH][HEIGHT]) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (matriz[i][j] == 2) matriz[i][j] = 0;
            if (matriz[i][j] == 3) matriz[i][j] = 1;
        }
    }
    return;
}
