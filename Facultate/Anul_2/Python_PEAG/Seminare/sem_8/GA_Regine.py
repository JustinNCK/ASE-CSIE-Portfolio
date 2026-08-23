import numpy
import matplotlib.pyplot as grafic
from Selectii import s_ruleta_SUS, s_elitista
from Recombinari import r_OCX
from Mutatii import m_perm_schimb



def GA_Regine(n,dim,pr,pm,nmax):
    # rezolvarea problemei celor n regine, pe o tabla n*n

    # I: n - numarul de regine
    #    dim - dimensiune populatie initiala
    #    pm - probabilitate de mutatie
	#    pr - probabilitate de recombinare
    #    nmax - numarul maxim de generatii
    # E: sol - permutarea care reprezinta cea mai buna solutie gasita
    #    V - vector cu cea mai buna calitate din fiecare generatie
    # Exemple de utilizare
    #   import GA_Regine as GR
    #   s,v=GR.GA_Regine(8,50,0.8,0.1,50)
    #   s,v=GR.GA_Regine(10,30,0.8,0.1,30)

    # initializari
    V=[]

    # generare populatie initiala
    pop=gen_pop_perm(dim,n)

    # bucla GA
    t=0         # contor iteratii
    vmax = 0  # valoarea celei mai bune solutii gasite
    # evolutie pina la consumarea tuturor iteratiilor sau atingerea calitatii maxime
    while (t<nmax) and (vmax<n*(n-1)/2):
        # selectie parinti
        parinti = s_ruleta_SUS(pop)
        # recombinare
        desc=recombinare(parinti,pr)
        # mutatie
        descm=mutatie(desc,pm)
        # selectie generatie urmatoare
        pop = s_elitista(pop, descm)
        # alte operatii
        t=t+1       #am terminat o iteratie
        # retine cea mai buna solutie
        vmax = max(pop[:, n])
        i = numpy.argmax(pop[:, n])
        sol = pop[i][:n].copy().astype(int)
        V.append(vmax)
    arata(sol, V)
    return sol,V

def f_obiectiv(x):
    # functia obiectiv pentru problema reginelor

    # I: x - individul (permutarea) evaluat(a)
    # E: c - calitate (numarul de perechi de regine care nu se ataca)

    n=len(x)
    c=n*(n-1)/2
    for i in range(n):
        for j in range(i+1,n):
            if abs(i-j)==abs(x[i]-x[j]):
                c=c-1
    return c

def gen_pop_perm(dim, n):
    # generare populatie de permutari

    # I: dim - dimensiune populatie (nr. de indivizi)
    #    n - dimensiune individ (numar de gene)
    # E: pop - populatia aleatoare generata, cu calitatea fiecarui individ pe ultima coloana

    pop=numpy.zeros((dim,n+1),dtype=int)
    for i in range(dim):
        pop[i,:n]=numpy.random.permutation(n)
        pop[i,n]=f_obiectiv(pop[i,:n])
    return pop

def mutatie(desc,pm):
    # operatia de mutatie a descendentilor obtinuti din recombinare

    # I: desc - matricea descendentilor
    #    pm - probabilitatea de mutatie
    # E: descm - matricea indivizilor obtinuti

    dim,n=numpy.shape(desc)
    descm=desc.copy()
    for i in range(dim):
        x=descm[i,:n-1]
        xm,reval=m_perm_schimb(x,pm)
        if reval:
            descm[i,:n-1]=xm
            descm[i][n-1]=f_obiectiv(xm)
    return descm

def recombinare(parinti,pr):
    # operatia de recombinare a parintilor selectati

    # I: parinti - parintii selectati
    #    pr - probabilitatea de recombinare
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
        d1,d2,da=r_OCX(x,y,pr)
        if da==1:
            desc[i,:n-1]=d1
            desc[i,n-1]=f_obiectiv(d1)
            desc[i+1,:n-1]=d2
            desc[i+1,n-1]=f_obiectiv(d2)
    return desc

def arata(sol,v):
    # vizualizare asezare regine pe tabla de sah

    # I: sol - permutarea care defineste asezarea
    #    v - vectorul cu cea mai buna calitate din fiecare generatie
    # E: -

    n=len(sol)
    t=len(v)
    maxim=max(v)
    optim=n*(n-1)/2
    t1="Evoluția calității (cel mai bun individ din fiecare generație).\nRezultatul "
    t2="Cea mai bună așezare a reginelor găsită.\nRezultatul "
    t4="este optim (" + str(maxim) + " vs " + str(optim) + ")"
    #t4=f'{"este optim ("}{maxim}{" vs "}{optim}{")"}'
    if maxim<optim:
        t3="nu "
    else:
        t3=""
    titlu1=f'{t1}{t3}{t4}'
    titlu2=t2+t3+t4

    fig1=grafic.figure()
    x=[i for i in range(t)]
    grafic.plot(x,v,'ro-')
    grafic.ylabel("Calitate")
    grafic.xlabel("Generația")
    grafic.title(titlu1)

    fig=grafic.figure()
    ax=fig.gca()
    x=[i+0.5 for i in range(n)]
    y=[sol[i]+0.5 for i in range(n)]
    grafic.plot(x,y,'r*',markersize=10)
    grafic.xticks(range(n+1))
    grafic.yticks(range(n+1))
    grafic.grid(True,which='both',color='k', linestyle='-', linewidth=1)
    ax.set_aspect('equal')
    grafic.title(titlu2)
    fig.show()

if __name__=="__main__":
    s,v=GA_Regine(8, 50, 0.8, 0.1, 50)
    print("Solutia:",s)
    print('Evolutia calitatilor:',[int(x) for x in v])
    grafic.pause(20)