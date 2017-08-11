package negocio;

import java.util.*;

public class Largura {

	public List<String> caminho = new ArrayList<String>();

	public void BFS(int inicio, int fim, Grafos grafo) {
		int vertice = grafo.getV();
		LinkedList<Integer> adjacente[] = grafo.getAdj();
		boolean visited[] = new boolean[vertice];

		LinkedList<Integer> queue = new LinkedList<Integer>();

		visited[inicio] = true;
		queue.add(inicio);

		while (queue.size() != 0) {
			inicio = queue.poll();
			// System.out.print(s + " ");
			caminho.add(Util.ConverteCidadeParaString(inicio));
			Iterator<Integer> i = adjacente[inicio].listIterator();
			while (i.hasNext()) {
				int n = i.next();
				if (!visited[n]) {
					visited[n] = true;
					queue.add(n);
				}
			}
		}

		int distancia = 0;
		int cont = 0;
		for (int i = 0; i < caminho.size(); i++) {
			if (cont == 1) {
				distancia += Util.calculaDistancia(caminho.get(i - 1), caminho.get(i));
				cont = 0;
			}
			System.out.println(caminho.get(i));

			if (caminho.get(i) == Util.ConverteCidadeParaString(fim)) {
				break;
			}
			cont++;
		}
		System.out.println("Distancia: " + distancia);
	}

}
