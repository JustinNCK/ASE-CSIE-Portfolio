import numpy


# calitatea indivizilor populatiei este de tip real si pastrata intr-un vector separat

def GA_TSP(numef,dim,alti_parametri_de_control,nmax):
    # rezolvarea problemei comis-voiajorului. solutiile sint reprezentate ca permutari

    # I: numef - numele fisierului cu matricea distantelor (ponderile grafului)
    #    dim - dimensiune populatie initiala
    #    ...
    #    nmax - numarul de generatii
    # E: sol - permutarea care reprezinta cea mai buna solutie gasita
    #    V - vector cu costul celui mai bun drum din fiecare generatie
    # Exemple de utilizare
    #   import GA_TSP as GT2
    #   s,v=GT2.GA_TSP('TSP_distante1.txt',100, 0.8, 0.1, 200)

    # initializari
    dist=numpy.genfromtxt(numef)
    V=[]

    # generare populatie initiala
    m,n=numpy.shape(dist)                # dimensiunile sint egale, m nu va fi utilizat
    pop,cal=gen_pop_perm(dim,n,dist)

    # bucla GA
    for t in range(nmax):
        # selectie parinti
        
        # recombinare
        
        # mutatie
        
        # selectie generatie urmatoare
        
        # alte operatii
        # retine cea mai buna solutie
        
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
        pop[i,:]=numpy.random.permutation(n)
        cal[i]=f_obiectiv(pop[i,:n],dist)
    return pop, cal



