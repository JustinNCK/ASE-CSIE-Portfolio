import numpy
import matplotlib.pyplot as grafic
from Selectii import s_ruleta_SUS, s_elitista
from Recombinari import r_OCX
from Mutatii import m_perm_schimb

def f_x(x, p):
    penalizare = abs(x.sum() - p)
    for i in range(1, len(x) - 1):
        if x[i] == 1 and x[i - 1] == x[i + 1] == 0:
            penalizare += 1
    if x[0] == 1 and x[1] == x[-1] == 0:
        penalizare += 1
    if x[-1] == 1 and x[-2] == x[0] == 0:
        penalizare += 1
    return penalizare

def gen_pop(x, y, m):
    pop = numpy.random.randint(2, size = (x, y))
    obv = new float[]  # TODO: fix syntax error — aceasta este sintaxa C#, nu Python valida; scriptul este netestat

    for i in range(x):
        print(i)
        obv = 1 / (f_x(pop[i, :-1], m) + 1)

    return pop