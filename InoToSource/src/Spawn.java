import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Spawn {
	public static SpawnResult CommandLineSync(String command, String args, String workingDirectory) {
		SpawnResult result = new SpawnResult();
		try {
			String line;
			Process process = Runtime.getRuntime().exec(String.valueOf(command) + " " + args);
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
				result.setExitCode(-1);
				result.setStderrString(e.toString());
			}
			BufferedReader input = new BufferedReader(new InputStreamReader(process.getInputStream()));
			while ((line = input.readLine()) != null) {
				result.setStdoutString(String.valueOf(result.getStdoutString()) + line);
			}
			input.close();
			result.setExitCode(process.exitValue());
		} catch (IOException e) {
			e.printStackTrace();
			result.setExitCode(-1);
			result.setStderrString(e.toString());
		}
		return result;
	}
}