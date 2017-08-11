import javax.swing.JOptionPane;

public class Main {

	public static void main(String[] args) {
		MetodosGrafo metodosgrafo = new MetodosGrafo();
		
		String [] listaCidades = {"Rio Grande", "Pelotas", "Jaguarão", "Bagé", 
				"Porto Alegre", "Santa Maria", "Gramado"};
		
		int [][] listaDistancias = {{0,52,0,0,0,0,0},{52,0,152,180,0,0,0},{0,152,0,0,402,0,0},{0,180,0,0,374,250,0},
				{0,0,391,374,0,0,115},{0,0,0,250,0,0,0},{0,0,0,0,115,0,0}};
		
		
		String [] grafoInicial = {"0","0","0","0","0","0","0",};
		String [] grafo = grafoInicial;
		
		int [][] arestasIniciais = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
		
		int [][] arestas = arestasIniciais;
		
	    String[] algoritmoBusca = { "Profundidade", "Largura", "Menor Caminho"};
		
		int cidade1 = -1;
		int cidade2 = -1;
		
		boolean loop = true;
		while(loop){
			  Object[] options = { "Carregar Cidades", "Busca Caminho", "Reiniciar"};
			  int escolha = JOptionPane.showOptionDialog(null, "Escolha uma opção:", "Grafo de Cidades", 
			      JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, 
			      options, options[2]);
			  
			  if (escolha == 0) {
				  System.out.println("Carregando lista de cidades e distâncias:");
				  grafo = listaCidades;
				  arestas = listaDistancias;
				  System.out.printf("\nLista de cidades:\n");
				  for (int i = 0; i < 7; i++){
					  System.out.print(grafo[i]);
					  if (i < 6) System.out.print(", ");
				  }
				  System.out.printf("\n\n");
			  
			  } else if (escolha == 1) {
				cidade1 = -1;
				cidade2 = -1;
				
				cidade1 = metodosgrafo.retornaIdCidade("partida", listaCidades);
				cidade2 = metodosgrafo.retornaIdCidade("chegada", listaCidades);
					
				if (cidade1 < 0 || cidade2 < 0) break;
				
				else {
				    String busca = (String) JOptionPane.showInputDialog(null, "Escolha o tipo de algorítmo:",
					        "Algorítimo de busca", JOptionPane.QUESTION_MESSAGE, null, 
					        algoritmoBusca,
					        algoritmoBusca[0]);
					    if (busca == "Profundidade"){
					    	metodosgrafo.buscaProfundidade(cidade1, cidade2, arestas);
					    } else if (busca == "Largura"){
					    	metodosgrafo.buscaLargura(cidade1, cidade2, arestas);
					    } else if (busca == "Menor Caminho"){
					    	metodosgrafo.buscaProfundidade(cidade1, cidade2, arestas);
					    }
				}
			  
			  } else if (escolha==2) {
					grafo = grafoInicial;
					arestas = arestasIniciais;
					System.out.println("Reiniciando o grafo e as arestas");
			  } else {
				  System.out.println("Saindo...");
				  loop=false;
			  }
		}
		
	}
}