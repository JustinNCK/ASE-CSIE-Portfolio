import numpy as np

#5
def cmmdc_recursiv(a, b):
    if b == 0:
        return a
    return cmmdc_recursiv(b, a % b)


# print(cmmdc_recursiv(48, 18))