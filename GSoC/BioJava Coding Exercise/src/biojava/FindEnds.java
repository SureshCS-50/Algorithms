/**
 * 
 */
package biojava;

//Java Imports
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 * @author Sapan Diwakar
 * 
 */
public class FindEnds {

	/**
	 * @param args
	 *            Command line arguments containing the path to input and output
	 *            file.
	 */
	public static void main(String[] args) {
		StringOverlapFinder sof = new StringOverlapFinderImpl();

		// The Print Stream to write to
		PrintStream out;

		// The reader to read from
		BufferedReader in;

		try {
			switch (args.length) {
			case 1:
				in = new BufferedReader(new InputStreamReader(
						new FileInputStream(args[0])));
				out = System.out;
				break;
			case 2:
				in = new BufferedReader(new InputStreamReader(
						new FileInputStream(args[0])));
				out = new PrintStream(new FileOutputStream(args[1]));
				break;
			default:
				System.out.println("Incorrect Usage");
				return;
			}
		} catch (Exception e) {
			System.out.println("Unable to find the file specified");
			e.printStackTrace();
			return;
		}

		String inputLine;

		try {
			while ((inputLine = in.readLine()) != null) {
				String[] input = inputLine.split("\t");

				out.println(sof.cleanX(input[0], input[1]));
			}
		} catch (IOException e) {
			System.out.println("Error reading from file");
			e.printStackTrace();
		}
	}
}
