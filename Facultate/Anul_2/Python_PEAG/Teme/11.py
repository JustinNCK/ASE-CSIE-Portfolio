import numpy as np

#11

def functie_f11(x):
    return (np.sin(x - 2)) ** 2 - x * np.cos(x)


def hill_climbing_simplu():
    punct_actual = np.random.randint(1, 2501)
    continuă = True
    while continuă:
        continuă = False
        vecini = []
        if punct_actual > 1: vecini.append(punct_actual - 1)
        if punct_actual < 2500: vecini.append(punct_actual + 1)

        for vecin in vecini:
            if functie_f11(vecin) > functie_f11(punct_actual):
                punct_actual = vecin
                continuă = True
    return punct_actual, functie_f11(punct_actual)


# print(hill_climbing_simplu())
