import numpy
from math import sin, cos, exp
import matplotlib.pyplot as grafic
from mpl_toolkits.mplot3d import Axes3D


def f_obiectiv(a):
    # o functie de maximizat cu maxime locale

    # I: a - punctul din plan in care se calculeaza valoarea functiei (doua coordonate)
    # E: z - valoarea functiei in punctul x

    x=a[0]
    y=a[1]
    z= exp(-x**2-y**2)+y*cos(5*x)-x*sin(3*y)
    return z

def vecini(x, nr, pas, intx, inty):
    # calculează vecinii unui punct (matrice in plan)

    # I: x - punct curent (doua coordonate)
    #    nr - numar de vecini pe fiecare directie
    #    pas - distanta intre vecinii consecutivi pe axa
    #    intx - capetele intervalului de lucru pe axa x
    #    inty - capetele intervalului de lucru pe axa y
    # E: lista vecini (perechi coord. x, coord. y), lista valori

    vecx=[x[0]+i*pas for i in range(-nr, nr+1) if ((x[0]+i*pas>intx[0]) and (x[0]+i*pas<=intx[1]))]
    vecy=[x[1]+i*pas for i in range(-nr, nr+1) if ((x[1]+i*pas>inty[0]) and (x[1]+i*pas<=inty[1]))]
    vec=[[x,y] for x in vecx for y in vecy]
    val=[f_obiectiv(p) for p in vec]
    return [vec,val]

def HC(intx, inty, nrp, nrv, pas):
    # implementare hillclimbing pentru gasirea maximului unei functii de doua variabile

    # I: intx, inty - intervalele pe care e definita functia
    #    nrp - numarul de puncte initiale folosite de algoritm
    #    nrv - numarul de vecini folositi pe fiecare directie (4 directii)
    #    pas - distanta intre doi vecini consecutivi pe axa
    # E: x - punctul de paxim (2 coordonate)
    #    fx - valoarea maxima a functiei (in punctul x)
    # Exemple de apel:
    #    import HC_2var_int as H2
    #    x,fx=H2.HC([-2,2],[-2,2],50,2,0.1)
    #    x,fx=H2.HC([-2,2],[-2,2],100,10,0.1)

    X=[None]*nrp
    Y=[None]*nrp
    Z=[None]*nrp
    pc=[0,0]
    # pentru fiecare punct initial
    for i in range(nrp):
        # aplicare hillclimbing pentru punctul initial curent generat aleator
        pc[0] = numpy.random.uniform(intx[0],intx[1])
        pc[1] = numpy.random.uniform(inty[0],inty[1])
        local=0         # nu am ajuns in maxim local
        while not local:
            # calculeaza vecinii punctului curent si valorile corespunzatoare ale functiei
            nvec, nval = vecini(pc, nrv, pas, intx, inty)
            valmax = max(nval)
            poz = nval.index(valmax)
            vecmax = nvec[poz]
            # inlocuieste punctul curent cu cel mai bun vecin, daca exista unul mai bun
            if valmax > f_obiectiv(pc):
                pc = vecmax
            else:
                # nici un vecin mai bun, inseamna ca am atins un maxim local
                local = 1
            # memoreaza cel mai bun punct gasit si valoarea corespunzatoare a functiei
        X[i]=pc[0]
        Y[i]=pc[1]
        Z[i]=f_obiectiv(pc)

    # determina cel mai bun dintre punctele finale si valoarea corespunzatoare a functiei obiectiv
    fx = max(Z)
    poz = Z.index(fx)
    x = [X[poz],Y[poz]]

    # afiseaza rezultatele si graficul
    print("Valoare maxima calculata: ", fx)
    print("E atinsa in punctul: (", x[0],",",x[1],")")
    deseneaza(intx, inty, X, Y, Z, x, fx)

    return [x, fx]

def deseneaza(intx, inty, X, Y, Z, xmax, zmax):
    # vizualizare rezultate pentru hillclimbing 2 variabila

    # I: intx - capete interval de lucru pe axa x
    #    inty - capete interval de lucru pe axa y
    #    X,Y - liste cu coordonatele punctelor finale calculate
    #    Z - lista valorilor functiei in punctele din X
    #    xmax, zmax - coordonatele celui mai bun punct gasit (3D)
    # E: -

    fig=grafic.figure()
    # ax=fig.gca(projection='3d')       #pina la python 3.10
    ax = fig.add_subplot(projection='3d')  # de la python 3.11

    x=numpy.arange(intx[0],intx[1],0.1)
    y=numpy.arange(inty[0],inty[1],0.1)
    x, y = numpy.meshgrid(x, y)
    z=numpy.exp(-x**2-y**2)+y*numpy.cos(5*x)-x*numpy.sin(3*y)

    surf=ax.plot_surface(x,y,z,cmap='viridis', linewidth=1,edgecolor='k') #binary, plasma, spectral, hsv, coolwarm
    ax.plot3D(X,Y,Z,'bo')
    ax.plot3D([xmax[0]],[xmax[1]],[zmax],'r*',markersize=20)

    grafic.show()


x,fx=HC([-2,2],[-2,2],100,10,0.1)