import numpy as np
def f_obv(x):
    #I: x - cromozom
    #E: c - calitatea: reprezentata prin suma elemetelor vectorului binar
    return sum(x)

def gen_pop(dim, n):
    #I: dim - nr de indivizi din populatie, n - nr de cromozomi
    #E: pop - populatia generata
    pop =np.zeros((dim, n + 1), dtype=int)
    for i in range(dim):
        pop[i, :-1] = np.random.randint(0, 2, n)
        pop[i, -1] = f_obv(pop[i, :-1])
    return pop

def op_r(x, y, pr, nr):
    #I: x, y - parintii, pr - probabilitatea de recombinare, nr - nr de puncte de inrucisare multi punct
    #E: a, b - copii, dif - daca difera de parinti sau nu
    a = x.copy()
    b = y.copy()
    dif = 0
    r = np.random.uniform(0, 1)
    if r < pr:
        dif = 1
        m = len(x)
        p = []
        for i in range(m):
            poz = np.random.randint(m)
            while poz in p:
                poz = np.random.randint(m)
            p.append(poz)
        p.sort()
        if nr % 2 == 1:
            p.append(m)
        for i in range(0, nr, 2):
            a[p[i]:p[i + 1]] = y[p[i]:p[i + 1]]
            b[p[i]:p[i + 1]] = x[p[i]:p[i + 1]]
    return a, b, dif

def recombinare(pop, pr, nr):
    perechi = np.random.permutation(pop.shape[0])
    pop_c = pop.copy()
    for i in range(0, pop.shape[0], 2):
        d1, d2, dif = op_r(pop[perechi[i], :-1], pop[perechi[i + 1], :-1], pr, nr)
        if dif == 1:
            pop_c[perechi[i], :-1] = d1.copy()
            pop_c[perechi[i], -1] = f_obv(d1)
            pop_c[perechi[i + 1], :-1] = d2.copy()
            pop_c[perechi[i + 1], -1] = f_obv(d2)
    return pop_c