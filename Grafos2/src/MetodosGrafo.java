import java.util.ArrayList;

import javax.swing.JOptionPane;

public class MetodosGrafo {

	public int retornaIdCidade(String ponto, String[] listaCidades){
		while(true){
			String inputCidade = JOptionPane.showInputDialog(null, "Digite o ponto de "+ponto, "Pesquisa de distâncias",
					JOptionPane.QUESTION_MESSAGE);
			if(inputCidade == null) return -1;
			for (int i = 0; i < 7; i++){
				if(inputCidade.trim().toLowerCase().equals(listaCidades[i].trim().toLowerCase())) return i;
			}
			System.out.println("Cidade não encontrada!");
		}
	}
	
	public void buscaProfundidade(int cidade1, int cidade2, int[][] arestas){
		ArrayList<Integer> caminhoPercorrido = new ArrayList<>();
		ArrayList<Integer> caminhoReal = new ArrayList<>();
		
		int cidadeAtual = 0;
		caminhoPercorrido.add(cidade1);
		caminhoReal.add(cidade1);
		
		cidadeAtual = cidade1;
		
		boolean adicionado = false;

		while(caminhoReal.get(caminhoReal.size() - 1) != cidade2){
			
			for (int i = 0; i < arestas[cidadeAtual].length; i++){
				
				if(arestas[cidadeAtual][i] > 0){
					adicionado = false;
					for (Integer integer : caminhoPercorrido) {
						if (integer == i) {
							adicionado = true;
							break;
						}
					}
					if (!adicionado) {
						caminhoReal.add(i);
						caminhoPercorrido.add(i);						
						cidadeAtual = i;
						break;
					}		
				}

				if (i == arestas[cidadeAtual].length-1){
					caminhoReal.remove(caminhoReal.size()-1);
					cidadeAtual = caminhoReal.get(caminhoReal.size()-1);
					
				}
			}
		}
		
		System.out.println("Caminho Percorrido");
		for (Integer integer : caminhoPercorrido) {
			System.out.print(integer+1+"->");
		}
		System.out.println();
		System.out.println("Caminho Real");
		int dist = 0;
		int cont = 0;
		for (Integer integer : caminhoReal) {
			
			System.out.print(integer+1+"->");
			if (++cont != caminhoReal.size()){
				dist +=  arestas[integer][caminhoReal.get(cont)];
			}
			
		}
		System.out.println("Distância Total = "+dist);
	}

	public void buscaLargura(int cidade1, int cidade2, int[][] arestas) {
		ArrayList<Integer> listaLargura = new ArrayList<>();
		ArrayList<Integer> fila = new ArrayList<>();
		
		int cidadeAtual = cidade1;
		
		boolean adicionado = false;
		if (cidade1 < cidade2){
			while (cidadeAtual != cidade2){
				for (int i = cidadeAtual; i < arestas[cidadeAtual].length; i++){
					adicionado = false;
					if(arestas[cidadeAtual][i] > 0){
						for (Integer integer : listaLargura) {
							if(integer == i){
								adicionado = true;
							}
						}
						
						for (Integer integer : fila) {
							if(integer == i){
								adicionado = true;
							}
						}
						
						if(!adicionado){
							fila.add(i);
						}
					}
				}
				listaLargura.add(cidadeAtual);
				cidadeAtual = fila.get(0);
				fila.remove(0);
			}
		} else {
			while (cidadeAtual != cidade2){
				for (int i = cidadeAtual; i >= 0; i--){
					adicionado = false;
					if(arestas[cidadeAtual][i] > 0){
						for (Integer integer : listaLargura) {
							if(integer == i){
								adicionado = true;
							}
						}
						
						for (Integer integer : fila) {
							if(integer == i){
								adicionado = true;
							}
						}
						
						if(!adicionado){
							fila.add(i);
						}
					}
				}
				listaLargura.add(cidadeAtual);
				cidadeAtual = fila.get(0);
				fila.remove(0);
			}
		}
		listaLargura.add(cidadeAtual);
		System.out.println("Lista de busca por largura");
		for (Integer integer : listaLargura) {
			System.out.print(integer+"->");
		}
		
	}

}
