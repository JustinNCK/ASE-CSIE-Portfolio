import numpy
import matplotlib.pyplot as grafic
from Selectii import s_ruleta_SUS, s_elitista
from Recombinari import r_unipunct
from Mutatii import m_binar


def GA_Rucsac01(numef,cmax,dim,pr,pm,nmax):
    # rezolvarea problemei rucsacului in varianta discreta

    # I: numef - numele fisierului cu profituri si costuri asociate obiectelor (2 linii)
    #    cmax - capacitatea rucsacului (cost maxim admis)
    #    dim - dimensiune populatie initiala
	#    pr - probabilitatea de recombinare
    #    pm - probabilitate de mutatie
    #    nmax - numarul maxim de generatii
    # E: sol - sirul care reprezinta cea mai buna solutie gasita
    #    v - costul celei mai bune solutii gasite
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
        parinti = s_ruleta_SUS(pop)
        # recombinare
        desc=recombinare(parinti,pr, profit,cost,cmax)
        # mutatie
        descm=mutatie(desc,pm, profit,cost,cmax)
        # selectie generatie urmatoare
        pop = s_elitista(pop, descm)
        # alte operatii
        # retine cea mai buna solutie
        vmax = max(pop[:, m])
        i = numpy.argmax(pop[:, m])
        sol = pop[i][:m].copy().astype(int)
        V.append(vmax)
    arata(sol, V)
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
        if numpy.dot(x,cost)<cmax:
            pop[i,:m]=x
            pop[i,m]=f_obiectiv(x,profit)
            i+=1
    return pop


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
        acceptabil=0
        while not acceptabil:
            xm,reval=m_binar(descm[i, :n - 1],pm)
            if numpy.dot(xm,cost)<=cmax:
                acceptabil=1
        if reval:
            descm[i,:n-1] = xm
            descm[i][n-1]=f_obiectiv(xm,profit)
    return descm

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
        desc[i,:]=parinti[perechi[i],:]
        desc[i+1,:]=parinti[perechi[i+1],:]
        acceptabil=0
        while not acceptabil:
            c1,c2,da=r_unipunct(x,y,pr)
            if numpy.dot(c1,cost)<=cmax and numpy.dot(c2,cost)<=cmax:
                acceptabil=1
        if da:
            desc[i,:n-1]=c1
            desc[i,n-1]=f_obiectiv(c1,profit)
            desc[i+1,:n-1]=c2
            desc[i+1,n-1]=f_obiectiv(c2,profit)
    return desc

def arata(sol,v):
    # vizualizare rezultate Rucsac01

    # I: sol - vectorul binar care defineste selectia obiectelor
    #    v - vectorul cu cea mai buna calitate din fiecare generatie
    # E: -

    n=len(sol)
    t=len(v)
    maxim=max(v)            #maxim=v[-1]    v[t-1]
    print("Cel mai mare profit calculat: ",maxim)
    print("Pentru selecția obiectelor ",sol)
    for i in range(n):
        incarcat="da" if sol[i]==1 else "nu"
        print("Obiectul ",i+1," -> ",incarcat)

    fig=grafic.figure()
    x=[i for i in range(t)]
    y=[v[i] for i in range(t)]      #y=v   y=v.copy()
    grafic.plot(x,y,'ro-')
    grafic.ylabel("Calitate")
    grafic.xlabel("Generația")
    grafic.title("Evoluția calității celui mai bun individ din fiecare generație")

    fig.show()

if __name__=="__main__":
    s, v = GA_Rucsac01("date_R01.txt", 26.3, 100, 0.7, 0.1, 50)
    grafic.pause(20)
    #print("Solutia:",s)
    #print("Profit: ",v[-1])
    #print('Evolutia calitatilor:',v)
