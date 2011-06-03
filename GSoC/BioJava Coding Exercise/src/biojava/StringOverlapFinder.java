/**
 * 
 */
package biojava;

/**
 * @author Sapan Diwakar
 * 
 */
public interface StringOverlapFinder {

	/**
	 * 
	 * @param x
	 *            the String x
	 * @param y
	 *            the String y
	 * @return the String containing non-overlapping start of x
	 */
	String cleanX(String x, String y);
}