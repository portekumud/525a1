import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph() 
plt.subplot(211)
G.add_edges_from([(0, 1), (0, 2), (0, 4), (1, 0), (1, 2), (2, 0), (2, 1), (2, 3), (2, 4), (3, 2), (3, 4), (4, 0), (4, 2), (4, 3)])
nx.set_node_attributes(G, {0: 'green', 1: 'green', 2: 'yellow', 3: 'yellow', 4: 'green'}, name='color')
nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, 'color').values()))
plt.savefig('graph14-01010312312321.png')
