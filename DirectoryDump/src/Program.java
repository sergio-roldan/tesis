/**
 * Main class to run the program
 * 
 * @author Sergio Roldan
 * @since 25/02/2017
 *
 */
public class Program {

	/**
	 * Main method, executed when the program is launched.
	 * 
	 * @param args
	 *            arguments needed by the program.
	 */
	public static void main(String[] args) {
		ProgramOptions opts = new ProgramOptions(args);
		if (!opts.parse()) {
			System.out.println("Error: {0}" + opts.getErrorMessage());
			System.exit(1);
		}

		Boolean recursive = Boolean.valueOf(opts.getRecursive());
		String source = opts.getSourceDirectory();
		String dest = opts.getTargetDirectory();
		DirectoryCopy copy = new DirectoryCopy(source, dest);
		if (!copy.execute(recursive)) {
			System.out.println("Error: {0}" + copy.getErrorMessage());
			System.exit(2);
		}
		System.out.println("Proceso de copiado terminado perfectametne");
		System.exit(0);
	}
}