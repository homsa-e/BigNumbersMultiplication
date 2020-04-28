import pandas as pd
import matplotlib.pyplot as plt
f = pd.read_csv("dataK.csv", names = ['size', 'School', 'Kara'])
plt.plot(f['size'], f['School'], label='School')
plt.plot(f['size'], f['Kara'], label='Kara')
#plt.plot(f['size'], f['D&C'], label='D&C')
#plt.plot(f['size'], (3*f['size']/1000)**2, label='C*n^2')
#plt.plot(f['size'], (f['size']/100)**1.59, label='n^1.59')
plt.legend()
plt.savefig("figure6.jpg", dpi=300)
plt.show()
