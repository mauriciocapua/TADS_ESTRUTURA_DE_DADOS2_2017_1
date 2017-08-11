package xmlread;

import xmlread.Metodos;
import java.io.File;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;

public class Main {

	public static void main(String[] args) {
		try {

			File fXmlFile = new File("C:\\Users\\Mauricio Capua\\Desktop\\pyC45-master\\DecisionTree.xml");

			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);

			// optional, but recommended
			// read this -
			// http://stackoverflow.com/questions/13786607/normalization-in-dom-parsing-with-java-how-does-it-work
			doc.getDocumentElement().normalize();

			Node atual = doc.getDocumentElement();

			int posicao = 0;
			NamedNodeMap namedNodeMap = atual.getAttributes();
			Boolean value = false;

			while (atual.getFirstChild().getNodeName() != "#text") {
				namedNodeMap = atual.getFirstChild().getAttributes();
				value = Boolean.parseBoolean(namedNodeMap.getNamedItem("value").getNodeValue());

				if (Metodos.caixaPergunta(atual.getFirstChild().getNodeName(), posicao + 1)) {
					if (value) {
						atual = atual.getFirstChild();
					} else {
						atual = atual.getLastChild();
					}
				} else {
					if (value) {
						atual = atual.getLastChild();
					} else {
						atual = atual.getFirstChild();
					}
				}
				posicao++;
			}
			Metodos.caixaResposta(atual.getTextContent());

			// Metodos.caixaResposta();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
