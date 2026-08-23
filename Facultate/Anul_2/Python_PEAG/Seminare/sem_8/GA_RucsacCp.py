import numpy
import matplotlib.pyplot as grafic
from Selectii import s_ruleta_SUS, s_elitista
from Recombinari import r_OCX
from Mutatii import m_perm_schimb


def GA_RucsacCp(numef,cmax,dim,pr,pm,nmax):
    # rezolvarea problemei rucsacului in varianta continua - cu permutari

    # genotip: permutare, ordinea de incarcare a obiectelor
    # fenotip: fractii incarcate din fiecare obiect
    # I: numef - numele fisierului cu profituri si costuri asociate obiectelor (2 linii)
    #    cmax - capacitatea rucsacului (cost maxim admis)
    #    dim - dimensiune populatie initiala
    #    pm, pr - probabilitate de mutatie, respectiv de recombinare
    #    nmax - numarul maxim de generatii
    # E: sol - permutarea care reprezinta cea mai buna solutie gasita
    #    v - profitul celei mai bune solutii gasite
    # Exemple de utilizare
    #    import GA_RucsacCp as GCp
    #    s,v=GCp.GA_RucsacCp("date_RC1.txt",30,100,0.7,0.1,50)
    #    Cel mai mare profit calculat:  56.0
    #    Pentru selecția obiectelor  [0. 0. 0. 1. 0. 0.66666667 1. 1. 1.]
    #    Cel mai mare profit calculat:  56.0
    #    Pentru selecția obiectelor  [1. 0. 0. 1. 0. 0.33333333  1. 1. 1.]
    #    Cel mai mare profit calculat:  56.0
    #    Pentru selecția obiectelor  [0.  0.  0.  1.  0.  1.  0.7 1.  1. ]
    #    Cel mai mare profit calculat:  56.0
    #    Pentru selecția obiectelor  [1.  0.  0.  1.  0.  1.  0.4 1.  1. ]
    #
    #    s,v=GCp.GA_RucsacCp("date_RC2.txt",400,100,0.7,0.1,50)
    #    Cel mai mare profit calculat:  861.9333333333334
    #     Pentru selecția obiectelor  [1. 0. 0.73333333 0. 1. 0. 1. 0. 0. 0. 0. 0.
    #     1. 0. 0. 1. 0. 1. 1. 1.]


    # initializari
    date=numpy.genfromtxt(numef)
    profit=date[0].copy()
    cost = date[1].copy()
    m=len(profit)
    V=[]

    # generare populatie initiala
    pop=gen_pop(dim,profit,cost,cmax)

    # bucla GA
    k=0
    divers=True
    while (k<nmax) and divers:
        # selectie parinti
        parinti=s_ruleta_SUS(pop)
        # recombinare
        desc=recombinare(parinti,pr, profit,cost,cmax)
        # mutatie
        descm=mutatie(desc,pm, profit,cost,cmax)
        # selectie generatie urmatoare
        pop=s_elitista(pop,descm)
        # alte operatii
        # retine cea mai buna solutie
        vmax=max(pop[:,m])
        vmin=min(pop[:,m])
        divers=(vmax!=vmin)
        i=numpy.argmax(pop[:,m])
        sol=gen_alocare(pop[i][:m],cost,cmax)
        V.append(vmax)
        k+=1
    arata(sol,V)
    return sol,V

def gen_alocare(a, cost, cmax):
    # decodificare genotip. stabileste incarcare in functie de ordinea data de genotip

    # I: a - genotip; permutare = ordinea in care sint considerate obiectele
    #    cost - costul fiecarui obiect (vector)
    #    cmax - capacitatea de incarcare (cost maxim)
    # E: y - fenotip; sir de fractii care arata cit se incarca din fiecare obiect

    CR=cmax
    x = a.copy().astype(int)
    n=len(x)
    y=numpy.zeros(n,dtype=float)
    i=0
    while CR>0 and i<n:
        if CR>cost[x[i]]:
            y[x[i]] = 1.     #incarca obiectul intreg
            CR-=cost[x[i]]
        else:
            y[x[i]]=CR/cost[x[i]]
            CR=0
        i+=1
    return y


def f_obiectiv(y,profit):
    # functia obiectiv pentru problema rucsacului

    # I: y - fenotipul asociat cromozomului evaluat (cromozom decodificat)
    #    profit - vectorul cu profitul tuturor obiectelor
    # E: c - calitate (profit adus de obiectele selectate conform y)

    c=numpy.dot(profit,y)
    return c


def gen_pop(dim, profit, cost, cmax):
    # generare populatie de indivizi acceptabili (permutari)

    # I: dim - dimensiune populatie (nr. de indivizi)
    #    profit - vector de profituri
    #    cost - vectorul de costuri
    #    cmax - capacitatea de incarcare (costul maxim)
    # E: pop - populatia aleatoare generata, cu calitatea fiecarui individ pe ultima coloana

    m=len(profit)
    pop=numpy.zeros((dim,m+1),dtype=int)
    for i in range(dim):
        x=numpy.random.permutation(m)
        pop[i, :m]=x
        y=gen_alocare(x,cost,cmax)
        pop[i,m]=f_obiectiv(y,profit)
    return pop


def recombinare(parinti,pr, profit,cost,cmax):
    # operatia de recombinare a parintilor selectati

    # I: parinti - parintii selectati
    #    pr - probabilitatea de recombinare
    #    profit - vector de profituri
    #    cost - vectorul de costuri
    #    cmax - capacitatea de incarcare (costul maxim)
    # E: desc - descendentii obtinuti

    dim,n=numpy.shape(parinti)
    desc=numpy.zeros((dim,n))
    # alegere aleatoare a perechilor de parinti
    perechi=numpy.random.permutation(dim)
    for i in range(0,dim,2):
        x=parinti[perechi[i],:n-1]
        y=parinti[perechi[i+1],:n-1]
        desc[i, :] = parinti[perechi[i], :]
        desc[i + 1, :] = parinti[perechi[i + 1], :]
        c1,c2,da=r_OCX(x,y,pr)
        if da==1:
            y1=gen_alocare(c1,cost,cmax)
            y2=gen_alocare(c2,cost,cmax)
            desc[i,:n-1]=c1
            desc[i][n-1]=f_obiectiv(y1,profit)
            desc[i+1,:n-1]=c2
            desc[i+1][n-1]=f_obiectiv(y2,profit)
    return desc

def mutatie(desc,pm, profit,cost,cmax):
    # operatia de mutatie a descendentilor obtinuti din recombinare

    # I: desc - matricea descendentilor
    #    pm - probabilitatea de mutatie
    #    profit - vector de profituri
    #    cost - vectorul de costuri
    #    cmax - capacitatea de incarcare (costul maxim)
    # E: descm - matricea indivizilor obtinuti

    dim,n=numpy.shape(desc)
    descm=desc.copy()
    for i in range(dim):
        x=descm[i, :n - 1]
        xm,da=m_perm_schimb(x,pm)
        if da==1:
            y=gen_alocare(xm,cost,cmax)
            descm[i,:n-1]=xm
            descm[i][n-1]=f_obiectiv(y,profit)
    return descm


def arata(sol,v):
    # vizualizare rezultate RucsacCp

    # I: sol - vectorul binar care defineste selectia obiectelor
    #    v - vectorul cu cea mai buna calitate din fiecare generatie
    # E: -

    n=len(sol)
    t=len(v)
    maxim=max(v)
    print("Cel mai mare profit calculat: ",maxim)
    print("Pentru selecția obiectelor ",sol)

    fig=grafic.figure()
    x=[i for i in range(t)]
    y=[v[i] for i in range(t)]
    grafic.plot(x,y,'ro-')
    grafic.ylabel("Calitate")
    grafic.xlabel("Generația")
    grafic.title("Evoluția calității celui mai bun individ din fiecare generație")

    fig.show()


if __name__=="__main__":
    s, v = GA_RucsacCp("date_RC2.txt", 400, 100, 0.7, 0.1, 50)
    grafic.pause(20)