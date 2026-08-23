import numpy
import matplotlib.pyplot as grafic


def f_obiectiv(x):
    # functia obiectiv pentru problema reginelor

    # I: x - individul (permutarea) evaluat(a)
    # E: c - calitate (numarul de perechi de regine care nu se ataca

    n=len(x)
    c=n*(n-1)/2
    for i in range(n):
        for j in range(i+1,n):
            if abs(i-j)==abs(x[i]-x[j]):
                c=c-1
    return c


def vecini(p):
    # genereaza permutarile vecine lui p prin aplicarea cite unei transpozitii

    # I: p - permutare data
    # E: v - lista de permutari vecine
    # o transpozitie inseamna ca reginele din pozitiile (i,p[i]) si (j,p[j]) sint mutate
    # in pozitiile (i,p[j]) respectiv (j,p[i])

    v=[]
    n=len(p)
    for i in range(n):
        for j in range(i+1,n):
            pv=p.copy()
            pv[i]=p[j]
            pv[j]=p[i]
            v.append(pv)
    return v


def HC(n, max):
    # implementare hillclimbing rezolvarea problemei celor n regine

    # I: n - numarul de regine
    #    max - numarul maxim de iteratii (puncte de start)
    # E: p_optim - cea mai buna permutare obtinuta
    #    c_optim - calitatea permutarii obtinute
    # Exemple de apel:
    #    import HC_regine as HR
    #    p,c=HR.HC(8,2)
    #    p,c=HR.HC(14,5)
    #    p,c=HR.HC(24,10)

    # cautarea continua pina la atingerea calitatii optime (e cunoscuta) sau consumarea iteratiilor
    c_optim=-1
    nrp=1
    while c_optim<n*(n-1)/2 and nrp<max:
        # hillclimbing pentru punctul initial x generat aleator
        x=numpy.random.permutation(n)
        x=x.tolist()
        c_max=f_obiectiv(x)
        local=0
        while not local:
            vec=vecini(x)
            nvec=len(vec)
            # cauta cel mai bun vecin
            cm=f_obiectiv(vec[0])
            poz=0
            for i in range(1,nvec):
                cc=f_obiectiv(vec[i])
                if cm<cc:
                    cm=cc
                    poz=i
            # daca cel mai bun vecin e mai bun decit punctul initial, el devine punct initial
            if cm>c_max:
                x=vec[poz]
                c_max=cm
            else:
                local=1
            if c_optim<c_max:
                c_optim=c_max
                p_optim=x
        nrp=nrp+1
    if c_optim<n*(n-1)/2:
        print("Atenție: cea mai bună permutare găsită nu este corectă!",c_optim,"<",n*(n-1)/2)
    else:
        print("Succes! Cea mai bună permutare găsită este corectă!")
    print("Cea mai bună așezare găsită are valoarea: ",c_optim)
    print("Cea mai bună permutare gasită este: ",p_optim)
    arata(p_optim)
    return [p_optim,c_optim]


def arata(sol):
    # vizualizare asezare regine pe tabla de sah

    # I: x - permutarea care defineste asezarea
    # E: -

    n=len(sol)
    fig=grafic.figure()
    ax=fig.gca()
    x=[i+0.5 for i in range(n)]
    y=[sol[i]+0.5 for i in range(n)]
    grafic.plot(x,y,'r*',markersize=10)
    grafic.xticks(range(n+1))
    grafic.yticks(range(n+1))
    grafic.grid(True,which='both',color='k', linestyle='-', linewidth=1)
    ax.set_aspect('equal')

    grafic.show()

if __name__=="__main__":
    p,c=HC(8,2)
