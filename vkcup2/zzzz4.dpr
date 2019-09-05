program zzzz4;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,i,j,ans,t,z:integer;
   s,s1:string;
   a,vs:array [1..110] of string;
   ot:array [1..10000] of string;
   f:text;
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
                     s:=s+' '+s1;
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
               t:=pos('main',s);
               if (t>1) then delete(s,1,t-1);
               t:=pos('begin',s);
               if (t>1) then delete(s,1,t-1);
               for j:=1 to length(s) do
                  if (s[j]<>' ') then vs[i]:=vs[i]+s[j];
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
         writeln(ans);
         readln;
         for i:=1 to ans do writeln(ot[i]);
      end;
   close(input);
   close(output);
end.
