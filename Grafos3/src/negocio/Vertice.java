package negocio;

import java.util.List;

public class Vertice {
	protected String descricao;
	protected boolean visitado;
	protected List<Aresta> arestas;

	public Vertice(String descricao, boolean visitado, List<Aresta> arestas) {
		this.descricao = descricao;
		this.visitado = visitado;
		this.arestas = arestas;
	}

	public Vertice(String descricao, boolean visitado) {
		this.descricao = descricao;
		this.visitado = visitado;
	}

	public Vertice() {
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public boolean isVisitado() {
		return visitado;
	}

	public void setVisitado(boolean visitado) {
		this.visitado = visitado;
	}

	public List<Aresta> getArestas() {
		return arestas;
	}

	public void setArestas(List<Aresta> arestas) {
		this.arestas = arestas;
	}

}
