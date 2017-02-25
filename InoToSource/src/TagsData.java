public class TagsData {
	private String ctagsExecutable;
	private String sourceCode;
	private String workingDirectory;
	private String commandArgs;

	public TagsData(String ctagsExecutable, String sourceCode, String workingDirectory, String commandArgs) {
		this.ctagsExecutable = ctagsExecutable;
		this.sourceCode = sourceCode;
		this.workingDirectory = workingDirectory;
		this.commandArgs = commandArgs;
	}

	public String getCtagsExecutable() {
		return this.ctagsExecutable;
	}

	public String getSourceCode() {
		return this.sourceCode;
	}

	public String getWorkingDirectory() {
		return this.workingDirectory;
	}

	public String getCommandArgs() {
		return this.commandArgs;
	}
}