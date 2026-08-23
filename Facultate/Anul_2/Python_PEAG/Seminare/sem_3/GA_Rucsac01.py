import numpy


def GA_Rucsac01(numef,cmax,dim,alti_parametri_de_control,nmax):
    # rezolvarea problemei rucsacului in varianta discreta

    # I: numef - numele fisierului cu profituri si costuri asociate obiectelor (2 linii)
    #    cmax - capacitatea rucsacului (cost maxim admis)
    #    dim - dimensiune populatie initiala
    #    ...
    #    nmax - numarul maxim de generatii
    # E: sol - sirul care reprezinta cea mai buna solutie gasita
    #    v - profitul celei mai bune solutii gasite
    # Exemple de utilizare
    #    import GA_Rucsac01 as GC
    #    s,v=GC.GA_Rucsac01("date_R01.txt",26.3,100,0.7,0.1,50)
    # Rezultate obtinute
    #    Cel mai mare profit calculat:  65.1
    #    Pentru selecția obiectelor  [0 1 1 0 1 0 0 1 0 1 1 1 0 0 0 1]

    # initializari
    date=numpy.genfromtxt(numef)
    profit=date[0].copy()
    cost = date[1].copy()
    m=len(profit)
    V=[]

    # generare populatie initiala
    pop=gen_pop_bin(dim,profit,cost,cmax)

    # bucla GA
    for i in range(nmax):
        # selectie parinti
        
        # recombinare
        
        # mutatie
        
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

def gen_pop_bin(dim, profit, cost, cmax):
    # generare populatie binara de indivizi acceptabili

    # I: dim - dimensiune populatie (nr. de indivizi)
    #    profit - vector de profituri
    #    cost - vectorul de costuri
    #    cmax - capacitatea de incarcare (costul maxim)
    # E: pop - populatia aleatoare generata, cu calitatea fiecarui individ pe ultima coloana

    m=len(profit)
    pop=numpy.zeros((dim,m+1),dtype=float)
    i=0
    while i<dim:
        x=numpy.random.randint(0,2,m)
        if numpy.dot(x,cost)<=cmax:
            pop[i,:m]=x
            pop[i,m]=f_obiectiv(x,profit)
            i+=1
    return pop

