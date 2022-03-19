import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class ArraysAndStrings {
    //Space O(1), Time O(n)
    static boolean solution1a(String input){
        int[] occurances = new int[128];
        for(int i = 0; i < input.length(); i++){
            occurances[input.charAt(i)]++;
            if(occurances[input.charAt(i)] > 1)
                return false;
        }
        return true;
    }
    //Space O(1), Time O(n^2), no additional data structure
    static boolean solution1b(String input){
        for(int i = 0; i < input.length()-1; i++){
            for(int j = i + 1; j < input.length(); j++){
                if(input.charAt(i) == input.charAt(j))
                    return false;
            }
        }
        return true;
    }

    //Space O(n)?, time O(n), using hashmap
    static boolean solution2a(String first, String second){
        if(first.length() != second.length() || first.length() == 0)
            return false;
        Map<Character, Integer> charDifference = new HashMap<Character, Integer>();

        for(int i = 0; i < first.length(); i++){
            char firstChar = first.charAt(i);
            char secondChar = second.charAt(i);

            if(charDifference.containsKey(firstChar))
                charDifference.put(firstChar, charDifference.get(firstChar) + 1);
            else
                charDifference.put(firstChar, 1);

            if(charDifference.containsKey(secondChar))
                charDifference.put(secondChar, charDifference.get(secondChar) - 1);
            else
                charDifference.put(secondChar, -1);
        }

        for(char key : charDifference.keySet())
            if(charDifference.get(key) != 0)
                return false;

        return true;
    }

    //space O(1), time O(n), using arrays
    static boolean solution2b(String first, String second){
        if(first.length() != second.length() || first.length() == 0)
            return false;

        int[] charOccurances = new int[128];

        for(int i = 0; i < first.length(); i++){
            charOccurances[first.charAt(i)]++;
            charOccurances[second.charAt(i)]--;
        }

        for(int i = 0; i < charOccurances.length; i++)
            if(charOccurances[i] != 0)
                return false;

        return true;
    }

    //space O(n), time O(n log n)
    static boolean solution2c(String first, String second){
        if(first.length() != second.length() || first.length() == 0)
            return false;

        char[] firstCharArr = first.toCharArray();
        char[] secondCharArr = second.toCharArray();

        Arrays.sort(firstCharArr);
        Arrays.sort(secondCharArr);

        for(int i = 0; i < firstCharArr.length; i++)
            if(firstCharArr[i] != secondCharArr[i])
                return false;

        return true;
    }

    //space O(1), time O(n)
    static void solution3a(char[] input, int trueLength){
        int counter = input.length - 1;
        for(int i = trueLength - 1; i >= 0; i--){
            if(input[i] != ' ') {
                input[counter] = input[i];
                counter--;
            }
            else{
                input[counter] = '0';
                counter--;
                input[counter] = '2';
                counter--;
                input[counter] = '%';
                counter--;
            }
        }
    }

    //space O(n), time O(n)
    static boolean solution4a(String input){
        if(input.length() == 0)
            return false;

        input = input.toLowerCase();

        Map<Character, Integer> charOccurances = new HashMap<>();
        for(int i = 0; i < input.length(); i++){
            char ch = input.charAt(i);
            if(input.charAt(i) != ' ') {
                if (charOccurances.containsKey(ch)) {
                    charOccurances.put(ch, charOccurances.get(ch) + 1);
                } else {
                    charOccurances.put(ch, 1);
                }
            }
        }

        int numOfOddChars = 0;

        for(Character ch : charOccurances.keySet()){
            if(charOccurances.get(ch) % 2 == 1)
                numOfOddChars++;
            if(numOfOddChars > 1)
                return false;
        }
        return true;
    }

    //space O(n), time O(n) - possible optimization, make int array for lowercase chars only
    static boolean solution4b(String input){
        if(input.length() == 0)
            return false;

        input = input.toLowerCase();

        int[] charOccurances = new int[128];
        for(int i = 0; i < input.length(); i++){
            if(input.charAt(i) != ' ')
                charOccurances[input.charAt(i)]++;
        }

        int numOfOddChars = 0;

        for(int i = 0; i < charOccurances.length; i++) {
            if (charOccurances[i] % 2 == 1)
                numOfOddChars++;
            if (numOfOddChars > 1)
                return false;
        }

        return true;
    }

    

}
