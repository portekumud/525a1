import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph() 
plt.subplot(211)
G.add_edges_from([(0, 1), (1, 0), (1, 2), (2, 1), (2, 3), (3, 0), (3, 2)])
nx.set_node_attributes(G, {0: 'green', 1: 'yellow', 2: 'yellow', 3: 'green'}, name='color')
nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, 'color').values()))
plt.savefig('graph3-012.pdf')
