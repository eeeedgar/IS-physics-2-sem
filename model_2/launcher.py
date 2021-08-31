import os
os.system('"main.exe"')

import matplotlib.pyplot as plt
import pylab

def read_file(filename):
    with open(filename, 'r', encoding='UTF-8') as f:
        x = []
        y = []
        for i in f.read().split('\n'):
            if i == '':
                break
            x_, y_ = [float(j) for j in i.split(' ')]
            x.append(x_)
            y.append(y_)
        return x, y

r2, h = 0, 0
with open('config.txt', 'r', encoding='UTF-8') as conf:
    conf.readline()
    r2, h = [int(i) for i in conf.readline().split(' ')]

r1 = r2 - h
point_width = 0.5
    
x, y = read_file('y_x.txt')
pylab.subplot(2, 2, 1)
m_x = max(x)
m_y = max(y)
m = max(m_x, m_y)
pylab.xlim(0, m)
pylab.ylim(r1, r2)
pylab.scatter(y, x, s = point_width)
pylab.title('y(x)')


x, y = read_file('y_t.txt')
pylab.subplot(2, 2, 2)
pylab.scatter(y, x, s = point_width)
pylab.title('y(t)')


x, y = read_file('a_t.txt')
pylab.subplot(2, 2, 3)
pylab.scatter(y, x, s = point_width)
pylab.title('a(t)')

x, y = read_file('v_t.txt')
pylab.subplot(2, 2, 4)
pylab.scatter(y, x, s = point_width)
pylab.title('v(t)')

pylab.show()
