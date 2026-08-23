import numpy as np

#3
def sortare_bule_matrice(matrice):
    for rând in matrice:
        schimbare = True
        while schimbare:
            schimbare = False
            for i in range(len(rând) - 1):
                if rând[i] > rând[i + 1]:
                    rând[i], rând[i + 1] = rând[i + 1], rând[i]
                    schimbare = True
    return matrice


# m3 = [[3, 1, 2], [10, 5, 8]]
# print(sortare_bule_matrice(m3))