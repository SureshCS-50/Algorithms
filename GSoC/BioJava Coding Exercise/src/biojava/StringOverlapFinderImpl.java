/**
 * 
 */
package biojava;

/**
 * @author Sapan Diwakar
 * 
 */
public class StringOverlapFinderImpl implements StringOverlapFinder {

	/**
	 * {@inheritDoc}
	 */
	@Override
	public String cleanX(String x, String y) {

		// Start from i = 5 since minimum length for overlap is 5
		for (int i = 5; i <= y.length(); ++i) {
			if (x.endsWith(y.substring(0, i))) {
				return x.substring(0, x.length() - i);
			}
		}

		// If overlap is not found, return x
		return x;

	}
}
