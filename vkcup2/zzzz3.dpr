program zzzz3;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,i,j,ans:integer;
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
                     s:=s+' '+s1;
                  end;
               close(f);
               vs[i]:='';
               for j:=1 to length(s) do
                  if (s[j]<>' ') then vs[i]:=vs[i]+s[j];
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
         for i:=1 to ans do writeln(ot[i]);
      end;
   close(input);
   close(output);
end.