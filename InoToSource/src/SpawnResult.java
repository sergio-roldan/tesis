public class SpawnResult {
	private String _stdoutStr;
	private String _stderrStr;
	private int _exitCode;

	public String getStdoutString() {
		return this._stdoutStr;
	}

	public void setStdoutString(String value) {
		this._stdoutStr = value;
	}

	public String getStderrString() {
		return this._stderrStr;
	}

	public void setStderrString(String value) {
		this._stderrStr = value;
	}

	public int getExitCode() {
		return this._exitCode;
	}

	public void setExitCode(int value) {
		this._exitCode = value;
	}
}