class Solution {
    public boolean isValid(String s) {
              Map<Character, Character> matchingParenthesis = new HashMap<>();
            matchingParenthesis.put('}', '{');
            matchingParenthesis.put(']', '[');
            matchingParenthesis.put(')', '(');
        Stack<Character> result = new Stack<>();
        if (s!=null && s.length()%2 != 0) {
            return false;
        }
        for (Character c : s.toCharArray()) {
            Character closingBraces = matchingParenthesis.get(c);
            if (closingBraces != null && !result.isEmpty()){
                if(closingBraces.equals(result.peek())) {
                    result.pop();
                } else {
                    break;
                }
                
            } 
            else {
                result.push(c);
            }
        }
        return result.size() == 0;

    }
}
