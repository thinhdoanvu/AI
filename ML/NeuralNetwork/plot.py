height = np.array([167,170,149,165,155,180,166,146,159,185,145,168,172,181,169])
weight = np.array([86,74,66,78,68,79,90,73,70,88,66,84,67,84,77])

colors = np.random.rand(15)
area = (30 * np.random.rand(15))**2 

plt.xlim(140,200)
plt.ylim(60,100)
plt.scatter(height,weight,s=area,c=colors)
plt.title("Chiều cao và cân nặng")
plt.xlabel("Chiều cao - cm")
plt.ylabel("Cân nặng - kg")

plt.show()