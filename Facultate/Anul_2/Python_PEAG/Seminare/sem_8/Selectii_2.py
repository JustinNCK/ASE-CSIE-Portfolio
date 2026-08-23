import numpy

def d_FPS_ss(pop,cal,c):
    # distributia de selectie FPS cu sigma scalare

    # I: pop - bazinul de selectie
    #    cal - calitate indivizi (vector)
    #    c - constanta din formula de ajustare. uzual: 2
    # E: p - vector probabilitati de selectie individuale
    #    q - vector probabilitati de selectie cumulate

    m,n=numpy.shape(pop)
    medie=numpy.mean(cal)
    sigma=numpy.std(cal)
    val=medie-c*sigma
    g=[numpy.max([0, cal[i]-val]) for i in range(m)]
    s=numpy.sum(g)
    p=g/s
    q=[numpy.sum(p[:i+1]) for i in range(m)]
    return p,q


def s_ruleta_SUS(pop,cal):
    # selectia tip ruleta multibrat

    # I: pop - bazinul de selectie
    #    cal - calitatea indivizilor (vector)
    # E: rez - populatia selectata
    #    crez - calitatea indivizilor selectati (vector)

    m,n=numpy.shape(pop)
    p,q=d_FPS_ss(pop,cal,2)
    rez=numpy.zeros((m,n),dtype=int)
    crez = numpy.zeros(m, dtype=float)
    i=0
    k=0
    r=numpy.random.uniform(0,1/m)
    while k<m:
        while r<=q[i]:
            rez[k,:n]=pop[i,:n]
            crez[k]=cal[i]
            r+=1/m
            k+=1
        i+=1
    return rez,crez


def s_elitista(pop,cal,desc,cdesc):
    # selectia elitista a generatiei urmatoare

    # I: pop - populatia curenta
    #    cal - calitatea indivizilor populatiei curente
    #    desc - descendentii populatiei curente
    #    cdesc - calitatea indivizilor descendenti
    # E: noua - matricea descendentilor selectati
    #    cnoua - calitatea indivizilor selectati

    noua=desc.copy()
    cnoua=cdesc.copy()
    dim,n=numpy.shape(pop)
    max1=max(cal)
    i=numpy.argmax(cal)
    max2=max(cdesc)
    if max1>max2:
        min2=min(cdesc)
        k=numpy.argmin(cdesc)
        noua[k,:]=pop[i,:]
        cnoua[k]=cal[i]
    return noua,cnoua

