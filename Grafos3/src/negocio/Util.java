package negocio;

import java.util.ArrayList;
import java.util.List;
import negocio.Dijkstra.*;

public class Util {
	static String[] cidades = { "BAGE", "CHUI", "JAGUARAO", "PELOTAS", "PORTO ALEGRE", "RIO GRANDE", "SANTA MARIA" };

	static int[][] distancias = { { 0, 368, 199, 180, 374, 257, 250 }, { 368, 0, 279, 267, 525, 249, 602 },
			{ 199, 279, 0, 152, 402, 200, 441 }, { 180, 267, 152, 0, 251, 52, 337 },
			{ 374, 525, 391, 251, 0, 317, 286 }, { 257, 249, 200, 52, 317, 0, 389 },
			{ 250, 602, 441, 337, 286, 389, 0 } };
	int matriz[][];
	public static String[][] cidadesOrdenadas = { { "RIO GRANDE", "1" }, { "PELOTAS", "2" }, { "CHUI", "3" },
			{ "JAGUARAO", "4" }, { "PORTO ALEGRE", "5" }, { "SANTA MARIA", "6" }, { "BAGE", "7" } };

	public static String[][] arestas = { { "52", "RIO GRANDE", "PELOTAS" }, { "152", "PELOTAS", "JAGUARAO" },
			{ "267", "PELOTAS", "CHUI" }, { "525", "CHUI", "PORTO ALEGRE" }, { "402", "JAGUARAO", "PORTO ALEGRE" },
			{ "199", "JAGUARAO", "BAGE" }, { "286", "PORTO ALEGRE", "SANTA MARIA" } };

	public static int ConverteCidadeParaInt(String cidade) {
		int retorno = -1;
		for (int i = 0; i < cidadesOrdenadas.length; i++) {
			if (cidadesOrdenadas[i][0] == cidade)
				retorno = Integer.parseInt(cidadesOrdenadas[i][1]);
		}
		return retorno;
	}

	public static String ConverteCidadeParaString(int cidade) {
		String retorno = null;
		for (int i = 0; i < cidadesOrdenadas.length; i++) {
			if (Integer.parseInt(cidadesOrdenadas[i][1]) == cidade)
				retorno = cidadesOrdenadas[i][0];
		}
		return retorno;
	}

//	public static void inicializaGrafo(Profundidade grafo) {
//		for (int i = 0; i < Util.arestas.length; i++) {
//			// System.out.println(ConverteCidade(Main.arestas[i][1]));
//			// System.out.println(ConverteCidade(Main.arestas[i][2]));
//
//			grafo.addEdge(Util.ConverteCidadeParaInt(Util.arestas[i][1]),
//					Util.ConverteCidadeParaInt(Util.arestas[i][2]));
//			grafo.addEdge(Util.ConverteCidadeParaInt(Util.arestas[i][2]),
//					Util.ConverteCidadeParaInt(Util.arestas[i][1]));
//
//		}
//	}

	public static void inicializaGrafo(Grafos grafo) {
		for (int i = 0; i < Util.arestas.length; i++) {
			// System.out.println(ConverteCidade(Main.arestas[i][1]));
			// System.out.println(ConverteCidade(Main.arestas[i][2]));

			grafo.addEdge(Util.ConverteCidadeParaInt(Util.arestas[i][1]),
					Util.ConverteCidadeParaInt(Util.arestas[i][2]));
			grafo.addEdge(Util.ConverteCidadeParaInt(Util.arestas[i][2]),
					Util.ConverteCidadeParaInt(Util.arestas[i][1]));

		}
	}

	public static String mostrarListaCidades() {
		String retorno = "";
		for (int i = 0; i < cidadesOrdenadas.length; i++) {
			retorno += cidadesOrdenadas[i][0] + ": " + cidadesOrdenadas[i][1] + "\n";
		}
		return retorno;
	}
	
	public static int calculaDistancia(String inicio, String fim) {
		int retorno = 0;
		for (int i = 0; i < Util.arestas.length; i++) {
			if (Util.arestas[i][1] == inicio) {
				retorno = Integer.parseInt(Util.arestas[i][0]);
			} else if (Util.arestas[i][2] == fim) {
				retorno += Integer.parseInt(Util.arestas[i][0]);
			}

		}
		return retorno;
	}

	public static void mostraMatriz() {
		Matriz matriz = new Matriz(7);
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (i != j) {
					matriz.agregar(i, j, distancias[i][j]);
				}
			}
		}
		matriz.imprimir();
	}

	public static void organizarDijkstra() {
		Grafo grafo = new Grafo();

		negocio.Dijkstra.Vertice vertice;
		for (int i = 0; i < cidadesOrdenadas.length; i++) {
			List<negocio.Dijkstra.Aresta> arestasArray = new ArrayList<negocio.Dijkstra.Aresta>();
			boolean arest = false;
			for (int j = 0; j < arestas.length; j++) {

				if (arestas[j][1] == cidadesOrdenadas[i][0]) {
					arest = true;
				}
			}
			if (arest) {
				vertice = new negocio.Dijkstra.Vertice();
				vertice.setDescricao(cidadesOrdenadas[i][0]);
				if (grafo.getVertices().size() != 0) {
					vertice.setPai(grafo.getVertices().get(grafo.getVertices().size() - 1));
					vertice.setVizinhos(grafo.getVertices());
				}
				negocio.Dijkstra.Vertice vtmp = new negocio.Dijkstra.Vertice();
				negocio.Dijkstra.Vertice vtmp2 = new negocio.Dijkstra.Vertice();
				negocio.Dijkstra.Aresta atmp = new negocio.Dijkstra.Aresta();

				atmp.setPeso(Integer.parseInt(arestas[i][0]));
				vtmp.setDescricao(arestas[i][1]);
				vtmp2.setDescricao(arestas[i][2]);
				atmp.setOrigem(vtmp);
				atmp.setDestino(vtmp2);
				arestasArray.add(atmp);

				vertice.setArestas(arestasArray);

				grafo.adicionarVertice(vertice);
			}
		}
		Dijkstra dijkstra = new Dijkstra();
		dijkstra.encontrarMenorCaminhoDijkstra(grafo, grafo.getVertices().get(0),
				grafo.getVertices().get(grafo.getVertices().size() - 1));
	}

	public static void mostraCaminho(List<Vertice> vertices) {
		for (int i = 0; i < vertices.size(); i++) {
			System.out.println(vertices.get(i).getDescricao());
		}
	}
}
