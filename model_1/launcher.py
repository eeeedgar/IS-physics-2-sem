import os
os.system('"main.exe"')

import matplotlib.pyplot as plt
import pylab

with open('plot.txt', 'r', encoding='UTF-8') as f:
    x = []
    y = []
    for i in f.read().split('\n'):
        if i == '':
            break
        x_, y_ = [float(j) for j in i.split(' ')]
        x.append(x_)
        y.append(y_)

m_x = max(x)
m_y = max(y)
m = max(m_x, m_y)

pylab.xlim(-100, m + 100)
pylab.ylim(-100, m + 100)

plt.plot(x, y)
plt.show()
        
