import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph() 
plt.subplot(211)
G.add_edges_from([(0, 1), (0, 2), (1, 0), (2, 0)])
nx.set_node_attributes(G, {0: 'green', 1: 'yellow', 2: 'yellow'}, name='color')
nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, 'color').values()))
plt.savefig('graph10845-001101012.png')
