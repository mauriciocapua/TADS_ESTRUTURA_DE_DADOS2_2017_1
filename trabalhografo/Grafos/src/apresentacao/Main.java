package apresentacao;

import javax.swing.JOptionPane;

import negocio.*;

public class Main {

	public static void main(String[] args) {
		String opcao = "";
		String[] algoritmoBusca = { "Mostrar Matriz", "Profundidade", "Largura", "Melhor Caminho", "Sair" };
		while (opcao != "Sair") {

			opcao = (String) JOptionPane.showInputDialog(null, "Escolha o tipo de algorítmo:", "",
					JOptionPane.QUESTION_MESSAGE, null, algoritmoBusca, algoritmoBusca[0]);
			switch (opcao) {
			case "Mostrar Matriz":
				Util.mostraMatriz();
				System.out.println("");
				break;
			case "Profundidade":
				Grafos grafo = new Grafos(14);
				Util.inicializaGrafo(grafo);

				Profundidade profundidade = new Profundidade();

				profundidade.DFS(
						Util.ConverteCidadeParaInt((String) JOptionPane.showInputDialog(null,
								"Informe a cidade inicial:", "", JOptionPane.QUESTION_MESSAGE, null,
								Util.ConverteMenu(), Util.ConverteMenu()[0])),
						Util.ConverteCidadeParaInt((String) JOptionPane.showInputDialog(null,
								"Informe a cidade inicial:", "", JOptionPane.QUESTION_MESSAGE, null,
								Util.ConverteMenu(), Util.ConverteMenu()[0])),
						grafo);

				// Integer.parseInt(
				// JOptionPane.showInputDialog(Util.mostrarListaCidades() + "
				// informe a cidade inicial")),
				// Integer.parseInt(
				// JOptionPane.showInputDialog(Util.mostrarListaCidades() +
				// "informe a cidade final")),
				// grafo);
				System.out.println("");
				break;

			case "Largura":
				Grafos grafo2 = new Grafos(14);
				Util.inicializaGrafo(grafo2);
				Largura largura = new Largura();

				largura.BFS(
						Util.ConverteCidadeParaInt((String) JOptionPane.showInputDialog(null,
								"Informe a cidade inicial:", "", JOptionPane.QUESTION_MESSAGE, null,
								Util.ConverteMenu(), Util.ConverteMenu()[0])),
						Util.ConverteCidadeParaInt((String) JOptionPane.showInputDialog(null,
								"Informe a cidade inicial:", "", JOptionPane.QUESTION_MESSAGE, null,
								Util.ConverteMenu(), Util.ConverteMenu()[0])),
						grafo2);

				break;
			case "Melhor Caminho":
				Util.organizarDijkstra();
				break;
			default:
				opcao = "Sair";
				break;

			}
		}

	}

}
