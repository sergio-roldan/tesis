import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.Paths;

public class ProgramOptions {
	private String tagsCmd;
	private String srcCode;
	private String srcDir;
	private String[] arguments;
	private String errorMessage;

	public ProgramOptions(String[] args) {
		this.arguments = args;
	}

	public boolean parse() {
		int len = this.arguments.length;
		int i = 0;
		while (i < len) {
			String current = this.arguments[i];
			if (current.indexOf("-t") != -1 || current.indexOf("--tags") != -1) {
				if (!this.checkTagProgramOption(current, i, len)) {
					return false;
				}
				++i;
			} else if (current.indexOf("-s") != -1 || current.indexOf("--source") != -1) {
				if (!this.checkSourceProgramOption(current, i, len)) {
					return false;
				}
				++i;
			} else if (current.indexOf("-d") != -1 || current.indexOf("--dir") != -1) {
				if (!this.checkDirectoryProgramOption(current, i, len)) {
					return false;
				}
				++i;
			}
			++i;
		}
		boolean bail = false;
		if (this.tagsCmd == null) {
			this.errorMessage = String.valueOf(this.errorMessage)
					+ "El parametro comando tags (-t o --tags) es obligatorio y debe apuntar a ctags.exe\n";
			bail = true;
		}
		if (this.srcCode == null) {
			this.errorMessage = String.valueOf(this.errorMessage)
					+ "El parametro c\ufffddigo (-s o --source) es obligatorio y debe contener el nombre del archivo a convertir\n";
			bail = true;
		}
		if (this.srcDir == null) {
			this.errorMessage = String.valueOf(this.errorMessage)
					+ "El parametro directorio (-d o --dir) es obligatorio y debe apuntar al directorio que contiene el c\ufffddigo fuente\n";
			bail = true;
		}
		if (bail) {
			return false;
		}
		if (!Files.exists(Paths.get(this.srcCode, new String[0]), new LinkOption[0])) {
			this.errorMessage = String.valueOf(this.errorMessage) + "El c\ufffddigo fuente {0} no existe\n"
					+ this.srcDir + this.srcCode;
			return false;
		}
		return true;
	}

	private boolean checkDirectoryProgramOption(String argument, int argumentIndex, int numberOfArguments) {
		if (!this.thereAreMoreArguments(numberOfArguments, argumentIndex).booleanValue()) {
			this.errorMessage = String.valueOf(this.errorMessage)
					+ "El parametro {0} debe ser seguido por el nombre del directorio\n" + argument;
			return false;
		}
		this.srcDir = this.arguments[argumentIndex + 1];
		if (!Files.exists(Paths.get(this.srcDir, new String[0]), new LinkOption[0])) {
			this.errorMessage = String.valueOf(this.errorMessage) + "El directorio {0} no existe\n" + this.srcDir;
			return false;
		}
		return true;
	}

	private boolean checkSourceProgramOption(String argument, int argumentIndex, int numberOfArguments) {
		if (!this.thereAreMoreArguments(numberOfArguments, argumentIndex).booleanValue()) {
			this.errorMessage = String.valueOf(this.errorMessage)
					+ "El parametro {0} debe ser seguido por el nombre del archivo\n" + argument;
			return false;
		}
		this.srcCode = this.arguments[argumentIndex + 1];
		return true;
	}

	private boolean checkTagProgramOption(String argument, int argumentIndex, int numberOfArguments) {
		if (!this.thereAreMoreArguments(numberOfArguments, argumentIndex).booleanValue()) {
			this.errorMessage = String.valueOf(this.errorMessage)
					+ "El parametro {0} debe ser seguido por la ruta al programa ctags.exe\n" + argument;
			return false;
		}
		this.tagsCmd = this.arguments[argumentIndex + 1];
		if (!Files.exists(Paths.get(this.tagsCmd, new String[0]), new LinkOption[0])) {
			this.errorMessage = String.valueOf(this.errorMessage) + "El programa {0} no existe\n" + this.tagsCmd;
			return false;
		}
		return true;
	}

	private Boolean thereAreMoreArguments(int number, int current) {
		if (current + 1 < number) {
			return true;
		}
		return false;
	}

	public String getTagsCommand() {
		return this.tagsCmd;
	}

	public void setTagsCommand(String value) {
		this.tagsCmd = value;
	}

	public String getSourceFileName() {
		return this.srcCode;
	}

	public void setSourceFileName(String value) {
		this.srcCode = value;
	}

	public String getSourceDirectory() {
		return this.srcDir;
	}

	public void setSourceDirectory(String value) {
		this.srcDir = value;
	}

	public String getErrorMessage() {
		return this.errorMessage;
	}
}