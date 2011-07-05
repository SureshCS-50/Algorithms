/**
 * 
 */
package prefixer;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author sapan
 *
 */
public class ExpUtils {
	
	private static Map<String, Operators> operators = null;

	/**
	 * Convert expression to prefix
	 * @param exp
	 * @param reduceFlag
	 * @return
	 */
	public static String toPrefix(String exp, boolean reduceFlag) {
		String[] inputList = removeDuplicateWhitespace(
				new StringBuffer(exp).reverse().toString().trim()).split(" ");
		Stack<String> workingStack = new Stack<String>();

		List<String> outputStrings = new ArrayList<String>();
		for (String input : inputList) {
			if (isOperator(input) == Operators.NONE) {
				outputStrings.add(input);
			} else {
				switch (isOperator(input)) {
				case CLOSING_PAR:
					workingStack.push(input);
					break;
				case OPENING_PAR:
					while (!workingStack.empty()
							&& !workingStack.peek().equals(
									getOperator(Operators.CLOSING_PAR))) {
						outputStrings.add(workingStack.pop());
					}
					if (!workingStack.empty()) {
						workingStack.pop();
					}
					break;
				default:
					if (workingStack.empty()
							|| workingStack.peek().equals(
									getOperator(Operators.CLOSING_PAR))) {
						workingStack.push(input);
					} else if (priority(input) >= priority(workingStack.peek())) {
						workingStack.push(input);
					} else {
						while (!workingStack.empty()
								&& priority(input) < priority(workingStack
										.peek())) {
							outputStrings.add(workingStack.pop());
						}
						workingStack.push(input);
					}
				}
			}
		}
		while (!workingStack.empty()) {
			outputStrings.add(workingStack.pop());
		}

		String prefixExp = (new StringBuffer(arrayToString(
				outputStrings.toArray(new String[0]), " "))).reverse()
				.toString();

		if (reduceFlag) {
			prefixExp = reducePrefixExp(prefixExp);
		}
		return prefixExp;
	}

	/**
	 * reduce prefix expression
	 * @param prefixExp
	 * @return
	 */
	public static String reducePrefixExp(String prefixExp) {
		String[] inputList = removeDuplicateWhitespace(
				prefixExp.trim()).split(" ");
		Stack <String> operatorStack = new Stack<String>();
		Stack <String> operandStack = new Stack<String>();
		
		final String MARKER = "MARKER"; 
		for (String input : inputList) {
			if (isOperator(input) == Operators.NONE && operandStack.empty()) {
				operandStack.push(input);
			} else if (isOperator(input) == Operators.NONE) {
				if (operandStack.peek().equals(MARKER)) {
					operandStack.push(input);
				} else {
					while (!operandStack.empty() && !operandStack.peek().equals(MARKER)) {
						String operand = operandStack.pop();
						operandStack.pop(); // POP Marker
						String operator = operatorStack.pop();
						input = evaluate(operand, input, operator);
					}
					operandStack.push(input);
				}
			} else {
				operandStack.push(MARKER);
				operatorStack.push(input);
			}
		}

		return operandStack.pop();
	}

	/**
	 * remove duplicate white spaces
	 * @param inputStr
	 * @return
	 */
	public static String removeDuplicateWhitespace(String inputStr) {
		String patternStr = "\\s+";
		String replaceStr = " ";
		Pattern pattern = Pattern.compile(patternStr);
		Matcher matcher = pattern.matcher(inputStr);
		return matcher.replaceAll(replaceStr);
	}

	/**
	 * convert array to string
	 * @param a
	 * @param separator
	 * @return
	 */
	public static String arrayToString(String[] a, String separator) {
		String result = "";
		if (a.length > 0) {
			result = a[0]; // start with the first element
			for (int i = 1; i < a.length; i++) {
				result = result + separator + a[i];
			}
		}
		return result;
	}
	
	/**
	 * evaluate operand1 operator operand2
	 * @param operand1
	 * @param operand2
	 * @param operator
	 * @return
	 */
	private static String evaluate(String operand1, String operand2, String operator) {
		if (containsOnlyNumbers(operand1) && containsOnlyNumbers(operand2)) {
			int result;
			int val1 = Integer.parseInt(operand1);
			int val2 = Integer.parseInt(operand2);
			switch (operators.get(operator)) {
			case PLUS:
				result = val1 + val2; 
				break;
			case MINUS:
				result = val1 - val2; 
				break;
			case MULTIPLY:
				result = val1 * val2; 
				break;
			case DIVIDE:
				result = val1 / val2; 
				break;
			default:
				result = 0;
				break;
			}
			return Integer.toString(result);
		} else {
			return operator + " " + operand1 + " " + operand2;
		}
	}
	
	/**
	 * check whether the string contains only numbers
	 * @param str
	 * @return
	 */
	private static boolean containsOnlyNumbers(String str) {
        
        //It can't contain only numbers if it's null or empty...
        if (str == null || str.length() == 0)
            return false;
        
        for (int i = 0; i < str.length(); i++) {

            //If we find a non-digit character we return false.
            if (!Character.isDigit(str.charAt(i)))
                return false;
        }
        
        return true;
    }

	/**
	 * returns the priority of the operator
	 * @param input
	 * @return
	 */
	private static int priority(String input) {
		if (input.equals(getOperator(Operators.MINUS))
				|| input.equals(getOperator(Operators.PLUS))) {
			return 1;
		} else if (input.equals(getOperator(Operators.DIVIDE))
				|| input.equals(getOperator(Operators.MULTIPLY))) {
			return 2;
		}
		return 0;
	}

	/**
	 * gets the operator's string representation
	 * @param input
	 * @return
	 */
	private static Object getOperator(Operators input) {
		for (String op : operators.keySet()) {
			if (operators.get(op).equals(input)) {
				return op;
			}
		}
		return null;
	}

	/**
	 * check whether the string is operator
	 * @param input
	 * @return
	 */
	private static Operators isOperator(String input) {
		if (operators == null) {
			operators = new HashMap<String, Operators>();
			operators.put("(", Operators.OPENING_PAR);
			operators.put(")", Operators.CLOSING_PAR);
			operators.put("/", Operators.DIVIDE);
			operators.put("*", Operators.MULTIPLY);
			operators.put("+", Operators.PLUS);
			operators.put("-", Operators.MINUS);
		}
		if (operators.keySet().contains(input)) {
			return operators.get(input);
		}
		return Operators.NONE;
	}

}
