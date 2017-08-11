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
		JOptionPane.showMessageDialog(null, "A escolha certa para voc� �: " + escolha, "Resposta!", 1);
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
			return "Disponibilidade de Jogos orientais � importante?";
		case "descontos_loja":
			return "Descontos na loja online s�o importantes?";
		case "estabilidade_online":
			return "Estabilidade online � importante?";
		case "jogos_first_party":
			return "Diponibilidade de Jogos First Party � importante?";
		case "dublagem_ptbr":
			return "Diponibilidade de Jogos Dublados em Portugu�s � importante?";
		case "portabilidade":
			return "O console ser port�til � importante?";
		case "preco_console":
			return "O pre�o do console � importante?";
		case "retrocompatibilidade":
			return "O console ter retrocompatibilidade � importante?";
		default:
			return "erro";
		}
	}
}
