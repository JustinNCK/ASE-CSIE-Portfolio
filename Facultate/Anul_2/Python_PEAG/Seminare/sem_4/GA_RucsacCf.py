import numpy
from Mutatii import m_reale_neunif


def GA_RucsacCf(numef,cmax,dim,pm,T,nmax):
    # rezolvarea problemei rucsacului in varianta continua - cu fractii

    # I: numef - numele fisierului cu profituri si costuri asociate obiectelor (2 linii)
    #    cmax - capacitatea rucsacului (cost maxim admis)
    #    dim - dimensiune populatie initiala
    #    pm - probabilitate de mutatie
    #    T - valoarea maxima de fluaj
    #    ...
    #    nmax - numarul maxim de generatii
    # E: sol - sirul care reprezinta cea mai buna solutie gasita
    #    v - profitul celei mai bune solutii gasite
    # Exemple de utilizare
    #    import GA_RucsacCf as GCf
    #    s,v=GCf.GA_RucsacCf("date_RC1.txt",30,100,0.7,0.1,0.3,0.7,300)
    #    Cel mai mare profit calculat:  55.99945713537708
    #    Pentru selecția obiectelor  [0.57739832 0. 0. 1. 0. 0.86166602 0.6512268  1. 1.]
    #    Cel mai mare profit calculat:  55.999811593562455
    #    Pentru selecția obiectelor  [8.22130665e-01 0.00000000e+00 5.02411755e-05 1.00000000e+00
    #    0.00000000e+00 3.92596595e-01 1.00000000e+00 1.00000000e+00
    #    1.00000000e+00]

    # initializari
    date=numpy.genfromtxt(numef)
    profit=date[0].copy()
    cost = date[1].copy()
    m=len(profit)
    V=[]

    # generare populatie initiala
    pop=gen_pop(dim,profit,cost,cmax)

    # bucla GA
    for i in range(nmax):
        # selectie parinti
        
        # recombinare
        
        # mutatie
        descm=mutatie(desc,pm,T,profit,cost,cmax)
        # selectie generatie urmatoare
        
        # alte operatii
        # retine cea mai buna solutie
        
    return sol,V


def f_obiectiv(x,profit):
    # functia obiectiv pentru problema rucsacului

    # I: x - individul evaluat
    #    profit - vectorul cu profitul tuturor obiectelor
    # E: c - calitate (profit adus de obiectele selectate conform x)

    c=numpy.dot(profit,x)
    return c


def gen_pop(dim, profit, cost, cmax):
    # generare populatie de indivizi  aceptabili (fractii)

    # I: dim - dimensiune populatie (nr. de indivizi)
    #    profit - vector de profituri
    #    cost - vectorul de costuri
    #    cmax - capacitatea de incarcare (costul maxim)
    # E: pop - populatia aleatoare generata, cu calitatea fiecarui individ pe ultima coloana

    m=len(profit)
    pop=numpy.zeros((dim,m+1),dtype=float)
    i=0
    while i<dim:
        x=numpy.random.uniform(0,1,m)
        if numpy.dot(x,cost)<cmax:
            pop[i,:m]=x
            pop[i,m]=f_obiectiv(x, profit)
            i+=1
    return pop


def mutatie(desc,pm,T, profit,cost,cmax):
    # operatia de mutatie a descendentilor obtinuti din recombinare

    # I: desc - matricea descendentilor
    #    pm - probabilitatea de mutatie
    #    T - valoarea maxima de fluaj (modificarea maxima admisa)
    #    profit - vector de profituri
    #    cost - vectorul de costuri
    #    cmax - capacitatea de incarcare (costul maxim)
    # E: descm - matricea indivizilor obtinuti

    dim,n=numpy.shape(desc)
    descm=desc.copy()
    for i in range(dim):
        x=descm[i, :n - 1]
        acceptabil = 0
        while not acceptabil:
            xm,reval=m_reale_neunif(x,pm,0,1,T)
            if numpy.dot(xm,cost)<=cmax:
                acceptabil=1
        if reval:
            descm[i,:n-1]=xm
            descm[i][n-1]=f_obiectiv(xm,profit)
    return descm

