bool match(string s,int spos,string p,int ppos){
    int n=s.length();
    int m=p.length();
    if ((spos==n)&&(ppos==m))
        return true;
    else{
        if ((spos==n)||(ppos==m)) return false;
        if (p[ppos]=='.'){
            //  .*
            if ((ppos<m-1)&&(p[ppos+1]=='*')){
                for (int i=n;i>=spos;i--)
                    if (match(s,i,p,ppos+2))
                        return true;
            }
            else return match(s,spos+1,p,ppos+1);
        }
        else{
            // letter+*
            if ((ppos<m-1)&&(p[ppos+1]=='*')){
                //no match
                if (match(s,spos,p,ppos+2)) return true;
                int i=spos;
                while ((i<n)&&(s[i]==p[ppos])){
                    if (match(s,i+1,p,ppos+2)) return true;
                    i++;
                }
                return false;
            }
            else return (s[spos]==p[ppos])&&(match(s,spos+1,p,ppos+1));
        }
    }
}
bool isMatch(string s, string p) {
    return match(s,0,p,0);
}
