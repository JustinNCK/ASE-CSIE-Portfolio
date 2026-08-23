import numpy as np

#6
def operatii_matriceale(A, B, putere_n):
    a_np = np.array(A)
    b_np = np.array(B)
    transpusa = a_np.T
    suma = a_np + b_np
    produs = np.dot(a_np, b_np)
    putere = np.linalg.matrix_power(a_np, putere_n)
    return transpusa.tolist(), suma.tolist(), produs.tolist(), putere.tolist()


# m_a = [[1, 2], [3, 4]]
# m_b = [[5, 6], [7, 8]]
# print(operatii_matriceale(m_a, m_b, 2))