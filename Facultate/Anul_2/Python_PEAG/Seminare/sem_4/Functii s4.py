import numpy as np

def op_schimb(x, pm):
    y = x.copy()
    nou = 0
    r = np.random.uniform(0, 1)
    if r <= pm:
        m = len(x)
        nou = 1
        #var 1
        i, j = np.random.randint(0, m, 2)
        while i == j:
            i, j = np.random.randint(0, m, 2)
        #var 2
        #i, j = np.random.choice(m, 2, replace=False)
        #var 3
        #i, j = np.random.permutation(m)[:2]

        y[i] = x[i]
        y[j] = x[j]

    return y, nou

def mutatie(desc, pm):
    #etapa de mutatie pentru prob reginelor
    #descm - populati de descendenti
    #pm - prob de mutatie

    descm = desc.copy()
    dim,_ = np.shape(desc)
    for i in range(dim):
        x = desc[i, :-1]
        y, nou = op_schimb(x, pm)
        if nou:
            descm[i, :-1] = y.copy()
            descm[i, -1] = f_obiectiv(x)
    return descm
