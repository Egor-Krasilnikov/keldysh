import numpy as np 
import matplotlib.pyplot as plt 


data = np.loadtxt('data_keldysh.txt')
x3 = data[:, 0]
y3 = data[:, 1]   


plt.subplot()

plt.scatter(x3, y3, label='')

# plt.xlabel('I, A')
# plt.ylabel('U, B')
# plt.title('Калибровка')



plt.savefig('Picture.jpg')
plt.legend()
plt.show()




# ax.legend()
# ax.xaxis.set_minor_locator(AutoMinorLocator())
# ax.yaxis.set_minor_locator(AutoMinorLocator())
# ax.tick_params(which='major', length=10, width=1)
# ax.tick_params(which='minor', length=5, width=1)

#строительство минорной и мажорной сетки