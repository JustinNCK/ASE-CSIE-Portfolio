import numpy
import matplotlib.pyplot as grafic
from Selectii_2 import s_ruleta_SUS, s_elitista
from Recombinari import r_PMX
from Mutatii import m_perm_inversiune

# calitatea indivizilor populatiei este de tip real si pastrata intr-un vector separat

def GA_TSP(numef,dim,pr,pm,nmax):
    # rezolvarea problemei comis-voiajorului. solutiile sint reprezentate ca permutari

    # I: numef - numele fisierului cu matricea distantelor (ponderile grafului)
    #    dim - dimensiune populatie initiala
    #    pm - probabilitate de mutatie
	#    pr - probabilitatea de recombinare
    #    nmax - numarul de generatii
    # E: sol - permutarea care reprezinta cea mai buna solutie gasita
    #    V - vector cu costul celui mai bun drum din fiecare generatie
    # Exemple de utilizare
    #   import GA_TSP_2 as GT2
    #   s,v=GT2.GA_TSP('TSP_distante1.txt',100, 0.8, 0.1, 200)
    # s, v = GT2.GA_TSP('TSP_distante2.txt', 300, 0.8, 0.1, 150)
    # Cea mai mică distanță calculată: 25.0
    # Un drum cu costul 25.0
    # este: [10  8  5  6  2  7  4  1  0  3  9 11]

    # initializari
    dist=numpy.genfromtxt(numef)
    V=[]

    # generare populatie initiala
    m,n=numpy.shape(dist)                # dimensiunile sint egale, m nu va fi utilizat
    pop,cal=gen_pop_perm(dim,n,dist)

    # bucla GA
    for t in range(nmax):
        # selectie parinti
        parinti, cparinti = s_ruleta_SUS(pop, cal)
        # recombinare
        desc,cdesc=recombinare(parinti,cparinti,pr,dist)
        # mutatie
        descm,cdescm=mutatie(desc,cdesc,pm,dist)
        # selectie generatie urmatoare
        pop, cal = s_elitista(pop, cal, descm, cdescm)
        # alte operatii
        # retine cea mai buna solutie
        vmax = max(cal)
        i = numpy.argmax(cal)
        sol = pop[i][:n]
        V.append(vmax)
    arata(sol, V)
    return sol,V

def f_obiectiv(x, dist):
    # functia obiectiv pentru problema comis voiajorului

    # I: x - individul (permutarea) evaluat(a)
    #    dist - matricea distantelor
    # E: c - calitate (costul drumului)

    n=len(x)
    c=dist[x[n-1]][x[0]]
    for i in range(n-1):
        c=c+dist[x[i]][x[i+1]]
    return 1/c

def gen_pop_perm(dim, n, dist):
    # generare populatie de permutari

    # I: dim - dimensiune populatie (nr. de indivizi)
    #    n - dimensiune individ (numar de gene)
    #    dist - matricea distantelor, necesara pentru evaluare
    # E: pop - populatia aleatoare generata
    #    cal - vector cu calitatile indivizilor din populatie

    pop=numpy.zeros((dim,n),dtype=int)
    cal=numpy.zeros(dim,dtype=float)
    for i in range(dim):
        pop[i,:n]=numpy.random.permutation(n)
        cal[i]=f_obiectiv(pop[i,:n],dist)
    return pop, cal


def mutatie(desc,cdesc,pm,dist):
    # operatia de mutatie a descendentilor obtinuti din recombinare

    # I: desc - matricea descendentilor
    #    cdesc - calitate indivizi
    #    pm - probabilitatea de mutatie
    # E: descm - matricea indivizilor obtinuti
    #    cdescm - calitate indivizi obtinuti

    dim,n=numpy.shape(desc)
    descm=desc.copy()
    cdescm=cdesc.copy()
    for i in range(dim):
        x=desc[i,:n]
        xm,reval=m_perm_inversiune(x,pm)
        if reval:
            descm[i,:n]=xm
            cdescm[i]=f_obiectiv(xm,dist)
    return descm,cdescm

def recombinare(parinti,cal,pr,dist):
    # operatia de recombinare a parintilor selectati

    # I: parinti - parintii selectati
    #    cal - calitate parinti
    #    pr - probabilitatea de recombinare
    #    dist - matricea distantelor, pentru evaluare
    # E: desc - descendentii obtinuti
    #    cdesc - calitate descendenti

    dim,n=numpy.shape(parinti)
    desc=numpy.zeros((dim,n), dtype=int)
    cdesc=numpy.zeros(dim,dtype=float)
    # alegere aleatoare a perechilor de parinti
    perechi=numpy.random.permutation(dim)
    for i in range(0,dim,2):
        x=parinti[perechi[i],:n]
        y=parinti[perechi[i+1],:n]
        desc[i,:]=x
        desc[i+1,:]=y
        cdesc[i]=cal[i]
        cdesc[i+1]=cal[i+1]
        d1,d2,da=r_PMX(x,y,pr)
        if da==1:
            desc[i,:n]=d1
            cdesc[i]=f_obiectiv(d1,dist)
            desc[i+1,:n]=d2
            cdesc[i+1]=f_obiectiv(d2,dist)
    return desc,cdesc

def arata(sol,v):
    # vizualizare rezultate TSP

    # I: x - permutarea care defineste asezarea
    # E: -

    n=len(sol)
    t=len(v)
    maxim=max(v)
    cost=1/maxim
    print("Cea mai mică distanță calculată: ",cost)
    print("Un drum cu costul ",cost," este: ",sol)

    fig=grafic.figure()
    x=[i for i in range(t)]
    y=[1/v[i] for i in range(t)]
    grafic.plot(x,y,'ro-')
    grafic.ylabel("Calitate")
    grafic.xlabel("Generația")
    grafic.title("Evoluția costului celui mai bun individ din fiecare generație")

    fig.show()


if __name__=="__main__":
    s,v=GA_TSP('TSP_distante1.txt',100, 0.8, 0.1, 200)
    grafic.pause(20)
    print("Solutia:",s)
    print('Evolutia calitatilor:',v)
