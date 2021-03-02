class Solution {
    public String replaceSpace(String s) {
        int length = s.length();
        char[] c = new char[length*3];
        int size=0;
        for(int i=0,j=0;i<length;i++){
            if(s.charAt(i)!=' ')c[size++]=s.charAt(i);
            else{
                c[size++]='%';
                c[size++]='2';
                c[size++]='0';
            }
        }
        return new String(c,0,size);
    }
}