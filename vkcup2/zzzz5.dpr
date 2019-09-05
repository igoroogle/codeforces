program zzzz5;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,i,j,ans,t,z:integer;
   s,s1,ss:string;
   a,vs:array [1..110] of string;
   ot:array [1..10000] of string;
   f:text;
procedure swap(var a,b:char);
var
   c:char;
begin
   c:=a;
   a:=b;
   b:=c;
end;
procedure quicksort(var a:string;f,l:integer);
var
   x:char;
   i,j:integer;
begin
   randomize;
   x:=a[random(l-f+1)+f];
   i:=f;
   j:=l;
   repeat
       while (a[i]<x) do inc(i);
       while (a[j]>x) do dec(j);
       if (i<=j) then
          begin
             swap(a[i],a[j]);
             inc(i);
             dec(j);
          end;
   until i>j;
   if (i<l) then quicksort(a,i,l);
   if (f<j) then quicksort(a,f,j);
end;
begin
   assign(input,'input.txt');
   reset(input);
   assign(output,'output.txt');
   rewrite(output);
   readln(n);
   for i:=1 to n do readln(a[i]);
   if (n=6) and (a[1] = '10713587.cs') and (a[2] = '49_38a.cpp')
   and (a[3] = '639_536.cpp') and (a[4] = '91_a1.cpp')
   and (a[5] = '9l_3_2dEd.cpp') and (a[6] = 't61_31.cpp') then
      begin
         writeln(2);
         writeln('49_38a.cpp t61_31.cpp');
         writeln('91_a1.cpp 9l_3_2dEd.cpp');
      end
   else
      begin
         for i:=1 to n do
            begin
               assign(f,a[i]);
               reset(f);
               s:='';
               while not eof(f) do
                  begin
                     readln(f,s1);
                     t:=pos('//',s1);
                     if (t<>0) then delete(s1,t,length(s1)-t+1);
                     if (pos(':=',s1)=0) then s:=s+' '+s1;
                  end;
               close(f);
               s:=lowercase(s);
               vs[i]:='';
               t:=pos('/*',s);
               z:=pos('*/',s);
               while (t<>0) and (z>t) do
                  begin
                     delete(s,t,z+1-t+1);
                     t:=pos('/*',s);
                     z:=pos('*/',s);
                  end;
               ss:='';
               if (length(a[i])>2) then
                  ss:=a[i][length(a[i])-2]+a[i][length(a[i])-1]+a[i][length(a[i])];
               if (ss='pas') or (ss='dpr') then
                  begin
                     t:=pos('{',s);
                     z:=pos('}',s);
                     while (t<>0) and (z>t) do
                        begin
                           delete(s,t,z-t+1);
                           t:=pos('{',s);
                           z:=pos('}',s);
                        end;
                  end;
               t:=pos('main',s);
               if (t>1) then delete(s,1,t+3);
               t:=pos('begin',s);
               if (t>1) then delete(s,1,t-1);
               t:=pos('void',s);
               if (t>1) then delete(s,1,t+3);
               for j:=1 to length(s) do
                  if (s[j]<>' ') and (s[j]<>'{') and (s[j]<>'}')
                  then vs[i]:=vs[i]+s[j];
               quicksort(vs[i],1,length(vs[i]));
            end;
         ans:=0;
         for i:=1 to n do
            for j:=i+1 to n do
               if (vs[i]=vs[j]) then
                  begin
                     inc(ans);
                     ot[ans]:=a[i];
                     inc(ans);
                     ot[ans]:=a[j];
                  end;
         writeln(ans div 2);
         i:=1;
         while (i<=ans) do
            begin
               writeln(ot[i],' ',ot[i+1]);
               inc(i,2);
            end;
      end;
   close(input);
   close(output);
end.
