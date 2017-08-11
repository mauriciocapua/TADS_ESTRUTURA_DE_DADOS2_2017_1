package negocio.Dijkstra;

public class Aresta {

	private int peso;
	private Vertice origem;
	private Vertice destino;

	public Aresta(int peso, Vertice v1, Vertice v2) {

		this.peso = peso;
		this.origem = v1;
		this.destino = v2;

	}

	public Aresta() {
	}
	
	public Aresta(int peso) {
		this.peso = peso;
	}

	public void setPeso(int novoPeso) {

		this.peso = novoPeso;
	}

	public int getPeso() {

		return peso;
	}

	public void setDestino(Vertice destino) {
		this.destino = destino;
	}

	public Vertice getDestino() {
		return destino;
	}

	public void setOrigem(Vertice origem) {
		this.origem = origem;
	}

	public Vertice getOrigem() {
		return origem;
	}

	
	public String Print() {
		return "Aresta [peso=" + peso + ", origem=" + origem + ", destino=" + destino + "]";
	}
	
	

}