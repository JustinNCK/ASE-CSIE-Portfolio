import numpy
from math import sin, cos, exp, log2
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


def HC(intx, inty, nz, nrp):
    # implementare hillclimbing pentru gasirea maximului unei functii de doua variabile

    # I: intx, inty - intervalele pe care e definita functia
    #    nrp - numarul de puncte initiale folosite de algoritm
    #    nz - numar zecimale exacte
    # E: x - punctul de paxim (2 coordonate)
    #    fx - valoarea maxima a functiei (in punctul x)
    # Exemple de apel:
    #    import HC_2var_bit as HB2
    #    x,fx=HB2.HC([-2,2],[-2, 2],2,50)

    X=[None]*nrp
    Y=[None]*nrp
    Z=[None]*nrp
    pc=[0,0]
    # pentru fiecare punct initial
    for i in range(nrp):
        # aplicare hillclimbing pentru punctul initial curent generat aleator
        pc[0] = numpy.random.uniform(intx[0],intx[1])
        pc[1] = numpy.random.uniform(inty[0],inty[1])
        vecmax=pc       # cel mai bun vecin e punctul curent
        valmax=f_obiectiv(pc)
        local=0         # nu am ajuns in maxim local
        while not local:
            # calculeaza vecinii punctului curent si valorile corespunzatoare ale functiei
            rbx=real2bin(intx[0],intx[1],pc[0],nz)
            rby=real2bin(inty[0],inty[1],pc[1],nz)
            mx=len(rbx)
            my=len(rby)
            for j in range(mx):
                rnx = list(rbx)
                rnx[j] = '1' if rnx[j] == '0' else '0'
                rnx = "".join(rnx)
                vecx = bin2real(intx[0],intx[1], rnx)
                for k in range(my):
                    rny=list(rby)
                    rny[k]='1' if rny[k]=='0' else '0'
                    rny="".join(rny)
                    vecy=bin2real(inty[0],inty[1],rny)
                    if f_obiectiv([vecx,vecy]) > valmax:
                        vecmax = [vecx,vecy]
                        valmax = f_obiectiv(vecmax)
            # inlocuieste punctul curent cu cel mai bun vecin, daca exista unul mai bun
            if valmax > f_obiectiv(pc):
                pc = vecmax
            else:
                # nici un vecin mai bun, inseamna ca am atins un maxim local
                local = 1
            # memoreaza cel mai bun punct gasit si valoarea corespunzatoare a functiei
        X[i]=vecmax[0]
        Y[i]=vecmax[1]
        Z[i]=f_obiectiv(vecmax)

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
    #    xmax, zmax - corrdonatele celui mai bun punct gasit (3D)
    # E: -

    fig=grafic.figure()
    # ax=fig.gca(projection='3d')       #pina la python 3.10
    ax=fig.add_subplot(projection='3d')    #de la python 3.11

    x=numpy.arange(intx[0],intx[1],0.1)
    y=numpy.arange(inty[0],inty[1],0.1)
    x, y = numpy.meshgrid(x, y)
    z=numpy.exp(-x**2-y**2)+y*numpy.cos(5*x)-x*numpy.sin(3*y)

    surf=ax.plot_surface(x,y,z,cmap='binary')
    ax.plot3D(X,Y,Z,'bo')
    ax.plot3D([xmax[0]],[xmax[1]],[zmax],'r*',markersize=10)

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
    rb=bin(n)[2:].zfill(m)      #rb=format(n,f'0{m})b')

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
    x,fx=HC([-2,2],[-2, 2],2,50)