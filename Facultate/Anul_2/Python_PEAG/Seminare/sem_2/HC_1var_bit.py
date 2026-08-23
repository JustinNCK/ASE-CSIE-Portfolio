import numpy
from math import sin, cos, log2
import matplotlib.pyplot as grafic


def f_obiectiv(x):
    # o functie de maximizat cu maxime locale

    # I: x - punctul in care se calculeaza valoarea functiei
    # E: y - valoarea functiei in punctul x

    # o functie oarecare cu extreme locale
    y = x**3 * sin(x/3) + x**3 * cos(2*x) -x*sin(3*x) + x*cos(x)

    return y


def HC(a, b, nz, nrp):
    # implementare hillclimbing pentru gasirea maximului unei functii de o variabila

    # I: a, b - capetele intervalului pe care e definita functia  (o axa)
    #    nrp - numarul de puncte initiale folosite de algoritm
    #    nrv - numarul de vecini pe fiecare directie utilizati (total 2*nrv+1 - 1 e punctul curent)
    #    nz - numar zecimale exacte
    # E: x - punct de maxim
    #    fx - valoarea maxima a functiei (in punctul x)
    # Exemple de apel:
    #    import HC_1var_bit as HB
    #    x,fx=HB.HC(1.5,20.2,6,15)
    #    x,fx=HB.HC(-15,2.2,8,25)
    #    x,fx=HB.HC(-15,23.2,5,75)

    # initializare liste goale de coordonate
    X=[None]*nrp
    Y=[None]*nrp
    # pentru fiecare punct initial
    for i in range(nrp):
        # aplicare hillclimbing pentru punctul initial curent generat aleator
        pc=numpy.random.uniform(a,b)    # alege un punct de inceput aleator
        vecmax=pc                       # cel mai bun vecin e punctul curent
        valmax=f_obiectiv(pc)
        local=0                         # nu am ajuns in maxim local
        while not local:
            # calculeaza vecinii punctului curent si valorile corespunzatoare ale functiei
            rb=real2bin(a,b,pc,nz)
            m=len(rb)
            for j in range(m):
                rn=list(rb)
                rn[j]='1' if rn[j]=='0' else '0'
                rn="".join(rn)
                vec=bin2real(a,b,rn)
                if f_obiectiv(vec)>valmax:
                    vecmax=vec
                    valmax=f_obiectiv(vecmax)
            if valmax>f_obiectiv(pc):
                pc=vecmax
            else:
                local=1
        # memoreaza cel mai bun punct gasit si valoarea corespunzatoare a functiei
        X[i]=vecmax
        Y[i]=valmax

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
    grafic.plot(xmax,ymax,'r*',markersize=10)
    grafic.show()


def real2bin(a, b, x, nz):
    # obtinere reprezentare binara echivalenta unui numar real cu nz zecimale exacte din intervalul (a,b)

    # prin calcularea numarului de deplasari (n) fata de inceputul intervalului
    # x=a+n*pas, unde pas=(b-a)/(2**m-1) si reprezentarea lui n in baza 2 pe m biti
    # I: a, b - capetele intervalului
    #    x - valoarea reala de reprezentat
    #    nz - numar de zecimale exacte dorite
    # E: rb - reprezentarea binara pe m biti

    m=int(log2((b-a)*(10**nz)))+1
    n=round((x-a)*(2**m-1)/(b-a))
    rb=bin(n)[2:].zfill(m)   #rb=format(n,f'0{m})b')

    return rb


def bin2real(a,b,rb):
    # obtinere valoare reala din reprezentare binara

    # prin adaugarea unui numar de pasi fata de inceputul intervalului
    # x=a+n*pas, unde pas=(b-a)/(2*m-1), n e numarul de pasi, m e numarul de biti din reprezentarea binara
    # I: a, b - capetele intervalului
    #    rb - reprezentarea binara
    # E: x - numarul real corespunzator

    m=len(rb)
    n=int(rb,2)
    x=a+n*(b-a)/(2**m-1)

    return x

if __name__=='__main__':
    x,fx=HC(1.5,20.2,6,15)