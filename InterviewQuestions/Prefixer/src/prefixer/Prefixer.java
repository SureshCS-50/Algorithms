/**
 * 
 */
package prefixer;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * @author sapan
 * 
 */
public class Prefixer {


	/**
	 * Main function
	 * @param args filename and optional -r switch
	 */
	public static void main(String[] args) {
		boolean reduceFlag = false;
		File inputFile = null;
		if (args.length > 0 && args.length < 3) {
			for (String arg : args) {
				if (arg.equals("-r")) {
					reduceFlag = true;
				} else {
					inputFile = new File(arg);
				}
			}
		}
		if (inputFile == null) {
			System.err.println("Error in syntax.");
		} else {
			handleFile(inputFile, reduceFlag);
		}
	}

	private static void handleFile(File file, boolean reduceFlag) {
		try {
			BufferedReader input = new BufferedReader(new FileReader(file));
			String line = null;
			while ((line = input.readLine()) != null) {
				System.out.println(ExpUtils.toPrefix(line, reduceFlag));
			}
		} catch (FileNotFoundException e) {
			System.err.println("File not found!");
			e.printStackTrace();
		} catch (IOException e) {
			System.err.println("Error while reading from file!");
			e.printStackTrace();
		}
	}



}
