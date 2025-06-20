import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph() 
plt.subplot(211)
G.add_edges_from([(0, 2), (1, 2), (2, 0), (2, 1)])
nx.set_node_attributes(G, {0: 'yellow', 1: 'yellow', 2: 'green'}, name='color')
nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, 'color').values()))
plt.savefig('graph13726-012022220.png')
