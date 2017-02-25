import java.io.File;
import java.io.FileFilter;

public class Filtro implements FileFilter {
	String tipo;

	public Filtro(String tipo) {
		this.tipo = tipo;
	}

	@Override
	public boolean accept(File file) {
		boolean esTipo = false;
		if (this.tipo.compareTo("file") == 0) {
			esTipo = file.isFile();
		} else if (this.tipo.compareTo("directory") == 0) {
			esTipo = file.isDirectory();
		}
		return esTipo;
	}
}