import numpy as np


def f_obiectiv(x, c, v, max):
    # verifica fezabilitatea lui x si calculeaza f. obiectiv

    # I: x - candidat (vector binar - selectia obiectelor)
    #    c - vector de costuri asociate obiectelor
    #    v - vector de valori asociate obiectelor
    #    max - capacitatea maxima a rucsacului
    # E: ok - candidat fezabil (0 - nu / 1 - da)
    #    val - valoare obiecte selectate

    cost=np.dot(x,c)
    val=np.dot(x,v)
    return cost<=max, val

def vecini(x, c, v, max):
    # calculul vecinilor fezabile ai punctului curent si calitatile lor (valori f. obiectiv)

    # I: x - candidat (vector binar - selectia obiectelor)
    #    c - vector de costuri asociate obiectelor
    #    v - vector de valori asociate obiectelor
    #    max - capacitatea maxima a rucsacului
    # E: vec - vector de vecini fezabili
    #    cal - vector de calitati, in ordine

    n=x.size
    vec=np.zeros(0,dtype="int")
    cal=np.zeros(0,dtype="float")
    for i in range(n):
        y=x.copy()
        y[i]=not x[i]
        fezabil,valoare=f_obiectiv(y,c,v,max)
        if fezabil:
            vec=np.append(vec,y)
            cal=np.append(cal,valoare)
    dim=len(vec)
    vec=vec.reshape(round(dim/n),n)
    return vec, cal

def HC(fc,fv,dim,max):
    # implementare hillclimbing pentru rezolvarea problemei rucsacului 0-1

    # I: fc,fv - fisierele cu costuri/valori
    #    dim - numărul punctelor de start pentru hillclimbin
    #    max=capacitatea maxima a rucsacului
    # E: sol - solutia calculata
    #    val - maximul functiei fitness
    # Exemple de apel
    # import HC_Rucsac01_ndarray as r1
    # sol,val,P,C=r1.HC("cost.txt","valoare.txt",70,50) #- max 81
    # sol,val,P,C=r1.HC("cost1.txt","valoare1.txt",90,50) #- max 108
    # sol,val,P,C=r1.HC("cost2.txt","valoare2.txt",1000,56.6) #- max 128.2

    #citirea datelor
    c = np.genfromtxt(fc)
    v = np.genfromtxt(fv)
    n = c.size  # n=dimensiunea problemei
    puncte=np.zeros([dim,n],dtype="int")
    calitati=np.zeros(dim,dtype="float")
    for apeluri in range(dim):
        # genereaza punct initial
        local=False
        gata = False
        while gata == False:
            x = np.random.randint(0, 2, n)  # genereaza candidatul x cu elemente 0,1
            gata, val = f_obiectiv(x, c, v, max)
        while not local:
            vec,cal=vecini(x,c,v,max)
            if cal.size==0:
                local=True
            else:
                i = np.argmax(cal)
                vn = vec[i]
                if cal.max()>val:
                    val=cal.max()
                    x=vn
                else:
                    local=True
        puncte[apeluri] = x.copy()
        calitati[apeluri] = val

    vmax = np.max(calitati)
    i = np.argmax(calitati)
    sol=puncte[i]
    print("Cea mai buna valoare calculată: ", vmax)
    print("Alegerea corespunzatoare este: ", sol)
    return sol,vmax,puncte,calitati

#cod executabil
if __name__=="__main__":
    sol, val, P, C = HC("cost.txt", "valoare.txt", 70, 50)
    sol1, val1, P1, C1 = HC("cost1.txt", "valoare1.txt", 90, 50)
    sol2, val2, P2, C2 = HC("cost2.txt", "valoare2.txt", 1000, 56.6)