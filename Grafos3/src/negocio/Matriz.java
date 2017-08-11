package negocio;

import java.util.Formatter;

public class Matriz {
	private int n;
	private int[][] matriz;
	String[] cidades = { "Bagé", "Chui", "Jaguarão", "Pelotas", "Porto Alegre", "Rio Grande", "Santa Maria" };

	public Matriz(int n) {
		this.n = n;
		matriz = new int[this.n][this.n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matriz[i][j] = 0;
			}
		}
	}

	public void agregar(int i, int j, int peso) {
		matriz[i][j] += peso;
	}

	public void remover(int matriz[][]) {
		matriz = new int[this.n][this.n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matriz[i][j] = 0;
			}
		}
	}

	public void imprimir() {
		Formatter formatter = new Formatter();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0) {
					System.out.println(new Formatter().format("%17s%5s%10s%14s%9s%15s%10s%10s", "|||||||||||", "Bagé",
							"| Chui", "| Jaguarão", "| Pelotas", "| Porto Alegre", "| Rio Grande", "| Santa Maria"));
				}
				if (j == 0) {
					System.out.print(new Formatter().format("%17s", cidades[i] + "|"));
				}
				formatter = new Formatter();
				System.out.print(formatter.format("%10s", matriz[i][j] + "|"));

				formatter.close();
			}
			System.out.println();
		}
	}
}
