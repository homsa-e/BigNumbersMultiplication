import pandas as pd
import matplotlib.pyplot as plt
f = pd.read_csv("data.csv", names = ['size', 'School', 'D&C', 'Kara'])
plt.plot(f['size'], f['Kara'], label='Kara')
plt.plot(f['size'], f['D&C'], label='D&C')
plt.plot(f['size'], f['School'], label='School')
#plt.plot(f['size'], (f['size']/100)**2, label='n^2')
#plt.plot(f['size'], (f['size']/100)**1.59, label='n^1.59')
plt.legend()
plt.savefig("figure1.jpg", dpi=300)
plt.show()
