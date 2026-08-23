import numpy as np
import matplotlib.pyplot as plt

#PROBLEMA 1
def f_obiectiv(x):
    #SCOP: functia obiectov pentru problema 1
    #In: x - cromozomul evealuat
    #Out: c - calitatea lui cromozomului
    contor = 0
    n = len(x)
    for i in range(n - 1):
        for j in range(i + 1, n):
            if x[i] < x[j]:
                contor += 1

    #c = len([(i, j) for i in range(i - 1) for j in range(i + 1, n) if x[i] < x[j]])

    return contor

def a_gen(dim, n):
    #punctul a de la problema 1
    #In: dim - nr de indivizi, n - dimensiunea unui individ
    #Out: pop - populatie

    pop = np.zeros([dim, n + 1], dtype=int)
    for i in range(dim):
        x = np.random.permutation(n)
        pop[i, :-1] = x.copy()
        pop[i, -1] = f_obiectiv(x)

    return pop

def operator_mutatie(x, pm):
    #operatorul de mutatie prin inserare pentru permutari
    #In: x - cromozomul pe care aplicam mutatia, pm - probabilitate mutatie
    #Out: popm - populatie mutata, dif - 0 (y = x), 1(y != x)

    y = x.copy()
    dif = 0

    val = np.random.uniform(0, 1)
    if val < pm:
        n = len(x)
        poz = np.random.choice(n, 2, replace = False)
        poz.sort()
        y[poz[0] + 2:poz[1] + 1] = x[poz[0] + 1:poz[1]]
        y[poz[0] + 1] = x[poz[1]]
        dif = 1

    return y, dif

def b_mutatie(pop, pm):
    # punctul b de la problema 1
    # In: pop - populatia initiala, pm - probabilitate mutatie
    # Out: popm - populatie mutata

    popm = pop.copy()
    dim, n = np.shape(pop)

    for i in range(dim):
        individ, ok = operator_mutatie(popm[i, :-1], pm)
        if ok == 1:
            popm[i, :-1] = individ.copy()
            popm[i, -1] = f_obiectiv(individ)

    return popm


dim = 10
n = 12
pm = 0.213

var = a_gen(dim, n)
print("Populatia initiala: ")
print(var)

var2 = b_mutatie(var, pm)
print("Populatia finala: ")
print(var2)

print("Diferenta dintre cele doua matrici: ")
print(var2 - var)

plt.plot(var[:, -1], "rs", markersize = 12, label = "Populatia initiala")
plt.plot(var2[:, -1], "bo", markersize = 8, label = "Populatia finala")
plt.legend()
plt.show()