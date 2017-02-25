public class Program {
	public static void main(String[] args) {
		String cmdArgs = "--language-force=c";
		ProgramOptions opt = new ProgramOptions(args);
		if (!opt.parse()) {
			System.out.println(opt.getErrorMessage());
			System.exit(1);
		}

		ConvertInoToCSource converter = new ConvertInoToCSource(
				new TagsData(opt.getTagsCommand(), opt.getSourceFileName(), opt.getSourceDirectory(), cmdArgs));
		if (!converter.run()) {
			System.out.println("Error");
		}
		System.out.println("Convertido {0}: " + opt.getSourceFileName());
		System.exit(0);
	}
}