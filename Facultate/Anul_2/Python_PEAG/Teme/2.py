import numpy as np

#2
def gaseste_coloane_cu_minim_5(matrice):
    matrice_np = np.array(matrice)
    nr_coloane = matrice_np.shape[1]
    rezultat = []
    for j in range(nr_coloane):
        coloană = matrice_np[:, j]
        if np.min(coloană) == 5:
            rezultat.append(j)
    return rezultat


# m2 = [[10, 5, 8], [5, 6, 7], [8, 9, 5]]
# print(gaseste_coloane_cu_minim_5(m2))