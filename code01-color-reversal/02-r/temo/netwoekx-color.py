import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()
G.add_nodes_from([0,1,2,3])
G.add_edges_from([(0, 1), (0, 2), (0, 3), (1, 0), (2, 0), (2, 3), (3, 0), (3, 2)])

nx.set_node_attributes(G, {1: 'red', 2: 'blue', 3: 'green', 0: 'yellow'}, name='color')
nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, 'color').values()))
plt.show()
