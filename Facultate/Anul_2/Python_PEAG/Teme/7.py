import numpy as np

#7
def sortare_insertie_lista(lista):
    for i in range(1, len(lista)):
        cheie = lista[i]
        j = i - 1
        while j >= 0 and lista[j] > cheie:
            lista[j + 1] = lista[j]
            j -= 1
        lista[j + 1] = cheie
    return lista


# l7 = [5, 2, 9, 1, 5]
# print(sortare_insertie_lista(l7))