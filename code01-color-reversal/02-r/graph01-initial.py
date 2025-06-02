import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph() 
plt.figure(figsize =(9, 12))
G.add_edges_from([(0, 1), (0, 2), (0, 3), (1, 0), (2, 0), (2, 3), (3, 0), (3, 2)])
plt.subplot(211)
nx.draw_networkx(G)
plt.savefig('graph01-initial.png')
