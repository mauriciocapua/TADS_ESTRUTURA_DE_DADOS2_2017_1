package negocio;

import java.util.*;
import negocio.Util;

public class Profundidade {
	private int vertice;
	private LinkedList<Integer> adjacente[];

	List<String> DFSUtil(int v, boolean visited[], List<String> caminho) {
		visited[v] = true;

		caminho.add(Util.ConverteCidadeParaString(v));

		// System.out.println(Util.ConverteCidadeParaString(v) + " " + v);

		Iterator<Integer> i = adjacente[v].listIterator();
		while (i.hasNext()) {
			int n = i.next();
			if (!visited[n])
				DFSUtil(n, visited, caminho);
		}
		return caminho;
	}

	public void DFS(int v, int v2, Grafos grafo) {
		this.vertice = grafo.getV();
		this.adjacente = grafo.getAdj();
		boolean visited[] = new boolean[vertice];
		List<String> caminho = new ArrayList<String>();
		caminho = DFSUtil(v, visited, caminho);
		int distancia = 0;
		int cont = 0;
		for (int i = 0; i < caminho.size(); i++) {
			if (cont == 1) {
				distancia += Util.calculaDistancia(caminho.get(i - 1), caminho.get(i));
				cont = 0;
			}
			System.out.println(caminho.get(i));

			if (caminho.get(i) == Util.ConverteCidadeParaString(v2)) {
				break;
			}
			cont++;
		}
		System.out.println("Distancia: " + distancia);
	}

}
