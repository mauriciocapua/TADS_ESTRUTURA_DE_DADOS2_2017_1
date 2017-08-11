package negocio;

import java.util.LinkedList;

public class Grafos {
	private int vertices;
	private LinkedList<Integer> adjacente[]; // Adjacency Lists

	public Grafos(int vertices) {
		this.vertices = vertices;
		adjacente = new LinkedList[vertices];
		for (int i = 0; i < vertices; ++i)
			adjacente[i] = new LinkedList();
	}

	public void addEdge(int v, int w) {
		adjacente[v].add(w);
	}

	public int getV() {
		return this.vertices;
	}

	public void setV(int v) {
		this.vertices = v;
	}

	public LinkedList<Integer>[] getAdj() {
		return adjacente;
	}

	public void setAdj(LinkedList<Integer>[] adj) {
		this.adjacente = adj;
	}

}
