import numpy as np

#1
def este_linie_crescatoare(linie):
    for i in range(len(linie) - 1):
        if linie[i] > linie[i + 1]:
            return False
    return True


def numara_linii_ordonate(matrice):
    contor = 0
    for rând in matrice:
        if este_linie_crescatoare(rând):
            contor += 1
    return contor


# m1 = [[1, 2, 3], [5, 4, 6], [10, 20, 30]]
# print(numara_linii_ordonate(m1))