package xmlread;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Metodos {
	public static final String[] consoles = { "PS4", "Xbox One", "Playstation Vita", "Nintendo 3DS",
			"Nintendo Switch" };

	public static Boolean caixaPergunta(String nodo, int posicao) {
		int dialogButton = 1;
		int dialogResult = JOptionPane.showConfirmDialog(null, titulo(nodo), "Pergunta " + posicao, dialogButton);
		if (dialogResult == JOptionPane.YES_OPTION) {
			return true;
		}
		return false;
	}

	public static Boolean caixaResposta(String escolha) {
		JOptionPane.showMessageDialog(null, "A escolha certa para você é: " + escolha, "Resposta!", 1);
		// if(dialogResult == JOptionPane.YES_OPTION){
		// return true;
		// }
		return false;
	}

	public static Boolean caixaResposta() {
		int dialogButton = 1;
		JFrame frame = new JFrame("Input");
		String console = (String) JOptionPane.showInputDialog(frame, "Qual o console deveria ser?", "Console",
				JOptionPane.QUESTION_MESSAGE, null, consoles, consoles[0]);
		return false;
	}

	public static String titulo(String nodo) {
		switch (nodo) {
		case "jogos_orientais":
			return "Disponibilidade de Jogos orientais é importante?";
		case "descontos_loja":
			return "Descontos na loja online são importantes?";
		case "estabilidade_online":
			return "Estabilidade online é importante?";
		case "jogos_first_party":
			return "Diponibilidade de Jogos First Party é importante?";
		case "dublagem_ptbr":
			return "Diponibilidade de Jogos Dublados em Português é importante?";
		case "portabilidade":
			return "O console ser portátil é importante?";
		case "preco_console":
			return "O preço do console é importante?";
		case "retrocompatibilidade":
			return "O console ter retrocompatibilidade é importante?";
		default:
			return "erro";
		}
	}
}
