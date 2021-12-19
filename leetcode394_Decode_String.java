class Solution {
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0;i < s.length();i++){
            if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z'){
                sb.append(s.charAt(i));
            }
            else{
                int startBracket = s.indexOf('[',i);
                int endBracket = findEndBracket(s,startBracket);
                int repeat = Integer.parseInt(s.substring(i,startBracket));
                String content = decodeString(s.substring(startBracket + 1,endBracket));
                for(int j = 0;j < repeat;j++)
                    sb.append(content);
                i = endBracket;
            }
        }
        
        return sb.toString();
    }
    
    public int findEndBracket(String s,int idx){
        int count = 0;
        for(int i = idx;i < s.length();i++){
            if(s.charAt(i) == '[')
                count--;
            else if(s.charAt(i) == ']')
                count++;
            if(count == 0)
                return i;
        }
        return -1;
    }
}
