class Solution {
    public boolean isAnagram(String s, String t) {
     if(s.length()!=t.length()){
        return false ;
     }   
    HashMap<Character,Integer> map = new HashMap<>();

    for(int i=0;i<s.length();i++)
    {
        char ch =s.charAt(i);
        map.put(ch,map.getOrDefault(ch,0)+1);
    }
    for(int j=0;j<t.length();j++)
    {
        char ch1 = t.charAt(j);
        map.put(ch1,map.getOrDefault(ch1,0)-1);

        if(map.get(ch1)<0){
            return false;
        }

    }
    return true ;
    }
}
