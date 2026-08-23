import numpy as np

#10
def sorteaza_matrice_dupa_calitate(A, V):
    a_np = np.array(A)
    v_np = np.array(V)
    indici_sortati = np.argsort(v_np)
    return a_np[indici_sortati].tolist(), v_np[indici_sortati].tolist()


# a_rez, v_rez = sorteaza_matrice_dupa_calitate(matrice_a, vector_v)