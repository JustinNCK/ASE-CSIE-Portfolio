import numpy as np

#9
def genereaza_date_binare():
    A = np.random.randint(0, 2, (20, 7))
    V = np.sum(A, axis=1)
    return A.tolist(), V.tolist()


# matrice_a, vector_v = genereaza_date_binare()
# print(vector_v)