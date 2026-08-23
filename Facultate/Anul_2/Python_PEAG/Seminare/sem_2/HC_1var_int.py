import numpy
from math import sin, cos
import matplotlib.pyplot as grafic


def f_obiectiv(x):
    # o functie de maximizat cu maxime locale

    # I: x - punctul in care se calculeaza valoarea functiei
    # E: y - valoarea functiei in punctul x

    # o functie oarecare cu extreme locale
    y = x**3 * sin(x/3) + x**3 * cos(2*x) -x*sin(3*x) + x*cos(x)

    return y

def vecini(x, nr, pas, a, b):
    # calculează vecinii unui punct (pe o axă)

    # I: x - punct curent
    #    nr - numar de vecini pe fiecare directie
    #    pas - distanta intre vecinii consecutivi
    #    a, b - capetele intervalului de lucru
    # E: v - lista vecini (2 linii: puncte, valori)

    vec=[x+i*pas for i in range(-nr, nr+1) if ((x+i*pas>=a) and (x+i*pas<=b))]
    valv=[f_obiectiv(x+i*pas) for i in range(-nr, nr+1) if ((x+i*pas>=a) and (x+i*pas<=b))]
    #valv=[f_obiectiv(x) for x in vec]
    return [vec,valv]


def HC(a, b, nrp, nrv, pas):
    # implementare hillclimbing pentru gasirea maximului unei functii de o variabila

    # I: a, b - capetele intervalului pe care e definita functia  (o axa)
    #    nrp - numarul de puncte initiale folosite de algoritm
    #    nrv - numarul de vecini pe fiecare directie utilizati (total 2*nrv+1 - 1 e punctul curent)
    #    pas - distanta intre doi vecini consecutivi
    # E: x - punct de maxim
    #    fx - valoarea maxima a functiei (in punctul x)
    # Exemple de apel:
    #    import HC_1var_int as H
    #    x,fx=H.HC(1.5,10,100,5,0.1)
    #    x,fx=H.HC(-1.5,20.2,100,5,0.1)
    #    x,fx=H.HC(-15,2.2,100,5,0.1)
    #    x,fx=H.HC(-15,23.2,100,5,0.1)
    #    x,fx=H.HC(0,50,100,100,0.01)

    # initializare liste goale de coordonate
    X=[None]*nrp
    Y=[None]*nrp
    # pentru fiecare punct initial
    for i in range(nrp):
        # aplicare hillclimbing pentru punctul initial curent generat aleator
        pc=numpy.random.uniform(a,b)    # alege un punct de inceput aleator
        local=0                         # nu am ajuns in maxim local
        while not local:
            # calculeaza vecinii punctului curent si valorile corespunzatoare ale functiei
            nvec, nval=vecini(pc,nrv,pas,a,b)
            valmax=max(nval)
            poz=nval.index(valmax)
            vecmax=nvec[poz]
            # inlocuieste punctul curent cu cel mai bun vecin, daca exista unul mai bun
            if valmax>f_obiectiv(pc):
                pc=vecmax
            else:
                # nici un vecin mai bun, inseamna ca am atins un maxim local
                local=1
        # memoreaza cel mai bun punct gasit si valoarea corespunzatoare a functiei
        X[i]=pc
        Y[i]=f_obiectiv(vecmax)

    # determina cel mai bun dintre punctele finale si valoarea corespunzatoare a functiei obiectiv
    fx=max(Y)
    poz=Y.index(fx)
    x=X[poz]

    # afiseaza rezultatele si graficul
    print("Valoare maxima calculata: ", fx)
    print("E atinsa in punctul: ", x)
    deseneaza(a, b, X, Y, x, fx)
    return [x,fx]


def deseneaza(a, b, X, Y, xmax, ymax):
    # vizualizare rezultate pentru hillclimbing 1 variabila

    # I: a, b - capete interval de lucru
    #    X, Y - liste cu coordonatele punctelor finale calculate
    #    xmax, ymax - corrdonatele celui mai bun punct gasit
    # E: -

    x=numpy.arange(a,b,0.01)
    grafic.plot(x,[f_obiectiv(i) for i in x],'k-',X,Y,'bo')
    grafic.plot(xmax,ymax,'r*',markersize=20)
    grafic.show()


#Example call under PyCharm
if __name__=='__main__':
    x, fx = HC(1.5, 10, 100, 5, 0.1)
    x, fx = HC(0, 50, 100, 100, 0.01)