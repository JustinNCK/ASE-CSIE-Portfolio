import numpy as np

#4
def sortare_insertie_coloane(matrice):
    matrice_np = np.array(matrice)
    nr_linii, nr_coloane = matrice_np.shape
    for j in range(nr_coloane):
        for i in range(1, nr_linii):
            valoare_actuală = matrice_np[i, j]
            k = i - 1
            while k >= 0 and matrice_np[k, j] > valoare_actuală:
                matrice_np[k + 1, j] = matrice_np[k, j]
                k -= 1
            matrice_np[k + 1, j] = valoare_actuală
    return matrice_np.tolist()


# m4 = [[9, 3], [4, 8], [1, 5]]
# print(sortare_insertie_coloane(m4))