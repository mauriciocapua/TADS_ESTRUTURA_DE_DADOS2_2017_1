package apresentacao;

import javax.swing.JOptionPane;

import negocio.*;

public class Main {

	public static void main(String[] args) {
		int opcao = -1;

		while (opcao != 0) {

			opcao = Integer.parseInt(JOptionPane.showInputDialog(
					"informe a opção desejada \n1-Mostrar Matriz\n2-Profundidade\n3-Largura\n4-Melhor Caminho\n0-Sair"));
			switch (opcao) {
			case 1:
				Util.mostraMatriz();
				System.out.println("");
				break;
			case 2:
				Grafos grafo = new Grafos(14);
				Util.inicializaGrafo(grafo);

				Profundidade profuncidade = new Profundidade();
				profuncidade.DFS(
						Integer.parseInt(
								JOptionPane.showInputDialog(Util.mostrarListaCidades() + " informe a cidade inicial")),
						Integer.parseInt(
								JOptionPane.showInputDialog(Util.mostrarListaCidades() + "informe a cidade final")),
						grafo);
				System.out.println("");
				break;

			case 3:
				Grafos grafo2 = new Grafos(14);
				Util.inicializaGrafo(grafo2);
				Largura largura = new Largura();

				largura.BFS(
						Integer.parseInt(
								JOptionPane.showInputDialog(Util.mostrarListaCidades() + " informe a cidade inicial")),
						Integer.parseInt(
								JOptionPane.showInputDialog(Util.mostrarListaCidades() + "informe a cidade final")),
						grafo2);

				break;
			case 4:
				Util.organizarDijkstra();
				break;
			default:
				break;

			}
		}

	}

}
