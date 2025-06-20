import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph() 
plt.subplot(211)
G.add_edges_from([(0, 1), (0, 2), (1, 0), (2, 0)])
nx.set_node_attributes(G, {0: 'yellow', 1: 'green', 2: 'yellow'}, name='color')
nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, 'color').values()))
plt.savefig('graph28716-221220002.png')
