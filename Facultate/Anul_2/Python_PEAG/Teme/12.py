import numpy as np

#12
def functie_f12(x):
    return (np.sin(x - 2)) ** 2


def hill_climbing_genotip():
    # 2500 se încadrează pe 12 biți (2^12 = 4096)
    x_init = np.random.randint(1, 2501)
    genotip = list(bin(x_init)[2:].zfill(12))

    while True:
        x_curent = int("".join(genotip), 2)
        valoare_curenta = functie_f12(x_curent)
        mai_bine = False

        for i in range(len(genotip)):
            copie_genotip = list(genotip)
            copie_genotip[i] = '1' if genotip[i] == '0' else '0'
            x_vecin = int("".join(copie_genotip), 2)

            if 1 <= x_vecin <= 2500 and functie_f12(x_vecin) > valoare_curenta:
                genotip = copie_genotip
                valoare_curenta = functie_f12(x_vecin)
                mai_bine = True
                break
        if not mai_bine:
            break

    return int("".join(genotip), 2), valoare_curenta

# print(hill_climbing_genotip())