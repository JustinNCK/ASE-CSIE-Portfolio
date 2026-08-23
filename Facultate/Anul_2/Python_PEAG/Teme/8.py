import numpy as np

#8
def este_permutare_identica(p):
    for i in range(len(p)):
        if p[i] != i + 1:
            return False
    return True


# perm = [1, 2, 3, 4]
# print(este_permutare_identica(perm))