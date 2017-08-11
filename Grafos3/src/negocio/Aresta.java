package negocio;

public class Aresta {
	protected int peso;
	protected String destino;

	public Aresta() {
	}

	public Aresta(int peso, String destino) {
		this.peso = peso;
		this.destino = destino;
	}

	public int getPeso() {
		return peso;
	}

	public void setPeso(int peso) {
		this.peso = peso;
	}

	public String getDestino() {
		return destino;
	}

	public void setDestino(String destino) {
		this.destino = destino;
	}

}
